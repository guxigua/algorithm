int PARTITION(int *arr, int p, int r)     //把子数组原址排序，并返回中间值q
{
	int x	=	*(arr+r);
	int i	=	p-1;
	int j	=	p;
	int temp;
	for(; j <= r-1; j++)
	{
		if (arr[j] <= x)
		{
			++i;
			temp	=	arr[i];
			arr[i]  =	arr[j];
			arr[j]  =	temp;
		}
	}
	temp		=	arr[i+1];
	arr[i+1]	=	arr[r];
	arr[r]		=	temp;
	return i+1;
}
void QUICKSORT(int *arr, int p, int r)
{
	int q;
	if (p < r)
	{
	q	=	PARTITION(arr, p, r);
	QUICKSORT(arr, p, q-1);
	QUICKSORT(arr, q+1, r);
	}
}

int main()
{
	int arr[8] = {18,21,13,4,58,6,47,8};
	QUICKSORT(arr, 0, 7);
}
