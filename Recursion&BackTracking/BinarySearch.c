#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool binarySearch(int arr[], int target, int start, int end)
{
    if (start > end)
    {
        return false;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == target)
    {
        return true;
    }
    else if (arr[mid] < target)
    {
        return binarySearch(arr, target, mid + 1, end);
    }
    else
    {
        return binarySearch(arr, target, start, mid - 1);
    }
}

int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int target=9;
    int size=sizeof(arr)/sizeof(arr[0]);
    bool result=binarySearch(arr,target,0,size-1);

    if(result)
    {
        printf("Found");
    }
    else
    {
        printf("Not Found");
    }
    return 0;
}