#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

bool isPalindrom(char s[],int size, int start,int end)
{
    if (start >= end)
    {
        return true;
    }
    if (s[start] != s[end])
    {
        return false;
    }
    
    return isPalindrom(s, size, start+1, end-1);
    
    
}
int main()
{
    char s[]="car";
    int size=strlen(s);

    bool result=isPalindrom(s,size,0,size-1);

    if(result)
    {
        printf("The string is a palindrom");
    }
    else
    {
        printf("The string is not a palindrom");
    }

    return 0;
}