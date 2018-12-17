/*
Imprime 3 bloque master 
printf("Soy el thread MASTER %d, actuando en solitario dentro del primer bloque\n");
printf("Soy el thread MASTER %d, actuando en solitario dentro del segundo bloque\n");
printf("Soy el thread MASTER %d, actuando en solitario dentro del tercer bloque\n");

Imprimir por todos los hilos
printf("Soy el thread %d, fuera de los singles\n");
*/

#include "stdio.h" 
#include <omp.h>

int main(int argc, char *argv[])
{
	#pragma omp parallel num_threads(1) 
	{
		#pragma master
		{ 
			printf("Soy el thread MASTER %d, actuando en solitario dentro del primer bloque \n",omp_get_thread_num()); 
			
		}
		#pragma master
		{ 
			printf("Soy el thread MASTER %d, actuando en solitario dentro ddel segundo bloque \n",omp_get_thread_num()); 
			
		} 
		#pragma master
		{ 
			printf("Soy el thread MASTER %d, actuando en solitario dentro ddel tercer bloque \n",omp_get_thread_num()); 
		}

		// QUÉ OCURRE EN ESTA SECCION ??
		printf("Soy el thread %d, fuera de los singles\n",omp_get_thread_num()); 
	}//parallel

	return(0);
}
