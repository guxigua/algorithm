#include <stdio.h>
int main()
{
    int i, j, temp;
    int arr[5] = {5,4,3,2,1};
    for(i = 0; i < 4; i++)
    {
        for(j = 5-1; j > i; j--)
        {
            if(arr[j] < arr[j-1])
            {
                temp   = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
    //for(i = 0; i < 5; i++)   printf("%d ", arr[i]);  输出验证排序的正确性
}
