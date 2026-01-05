#include<stdio.h> 

int factorial(int No)
{
    static int ifact = 1;

    if(No > 1)
    {
        ifact = ifact * No;
        factorial(No-1);
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

