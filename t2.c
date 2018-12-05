#include<omp.h>
#include<stdio.h>


void A(int *a)
{
	printf("a++\n");
	(*a)++;
}

void B(int *a)
{
	printf("a--\n");
	(*a)--;
}


void f(int *a)
{
	#pragma omp critical
	printf("This is thread %d of %d\n",omp_get_thread_num(),omp_get_num_threads());
	A(a);

	sleep(5);

	#pragma omp critical
	printf("This is thread %d of %d\n",omp_get_thread_num(),omp_get_num_threads());
	B(a);

}

void main()
{
	int i,a=0;

	#pragma omp parallel for
	for(i=0;i<4;i++)
	{
		printf("Thread no. %d triggered\n",omp_get_thread_num());
		f(&a);
	}
}
