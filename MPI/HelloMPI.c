/*


*/

#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
int NCPU,tid,NPR,NTHR;

int main(int argc, char* argv[])
{

	int rank, size;
	MPI_Init(&argc, &argv);//Inicializa MPI
	MPI_Comm_rank(MPI_COMM_WORLD, &rank); //El rank id va de acuerdo al número de procesos #ranks=0..N-1
	MPI_Comm_size(MPI_COMM_WORLD, &size); //Número de procesos con que se ejecutó
	char processor_name[MPI_MAX_PROCESSOR_NAME];//Nombre de procesador
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);
	printf("Hello World from process %d of %d in procesor: %s\n", rank, size,processor_name);
	MPI_Finalize();
	
	return 0;

}
