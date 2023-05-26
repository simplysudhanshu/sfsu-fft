# Install script for directory: /global/cfs/cdirs/m3930/sudhanshu/SENSEI/utils/SVTK/Common/Math

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/svtk-9.0" TYPE FILE FILES
    "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/utils/SVTK/Common/Math/svtkTuple.h"
    "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/utils/SVTK/Common/Math/svtkAmoebaMinimizer.h"
    "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/utils/SVTK/Common/Math/svtkFunctionSet.h"
    "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/utils/SVTK/Common/Math/svtkInitialValueProblemSolver.h"
    "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/utils/SVTK/Common/Math/svtkMatrix3x3.h"
    "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/utils/SVTK/Common/Math/svtkMatrix4x4.h"
    "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/utils/SVTK/Common/Math/svtkPolynomialSolversUnivariate.h"
    "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/utils/SVTK/Common/Math/svtkQuaternionInterpolator.h"
    "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/utils/SVTK/Common/Math/svtkRungeKutta2.h"
    "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/utils/SVTK/Common/Math/svtkRungeKutta4.h"
    "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/utils/SVTK/Common/Math/svtkRungeKutta45.h"
    "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/utils/SVTK/Common/Math/svtkQuaternion.h"
    "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Common/Math/svtkCommonMathModule.h"
    "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/utils/SVTK/Common/Math/svtkQuaternion.txx"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64" TYPE STATIC_LIBRARY FILES "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/lib64/libsvtkCommonMath-9.0.a")
endif()

