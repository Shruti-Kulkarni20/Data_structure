//Magic Number - if recursive sum of its digit is one 

#include<stdio.h>
#include<stdbool.h>

//Input : 19
//Output: 1 + 9 -> 10 -> 1 + 0 -> 1
//        true


int CheckMagic(int iNo)
{
    int iSum = 0;
    int idigit = 0;

    iSum = iNo;

    while (iSum > 9)
    {
        iNo = iSum;

        iSum = 0;

        while (iNo != 0)
        {
           idigit = iNo % 10;
           iSum = iSum + idigit;
           iNo = iNo/10;
        }
        
    }

    return iSum == 1;
    
}
int main()
{
    int iValue = 0;
    bool bRet = false;

    printf("enter a number : \n");
    scanf("%d",&iValue);

    bRet = CheckMagic(iValue);

    if(bRet)
    {
        printf("%d is magic number\n",iValue);
    }
    else
    {
         printf("%d is not magic number\n",iValue);
    }
    return 0;
}