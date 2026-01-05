#include<stdio.h>

int factorial(int No)
{
    static int i = 1;
    static int ifact = 1;

    if(i <= No)
    {
        ifact = ifact * i;
        i++;
        factorial(No);
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

//avoid use of iteration and recursion toghether