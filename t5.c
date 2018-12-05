#include<omp.h>
#include<stdio.h>

void main()
{
	int n,id,proc,maxThread,parThread,dynamic,nested;
	
	#pragma omp parallel private(n,id)
	{
		id=omp_get_thread_num();

		printf("Thread %d starting\n",id);

		if(id==0)
		{
			n=omp_get_num_threads();
			proc=omp_get_num_procs();
			maxThread=omp_get_max_threads();
			parThread=omp_in_parallel();
			dynamic=omp_get_dynamic();
			nested=omp_get_nested();

			printf("Total number of threads=%d\n",n);
			printf("Total number of processes=%d\n",proc);
			printf("Maximum threads=%d\n",maxThread);
			printf("Parallel threads=%d\n",parThread);
			printf("Dynamic threads=%d\n",dynamic);
			printf("Nested threads=%d\n",nested);






		}

	}
}
