/*
Cada Hilo suma a total el valor de su id+1
printf("Suma local %d\n");

Se imprime 1 vez el valor de la suma total
printf("reduction %d\n");
*/

#include "stdio.h" 
#include <omp.h>

int main(int argc, char *argv[])
{

	int t=0;

	/*Crea la variable t privada para cada Thread
	al finalizar combina los resultados previos*/
	#pragma omp parallel reduction(+:t)
	{
		
		 t = omp_get_thread_num() + 1;
		 printf("Suma local %d\n", t);
	}
	
	printf("reduction %d\n", t);
	return(0);
}
