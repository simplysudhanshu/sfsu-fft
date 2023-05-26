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
include sensei/testing/CMakeFiles/testProgrammableDataAdaptor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include sensei/testing/CMakeFiles/testProgrammableDataAdaptor.dir/compiler_depend.make

# Include the progress variables for this target.
include sensei/testing/CMakeFiles/testProgrammableDataAdaptor.dir/progress.make

# Include the compile flags for this target's objects.
include sensei/testing/CMakeFiles/testProgrammableDataAdaptor.dir/flags.make

sensei/testing/CMakeFiles/testProgrammableDataAdaptor.dir/testProgrammableDataAdaptor.cpp.o: sensei/testing/CMakeFiles/testProgrammableDataAdaptor.dir/flags.make
sensei/testing/CMakeFiles/testProgrammableDataAdaptor.dir/testProgrammableDataAdaptor.cpp.o: ../sensei/testing/testProgrammableDataAdaptor.cpp
sensei/testing/CMakeFiles/testProgrammableDataAdaptor.dir/testProgrammableDataAdaptor.cpp.o: sensei/testing/CMakeFiles/testProgrammableDataAdaptor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object sensei/testing/CMakeFiles/testProgrammableDataAdaptor.dir/testProgrammableDataAdaptor.cpp.o"
	cd /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/sensei/testing && /opt/cray/pe/craype/2.7.10/bin/CC $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT sensei/testing/CMakeFiles/testProgrammableDataAdaptor.dir/testProgrammableDataAdaptor.cpp.o -MF CMakeFiles/testProgrammableDataAdaptor.dir/testProgrammableDataAdaptor.cpp.o.d -o CMakeFiles/testProgrammableDataAdaptor.dir/testProgrammableDataAdaptor.cpp.o -c /global/cfs/cdirs/m3930/sudhanshu/SENSEI/sensei/testing/testProgrammableDataAdaptor.cpp

sensei/testing/CMakeFiles/testProgrammableDataAdaptor.dir/testProgrammableDataAdaptor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testProgrammableDataAdaptor.dir/testProgrammableDataAdaptor.cpp.i"
	cd /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/sensei/testing && /opt/cray/pe/craype/2.7.10/bin/CC $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /global/cfs/cdirs/m3930/sudhanshu/SENSEI/sensei/testing/testProgrammableDataAdaptor.cpp > CMakeFiles/testProgrammableDataAdaptor.dir/testProgrammableDataAdaptor.cpp.i

sensei/testing/CMakeFiles/testProgrammableDataAdaptor.dir/testProgrammableDataAdaptor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testProgrammableDataAdaptor.dir/testProgrammableDataAdaptor.cpp.s"
	cd /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/sensei/testing && /opt/cray/pe/craype/2.7.10/bin/CC $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /global/cfs/cdirs/m3930/sudhanshu/SENSEI/sensei/testing/testProgrammableDataAdaptor.cpp -o CMakeFiles/testProgrammableDataAdaptor.dir/testProgrammableDataAdaptor.cpp.s

# Object files for target testProgrammableDataAdaptor
testProgrammableDataAdaptor_OBJECTS = \
"CMakeFiles/testProgrammableDataAdaptor.dir/testProgrammableDataAdaptor.cpp.o"

# External object files for target testProgrammableDataAdaptor
testProgrammableDataAdaptor_EXTERNAL_OBJECTS =

bin/testProgrammableDataAdaptor: sensei/testing/CMakeFiles/testProgrammableDataAdaptor.dir/testProgrammableDataAdaptor.cpp.o
bin/testProgrammableDataAdaptor: sensei/testing/CMakeFiles/testProgrammableDataAdaptor.dir/build.make
bin/testProgrammableDataAdaptor: lib64/libsensei.a
bin/testProgrammableDataAdaptor: lib64/libsenseiCore.a
bin/testProgrammableDataAdaptor: lib64/libpugixml.a
bin/testProgrammableDataAdaptor: utils/SVTK/lib64/libsvtkCommonDataModel-9.0.a
bin/testProgrammableDataAdaptor: utils/SVTK/lib64/libsvtkCommonTransforms-9.0.a
bin/testProgrammableDataAdaptor: utils/SVTK/lib64/libsvtkCommonMisc-9.0.a
bin/testProgrammableDataAdaptor: utils/SVTK/lib64/libsvtkCommonMath-9.0.a
bin/testProgrammableDataAdaptor: utils/SVTK/lib64/libsvtkCommonSystem-9.0.a
bin/testProgrammableDataAdaptor: utils/SVTK/lib64/libsvtkCommonCore-9.0.a
bin/testProgrammableDataAdaptor: utils/SVTK/lib64/libsvtksys-9.0.a
bin/testProgrammableDataAdaptor: lib64/python3.9/site-packages//sensei//_PythonAnalysis.so
bin/testProgrammableDataAdaptor: sensei/testing/CMakeFiles/testProgrammableDataAdaptor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/testProgrammableDataAdaptor"
	cd /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/sensei/testing && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testProgrammableDataAdaptor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sensei/testing/CMakeFiles/testProgrammableDataAdaptor.dir/build: bin/testProgrammableDataAdaptor
.PHONY : sensei/testing/CMakeFiles/testProgrammableDataAdaptor.dir/build

sensei/testing/CMakeFiles/testProgrammableDataAdaptor.dir/clean:
	cd /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/sensei/testing && $(CMAKE_COMMAND) -P CMakeFiles/testProgrammableDataAdaptor.dir/cmake_clean.cmake
.PHONY : sensei/testing/CMakeFiles/testProgrammableDataAdaptor.dir/clean

sensei/testing/CMakeFiles/testProgrammableDataAdaptor.dir/depend:
	cd /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /global/cfs/cdirs/m3930/sudhanshu/SENSEI /global/cfs/cdirs/m3930/sudhanshu/SENSEI/sensei/testing /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/sensei/testing /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/sensei/testing/CMakeFiles/testProgrammableDataAdaptor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sensei/testing/CMakeFiles/testProgrammableDataAdaptor.dir/depend

