#include<omp.h>
#include<stdio.h>
#define RA 50
#define CA 50
#define RB 50
#define CB 10

void main()
{
	int a[RA][CA],b[RB][CB],c[RA][CB],i,j,k,id,n,chunk=10;
	
	#pragma omp parallel shared(a,b,c,n,chunk) private(i,j,k,id)
	{
		id=omp_get_thread_num();
		if(id==0)
		{
			n=omp_get_num_threads();
			printf("Total number of threads=%d\n",n);
		}

		#pragma omp for schedule(static,chunk)
		for(i=0;i<RA;i++)
			for(j=0;j<CA;j++)
				a[i][j]=i+j;

		#pragma omp for schedule(static,chunk)
		for(i=0;i<RB;i++)
			for(j=0;j<CB;j++)
				b[i][j]=i*j;

		#pragma omp for schedule(static,chunk)
		for(i=0;i<RA;i++)
			for(j=0;j<CB;j++)
				c[i][j]=0;

		#pragma omp for schedule(static,chunk)
		for(i=0;i<RA;i++)
		{
			printf("Thread %d multiplying row %d\n",id,i);
			for(j=0;j<CB;j++)
				for(k=0;k<CA;k++)
					c[i][j]=c[i][j]+(a[i][k]*b[k][j]);

		}
	}

	printf("\nResult Matrix:-\n");
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
			printf("%d\t",c[i][j]);
		printf("\n");
	}

}
