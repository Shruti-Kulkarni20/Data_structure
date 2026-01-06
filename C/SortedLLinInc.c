//sorted order linked list 

#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE,**PPNODE;

void InsertSortedInc(PPNODE first, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    PNODE temp = NULL;

    newn->data = no;
    newn->next = NULL;

    // Empty list OR insert at beginning
    if((*first == NULL) || (no < (*first)->data))
    {
        newn->next = *first;
        *first = newn;
        return;
    }

    temp = *first;

    // Find correct position
    while((temp->next != NULL) && (temp->next->data < no))
    {
        temp = temp->next;
    }

    // Insert node
    newn->next = temp->next;
    temp->next = newn;
}

void Display(PNODE first)
{
    while (first)
    {
        printf("| %d |->",first->data);
        first = first->next;
    }
    printf("NULL\n");

}

int main()
{
    PNODE head = NULL;

    InsertSortedInc(&head,11);
    InsertSortedInc(&head,7);
    InsertSortedInc(&head,21);
    InsertSortedInc(&head,31);
    InsertSortedInc(&head,40);
    InsertSortedInc(&head,51);
    InsertSortedInc(&head,75);
    InsertSortedInc(&head,51);

    Display(head);

    return 0;
}