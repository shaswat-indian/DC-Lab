#include<stdio.h>
#include<omp.h>

void main()
{
	int a[50],b[50],c[50],d[50],i,n,id;


	for(i=0;i<50;i++)
	{
		a[i]=i;
		b[i]=i;
		c[i]=d[i]=0;
	}

	#pragma omp parallel shared(a,b,c,d,n) private(i,id)
	{
	
		id=omp_get_thread_num();
		printf("Thread number %d is starting\n",id);

		if(id==0)
		{
			n=omp_get_num_threads();
			printf("Total number of threads=%d\n",n);
		}

		#pragma omp sections nowait
		{

			#pragma omp section
			{
				printf("Thread %d doing Addition\n",id);
				for(i=0;i<50;i++)
				{
					c[i]=a[i]+b[i];
					printf("Thread %d: c[%d]=%d\n",id,i,c[i]);			
				}
			}	
			
			#pragma omp section
			{
				printf("Thread %d doing Multiplication\n",id);
				for(i=0;i<50;i++)
				{
					d[i]=a[i]*b[i];
					printf("Thread %d: d[%d]=%d\n",id,i,d[i]);			
				}
			}		

		}		

	}


}
