#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARR_SIZE 8

void COUNTING_SORT(int *arr, int *brr, int k)
{
	int *crr	=	(int*)malloc((k+1) * sizeof(int));
	int i;
	for(i =0; i < k+1; i++)
	*(crr+i)=0;
	for(i=0; i < ARR_SIZE; i++)
	{
		(*(crr+*(arr+i)))++;
	}

	for(i=1; i < k+1; i++)
	{
		*(crr+i)	+=	*(crr+i-1);
	}
	for(i=ARR_SIZE-1; i >= 0; i--)
	{
		*(brr+*(crr+*(arr+i))-1)	=	*(arr+i);
		*(crr+*(arr+i))			=	*(crr+*(arr+i))-1;
	}
}
int main()
{
	int arr[ARR_SIZE]	=	{2,5,3,0,2,3,0,3};
	int brr[ARR_SIZE]={};
	COUNTING_SORT(arr, brr, 5);
	return 0;
}
