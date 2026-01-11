//peterson No or Strong No or krushnmaurti No
// summation of all fctorial is equal to the number

#include<stdio.h>
#include<stdbool.h>

//Input : 145
//Output: 5! + 4! + 1!
//        120 + 24 + 1
//        145
//        true

bool CheckStrong(int iNo)
{
    int iDigit = 0;
    int itemp = iNo;
    int isum = 0;
    int iFact = 1,i = 0;

    while (iNo != 0)
    {
        iDigit = iNo % 10;

        iFact = 1;

        for(i = 1;i <= iDigit;i++)
        {
            iFact = iFact * i;
        }

        isum = isum + iFact;
        iNo = iNo / 10;
    }

    if(isum == itemp)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int main()
{
   int iValue = 0;
   int bRet = false;

   printf("Enter Number : \n");
   scanf("%d",&iValue);

   bRet = CheckStrong(iValue);

   if(bRet == true)
   {
     printf("%d is strong number\n",iValue);
   }
   else
   {
     printf("%d is not a strong number",iValue);
   }

    return 0;
}