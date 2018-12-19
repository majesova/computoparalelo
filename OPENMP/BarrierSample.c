/*
Imprime por todos los hilos
	printf("Task parallel: %d\n");
	
Imprime por el maestro
	printf("Task master: %d\n");
		
Sincroniza todos los threads del equipo.
	printf("Task Barrier: %d\n");
*/

#include "stdio.h" 
#include <omp.h>
/*
• Sincroniza todos los threads del equipo. 
Cuando un thread alcanza una directiva barrier, 
esperará en ese punto hasta que todos los threads del equipo lleguen hasta esta directiva.
• Cuando todos los threads han alcanzado dicho punto, 
continúan con la ejecución en paralelo del código que sigue a la barrera.
*/
int main(int argc, char *argv[])
{
	
	#pragma omp parallel num_threads(10) 
	{
		printf("Task parallel: %d\n", omp_get_thread_num());
		//Una instrucción ejecutada en el bloque maestro
		#pragma omp master
			printf("Task master: %d\n", omp_get_thread_num());
		//Esto queda a la espera que todos los threads terminen su ejecución
		#pragma omp barrier
			printf("Task Barrier: %d\n", omp_get_thread_num());
	}
	
	return(0);
}
