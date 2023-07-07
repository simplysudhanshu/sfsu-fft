#ifndef Fft_h
#define Fft_h

#include <AnalysisAdaptor.h>

class svtkDataArray;
class svtkDataObject;

namespace sensei
{
    /// Performs Fast Fourier Transform in parallel.
class SENSEI_EXPORT Fft : public AnalysisAdaptor
{
public:
  /// allocates a new instance
  static Fft* New();

  senseiTypeMacro(Fft, AnalysisAdaptor);

  void Initialize(std::string const& direction, std::string const& python_xml, std::string const& mesh_name, std::string const& array_name);

  /// compute the Fft for this time step
  bool Execute(DataAdaptor* data, DataAdaptor**) override;

  /// finalize the run
  int Finalize() override;


  // MPI_Comm GetCommunicator() { return this->Comm; }

protected:
  Fft();
  ~Fft();

  Fft(const Fft&) = delete;
  void operator=(const Fft&) = delete;

  MPI_Comm Comm;
  
  struct InternalsType;
  InternalsType *Internals;

  svtkDataArray* GetArray(svtkDataObject* dobj, const std::string& arrayname);

};

}
#endif