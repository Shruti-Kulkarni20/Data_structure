//Singly Circular Linked List

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Display(PNODE first,PNODE last)
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    do
    {
        printf("| %d | ->",first->data);
        first = first->next;
    } while (first != last->next);
    
    printf("\n");
}

int Count(PNODE first,PNODE last)
{
    int iCount = 0;

    if(first == NULL && last == NULL)
    {
        return -1;
    }
    do
    {
        iCount++;
        first = first->next;
    } while (first != last->next);
    
    return iCount;
}
void insertFirst(PPNODE first,PPNODE last,int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last =  newn;
        (*last)->next = *first;
    }
    else
    {
        newn->next = *first;
        *first = newn;
        (*last)->next = *first;
    }
}

void insertLast(PPNODE first,PPNODE last,int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        newn->next = *first;
    }
    else
    {
        (*last)->next = newn;
        *last = newn;
        (*last)->next = *first;
    }

}

void insertAtPos(PPNODE first,PPNODE last,int no,int pos)
{
    int iCount = 0,i = 0;

    iCount = Count(*first,*last);

    if(pos < 1 || pos > iCount+1)
    {
        printf("Invalid Input");
        return;
    }
    if(pos == 1)
    {
        insertFirst (first,last,no);
    }
    else if(pos == 2)
    {
        insertLast(first,last,no);
    }
    else
    {
        PNODE temp = NULL;
        PNODE newn = NULL;

        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;

        temp = *first;

        for(i = 0;i < pos-2;i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

void deleteFirst(PPNODE first,PPNODE last)
{
    if(*first == NULL && *last ==  NULL)
    {
        return;
    }
    else if(*first == *last)
    { 
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        *first = (*first) -> next;
        free((*last)->next);
        (*last)->next = *first;
    }
}

void deleteLast(PPNODE first,PPNODE last)
{
    if(*first == NULL && *last ==  NULL)
    {
        return;
    }
    else if(*first == *last)
    { 
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        PNODE temp = NULL;
        temp = *first;
        while (temp->next != *last)
        {
           temp = temp->next;
        }
        
        free(*last);
        *last = temp;
        (*last)->next = *first; 
    }
}

void deleteAtPos(PPNODE first,PPNODE last,int pos)
{
    int iCount = 0, i= 0;

    iCount = Count(*first,*last);

    if(pos < 1 || pos > iCount)
    {
        printf("Invalid Position");
        return ;
    }

    if(pos == 1)
    {
        deleteFirst(first,last);
    }
    else if(pos == iCount)
    {
        deleteLast(first,last);
    }
    else
    {
        PNODE temp = NULL;
        PNODE target = NULL;

        temp = *first;
        for(i = 1 ; i < pos-1;i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        free(target);

    }
}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iRet = 0;

    insertFirst(&head,&tail,51);
    insertFirst(&head,&tail,21);
    insertFirst(&head,&tail,11);

    insertLast(&head,&tail,101);
    insertLast(&head,&tail,111);

    insertAtPos(&head,&tail,105,5);

    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of elements present in Circular linked list are : %d\n",iRet);

    deleteFirst(&head,&tail);

    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of elements present in Circular linked list are : %d\n",iRet);

    deleteLast(&head,&tail);
     Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of elements present in Circular linked list are : %d\n",iRet);

    deleteAtPos(&head,&tail,3);
     Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of elements present in Circular linked list are : %d\n",iRet);



    return 0;
} 