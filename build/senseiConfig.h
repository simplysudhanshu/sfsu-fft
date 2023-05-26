#ifndef senseiConfig_h
#define senseiConfig_h

#define SENSEI_VERSION "v4.1.0-24-g97ad10f"
#define SENSEI_VERSION_MAJOR 4
#define SENSEI_VERSION_MINOR 1
#define SENSEI_VERSION_PATCH 0

#if defined(_WIN32)
#define SENSEI_IMPORT __declspec(dllimport)
#define SENSEI_EXPORT __declspec(dllexport)
#define SENSEI_HIDDEN
#elif __GNUC__ >= 4
#define SENSEI_IMPORT __attribute__((visibility("default")))
#define SENSEI_EXPORT __attribute__((visibility("default")))
#define SENSEI_HIDDEN __attribute__((visibility("hidden")))
#else
#define SENSEI_IMPORT
#define SENSEI_EXPORT
#define SENSEI_HIDDEN
#endif

#define ENABLE_SENSEI
/* #undef ENABLE_CUDA */
#define ENABLE_PYTHON
/* #undef ENABLE_CATALYST */
/* #undef ENABLE_CATALYST_PYTHON */
/* #undef ENABLE_LIBSIM */
/* #undef ENABLE_ADIOS1 */
/* #undef ENABLE_ADIOS2 */
/* #undef ENABLE_HDF5 */
/* #undef ENABLE_CONDUIT */
/* #undef ENABLE_ASCENT */
/* #undef ENABLE_OSPRAY */
/* #undef ENABLE_VTK_CORE */
/* #undef ENABLE_VTK_MPI */
/* #undef ENABLE_VTK_IO */
/* #undef ENABLE_VTK_RENDERING */
/* #undef ENABLE_VTK_ACCELERATORS */
/* #undef ENABLE_VTK_FILTERS */
/* #undef ENABLE_VTK_FILTERS_PARALLEL_GEOMETRY */
/* #undef ENABLE_VTKM */
/* #undef ENABLE_PROFILER */

#define SENSEI_PYTHON_VERSION 3

#ifdef __cplusplus
#include <svtkSetGet.h>
#define senseiBaseTypeMacro(a1, a2) svtkBaseTypeMacro(a1, a2)
#define senseiTypeMacro(a1, a2) svtkTypeMacro(a1, a2)
#define senseiNewMacro(thisClass) \
  thisClass* thisClass::New() \
  { \
  auto result = new thisClass; \
  result->InitializeObjectBase(); \
  return result; \
  }
#endif

#endif
