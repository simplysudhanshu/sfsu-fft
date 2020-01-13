#ifndef CatalystAnalysisAdaptor_h
#define CatalystAnalysisAdaptor_h

#include "AnalysisAdaptor.h"
#include "MeshMetadata.h"

#include <memory>
#include <vector>

class vtkCPDataDescription;
class vtkCPInputDataDescription;
class vtkCPPipeline;
class vtkDataObject;

namespace sensei
{

/** An adaptor that invokes ParaView Catalyst. The adaptor is configured via a
 * ParaView generated Catalyst Python script. See ::AddPythonScriptPipeline.
 */
class CatalystAnalysisAdaptor : public AnalysisAdaptor
{
public:
  /// creates a new instance
  static CatalystAnalysisAdaptor* New();

  senseiTypeMacro(CatalystAnalysisAdaptor, AnalysisAdaptor);

  /// prints the current adaptor state.
  void PrintSelf(ostream& os, vtkIndent indent) override;

  ///@name Run time configuration
  ///@{

  /** Add a vtkCPPipeline subclass to the global Catalyst Co-Processor. This is
   * a manual configuration method and can be used for pipelines hard wired
   * with compiled C++ code. This is the high performance bare metal method. A
   * run time defined Catalyst Python script may also be used. See
   * ::AddPythonScriptPipeline.
   */
  virtual void AddPipeline(vtkCPPipeline* pipeline);

  /** Adds a pipeline defined in a Catalyst python script. The Catalyst
   * Python script can be automatically generated using the ParaView GUI on a
   * representative dataset. The ::VTKPosthocIO and VTKAmrWriter can be used to
   * obtain such data.
   */
  virtual void AddPythonScriptPipeline(const std::string &fileName);

  /// Control how frequently the in situ processing occurs.
  int SetFrequency(unsigned int frequency);

  ///@}

  /// Invoke in situ processing using Catalyst
  bool Execute(DataAdaptor* data, DataAdaptor*&) override;

  /// Shuts ParaView catalyst down.
  int Finalize() override;

protected:
  CatalystAnalysisAdaptor();
  ~CatalystAnalysisAdaptor();

  void Initialize();

  int DescribeData(int timeStep, double time,
    const std::vector<MeshMetadataPtr> &metadata, vtkCPDataDescription *dataDesc);

  int SelectData(DataAdaptor *dataAdaptor,
    const std::vector<MeshMetadataPtr> &reqs, vtkCPDataDescription *dataDesc);

  int SetWholeExtent(vtkDataObject *dobj, vtkCPInputDataDescription *desc);

private:
  CatalystAnalysisAdaptor(const CatalystAnalysisAdaptor&); // Not implemented.
  void operator=(const CatalystAnalysisAdaptor&); // Not implemented.

  unsigned int Frequency;
};

}

#endif
