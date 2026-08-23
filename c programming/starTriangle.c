#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>



int main()
{
    int rows=5;

    for (int i = 0; i < rows; i++)
    {
        // for (int spaces = 0; spaces < rows-i; spaces++)
        // {
        //     printf("  ");
        // }
        
        for (int j = 0; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}