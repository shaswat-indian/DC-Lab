#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

long long factorial(int n)
{
	if(n==0||n==1)
		return 1;
	long long fact=1;
	for(int i=2;i<=n;i++)
		fact*=i;

	return fact;
}


void main()
{
	int i,n=10;
	long long *x;

	x=(long long *)malloc(sizeof(long long)*(n+1));

	for(i=0;i<=n;i++)
	{
		x[i]=factorial(i);
	}



	#pragma omp parallel for firstprivate(x)
	for(i=1;i<=n;i++)
		x[i]=i*x[i-1];

	for(i=1;i<=n;i++)
		printf("Factorial(%d)=%lldx[%d]=%lld\n",i,x[i-1],i,x[i]);	



	

}
