//search

#include<iostream>
using namespace std;

class ArrayX
{
    public:
      int *Arr;
      int iSize;

      ArrayX(int no)
      {
        iSize = no;
        Arr = new int[iSize];
      }

      ~ArrayX()
      {
        delete [] Arr;
      }
      void Accept()
      {
        cout<<"Enter "<<iSize<<" elements : \n";

        int i = 0;

        for(i = 0; i < iSize;i++)
        {
            cin>>Arr[i];
        }
      }

      void Display()
      {
        cout<<"Elements of the array are : \n";

        int i = 0;

        for(i = 0; i< iSize;i++)
        {
            cout<<Arr[i]<<"\t";
        }
        cout<<"\n";
      }

      bool LinearSearch(int no)
      {
         int i = 0;
         bool bFlag = false;

         for(i = 0; i < iSize; i++)
         {
            if(Arr[i] == no)
            {
                bFlag = true;
                break;
            }
         }

         return bFlag;
      }

      bool BidirectionalSearch(int no)
      {
        int istart =  0;
        int iEnd = 0;

        bool bFlag = false;

        for(istart = 0,iEnd = iSize - 1; istart <= iEnd;istart++,iEnd--)
        {
            if(Arr[istart] == no || Arr[iEnd] == no)
            {
                bFlag = true;
                break;
            }
        }
        return bFlag;
      }
};

int main()
{
    int ilength = 0;

    cout<<"Enter the size of array : \n";
    cin>>ilength;

    ArrayX *aobj = new ArrayX(ilength);

    bool bRet = false;

    aobj->Accept();

    aobj->Display();

    bRet = aobj->BidirectionalSearch(30);

    if(bRet == true)
    {
        cout<<"Element is present\n";
    }
    else
    {
        cout<<"Element is not present\n";
    }

    return 0;
}