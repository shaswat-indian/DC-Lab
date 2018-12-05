#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

void main()
{
	int a[100],i,maxSerial,maxParallel;
	srand(500);
	for(i=0;i<100;i++)
		a[i]=rand();

	maxSerial=a[0];
	maxParallel=a[0];

	#pragma omp parallel for
	for(i=0;i<100;i++)
	{
		if(a[i]>maxParallel)
		{
			#pragma omp critical
			if(a[i]>maxParallel)
				maxParallel=a[i];
		}
	}

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
