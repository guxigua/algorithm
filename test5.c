//把一个数组建成最大堆

void MAX_HEAPIFY(int *arr, int i, int size)
{
	int L	=	2*i;	
	int R	=	2*i+1;
	int largest;
	int temp;
	if( L <= size && arr[L-1] > arr[i-1]) largest = L;
	else largest = i;

	if(R <= size && arr[R-1] > arr[largest-1] ) largest = R;
	
	if (largest != i)
	{
		temp = arr[i-1];
		arr[i-1] = arr[largest-1];
		arr[largest-1] = temp;
		MAX_HEAPIFY(arr, largest, size);
	}
}
void build_max_heap(int *arr, int size)
{
	int  i;
	for(i = size/2; i >= 1; i--)
	MAX_HEAPIFY(arr, i, size);
}
int main()
{
	int arr[10]={91,12,13,44,45,6,87,8,89,90};
	build_max_heap(arr, 10);
	return 0;
}
