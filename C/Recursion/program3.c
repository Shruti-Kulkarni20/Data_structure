#include<stdio.h>

void Display()
{
    int i = 0;
    printf("jay Ganesh...:%d\n",i);

    i++;

    Display();
}
int main()
{
    Display();

    return 0;
}