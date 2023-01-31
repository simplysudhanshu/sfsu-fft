/*
FFT ENDPOINT SCRIPT

Applies forward or inverse FFT on input data.

$ mpirun -np p ./fft_endpoint x y i d
    p = no. of processors for parallel execution
    x = x_dimension
    y = y_dimension
    w = input file name
    t = direction (0 = forward, 1 = inverse)

// Contributions:
Sudhanshu Kulkarni, E. Wes Bethel
2022
*/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <algorithm>
#include <omp.h>
#include <chrono>

//#include <mpi.h>
//#include <fftw3.h>
#include <fftw3-mpi.h>

using namespace std;

/* Writing output instead of SENSEI Endpoint */
void
writeStuff(long int data_size, string outputFileName, vector<double> output_data_floats = {}, vector<int> output_labels = {})
{   
    printf("\nWriting output -> %s \t(size %ld)\n", outputFileName.c_str(), data_size);
    
    // open the input file
    FILE *f = fopen(outputFileName.c_str(), "w");
    if (f == NULL)
    {
        perror(" Problem opening output file ");
        return ;
    }

    // this code writes out the output as floats rather than converting to ubyte
    if (!output_data_floats.empty()){
        fwrite((const void *)output_data_floats.data(), sizeof(double), data_size, f);
    }
    else if (!output_labels.empty()){
        fwrite((const void *)output_labels.data(), sizeof(int), data_size, f);
    }
        
    fclose(f);
}

/* Reading input instead of SENSEI Endpoint */
vector <double>
readStuff(long int data_size, string inputFileName)
{   
    printf("\nReading input from -> %s \t(size %ld)\n", inputFileName.c_str(), data_size);
    
    // vector to hold input data
    vector<double> input_data_floats(data_size);

    // open the input file
    FILE *f = fopen(inputFileName.c_str(), "r");
    if (f == NULL)
    {
        perror(" Problem opening output file ");
        return input_data_floats;
    }

    // this code reads the input as floats rather than converting to ubyte
    fread((void *)input_data_floats.data(), sizeof(double), data_size, f);
        
    fclose(f);

    // DEBUG:
    // printf("\nINPUT DATA:\n");
    // for (int y = 0; y < sqrt(data_size); ++y) {
    //     for (int x = 0; x < sqrt(data_size); ++x)
    //     {
    //         printf("%f\t", input_data_floats[y*sqrt(data_size) + x]);
    //     }
    //     printf("\n");
    // }

    return input_data_floats;
}

