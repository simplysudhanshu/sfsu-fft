#include "Fft.h"
#include "DataAdaptor.h"
#include "ConfigurableAnalysis.h"
#include "MeshMetadata.h"
#include "MeshMetadataMap.h"

#include <iostream>
#include <vector>
#include <complex>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <algorithm>
#include <omp.h>
#include <chrono>

#include <fftw3-mpi.h>
#include <svtkDoubleArray.h>
#include <svtkImageData.h>
#include <svtkPointData.h>
#include <svtkFieldData.h>
#include "SVTKDataAdaptor.h"

#include <typeinfo>

/* Send over to Python */ 
static void
send_with_sensei(std::vector <double> data, ptrdiff_t xDim, ptrdiff_t yDim, std::string const& xmlFileName)
{
    auto aa = sensei::ConfigurableAnalysis::New();
    
    // MAKE SURE YOU HAVE THIS XML FILE IN /build/bin FOLDER
    aa->Initialize(xmlFileName);     
    
    // DEBUG:
    printf("\n-> FFT to Python :: SENSEI initialization complete");

    svtkDoubleArray *da = svtkDoubleArray::New();
    da->SetNumberOfTuples(data.size());
    da->SetName("data");
    printf("\n-> Created svtkDataArray\n");

    for (unsigned int i = 0; i < data.size(); ++i)
        *da->GetPointer(i) = data.at(i);
    
    // DEBUG:
    printf("\n-> FFT to Python :: Setting up data in svtkDataArray");

    svtkImageData *im = svtkImageData::New(); 
    im->SetDimensions(xDim, yDim, 0);
    im->GetPointData()->AddArray(da);
    da->Delete();

    // DEBUG:
    printf("\n-> FFT to Python :: Setting up data in svtkImageData");

    sensei::SVTKDataAdaptor *dataAdaptor = sensei::SVTKDataAdaptor::New();
    // auto* dataAdaptor = sensei::DataAdaptor::New();
    // dataAdaptor->AddArray(im, "data", 0, "random std::string");
    dataAdaptor->SetDataObject("data", im); 
    // im->Delete();

    // DEBUG:
    printf("\n-> FFT to Python :: Setting up data in svtkDataAdaptor");

    aa->Execute(dataAdaptor, nullptr);
}


/* Perform FFTW */
std::vector<double>
fftw(ptrdiff_t N0, ptrdiff_t N1, std::string direction, std::vector<double> input_data)
{
    /* FFTW MPI Stuff */
    ptrdiff_t alloc_local, local_n0, local_n0_start, y, x;

    fftw_plan plan;
    fftw_complex *data;

    fftw_mpi_init();

    /* get local data size and allocate */
    alloc_local = fftw_mpi_local_size_2d(N0, N1, MPI_COMM_WORLD, &local_n0, &local_n0_start);
    data = fftw_alloc_complex(alloc_local);

    /* create plan for in-place DFT */
    if (direction == "FFTW_FORWARD")
        plan = fftw_mpi_plan_dft_2d(N0, N1, data, data, MPI_COMM_WORLD, FFTW_FORWARD, FFTW_ESTIMATE);  
    else
        plan = fftw_mpi_plan_dft_2d(N0, N1, data, data, MPI_COMM_WORLD, FFTW_BACKWARD, FFTW_ESTIMATE);  

    /* Read the input data and store the appropriate portion of it, in rank's data container */
    // std::vector <double> input_data = readStuff(N0*N1, input_file_name);
    ptrdiff_t data_index = 0;

    /* Adding input data to FFTW data buffer */
    for (y = local_n0_start; y < local_n0_start + local_n0; ++y) 
        for (x = 0; x < N1; ++x){
            data[data_index][0] = input_data[y*N1 + x];
            data[data_index][1] = 0;
            ++data_index;
        }

    // DEBUG:
    // printf("\nINPUT DATA: (rank %d) [%ld x %ld] at offet %ld\n", myrank, local_n0, N1, local_n0_start);
    // for (y = 0; y < local_n0; ++y) {
    //     for (x = 0; x < N1; ++x)
    //     {
    //         printf("`(%d)%f\t", myrank, data[y*N1 + x][0]);
    //     }
    //     printf("\n");
    // }
    
    /* compute transforms, in-place, as many times as desired */
    fftw_execute(plan);

    // DEBUG:
    // printf("\nAFTER Forward FFT: (rank %d) [%ld x %ld]\n", myrank, local_n0, N1);
    // for (y = 0; y < local_n0; ++y) {
    //     for (x = 0; x < N1; ++x){
    //         printf("~(%d)%f\t", myrank, data[y*N1 + x][0]);
    //     }
    //     printf("\n");
    // }

    std::vector<double> sbuf;
    sbuf.reserve(local_n0*N1 + 2);
    // fill(sbuf.begin(), sbuf.end(), -1.0);

    // Appending local_n0 and local_n0_start to sbuf, to calculate global offet of this particular data
    sbuf.emplace_back(local_n0_start);
    sbuf.emplace_back(local_n0);
    
    // Adding FFT output data to source buffer
    if (direction == "FFTW_FORWARD"){
        for(x = 0; x < local_n0*N1; ++x)
            sbuf.emplace_back(data[x][0]);
    }
    else{
        for(x = 0; x < local_n0*N1; ++x)
            sbuf.emplace_back(data[x][0]/(N0*N1));
    }

    return sbuf;
}


