int main()
{

	int i, j, k;

	int A[20] = {1,1,1,1,1,1,1,1,1,/*前面的1是无关于排序的*/     0,2,4,6,8,10,/*L数组*/   1,3,5,7,9/*R数组*/};
	int p = 9;  //为L数组的开始下标
	int q = 14; //L数组的结束下标
	int r = 20; //数组长度

	int n1 = q - p + 1;   //L长度
	int n2 = r - q - 1;   //R长度
	int L[n1], R[n2];
	for(i = 0; i < n1; i++)  L[i] = A[p+i];
	for(i = 0; i < n2; i++)  R[i] = A[q+i+1];
	
	i = 0, j = 0;
	for(k = p; k < r; k++)
	{
		if( L[i] <= R[j]) 
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
	}
	return 0;
}
