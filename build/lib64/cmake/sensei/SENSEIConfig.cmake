set(SENSEI_VERSION "v4.1.0-24-g97ad10f")
set(SENSEI_VERSION_MAJOR "4")
set(SENSEI_VERSION_MINOR "1")
set(SENSEI_VERSION_PATCH "0")
set(SENSEI_VERSION_DEVEL "")

include(CMakeFindDependencyMacro)

if (NOT SENSEI_DIR)
  # NOTE: this is for the ECP spack based regression testing.
  set(SENSEI_DIR "${CMAKE_CURRENT_LIST_DIR}/../../")
endif ()

list(APPEND CMAKE_MODULE_PATH "${SENSEI_DIR}")

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_LIST_DIR}/svtk-9.0")
find_package(svtk REQUIRED)

set(SENSEI_LIB_TYPE STATIC)
if (OFF)
  set(SENSEI_LIB_TYPE SHARED)
endif()

if (OFF)
  set(BUILD_SHARED_LIBS OFF FORCE)
  set(CMAKE_FIND_LIBRARY_SUFFIXES ${CMAKE_STATIC_LIBRARY_SUFFIX})
  set(LINK_SEARCH_START_STATIC TRUE)
  set(LINK_SEARCH_END_STATIC TRUE)
endif()

set(ENABLE_SENSEI ON)
set(ENABLE_PYTHON ON)
set(ENABLE_CATALYST OFF)
set(ENABLE_CATALYST_PYTHON OFF)
set(ENABLE_LIBSIM OFF)
set(ENABLE_ADIOS1 OFF)
set(ENABLE_ADIOS2 OFF)
set(ENABLE_HDF5 OFF)
set(ENABLE_CONDUIT OFF)
set(ENABLE_OSPRAY OFF)
set(ENABLE_VTK_CORE OFF)
set(ENABLE_VTK_ACCELERATORS OFF)
set(ENABLE_VTK_MPI OFF)
set(ENABLE_VTK_IO OFF)
set(ENABLE_VTKM OFF)
set(ENABLE_VTKM_RENDERING OFF)
set(ENABLE_ASCENT OFF)

include(thread)
include(sMPI)
include(sSVTK)
include(pugixml)
include(sDIY)

if (ENABLE_CATALYST)
  if (NOT ParaView_DIR)
    set(ParaView_DIR "")
  endif()
  find_dependency(ParaView)
elseif (ENABLE_VTK_CORE)
  if (NOT VTK_DIR)
    set(VTK_DIR "")
  endif()
  find_dependency(VTK)
endif()

if (ENABLE_VTK_CORE)
  include(sVTK)
endif ()

if (ENABLE_VTKM)
  include(sVTKm)
endif()

if (ENABLE_LIBSIM)
  include(sLibsim)
endif()

if (ENABLE_ADIOS1)
  include(sADIOS1)
endif()

if (ENABLE_ADIOS2)
  if(NOT ADIOS2_DIR)
    set(ADIOS2_DIR "")
  endif()
  find_dependency(ADIOS2)
  include(sADIOS2)
endif()

if (ENABLE_HDF5)
  include(sHDF5)
endif()

if (ENABLE_CONDUIT)
  if(NOT CONDUIT_DIR)
    set(CONDUIT_DIR "")
  endif()
  find_dependency(Conduit NO_DEFAULT_PATH PATHS ${CONDUIT_DIR})
  include(sConduit)
endif()

if(ENABLE_ASCENT)
  if(NOT ASCENT_DIR)
    set(ASCENT_DIR "")
  endif()
  find_dependency(Ascent NO_DEFAULT_PATH PATHS ${ASCENT_DIR})
  include(sAscent)
endif()

include(senseiCore)

if (ENABLE_PYTHON)
  set(SENSEI_PYTHON_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../lib64/python3.9/site-packages//sensei/")

  include(sPython)

  add_library(sPythonAnalysis SHARED IMPORTED)
  set_property(TARGET sPythonAnalysis
    PROPERTY IMPORTED_LOCATION
    "${SENSEI_PYTHON_DIR}/_PythonAnalysis.so")
  if (APPLE)
    set_property(TARGET sPythonAnalysis
    PROPERTY IMPORTED_SONAME "@rpath/_PythonAnalysis.so")
  endif()
  add_dependencies(sPythonAnalysis PythonAnalysis)

endif()

include(sensei)
