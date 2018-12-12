#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

void main()
{
	int n=100000000,i,k,*arr;
	double t1,t2;

	arr=(int *)malloc(sizeof(int)*(n+1));

	for(i=0;i<=n;i++)
		arr[i]=1;

	k=2;

	t1=omp_get_wtime();

	#pragma omp parallel firstprivate(k) private(i)
	while(k*k<=n)
	{
		#pragma omp for
		for(i=k*k;i<=n;i+=k)
			arr[i]=0;

		//int f=0;
		for(i=k+1;i<=n;i++)
		{
			if(arr[i])
			{
				k=i;
				break;
			}
		}
	}

	t2=omp_get_wtime();

	printf("\nTime taken=%.2f\n",t2-t1);

	int count=0;
	for(i=2;i<=n;i++)
		if(arr[i])
			count++;

	printf("Total Primes between 1 to %d = %d\n",n,count);
	
	
	
}