namespace sensei
{
struct Fft::InternalsType
{
  InternalsType() : N0(0), N1(0), direction("FFTW_FORWARD"), python_xml("") {}
  ~InternalsType() {}

  ptrdiff_t N0, N1;
  std::string direction;
  std::vector <double> data;
  std::string python_xml;

};

//----------------------------------------------------------------------------
Fft::Fft()
{
  MPI_Comm_dup(MPI_COMM_WORLD, &this->Comm);
  this->Internals = new InternalsType;
}

//----------------------------------------------------------------------------
Fft::~Fft()
{
  MPI_Comm_free(&this->Comm);
  delete this->Internals;
}

//----------------------------------------------------------------------------
void Fft::Initialize(std::string const& direction, std::string const& python_xml){
    this->Internals->direction = direction;
    this->Internals->python_xml = python_xml;
}

//----------------------------------------------------------------------------
bool Fft::Execute(sensei::DataAdaptor* dataIn, sensei::DataAdaptor** dataOut)
{
  printf("\n-> FFT :: In FFTW Endpoint\n");

  // we do not return anything
  if (dataOut)
    {
      *dataOut = nullptr;
    }
    
    // get the mesh object
    svtkDataObject *dobj = nullptr;

    if (dataIn->GetMesh("simulation_data", true, dobj))
        {
        SENSEI_ERROR("Failed to get mesh: \t simulation_data" << "\"")
        return false;
    }
    svtkImageData* im = dynamic_cast<svtkImageData*>(dobj);
    cout << "Type of im: " << typeid(im).name() << "\n";
    
    // DEBUGGING DIFFERENT METHODS TO GetDimensions:
    printf("\n-> FFT :: Debug Point 1\n");

    int dimensions[3];
    int* dimP = dimensions;

    cout << "dimP: " << dimP << '\n' << "Type of dimP: " << typeid(dimP).name() << '\n';
    
    im->GetDimensions(dimP);          
    cout << "DIMP: " << dimP[0] << "-" << dimP[1] << "-" << dimP[2] << "\n";

    // ---

    svtkIdType dimsID[3];
    im->GetDimensions(dimsID);
    cout << "DIMSID: " << dimsID[0] << "-" << dimsID[1] << "-" << dimsID[2] << "\n";
    
    // ---

    const int* dims = im->GetDimensions();
    cout << "DIMS: " << dims[0] << "-" << dims[1] << "-" << dims[2] << "\n";


    // Setup dimensions of data to compute FFT from
    this->Internals->N0 = (long int)(dims[0]);
    this->Internals->N1 = (long int)(dims[1]);

    // DEBUG:
    printf("\n-> FFT :: dimensions: %ld, %ld", this->Internals->N0, this->Internals->N1);
    
    // Get Data
    svtkDataArray *da = dobj->GetAttributesAsFieldData(0)->GetArray("data");

    for (int i = 0; i < (this->Internals->N0 * this->Internals->N1); ++i){
        this->Internals->data.emplace_back(*da->GetTuple(i));
    } 

    // DEBUG:
    printf("\n-> FFT :: ALL input DATA === [%ld x %ld]\n", this->Internals->N0, this->Internals->N1);
    for (ptrdiff_t y = 0; y < this->Internals->N0; ++y) {
        for (ptrdiff_t x = 0; x < this->Internals->N1; ++x){
            printf("%f\t", this->Internals->data.at(y*this->Internals->N1 + x));
        }
        printf("\n");
    }

    // Perform FFT
    std::vector<double> fftw_data = fftw(this->Internals->N0, this->Internals->N1, this->Internals->direction, this->Internals->data);

    // DEBUG:
    printf("\n-> FFT :: ALL fftw DATA === [%ld x %ld]\n", this->Internals->N0, this->Internals->N1);
    for (ptrdiff_t y = 0; y < this->Internals->N0; ++y) {
        for (ptrdiff_t x = 0; x < this->Internals->N1; ++x){
            printf("%f\t", fftw_data.at(y*this->Internals->N1 + x + 2));
        }
        printf("\n");
    }

    printf("\n-> FFT :: SENDING to python\n");
    send_with_sensei(fftw_data, this->Internals->N1, this->Internals->N0, this->Internals->python_xml);
    
    return true;
}

//-----------------------------------------------------------------------------
int Fft::Finalize()
{
  return 0;
}

//----------------------------------------------------------------------------
Fft* Fft::New(){
    return new sensei::Fft();
}


}