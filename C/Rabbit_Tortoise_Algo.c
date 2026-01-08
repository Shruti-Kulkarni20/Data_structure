//Tortoise - rabit (floyids cycle algorithm)

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE,**PPNODE;

void InsertSortedIncUnique(PPNODE first,int no)
{
    PNODE newn = NULL, temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    //first element
    if((*first == NULL) ||(no < (*first)-> data))
    {
        newn->next = *first;
        *first = newn;
    }
    else //second on word
    {
        temp = *first;

        while((temp->next != NULL) && (temp->next->data < no))
        {

            temp = temp->next;
        }

        if((temp -> next == NULL) && (temp -> data == no))
        {
            free(newn);
            return;

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
       
        newn->next = temp->next;                                 
        temp->next = newn;    
        
    }

}
void Display(PNODE first)
{

    while(first)
    {
        printf("| %d | ->",first->data);
        first = first->next;      
    }
    printf("NULL\n");
}
bool CheckLoop(PNODE first)
{
    bool bFlag = false;

    PNODE teacher = NULL,student = NULL;

    teacher = first;
    student = first;

    while ((teacher != NULL) && (teacher->next != NULL))
    {
        teacher = teacher -> next -> next;
        student = student -> next;

        if (teacher == student)
        {
            bFlag = true;
            break;
        }
        
    }
    return bFlag;

}

int main()
{
    PNODE head = NULL;
    //L00P prepare
    PNODE last = NULL;
    PNODE temp = NULL;
    bool bRet = false;
    
    InsertSortedIncUnique(&head,11);
    InsertSortedIncUnique(&head,21);
    InsertSortedIncUnique(&head,51);
    InsertSortedIncUnique(&head,101);
    InsertSortedIncUnique(&head,111);
    InsertSortedIncUnique(&head,121);

    bRet = CheckLoop(head);

    if(bRet == true)
    {
        printf("Loop is there in Linked List \n");
    }
    else
    {
        printf("Loop is not there in Linked List \n");

    }

    return 0;
}