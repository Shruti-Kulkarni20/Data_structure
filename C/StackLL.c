//Stack implementation by using linked list 

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}NODE,*PNODE,**PPNODE;

void push(PPNODE first,int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }
}

void pop(PPNODE first)
{
    if(*first == NULL)
    {
       return;
    }
    else if ((*first)->next == NULL)
    {
        free(*first);
        *first= NULL;
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
    while(first != NULL)
    {
        printf("| %d |->",first->data);
        first = first->next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    push(&head,111);
    push(&head,101);
    push(&head,51);
    push(&head,21);
    push(&head,11);
    

    Display(head);

    iRet = Count(head);
    printf("Number of elements in stack are : %d \n",iRet);
    
    pop(&head);
    pop(&head);

    Display(head);

    iRet = Count(head);
    printf("Number of elements in stack are : %d \n",iRet);

    return 0;
}