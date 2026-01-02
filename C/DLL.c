//Doubly Linear Linked List

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}NODE,*PNODE,**PPNODE;

void Display(PNODE first)
{
    printf("\nNULL <=");
    while(first != NULL)
    {  
       printf("| %d |=>",first->data);
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
void insertFirst(PPNODE first,int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn;
        *first = newn;
        newn->prev = NULL; 
    }
}

void insertLast(PPNODE first,int no)
{ 
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
        newn->next = NULL;
    }
}

void insertAtPos(PPNODE first,int no,int pos)
{
    int iCount = 0, i = 0;

    iCount= Count(*first);

    if(pos < 1|| pos > iCount+1)
    {
        printf("Invalid position");
        return;
    }

    if(pos == 1)
    {
        insertFirst(first,no);
    }
    else if(pos == iCount)
    {
        insertLast(first,no);
    }
    else
    {
        PNODE temp = NULL;
        PNODE newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = *first;

        for(i = 1;i < pos-1;i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
}

void deleteFirst(PPNODE first)
{
    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        *first = (*first)->next;
        free((*first)->prev);
        (*first)->prev = NULL;
    }
}

void deleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        while (temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        free(temp->next);
        temp->next = NULL;
        
    }
}

void deleteAtPos(PPNODE first,int pos)
{
    PNODE temp = NULL;
    PNODE target = NULL;
    int iCount = 0, i = 0;

    iCount = Count(*first);

    if(pos < 1 || pos > iCount)
    {
        printf("Invalid Position");
        return;
    }

    if(pos == 1)
    {
        deleteFirst(first);
    }
    else if(pos == iCount)
    {
        deleteLast(first);
    }
    else
    {
        temp = *first;

        for(i = 1;i < pos -1 ; i++)
        {
            temp = temp ->next;
        }

        target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;
        free(target);
        
    }
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    insertFirst(&head,51);
    insertFirst(&head,21);
    insertFirst(&head,11);

    insertLast(&head,101);
    insertLast(&head,111);
    insertLast(&head,121);

    Display(head);

    iRet = Count(head);
    printf("Number of elements in linked list are : %d",iRet);

    insertAtPos(&head,105,5);

    Display(head);

    iRet = Count(head);
    printf("Number of elements in linked list are : %d",iRet);

    deleteFirst(&head);

    Display(head);

    iRet = Count(head);
    printf("Number of elements in linked list are : %d",iRet);

    deleteLast(&head);

    Display(head);

    iRet = Count(head);
    printf("Number of elements in linked list are : %d",iRet);

    deleteAtPos(&head,4);

    Display(head);

    iRet = Count(head);
    printf("Number of elements in linked list are : %d",iRet);

    return 0;
}