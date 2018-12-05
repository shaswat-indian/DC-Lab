#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

void main()
{
	int a[100],i,maxSerial,maxParallel;
	omp_lock_t mylock;
	srand(500);
	for(i=0;i<100;i++)
		a[i]=rand();

	maxSerial=a[0];
	maxParallel=a[0];

	omp_init_lock(&mylock);

	#pragma omp parallel for
	for(i=0;i<100;i++)
	{
		if(a[i]>maxParallel)
		{
			omp_set_lock(&mylock);
			if(a[i]>maxParallel)
				maxParallel=a[i];
			omp_unset_lock(&mylock);
		}
	}
	
	omp_destroy_lock(&mylock);

	for(i=0;i<100;i++)
	{
		if(a[i]>maxSerial)
			maxSerial=a[i];
	}
	
	printf("Maximum Parallel Value=%d\nMaximum Serial Value=%d\n",maxParallel,maxSerial);

	if(maxSerial==maxParallel)
		printf("Equal Serial and Parallel value\n");
	else
		printf("Unequal Serial and Parallel value\n");
	


}
