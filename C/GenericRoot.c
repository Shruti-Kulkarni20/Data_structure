//Generic Root or Digital Root

#include<stdio.h>

//Input : 9875
//Output : 9+8+7+5 = 29 = 2+9 = 11 = 1+1 = 2

//INput : 21
//output : 3

//input:7
//input:7

int GenericRoot(int iNo)
{
    int iSum = 0;
    int iDigit = 0;

    iSum = iNo;

    while (iSum > 9)
    {
        iNo = iSum;

        iSum = 0;

        while (iNo != 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + iDigit;
            iNo = iNo/10;
        }
        
    }
    
    return iSum; 
}

int main()
{
    int iValue = 0;
    int iRet = 0;

    printf("Enter Number : \n");
    scanf("%d",&iValue);

    iRet = GenericRoot(iValue);

    printf("Generic root of %d is %d\n");

    return 0;
}