#include "stdio.h"
#include <omp.h>
#include <stdlib.h>
int nthreads, tid;
int main(int argc, char *argv[]) {
    
    #pragma omp parallel
    {
        tid = omp_get_thread_num();
        printf("Hello World from thread = %d\n", tid);

        if (tid == 0) 
        {
        nthreads = omp_get_num_threads();
        printf("Number of threads = %d\n", nthreads);
        }
    }
    return (0);
}