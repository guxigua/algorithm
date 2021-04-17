void func1(int *A, int p, int q, int r)      //排序函数
{
	int i, j, k;

	int n1 = q - p + 1;   //L长度
	int n2 = r - q;   //R长度
	int L[n1], R[n2];
	for(i = 0; i < n1; i++)  L[i] = *(A+p+i-1);
	for(i = 0; i < n2; i++)  R[i] = *(A+q+i);
	
	i = 0, j = 0;
	for(k = p-1; k < r; k++)
	{
		if(  i < n1 && (j == n2 || L[i] <= R[j]) )
		{
			*(A+k) = L[i];
			i++;
		}
		else
		{
			*(A+k) = R[j];
			j++;
		}
	}
}
void func2(int *arr, int p, int r)
{
	int q;
	if(p < r)
	{
		q = (p+r)/2;
		func2(arr,p,q);
		func2(arr,q+1,r);
		func1(arr,p,q,r);

	}

}

int main()
{
	int A[20] = {10,9,81,7,63,5,4,31,2,1,0,12,2,33,4,105,6,97,88,9}; 
	func2(A,1,20);

	return 0;
}
