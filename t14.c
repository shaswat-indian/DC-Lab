#include<stdio.h>
#include<mpi.h>
#include<string.h>
#include<math.h>

double dx_arctan(double x)
{
	return 1/(1+(x*x));
}

int main(int argc, char* argv[])
{
	int id,np,n=100000,namesize,i;
	char pname[100],details[100];

	double pi1=3.141592653589793238462643;
	double start,end,h,sum,temp,pi2;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&np);
	MPI_Comm_rank(MPI_COMM_WORLD,&id);
	MPI_Get_processor_name(pname,&namesize);


	printf("Process %d of %d running on %s\n",id,np,pname);
	fflush(0);
	MPI_Barrier(MPI_COMM_WORLD);

	if(id==0)
	{
		start=MPI_Wtime();
	}
	MPI_Bcast(&n,1,MPI_INT,0,MPI_COMM_WORLD);
	h=1.0/n;
	sum=0.0;
	for(i=id+0.5;i<n;i+=np)
		sum+=dx_arctan(i*h);

	temp=4.0*sum*h;
	MPI_Reduce(&temp,&pi2,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
	if(id==0)
	{
		end=MPI_Wtime();
		printf("\nExpected Value of PI=%.16f\n",pi1);
		printf("Calculated Value of PI=%.16f\n",pi2);
		printf("Error=%.16f\n",fabs(pi1-pi2));
		printf("Total time taken=%f\n",(end-start));
	}

	MPI_Finalize();
	return 0;
}
