#include<stdio.h>

void Display()
{
    static int i = 0;
    printf("jay Ganesh...:%d\n",i);

    i++;

    Display();
}
int main()
{
    Display();

    return 0;
}

//64642 stack frame are created
//Stack overflow