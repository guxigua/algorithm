/*
插入排序，复杂度O(n^2);
*/

#include <stdio.h>
int main()
{
    int arr[10] = {10,9,8,7,6,10,100,299,1,0};
    int i, j, key;
    
    for(j = 0; j < 10; j++)
    {
        key =   arr[j];
        i   =   j -1;
        while( i >= 0 && arr[i] > key)
        {
            arr[i+1]    =   arr[i];
            i--;
        }
        arr[i+1]    =   key;
    }
    //for(i = 0; i < 10; i++) printf("%d  ",arr[i]);    输出语句，验证算法是否正确
    return 0;
}