int 
main(int argc, char *argv[])
{

    /* Initializing some required variables */
    if (argc != 5){
        printf("Exactly 4 arguments required: 'y_dim, x_dim, input_file_name, direction (0:forward, 1:inverse)' \t& in the same order.");
        exit(0);
    }

    /* Hold dimensions + noise related variables */
    const ptrdiff_t N0 = atoi(argv[2]), N1 = atoi(argv[1]), N0c = N0 / 2, N1c = N1 / 2;
    const string input_file_name = argv[3];
    const int direction = atoi(argv[4]);


    /* FFTW MPI Stuff */
    ptrdiff_t alloc_local, local_n0, local_n0_start, y, x, y_diff, x_diff;

    fftw_plan plan;
    fftw_complex *data;

    /* Timing stuff */
    chrono::time_point<chrono::high_resolution_clock> start_time, end_time;
    chrono::duration<double> elapsed_computation_time,  elapsed_fft_time, elapsed_inverse_fft_time, elapsed_gather_time;

    /* Initializing MPI */
    MPI_Init(&argc, &argv);
    int myrank, nranks; 
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Comm_size(MPI_COMM_WORLD, &nranks);

    fftw_mpi_init();

    if (myrank == 0)
        printf(":: FFT ENDPOINT ::\n=> Running FFT computation on %ld x %ld data from %s with %d way parallel.\n\n", N1, N0, input_file_name.c_str(), nranks);

    // all_data_containers (to store data aggregated from all ranks) 
    vector <double> all_fft_data(N0*N1, -1.0);

// ---------------------------------------------------
    start_time = chrono::high_resolution_clock::now();

    /* get local data size and allocate */
    alloc_local = fftw_mpi_local_size_2d(N0, N1, MPI_COMM_WORLD, &local_n0, &local_n0_start);
    data = fftw_alloc_complex(alloc_local);

    /* create plan for in-place DFT */
    if (direction == 0)
        plan = fftw_mpi_plan_dft_2d(N0, N1, data, data, MPI_COMM_WORLD, FFTW_FORWARD, FFTW_ESTIMATE);  
    else if (direction == 1)
        plan = fftw_mpi_plan_dft_2d(N0, N1, data, data, MPI_COMM_WORLD, FFTW_BACKWARD, FFTW_ESTIMATE);  
    else
        {
            printf("\n!\tInvalid direction specified: (0:forward, 1:inverse) => you entered %d", direction);
            exit(0);
        }

    /* Read the input data and store the appropriate portion of it, in rank's data container */
    vector <double> input_data = readStuff(N0*N1, input_file_name);
    ptrdiff_t data_index = 0;


    /* Adding input data to FFTW data buffer */
    for (y = local_n0_start; y < local_n0_start + local_n0; ++y) 
        for (x = 0; x < N1; ++x){
            data[data_index][0] = input_data[y*N1 + x];
            data[data_index][1] = 0;
            ++data_index;
        }

    // DEBUG:
    printf("\nINPUT DATA: (rank %d) [%ld x %ld] at offet %ld\n", myrank, local_n0, N1, local_n0_start);
    for (y = 0; y < local_n0; ++y) {
        for (x = 0; x < N1; ++x)
        {
            printf("`(%d)%f\t", myrank, data[y*N1 + x][0]);
        }
        printf("\n");
    }
    
    /* compute transforms, in-place, as many times as desired */
    fftw_execute(plan);

    // DEBUG:
    printf("\nAFTER Forward FFT: (rank %d) [%ld x %ld]\n", myrank, local_n0, N1);
    for (y = 0; y < local_n0; ++y) {
        for (x = 0; x < N1; ++x){
            printf("~(%d)%f\t", myrank, data[y*N1 + x][0]);
        }
        printf("\n");
    }
    
    /* SENDING DATA OVER TO RANK 0 */
    if (myrank != 0 && local_n0 > 0)
    {
        // Creating a source buffer of all values of computation to send
        vector <double> sbuf;
        sbuf.reserve(local_n0*N1 + 2);
        // fill(sbuf.begin(), sbuf.end(), -1.0);

        // Appending local_n0 and local_n0_start to sbuf, to calculate global offet of this particular data
        sbuf.emplace_back(local_n0_start);
        sbuf.emplace_back(local_n0);

        // Adding FFT output data to source buffer
        if (direction == 0){
            for(x = 0; x < local_n0*N1; ++x)
                sbuf.emplace_back(data[x][0]);
        }
        else{
            for(x = 0; x < local_n0*N1; ++x)
                sbuf.emplace_back(data[x][0]/(N0*N1));
        }
        
        
        printf("\nAFTER Forward FFT sbuf: (rank %d) [%ld x %ld]\n", myrank, local_n0, N1);
        for (y = 0; y < local_n0; ++y) {
            for (x = 0; x < N1; ++x){
                printf("_(%d)%f\t", myrank, sbuf[y*N1 + x]);
            }
            printf("\n");
        }

        printf("\nSENDING FROM %d, <FFT DATA> size: %ld + local_n0: %f, local_n0_start: %f\n", myrank, sbuf.size(), sbuf.rbegin()[0], sbuf.rbegin()[1]);
        MPI_Send(sbuf.data(), sbuf.size(), MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }
    /* GATHERING DATA */
    else
    {
        // Adding FFT data of rank 0 to all_data_container
        if (direction == 0){
            for(int k = 0; k < local_n0*N1; ++k)
                all_fft_data[k] = data[k][0];
        }
        else{
            for(int k = 0; k < local_n0*N1; ++k)
                all_fft_data[k] = data[k][0]/(N0*N1);
        }
        // Maintaining rank labels and portions of the domain they worked on
        vector <int> labels(N1*N0);
        for (int k = 0; k < local_n0; ++k)
            labels[k] = 0;

        /* Getting data from all other ranks */
        for (int k = 1; k < nranks; ++k){
            // Buffer to recieve into -> Assign maximum size possible for this buffer, recieving less is okay.
            vector <double> rbuf;
            rbuf.reserve((N0/2)*N1 + 2);
            
            int rcount;
            MPI_Status stat;

            MPI_Recv(rbuf.data(), (N0/2)*N1 + 2, MPI_DOUBLE, k, 0,  MPI_COMM_WORLD, &stat);
            MPI_Get_count(&stat, MPI_DOUBLE, &rcount);

            if(rcount > (N0/2)*N1 + 2) {
                printf("\n[Rank %d] error: we expected a maximum of %ld items from Rank %d, but received %d items. \n", 0, (N0/2)*N1 + 2, k, rcount);
            }
            else{
                local_n0_start = rbuf[0];
                local_n0 = rbuf[1];
                
                ptrdiff_t all_offset = local_n0_start*N1;

                printf("\nRECEiVING FROM %d, <FFT DATA> size: %d @ %ld, %ld = globally @ %ld\n", k, rcount, local_n0, local_n0_start, all_offset);

                // Run the loop for size - 2, because last two elements are offset variables and not actually data
                for(int rbuf_index = 2, x = all_offset; x < all_offset + local_n0*N1; ++x, ++rbuf_index)
                    all_fft_data[x] = rbuf[rbuf_index];

                // Adding rank labels
                for(x = all_offset; x < all_offset + (local_n0*N1); ++x)
                    labels[x] = k;
            }
        }

        // DEBUG:
        printf("\n=== ALL fft DATA === [%ld, %ld]\n", N0, N1);
        for (y = 0; y < N0; ++y) {
            for (x = 0; x < N1; ++x){
                printf("%f\t", all_fft_data[y*N1 + x]);
            }
            printf("\n");
        }
// ---------------------------------------------------
        /* final Time Measurements */
        end_time = chrono::high_resolution_clock::now();
        elapsed_computation_time = end_time - start_time;

        printf("\n ____ TIMING RESULTS ____");
        printf("\nElapsed Computation Time: %6.4f (ms)\n", elapsed_computation_time*1000.0);

        /* Writing output in data folder */
        string output_file_name;
        output_file_name = "data/fft_";
        output_file_name += argv[1];
        output_file_name += "x";
        output_file_name += argv[2];
        output_file_name += "_";
        output_file_name += argv[4];
        output_file_name += "-";
        output_file_name += to_string(nranks);
        output_file_name += "r.dat";
        writeStuff(N0*N1, output_file_name, all_fft_data, {});

        output_file_name = "data/fft_labels_";
        output_file_name += argv[1];
        output_file_name += "x";
        output_file_name += argv[2];
        output_file_name += "_";
        output_file_name += argv[4];
        output_file_name += "-";
        output_file_name += to_string(nranks);
        output_file_name += "r.dat";
        writeStuff(N0*N1, output_file_name, {}, labels);
    }

    MPI_Finalize();
}


