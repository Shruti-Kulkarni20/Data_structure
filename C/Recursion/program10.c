#include<stdio.h>

int factorial(int No)
{
    int i = 1;
    int ifact = 1;

    while (i <= No)
    {
        ifact = ifact * i;
        i++;
    }
    return ifact;
}

int main()
{
    int iRet = 0;
    int iValue = 5;

    iRet = factorial(iValue);

    printf("factorial is : %d\n",iRet);

    return 0;
}