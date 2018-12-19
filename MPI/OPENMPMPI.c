#include <stdio.h>
#include <mpi.h>
#include <omp.h>

int NCPU,tid,NPR,NTHR;

int main(int argc, char* argv[])
{
	int rank, size;
	
	MPI_Init(&argc, &argv);
	
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	char processor_name[MPI_MAX_PROCESSOR_NAME];

	
	#pragma omp parallel num_threads(2)  //Inicia código paralelo
  	{
		NCPU = omp_get_num_procs();
		tid = omp_get_thread_num();
		NPR = omp_get_num_threads();
		NTHR = omp_get_max_threads();
	}
    int name_len;
	
    MPI_Get_processor_name(processor_name, &name_len);
	printf("Hello from thread %d out of %d from process %d out of %d on %s\n",tid, NPR, rank, NCPU, processor_name);
	MPI_Finalize();
  
	return 0;

}
