# Install script for directory: /global/cfs/cdirs/m3930/sudhanshu/SENSEI/utils/SVTK/Utilities/KWSys/svtksys

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/svtk-9.0/svtksys" TYPE FILE FILES "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Utilities/KWSys/svtksys/Directory.hxx")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/svtk-9.0/svtksys" TYPE FILE FILES "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Utilities/KWSys/svtksys/DynamicLoader.hxx")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/svtk-9.0/svtksys" TYPE FILE FILES "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Utilities/KWSys/svtksys/Encoding.hxx")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/svtk-9.0/svtksys" TYPE FILE FILES "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Utilities/KWSys/svtksys/Glob.hxx")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/svtk-9.0/svtksys" TYPE FILE FILES "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Utilities/KWSys/svtksys/RegularExpression.hxx")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/svtk-9.0/svtksys" TYPE FILE FILES "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Utilities/KWSys/svtksys/SystemTools.hxx")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/svtk-9.0/svtksys" TYPE FILE FILES "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Utilities/KWSys/svtksys/CommandLineArguments.hxx")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/svtk-9.0/svtksys" TYPE FILE FILES "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Utilities/KWSys/svtksys/FStream.hxx")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/svtk-9.0/svtksys" TYPE FILE FILES "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Utilities/KWSys/svtksys/SystemInformation.hxx")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/svtk-9.0/svtksys" TYPE FILE FILES "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Utilities/KWSys/svtksys/Configure.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/svtk-9.0/svtksys" TYPE FILE FILES "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Utilities/KWSys/svtksys/SharedForward.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/svtk-9.0/svtksys" TYPE FILE FILES "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Utilities/KWSys/svtksys/Process.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/svtk-9.0/svtksys" TYPE FILE FILES "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Utilities/KWSys/svtksys/Base64.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/svtk-9.0/svtksys" TYPE FILE FILES "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Utilities/KWSys/svtksys/Encoding.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/svtk-9.0/svtksys" TYPE FILE FILES "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Utilities/KWSys/svtksys/MD5.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/svtk-9.0/svtksys" TYPE FILE FILES "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Utilities/KWSys/svtksys/System.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/svtk-9.0/svtksys" TYPE FILE FILES "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Utilities/KWSys/svtksys/Configure.hxx")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/svtk-9.0/svtksys" TYPE FILE FILES "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Utilities/KWSys/svtksys/String.hxx")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/svtk-9.0/svtksys" TYPE FILE FILES "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Utilities/KWSys/svtksys/hashtable.hxx")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/svtk-9.0/svtksys" TYPE FILE FILES "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Utilities/KWSys/svtksys/hash_fun.hxx")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/svtk-9.0/svtksys" TYPE FILE FILES "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Utilities/KWSys/svtksys/hash_map.hxx")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/svtk-9.0/svtksys" TYPE FILE FILES "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Utilities/KWSys/svtksys/hash_set.hxx")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64" TYPE STATIC_LIBRARY FILES "/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/lib64/libsvtksys-9.0.a")
endif()

