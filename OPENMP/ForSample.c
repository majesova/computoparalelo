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
    
      #pragma omp parallel num_threads(8) //ärea que contiene el código paralelo
      {
            //for que se va ejecutar con los hilos especificados arriba
            //Igual se puede poner en línea el parallel con el for
            #pragma omp for  
            for (i = 0; i < 16; i++){
                a[i] = 2 * i;
                //Se imprime valores del for con el hilo que lo ejecuta
                printf("Task [%d]: thread: %d\n", i+1,omp_get_thread_num());
            }
        }
	
	return(0);
}
