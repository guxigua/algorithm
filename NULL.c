#include <stdio.h>
int main()
{
	int arr[6] = {31, 41, 59, 26, 41, 58};
	int i, j, key;

	for(j = 1; j < 6; j++)
	{
		key	=	arr[j];
		i	=	j - 1;
		while( i >= 0 && arr[i] < key)
		{
			arr[i+1] = arr[i];
			i--;
		}
		arr[i+1] = key;
	}
	for(i = 0; i < 6; i++)
		printf("%d ", arr[i]);
	return 0;

}
