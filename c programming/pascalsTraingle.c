#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

long long factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n*factorial(n-1);
}

long long binomialCoefficient(int n, int k)
{
    return factorial(n)/ (factorial(k) * factorial(n-k));
}


int main()
{
    int rows;
    printf("Enter The Number of rows:");
    scanf("%d",&rows);

    for (int i = 0; i < rows; i++)
    {
        for (int spaces = 0; spaces < rows - i - 1; spaces++)
        {
            printf("  ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("%4lld",binomialCoefficient(i, j));
        }
        printf("\n");
    }
    
    return 0;
}