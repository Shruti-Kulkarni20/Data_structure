#include<stdio.h>
#include<string.h>

void reverseString(char s[], int sSize) 
{
    if(sSize == 0)
    {
        return;
    }
    else
    {
        printf("%c",s[sSize - 1]);
        
        reverseString( s,sSize - 1);
    }
    
}

int main()
{
    char Arr[] = {'h','e','l','l','o'};
    int iSize = 6;
 
    reverseString(Arr,iSize);
    
    return 0;
}