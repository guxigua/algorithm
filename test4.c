#define MAX_SIZE 20 
typedef struct Data1
{
	int arr[MAX_SIZE];
	int low;
	int mid;
	int high;
}Data1;

typedef struct  Data2
{
	int low;
	int high;
	int sum;
}Data2;

typedef struct Data3
{
	int arr[MAX_SIZE];
	int low;
	int high;
}Data3;


void assignment(int *arr1, int *arr2,int max)
{
	int i;	
	for(i = 0; i < max; i++)
		arr1[i]	=	arr2[i];
}
Data2  max_heapify(Data1 D1)
{
	int left_sum	=	D1.arr[D1.mid-1] -	1;
	int right_sum	=	D1.arr[D1.mid] - 1;
	int sum		=	0;
	int i		=	0;
	int max_left,max_right;
	for(i = D1.mid; i >= D1.low; i--)
	{
		sum	+=	D1.arr[i-1];
		if(sum > left_sum)
		{
			left_sum	=	sum;
			max_left	=	i;
		}
	}
	for(sum = 0, i = D1.mid+1; i <= D1.high; i++)
	{
		sum	+=	D1.arr[i-1];
		if(sum > right_sum)
		{
			right_sum	=	sum;
			max_right	=	i;
		}
	}
	Data2 temp;
	temp.low	=	max_left;
	temp.high	=	max_right;
	temp.sum	=	left_sum+right_sum;
	return temp;
}

Data2 FindMaxSubarray(Data3 d3)
{
	int mid;
	if(d3.high	==	d3.low)
	{
		Data2	temp={.low=d3.low, .high=d3.high, .sum=d3.arr[d3.low-1]};
		return temp;
	}
	else
	{
		mid		=	(d3.low+d3.high)/2;
		Data3 d30;
		assignment(d30.arr, d3.arr,MAX_SIZE);
		d30.low = d3.low;
		d30.high = mid;
		Data2 d2_left	=	FindMaxSubarray(d30); 

		d30.low = mid+1;
		d30.high=d3.high;
		Data2 d2_right	=	FindMaxSubarray(d30);

		Data1 d10;
		assignment(d10.arr,d3.arr,MAX_SIZE);
		d10.low = d3.low;
		d10.mid = mid;
		d10.high= d3.high;
		Data2 d2_cross = max_heapify(d10);

		if(d2_left.sum >= d2_right.sum && d2_left.sum >= d2_cross.sum)
			return d2_left;
		else if(d2_right.sum >= d2_left.sum && d2_right.sum >= d2_cross.sum)
			return d2_right;
		else
			return d2_cross;

	}
}

int main()
{
	Data3 d1;
	int array[MAX_SIZE]	=	{-1,-2,-3,-4,-5,-6,-27,-8,9,-1000,-11,129,11,-14,-15,-16,-17,-18,-19,10000};
	int i;
	assignment(d1.arr,array,MAX_SIZE);
	d1.low=1;
	d1.high=20;
	Data2 test = FindMaxSubarray(d1);
	return 0;
}
//
