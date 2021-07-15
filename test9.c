int func(int key, int *arr, int start, int end)
{
        if(key < arr[(end + start) / 2 - 1])
                return func(key, arr, start, (end + start) / 2 - 1);
        else if(key > arr[(end + start) / 2 - 1])
                return func(key, arr, (end + start) / 2 + 1, end);
        else
                return (end + start) / 2 - 1;
}
