#include <stdio.h>
int main()
{
	int arr[5] = {5,4,3,2,1};
	int i, j, key;
	for(j = 0; j < 4; j++)
	{
		key = arr[j];
		i = j + 1;
		while( i < 5 && arr[i] < key ) 
		{
			key = arr[i];
			i++;
		}
		arr[i-1] = arr[j];
		arr[j]   = key;
	}
	//	for(i = 0; i < 5; i++)	printf("%d ", arr[i]);
	return 0;
}
