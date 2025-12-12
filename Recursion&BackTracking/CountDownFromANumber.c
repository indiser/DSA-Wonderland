#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int countDown(int n)
{
    if (n==0)
    {
        return 0;
    }
    else
    {
        printf("The number is:%d\n",n);
        return countDown(n-1);
    }
    
}
int main()
{
    int n=5;
    countDown(n);
    return 0;
}