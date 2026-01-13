//Harshad Number /Niven Number

#include<stdio.h>
#include<stdbool.h>

//Input : 18
//Output: 18 -> 1 + 8 -> 9
//        (18 % 9) == 0
//        true

bool CheckNiven(int iNo)
{
    int iDigit = 0,iSum = 0,iTemp = iNo;

    while (iNo != 0)
    {
        iDigit = iNo % 10;
        iSum = iSum + iDigit;
        iNo = iNo /10;
    }

    return(iTemp % iSum == 0);
    
}
int main()
{
    int iValue = 0;
    bool bRet = false;

    printf("Enter Number :\n");
    scanf("%d",&iValue);

    bRet = CheckNiven(iValue);

    if(bRet == true)
    {
        printf("%d is niven number\n",iValue);
    }
    else
    {
        printf("%d is not niven number\n",iValue);
    }

    return 0;
}