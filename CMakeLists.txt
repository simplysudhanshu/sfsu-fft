cmake_minimum_required(VERSION 3.14)
project(test_project LANGUAGES CXX)

set(CMAKE_BUILD_TYPE "Release")

find_package(MPI REQUIRED)

add_executable(fftw_mpi_example fftw_mpi_example.cpp)
add_executable(data_generator data_generator.cpp)
# fftw_mpi_example.cpp source code located here: https://fftw.org/doc/2d-MPI-example.html

# end of file
