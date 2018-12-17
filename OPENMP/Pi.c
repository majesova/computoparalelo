/*
Pi
*/

#include "stdio.h" 
#include <omp.h>

//version 1 PI
//para C sin OPENMP
static long num_steps = 100000;
double step;
double start, delta;

int main(int argc, char *argv[])
{
		int numOfThreads = 100;
		for(int j=1; j<numOfThreads; j++){
			int i; 
			double x, pi, sum = 0.0;
			omp_set_num_threads(j);
			sum = 0.0;
			double start = omp_get_wtime();
			
			step = 1.0/(double) num_steps;
			#pragma omp parallel for reduction(+:sum) private(x)
			for (i=1;i<= num_steps; i++){
				x = (i-0.5)*step;
				sum = sum + 4.0/(1.0+x*x);
				//printf("%.16g\n", sum);
			}
			pi = step * sum;
			delta = omp_get_wtime() - start;
			printf("Pi = %.16g tardó %.4g s con %d hilos\n", pi, delta, j);
			//printf("Pi = %g \n",pi);
		}
  return(0);
}