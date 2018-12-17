/*
Crear 3 secciones, cada seccion realiza una tarea e imprimir el hilo que la realiza

section 1
	printf("Task A: %d\n");

section 2
	printf("Task B: %d\n");
	
section 3
	printf("Task C: %d\n");	
	
*/

#include "stdio.h" 
#include <omp.h>

int main(int argc, char *argv[])
{
/*
	#pragma omp parallel
	#pragma omp sections
*/
	#pragma omp parallel sections
	{
		 #pragma omp section
		{
			 printf("Task A: thread_num %d\n", omp_get_thread_num());
		}	
		 #pragma omp section
			 printf("Task B: thread_num %d\n", omp_get_thread_num());
		
		 #pragma omp section
		 	printf("Task C: thread_num %d\n", omp_get_thread_num());
	}
	
	return(0);
}
