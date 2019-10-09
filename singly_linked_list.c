#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct Node
{
int info;
struct Node *next;
};
struct node* createNodeList(int n)
{
    struct Node *start=NULL;
    struct Node *temp,*new_node;
    int no,i;
    start=(struct Node*)malloc(sizeof(struct Node));
    if(start==NULL)
        printf("memory can not be allocated\n");
    else
    {
        printf("enter data for node 1:\n");
        scanf("%d",&no);
        start->info=no;
        start->next=NULL;
        temp=start;
        for(i=2;i<=n;i++)
        {
            //printf("in loop\n");
            new_node=(struct Node*)malloc(sizeof(struct Node));
            if(new_node==NULL)
                printf("memory can not be allocated\n");
            else
            {
                printf("enter data for node %d:\n",i);
                scanf("%d",&no);
                new_node->info=no;
                new_node->next=NULL;
                temp->next=new_node;
                temp=temp->next;
            }
        }
    }
    return start;
};
void displaynodelist(struct Node*start)
{
    struct Node*temp;
    temp=start;
    printf("\nLINKED LIST IS:- ");
    while(temp!=NULL)
    {
        printf("%d-> ",temp->info);
        temp=temp->next;
    }
    printf("NULL");
}
int main()
{
    int n;
    printf("ENTER NO OF NODES YOU WANT TO INSERT IN LINKED LIST!:\n");
    scanf("%d",&n);
    struct Node*start=createNodeList(n);
    displaynodelist(start);
}
