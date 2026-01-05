#include<stdio.h>

void Display()
{
    static int i = 0;
    if (i <= 5)
    {
        printf("Jay Ganesh...: %d \n",i);
        i++;
        Display();
    }
    
}
int main()
{
    Display();

    return 0;
}
