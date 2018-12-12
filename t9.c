#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

void main()
{
	int i;
	#pragma omp parallel private(i)
	{
		int n=omp_get_num_threads();
		int id=omp_get_thread_num();
		int lettersPerThread=26/n;
		int start=65+(id*lettersPerThread);
		int end=65+(id*lettersPerThread)+lettersPerThread;
		for(i=start;i<end;i++)
			printf("%c\t",i);
	}

	printf("\n");
}
