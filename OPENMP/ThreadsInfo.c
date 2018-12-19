#include "stdio.h"//librería de entrada y salida
#include <omp.h>//Librería openmp
#include <stdlib.h>//Librería para operaciones estándar
int NCPU,tid,NPR,NTHR;
int main(int argc, char *argv[])
{
  #pragma omp parallel num_threads(5)//Region donde se encuentra código para ejecutarse en paralelo
  {
    /*Returns the number of processors that are available to
    /the device at the time the routine is called*/
    NCPU = omp_get_num_procs();
    /*Returns the thread number of the calling thread within
    the current team*/
    tid = omp_get_thread_num();
    /*Returns the number of threads in the current team. The
    binding region for an omp_get_num_threads region is
    the innermost enclosing parallel region*/
    NPR = omp_get_num_threads();
    /*Returns an upper bound on the number of threads that
    could be used to form a new team if a parallel construct
    without a num_threads clause were encountered afer
    executon returns from this routine*/
    NTHR = omp_get_max_threads();

    if (tid == 0) {
      printf("# DE CPUS\t= %i\n",NCPU);
      printf("# DE THREADS SOLICITADOS\t= %i\n",NTHR);
      printf("# DE THREADS DISPONIBLES PR\t= %i\n",NPR);
    }else{
      printf("Hello multicore user! I am thread %i out of %i\n",tid,NPR);
    }
  }
  return(0);
}
