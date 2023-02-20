# sfsu-fft
FFT Endpoint for SENSEI

The entire pipeline is divided in 3 steps:

- `data_generator.cpp` : Generate data of specified size. 

- `fftw_endpoint.cpp` : Apply FFTW and get the data in spectral domain.

- `denoiser.py` : Script to display and denoise the FFTW data.

There is an additional helper script `imshow.py` which can be used to display any intermediate file without denoising it. The main purpose of adding this file is to files generated at intermediate stages of the pipeline.

> Data generator and FFTW endpoint scripts are MPI-enabled.

Detailed instructions on how to build and run these files are present in the file itself. _CMake + Make can be used to build the c++ files._ 

The *Data* folder contains some trivial examples of previously computed data, fftw and images. There are some `.bov` files which can be used as a sample in case we want to view the files in VisIt. Feel free to remove all files and spin up new data.
