
#include <iostream>
#include <vector>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <algorithm>
#include <omp.h>
#include <chrono>

#include <mpi.h>
//#include <fftw3.h>
//#include <fftw3-mpi.h>


int 
main(int ac, char *av[])
{
   MPI_Init(&ac, &av);
  
   int myrank, nranks; 
   MPI_Comm_rank( MPI_COMM_WORLD, &myrank);
   MPI_Comm_size( MPI_COMM_WORLD, &nranks);

   printf(" Hello world, I am rank %d of %d total ranks \n", myrank, nranks);

   MPI_Finalize();
}


