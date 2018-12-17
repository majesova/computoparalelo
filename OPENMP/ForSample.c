/*
Imprime un for y asigna 1 instrucción a cada hilo
printf("Task [%d]: %d\n");
*/
#include "stdio.h"
#include <omp.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    const int N = 8;
    int i, a[N];
    int suma=0;
    //AGREGAR PRAGMA PARALLEL
      #pragma omp parallel num_threads(8) 
      {
            //AGREGAR FOR
            #pragma omp for  
            for (i = 0; i < 80; i++){
                a[i] = 2 * i;

                printf("Task [%d]: thread: %d\n", i+1,omp_get_thread_num());
            }
        }
	
	return(0);
}
