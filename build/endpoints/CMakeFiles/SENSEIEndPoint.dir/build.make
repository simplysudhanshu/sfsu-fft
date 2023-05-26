# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /global/common/software/nersc/cori-2022q1/spack/cray-cnl7-haswell/cmake-3.22.2-ugphoa4/bin/cmake

# The command to remove a file.
RM = /global/common/software/nersc/cori-2022q1/spack/cray-cnl7-haswell/cmake-3.22.2-ugphoa4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /global/cfs/cdirs/m3930/sudhanshu/SENSEI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build

# Include any dependencies generated for this target.
include endpoints/CMakeFiles/SENSEIEndPoint.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include endpoints/CMakeFiles/SENSEIEndPoint.dir/compiler_depend.make

# Include the progress variables for this target.
include endpoints/CMakeFiles/SENSEIEndPoint.dir/progress.make

# Include the compile flags for this target's objects.
include endpoints/CMakeFiles/SENSEIEndPoint.dir/flags.make

endpoints/CMakeFiles/SENSEIEndPoint.dir/SENSEIEndPoint.cpp.o: endpoints/CMakeFiles/SENSEIEndPoint.dir/flags.make
endpoints/CMakeFiles/SENSEIEndPoint.dir/SENSEIEndPoint.cpp.o: ../endpoints/SENSEIEndPoint.cpp
endpoints/CMakeFiles/SENSEIEndPoint.dir/SENSEIEndPoint.cpp.o: endpoints/CMakeFiles/SENSEIEndPoint.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object endpoints/CMakeFiles/SENSEIEndPoint.dir/SENSEIEndPoint.cpp.o"
	cd /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/endpoints && /opt/cray/pe/craype/2.7.10/bin/CC $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT endpoints/CMakeFiles/SENSEIEndPoint.dir/SENSEIEndPoint.cpp.o -MF CMakeFiles/SENSEIEndPoint.dir/SENSEIEndPoint.cpp.o.d -o CMakeFiles/SENSEIEndPoint.dir/SENSEIEndPoint.cpp.o -c /global/cfs/cdirs/m3930/sudhanshu/SENSEI/endpoints/SENSEIEndPoint.cpp

endpoints/CMakeFiles/SENSEIEndPoint.dir/SENSEIEndPoint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SENSEIEndPoint.dir/SENSEIEndPoint.cpp.i"
	cd /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/endpoints && /opt/cray/pe/craype/2.7.10/bin/CC $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /global/cfs/cdirs/m3930/sudhanshu/SENSEI/endpoints/SENSEIEndPoint.cpp > CMakeFiles/SENSEIEndPoint.dir/SENSEIEndPoint.cpp.i

endpoints/CMakeFiles/SENSEIEndPoint.dir/SENSEIEndPoint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SENSEIEndPoint.dir/SENSEIEndPoint.cpp.s"
	cd /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/endpoints && /opt/cray/pe/craype/2.7.10/bin/CC $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /global/cfs/cdirs/m3930/sudhanshu/SENSEI/endpoints/SENSEIEndPoint.cpp -o CMakeFiles/SENSEIEndPoint.dir/SENSEIEndPoint.cpp.s

# Object files for target SENSEIEndPoint
SENSEIEndPoint_OBJECTS = \
"CMakeFiles/SENSEIEndPoint.dir/SENSEIEndPoint.cpp.o"

# External object files for target SENSEIEndPoint
SENSEIEndPoint_EXTERNAL_OBJECTS =

bin/SENSEIEndPoint: endpoints/CMakeFiles/SENSEIEndPoint.dir/SENSEIEndPoint.cpp.o
bin/SENSEIEndPoint: endpoints/CMakeFiles/SENSEIEndPoint.dir/build.make
bin/SENSEIEndPoint: lib64/libsensei.a
bin/SENSEIEndPoint: lib64/libsenseiCore.a
bin/SENSEIEndPoint: lib64/libpugixml.a
bin/SENSEIEndPoint: utils/SVTK/lib64/libsvtkCommonDataModel-9.0.a
bin/SENSEIEndPoint: utils/SVTK/lib64/libsvtkCommonTransforms-9.0.a
bin/SENSEIEndPoint: utils/SVTK/lib64/libsvtkCommonMisc-9.0.a
bin/SENSEIEndPoint: utils/SVTK/lib64/libsvtkCommonMath-9.0.a
bin/SENSEIEndPoint: utils/SVTK/lib64/libsvtkCommonSystem-9.0.a
bin/SENSEIEndPoint: utils/SVTK/lib64/libsvtkCommonCore-9.0.a
bin/SENSEIEndPoint: utils/SVTK/lib64/libsvtksys-9.0.a
bin/SENSEIEndPoint: lib64/python3.9/site-packages//sensei//_PythonAnalysis.so
bin/SENSEIEndPoint: endpoints/CMakeFiles/SENSEIEndPoint.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/SENSEIEndPoint"
	cd /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/endpoints && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SENSEIEndPoint.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
endpoints/CMakeFiles/SENSEIEndPoint.dir/build: bin/SENSEIEndPoint
.PHONY : endpoints/CMakeFiles/SENSEIEndPoint.dir/build

endpoints/CMakeFiles/SENSEIEndPoint.dir/clean:
	cd /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/endpoints && $(CMAKE_COMMAND) -P CMakeFiles/SENSEIEndPoint.dir/cmake_clean.cmake
.PHONY : endpoints/CMakeFiles/SENSEIEndPoint.dir/clean

endpoints/CMakeFiles/SENSEIEndPoint.dir/depend:
	cd /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /global/cfs/cdirs/m3930/sudhanshu/SENSEI /global/cfs/cdirs/m3930/sudhanshu/SENSEI/endpoints /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/endpoints /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/endpoints/CMakeFiles/SENSEIEndPoint.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : endpoints/CMakeFiles/SENSEIEndPoint.dir/depend

