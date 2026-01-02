//Doubly circular Linked List

#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node* next;
    struct node*prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node **PPNODE;

void Display(PNODE first,PNODE last)
{
    printf("<=");
    do
    {
        printf("| %d |=>",first->data);
        first = first->next;
    } while (first != last->next);
    printf("\n");
}

int Count(PNODE first,PNODE last)
{
    int iCount = 0;
    do
    {
       iCount++;
       first = first->next;
    } while (first != last->next);

    return iCount;
}

void insertFirst(PPNODE first,PPNODE last,int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
        (*last)->next = *first;
        (*first)->prev = *last;
    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn;
        *first = newn;
        
        (*last)->next = *first;
        (*first)->prev = *last;
    }
}

void insertLast(PPNODE first,PPNODE last ,int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
        (*last)->next = *first;
        (*first)->prev = *last;
    }
    else
    {
        (*last)->next = newn;
        newn->prev = *last;
        *last = newn;
        (*last)->next = *first;
        (*first)->prev = *last;
    }
    

}

void insertAtPos(PPNODE first,PPNODE last,int no,int pos)
{
   
    int iCount = 0,i = 0;

    iCount = Count(*first,*last);

    if(pos < 1 || pos > iCount+1)
    {
        printf("Invalid position");
        return;
    }

    if(pos == 1)
    {
        insertFirst(first,last,no);
    }
    else if(pos == iCount)
    {
        insertLast(first,last,no);
    }
    else
    {
        PNODE newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        PNODE temp = NULL;

        temp = *first;

        for(i = 1; i < pos-1;i++)
        {
            temp = temp->next;
        }

        newn->next = temp ->next;
        temp->next->prev = newn;
        temp->next=newn;
        newn->prev = temp;

    }
}

void deleteFirst(PPNODE first,PPNODE last)
{
    if(*first == NULL && *last == NULL)
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
        *first = (*first)->next;
        free((*last)->next);
        (*first)->prev = *last;
        (*last)->next = *first;
    }

}

void deleteLast(PPNODE first,PPNODE last)
{
   if(*first == NULL && *last == NULL)
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
        *last = (*last)->prev;
        free((*last)->next);

        (*first)->prev = *last;
        (*last)->next = *first;
        
    }
}

void deleteAtPos(PPNODE first,PPNODE last,int pos)
{
    int iCount = 0, i =0;

    iCount = Count(*first,*last);

    if(pos < 1 || pos > iCount)
    {
       printf("Invalid input \n");
       return;
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

        for(i =1; i < pos-1;i++)
        {
            temp = temp->next;
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
    PNODE tail = NULL;
    int iRet = 0;

    insertFirst(&head,&tail,51);
    insertFirst(&head,&tail,21);
    insertFirst(&head,&tail,11);

    insertLast(&head,&tail,101);
    insertLast(&head,&tail,111);
    insertLast(&head,&tail,121);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("Number of element in doubly circular linked list are : %d\n",iRet);

    insertAtPos(&head,&tail,105,5);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("Number of element in doubly circular linked list are : %d\n",iRet);

    deleteFirst(&head,&tail);
    
    Display(head,tail);

    iRet = Count(head,tail);
    printf("Number of element in doubly circular linked list are : %d\n",iRet);

    deleteLast(&head,&tail);
    
    Display(head,tail);

    iRet = Count(head,tail);
    printf("Number of element in doubly circular linked list are : %d\n",iRet);

    deleteAtPos(&head,&tail,4);
    
    Display(head,tail);

    iRet = Count(head,tail);
    printf("Number of element in doubly circular linked list are : %d\n",iRet);

    return 0;
}