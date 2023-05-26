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

# Utility rule file for senseiPython_swig_compilation.

# Include any custom commands dependencies for this target.
include python/CMakeFiles/senseiPython_swig_compilation.dir/compiler_depend.make

# Include the progress variables for this target.
include python/CMakeFiles/senseiPython_swig_compilation.dir/progress.make

python/CMakeFiles/senseiPython_swig_compilation: python/CMakeFiles/senseiPython.dir/senseiPythonPYTHON.stamp

python/CMakeFiles/senseiPython.dir/senseiPythonPYTHON.stamp: ../sensei/DataAdaptor.i
python/CMakeFiles/senseiPython.dir/senseiPythonPYTHON.stamp: ../python/senseiPython.i
python/CMakeFiles/senseiPython.dir/senseiPythonPYTHON.stamp: ../python/senseiPython.i
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Swig compile senseiPython.i for python"
	cd /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/python && /global/common/software/nersc/cori-2022q1/spack/cray-cnl7-haswell/cmake-3.22.2-ugphoa4/bin/cmake -E make_directory /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/python/CMakeFiles/senseiPython.dir /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/lib64/python3.9/site-packages//sensei/ /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/python
	cd /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/python && /global/common/software/nersc/cori-2022q1/spack/cray-cnl7-haswell/cmake-3.22.2-ugphoa4/bin/cmake -E touch /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/python/CMakeFiles/senseiPython.dir/senseiPythonPYTHON.stamp
	cd /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/python && /global/common/software/nersc/cori-2022q1/spack/cray-cnl7-haswell/cmake-3.22.2-ugphoa4/bin/cmake -E env SWIG_LIB=/global/common/software/nersc/pm-stable/sw/swig/4.1.0/share/swig/4.1.0 /global/common/software/nersc/pm-stable/sw/swig/4.1.0/bin/swig -python -I/global/cfs/cdirs/m3930/sudhanshu/SENSEI -I/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build -I/global/cfs/cdirs/m3930/sudhanshu/SENSEI/python -I/global/cfs/cdirs/m3930/sudhanshu/SENSEI/utils/pysvtk -I/opt/python/3.9.7.1/lib/python3.9/site-packages/numpy/core/include -I/global/cfs/cdirs/m3930/sudhanshu/SENSEI/sensei -I/global/cfs/cdirs/m3930/sudhanshu/SENSEI/utils/pugixml/src -I/global/cfs/cdirs/m3930/sudhanshu/SENSEI/utils -I/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Common/DataModel -I/global/cfs/cdirs/m3930/sudhanshu/SENSEI/utils/SVTK/Common/DataModel -I/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Common/Core -I/global/cfs/cdirs/m3930/sudhanshu/SENSEI/utils/SVTK/Common/Core -I/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Utilities/KWIML -I/global/cfs/cdirs/m3930/sudhanshu/SENSEI/utils/SVTK/Utilities/KWIML -I/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Utilities/KWSys -I/global/cfs/cdirs/m3930/sudhanshu/SENSEI/utils/SVTK/Utilities/KWSys -I/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Common/Math -I/global/cfs/cdirs/m3930/sudhanshu/SENSEI/utils/SVTK/Common/Math -I/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/Common/Transforms -I/global/cfs/cdirs/m3930/sudhanshu/SENSEI/utils/SVTK/Common/Transforms -I/opt/cray/pe/mpt/7.7.19/gni/mpich-gnu/8.2/include -I/opt/cray/rca/2.2.20-7.0.3.1_3.48__g8e3fb5b.ari/include -I/opt/cray/alps/6.6.67-7.0.3.1_3.43__gb91cd181.ari/include -I/opt/cray/xpmem/default/include -I/opt/cray/gni-headers/default/include -I/opt/cray/pe/pmi/5.0.17/include -I/opt/cray/ugni/default/include -I/opt/cray/udreg/default/include -I/opt/cray/wlm_detect/1.3.3-7.0.3.1_3.23__g7109084.ari/include -I/opt/cray/krca/2.2.8-7.0.3.1_3.33__g59af36e.ari/include -I/opt/cray-hss-devel/9.0.0/include -I/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/utils/SVTK/ThirdParty/utf8 -I/global/cfs/cdirs/m3930/sudhanshu/SENSEI/utils/SVTK/ThirdParty/utf8 -I/global/cfs/cdirs/m3930/sudhanshu/SENSEI/utils/SVTK/Utilities/KWIML/svtkkwiml/include/ -I/opt/python/3.9.7.1/include/python3.9 -I/opt/python/3.9.7.1/lib/python3.9/site-packages/mpi4py/include -outdir /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/lib64/python3.9/site-packages//sensei/ -c++ -module senseiPython -interface _senseiPython -I/global/cfs/cdirs/m3930/sudhanshu/SENSEI -I/global/cfs/cdirs/m3930/sudhanshu/SENSEI/build -o /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/python/senseiPythonPYTHON_wrap.cxx /global/cfs/cdirs/m3930/sudhanshu/SENSEI/python/senseiPython.i

senseiPython_swig_compilation: python/CMakeFiles/senseiPython.dir/senseiPythonPYTHON.stamp
senseiPython_swig_compilation: python/CMakeFiles/senseiPython_swig_compilation
senseiPython_swig_compilation: python/CMakeFiles/senseiPython_swig_compilation.dir/build.make
.PHONY : senseiPython_swig_compilation

# Rule to build all files generated by this target.
python/CMakeFiles/senseiPython_swig_compilation.dir/build: senseiPython_swig_compilation
.PHONY : python/CMakeFiles/senseiPython_swig_compilation.dir/build

python/CMakeFiles/senseiPython_swig_compilation.dir/clean:
	cd /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/python && $(CMAKE_COMMAND) -P CMakeFiles/senseiPython_swig_compilation.dir/cmake_clean.cmake
.PHONY : python/CMakeFiles/senseiPython_swig_compilation.dir/clean

python/CMakeFiles/senseiPython_swig_compilation.dir/depend:
	cd /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /global/cfs/cdirs/m3930/sudhanshu/SENSEI /global/cfs/cdirs/m3930/sudhanshu/SENSEI/python /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/python /global/cfs/cdirs/m3930/sudhanshu/SENSEI/build/python/CMakeFiles/senseiPython_swig_compilation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : python/CMakeFiles/senseiPython_swig_compilation.dir/depend

