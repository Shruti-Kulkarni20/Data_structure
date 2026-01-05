#include<stdio.h>

int factirial()
{
    static int i = 1;
    static int iFact = 1;

    if(i <=5)
    {
        iFact = iFact * i;
        i++;
        factirial();
    }
    return iFact;
}
int main()
{
    int iRet = 0;

    iRet = factirial();

    printf("factorial is : %d\n",iRet);

    return 0;
}
