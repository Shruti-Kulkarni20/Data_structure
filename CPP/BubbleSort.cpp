#include<iostream>
using namespace std;

class ArrayX
{
    public:
     int *Arr;
     int isize;
     bool Sorted;

     ArrayX(int no)
     {
        isize = no;
        Arr = new int[isize];
        Sorted = true;
     }

     ~ArrayX()
     {
        delete[]Arr;
     }

     void Accept()
     {
        cout<<"enter"<<isize<<"elemnts : \n";

        int i = 0;

        for(i = 0;i < isize;i++)
        {
            cout<<"enter the element no : "<<i + 1<<"\n";
            cin>>Arr[i];

            if((i > 0) && (Sorted == true))
            {
                if(Arr[i] < Arr[i - 1])
                {
                    Sorted = false;
                }
            }
        }
     }

     void Display()
     {
        cout<<"Elements of the array are : \n";

        int i = 0;

        for(i = 0;i < isize; i++)
        {
            cout<<Arr[i]<<"\t";
        }
        cout<<"\n";
     }

     void BubbleSort()
     {
        int i = 0,j = 0,temp = 0;

        if(Sorted == true)
        {
            return;
        }

        for(i = 0; i < isize ;i++)
        {
            for(j = 0;j < isize -1;j++)
            {
                if(Arr[j] > Arr[j + 1])
                {
                    temp = Arr[j];
                    Arr[j] = Arr[j + 1];
                    Arr[j + 1] = temp;
                }
            }

            cout<<"Data after Pass : "<<i+1<<"\n";

            Display();
        }
     }

};

int main()
{
    int ilength = 0;
    int iValue = 0;

    bool bRet = false;

    cout<<"Enter the size of array : \n";
    cin>>ilength;

    ArrayX *aobj = new ArrayX(ilength);

    aobj->Accept();

    aobj->Display();

    aobj->BubbleSort();

    cout<<"Data after sorting : \n";

    aobj->Display();
   
    delete aobj;

    return 0;
}