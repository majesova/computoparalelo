/*


*/

#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
int NCPU,tid,NPR,NTHR;

int main(int argc, char* argv[])
{

	int rank, size;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);
	printf("Hello World from process %d of %d in procesor: %s\n", rank, size,processor_name);
	MPI_Finalize();
	


	return 0;

}
