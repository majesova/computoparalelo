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
	#pragma omp parallel num_threads(8) 
	{
		//Se ejecuta una sola vez en el hilo maestro, usualmente es el 0.
		#pragma omp master
		{ 
			printf("Soy el thread MASTER %d, actuando en solitario dentro del primer bloque \n",omp_get_thread_num()); 
		}
		#pragma omp master
		{ 
			printf("Soy el thread MASTER %d, actuando en solitario dentro ddel segundo bloque \n",omp_get_thread_num()); 
			
		} 
		#pragma omp master
		{ 
			printf("Soy el thread MASTER %d, actuando en solitario dentro ddel tercer bloque \n",omp_get_thread_num()); 
		}
		//Esta sección se ejecuta por cada hilo
		printf("Soy el thread %d, fuera del master\n",omp_get_thread_num()); 
	}//parallel

	return(0);
}
