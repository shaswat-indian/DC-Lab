#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

void main()
{
	int rows,cols,**matrix, *vector,i,j,*serOP,*parOP;
	printf("\nEnter Number of Rows: ");
	scanf("%d",&rows);
	printf("\nEnter Number of Columns: ");
	scanf("%d",&cols);

	matrix=(int **)malloc(sizeof(int)*rows);
	for(i=0;i<rows;i++)
	{
		matrix[i]=(int *)malloc(sizeof(int)*cols);
		for(j=0;j<cols;j++)
			matrix[i][j]=i+j;
	}

	vector=(int *)malloc(sizeof(int)*cols);
	for(i=0;i<cols;i++)
		vector[i]=i;

	parOP=(int *)malloc(sizeof(int)*rows);
	serOP=(int *)malloc(sizeof(int)*rows);

	for(i=0;i<rows;i++)
	{
		parOP[i]=0;
		serOP[i]=0;
	}

	printf("\nInput Matrix is:-\n");
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
			printf("%d\t",matrix[i][j]);
		printf("\n");
	}


	printf("\nInput Vector is:-\n");
	for(i=0;i<cols;i++)
		printf("%d\n",vector[i]);

	#pragma omp parallel for private(j)
	for(i=0;i<rows;i++)
		for(j=0;j<cols;j++)
			parOP[i]=parOP[i]+matrix[i][j]*vector[j];

	
	for(i=0;i<rows;i++)
		for(j=0;j<cols;j++)
			serOP[i]=serOP[i]+matrix[i][j]*vector[j];

	printf("\nParallel Output is:-\n");
	for(i=0;i<rows;i++)
	{
		printf("%d\n",parOP[i]);
	}

	printf("\nSerial Output is:-\n");
	for(i=0;i<rows;i++)
	{
		printf("%d\n",parOP[i]);
	}

	for(i=0;i<rows;i++)
		if(serOP[i]!=parOP[i])
		{
			printf("\nSerial and Parallel product Unequal!\n");
			exit(0);
		}

	printf("\nSerial and Parallel product Equal!\n");

	free(matrix);
	free(vector);
	free(serOP);
	free(parOP);
	

}
