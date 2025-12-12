#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int sumOfArray(int arr[], int size, int index)
{
    if (index >= size)
    {
        return 0;
    }
    else
    {
        return arr[index] + sumOfArray(arr, size, index + 1);
    }
    
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("The sum of the array is: %d", sumOfArray(arr, size, 0));
    return 0;
}