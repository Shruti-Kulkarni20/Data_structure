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

     void BubbleSortEfficient()
     {
        int i = 0,j = 0,temp = 0;
        bool bFlag = true;

        if(Sorted == true)
        {
            return;
        }

        for(i = 0;(i < isize && bFlag == true);i++)
        {
            bFlag = false;

            for(j = 0; j < isize-1-i;j++)
            {
                if(Arr[j] > Arr[j + 1])
                {
                    temp = Arr[j];
                    Arr[j] = Arr[j + 1];
                    Arr[j + 1] = temp;

                    bFlag = true;
                }
            }

            cout<<"Data after pass : "<<i + 1<<"\n";

            Display();
        }
     }

     void SelectionSort()
     {
        int i = 0,j = 0,min_index = 0,temp = 0;

        for(i = 0;i <isize - 1;i++)
        {
            min_index = i;

            for(j = i+1;j < isize;j++)
            {
                if(Arr[j] < Arr[min_index])
                {
                    min_index = j;
                }
            }

            if(i != min_index)
            {
                temp = Arr[i];
                Arr[i] = Arr[min_index];
                Arr[min_index] = temp;

            }
        }
     }

     void InsertionSort()
     {
        int i =0, j = 0,selected = 0;

        for(i = 1;i < isize;i++)
        {
            for(j = i -1,selected = Arr[i];(j >= 0) && (Arr[j] > selected);j--)
            {
                Arr[j + 1] = selected;
            }
            Arr[j + 1] = selected;
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

    aobj->SelectionSort();

    cout<<"Data after sorting : \n";

    aobj->Display();
   
    delete aobj;

    return 0;
}