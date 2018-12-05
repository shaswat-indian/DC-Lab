#include<omp.h>
#include<stdio.h>

void main()
{
	int a[50], b[50], sum=0,i;
	
	for(i=0;i<50;i++)
	{
		a[i]=i;
		b[i]=i;
	}

	#pragma omp parallel for reduction(+:sum)
	for(i=0;i<50;i++)
	{
		sum=sum+a[i]+b[i];
	}

	printf("Sum=%d\n",sum);
}
