/*
Imprime 3 bloque single 
printf("Soy el thread %d, actuando en solitario dentro del primer bloque\n");
printf("Soy el thread %d, actuando en solitario dentro del segundo bloque\n");
printf("Soy el thread %d, actuando en solitario dentro del tercer bloque\n");

Imprimir por todos los hilos
printf("Soy el thread %d, fuera de los singles\n");
*/

#include "stdio.h" 
#include <omp.h>
int main(int argc, char *argv[])
{
	#pragma omp parallel  
	{
		//Solo se ejecuta una vez en un único hilo
		//Es decir se ejectará una única vez a diferencia de la última línea que se ejecuta en cada hilo
		#pragma omp single
		{ 
			printf("Soy el thread %d, actuando en solitario dentro del primer bloque\n",omp_get_thread_num()); 
		}
		#pragma omp single
		{ 
			printf("Soy el thread %d, actuando en solitario dentro del segundo bloque \n",omp_get_thread_num()); 	
		} 
		#pragma omp single
		{ 
			printf("Soy el thread %d, actuando en solitario dentro del tercer bloque \n",omp_get_thread_num()); 
		}
		
 		printf("Soy el thread %d, fuera de los singles\n",omp_get_thread_num()); 
        
	}//fin parallel

	return(0);
}
