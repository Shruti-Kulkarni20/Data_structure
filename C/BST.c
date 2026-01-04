//Binary search Tree 

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int data;
    struct node * lchild;
    struct node * rchild;
}NODE,*PNODE,**PPNODE;

void InsertInBST(PPNODE first,int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;


    if(*first == NULL)
    {
        *first = newn;
    }
    else 
    {
        temp = *first;

        while(1)
        {
            if(no == temp->data)
            {
                printf("Duplicate element : Unable to insert node\n");
                free(newn);
                break;
            }
            else if(no > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp ->rchild;
            }
            else if(no < temp->data)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild ;
            }

        }
    }     
}

void Inorder(PNODE first)
{
    if(first != NULL)
    {
        Inorder(first->lchild);
        printf("%d\t",first->data);
        Inorder(first->rchild);
    }
    
}

void Preorder(PNODE first)
{
    if(first != NULL)
    {
        printf("%d\t",first->data);
        Preorder(first->lchild);
        Preorder(first->rchild);
    }

}

void Postorder(PNODE first)
{
    if (first != NULL)
    {
        Postorder(first->lchild);
        Postorder(first->rchild);
        printf("%d\t",first->data);
    }
    
}

bool Search(PNODE first,int no)
{
    bool bFlag = false;

    while (first != NULL)
    {
        if(no == first->data)
        {
            bFlag = true;
            break;
        }
        else if(no > first->data)
        {
            first = first->rchild;
        }
        else if(no < first->data)
        {
            first = first->lchild;
        }
    }   
    return bFlag;
}

int Count(PNODE first)
{
    static int iCount = 0;

    if(first != NULL)
    {
        iCount++;
        Count(first->rchild);
        Count(first->lchild);
    }

    return iCount;
}

int CountLeafNode(PNODE first)
{
    static int iCount = 0;

    if (first != NULL)
    {
        if (first -> lchild == NULL && first->rchild == NULL)
        {
            iCount++;
        }
        CountLeafNode(first->rchild);
        CountLeafNode(first->lchild);
    }
      
    return iCount;
}

int CountParentNode(PNODE first)
{
    static int iCount = 0;

    if(first != NULL)
    {
        if (first->lchild != NULL && first ->rchild != NULL)
        {
            iCount++;
        }
    }
    CountParentNode(first->rchild);
    CountParentNode(first->lchild);  
}

int main()
{
    PNODE head =  NULL;
    int iRet = 0;
    bool bRet = false;


    InsertInBST(&head,11);
    InsertInBST(&head,9);
    InsertInBST(&head,17);
    InsertInBST(&head,25);
    InsertInBST(&head,7);
    InsertInBST(&head,35);
    InsertInBST(&head,10);
    InsertInBST(&head,15);
    InsertInBST(&head,21);
    InsertInBST(&head,26);
    InsertInBST(&head,37);
    InsertInBST(&head,89);
    InsertInBST(&head,91);
    InsertInBST(&head,65);
    InsertInBST(&head,12);
    InsertInBST(&head,20);
    InsertInBST(&head,44);
    InsertInBST(&head,66);
    InsertInBST(&head,90);
    InsertInBST(&head,88);

    printf("Preorder :\n");
    Preorder(head);
    printf("\nInorder :\n");
    Inorder(head);
    printf("\nPostorder :\n");
    Postorder(head);

    bRet = Search(head,89);

    if(bRet == true)
    {
        printf("Number is present in tree.\n");
    }
    else
    {
        printf("Number is not present in tree.\n");
    }

    iRet = Count(head);
    printf("\nNumber of elements present in tree are : %d\n",iRet);

    iRet = CountLeafNode(head);
    printf("Number of leaf node are %d\n",iRet);

    iRet = CountParentNode(head);
    printf("Number of Parent nodes are %d\n",iRet);

    return 0;
}