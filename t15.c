#include<mpi.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char*argv[])
{

	int n,id,plen,i;
	char pname[100],details[100];
	
	MPI_Init(&argc, &argv);
	MPI_Status status;
	MPI_Comm_size(MPI_COMM_WORLD,&n);
	MPI_Comm_rank(MPI_COMM_WORLD,&id);
	MPI_Get_processor_name(pname,&plen);

	sprintf(details,"Processsor rank %d of %d running on %s\n",id,n,pname);

	if(id==0)
	{
		printf("%s",details);
		for(i=1;i<n;i++)
		{
			MPI_Recv(details,sizeof(details),MPI_BYTE,i,1,MPI_COMM_WORLD,&status);
			printf("%s",details);
		}	
	}
	else
	{
		MPI_Send(details,strlen(details),MPI_BYTE,0,1,MPI_COMM_WORLD);
	}
	if(id==0)
	{
		printf("Bye World!\n");
	}
	
	MPI_Finalize();

	return 0;
}
