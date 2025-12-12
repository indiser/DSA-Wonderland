#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Mathematical Solution:

//s=n*(n+1)/2

int sum(int n)
{
    if(n==1)
    {
        return 1;
    }
    else
    {
        return n+sum(n-1);
    }
}


int main()
{
    int n=5;
    printf("The sum of first %d numbers is: %d",n,sum(n));
    return 0;
}