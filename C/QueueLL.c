//Queue implementation by using linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
   int data;
   struct node *next;
}NODE,*PNODE,**PPNODE;

void enqueue(PPNODE first,int no)
{ 
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if (*first == NULL)
    {
       *first = newn;   
    }
    else
    {
        PNODE temp = NULL;

        temp = *first;

        while (temp->next != NULL)
        {
            temp = temp ->next;
        }

        temp->next = newn;
    }
    
}
void dequeue(PPNODE first)
{
    if(*first == NULL)
    {
        return;
    }
    else if((*first)-> next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        PNODE temp = NULL;
        temp = *first;

        *first = (*first)->next;
        free(temp);
    }

}

void Display(PNODE first)
{
    while (first != NULL)
    {
        printf("| %d |<-",first->data);
        first = first -> next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;
    while (first != NULL)
    {
        iCount++;
        first = first -> next;
    }
    return iCount;
}


int main()
{
    PNODE head = NULL;
    int iRet = 0;

    enqueue(&head,11);
    enqueue(&head,21);
    enqueue(&head,51);
    enqueue(&head,101);
    enqueue(&head,111);
    enqueue(&head,121);

    Display(head);

    iRet = Count(head);
    printf("Number of elements present in queue are : %d\n",iRet);

    dequeue(&head);
    dequeue(&head);

    Display(head);

    iRet = Count(head);
    printf("Number of elements present in queue are : %d\n",iRet);


    return 0;
}