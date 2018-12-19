#include <stdio.h>
#include "mpi.h"
// Para compilar y correr:
//		compile: mpicc -o mpi_send mpi_send.c
//		run: mpirun -n 4 mpi_send
//
int main(argc, argv)
int argc;
char **argv;
{
	int rank, value, size;
    MPI_Status status;

    MPI_Init(&argc, &argv);
 
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); //get the rank or ID of the current process
    MPI_Comm_size(MPI_COMM_WORLD, &size); //Número de procesos que están corriendo

    do { 
        if (rank == 0) {
            printf("Introduce un número (Negativo para detener):\n");
            scanf("%d",&value);
            MPI_Send(&value,1,MPI_INT,rank+1,0,MPI_COMM_WORLD); // El primer proceso envia un mensaje a todos los demás nodos
        } else {
            
            MPI_Recv(&value,1,MPI_INT,rank-1,0,MPI_COMM_WORLD,&status); // Cada proceso lo recibe, excepto el maestro
            
            if (rank < size-1)
                MPI_Send(&value,1,MPI_INT,rank+1,0,MPI_COMM_WORLD); // Cada prceso envía el valor al siguiente proceso
        
            printf("Process %d got %d\n",rank, value);  //Imprime lo recibido
        }
    } while (value >= 0); //Continúa ciclado hasta que encuentre un número negativo

    MPI_Finalize();

	return 0;
}