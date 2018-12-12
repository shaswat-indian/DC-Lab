#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

void main()
{
	int *sumOfPowers,n=10,i,j,x[10];
	
	sumOfPowers=(int *)malloc(sizeof(int)*n);
	
	#pragma omp parallel for private(j) lastprivate(x)
	for(i=0;i<n;i++)
	{
		x[0]=1;
		for(j=1;j<4;j++)
			x[j]=(i+1)*x[j-1];

		sumOfPowers[i]=x[0]+x[1]+x[2]+x[3];
	}


	for(i=0;i<n;i++)
	{
		printf("Sum of powers(0,1,2,3) for %d=%d\n",(i+1),sumOfPowers[i]);
	}

	printf("\nCube of last digit=%d\n",x[3]);

}
