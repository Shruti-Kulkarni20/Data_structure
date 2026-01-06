//sorted order linked list 

#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE,**PPNODE;

void InsertSortedIncUnique(PPNODE first, int no)
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

    //duplicate
    if(temp->next != NULL)
    {
        if((temp->data == no)||(temp->next->data == no))
        {
            free(newn);
            return;
        }
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

    InsertSortedIncUnique(&head,11);
    InsertSortedIncUnique(&head,-21);
    InsertSortedIncUnique(&head,7);
    
    InsertSortedIncUnique(&head,21);
    InsertSortedIncUnique(&head,-85);
    InsertSortedIncUnique(&head,51);
    
    InsertSortedIncUnique(&head,40);
    
    InsertSortedIncUnique(&head,7);
    InsertSortedIncUnique(&head,31);
    InsertSortedIncUnique(&head,-31);
    InsertSortedIncUnique(&head,51);
    InsertSortedIncUnique(&head,0);
    InsertSortedIncUnique(&head,75);

    Display(head);

    return 0;
}