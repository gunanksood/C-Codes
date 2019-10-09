#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    int INFO;
    struct node *PREV;
    struct node *NEXT;
}*START,*END;
void create_node_list(int n);
void displaylist(struct node *START);
int main()
{
    int n;
    printf("enter the no. of nodes :");
    scanf("%d",&n);
    create_node_list(n);
    displaylist(START);
}
void create_node_list(int n)
{
    START=NULL;
    END=NULL;
    struct node *new_node,*temp;
    int num,i;
    if(n>=1)
        START=(struct node *)malloc(sizeof(struct node));
    if (START==NULL)
        printf("memory can not be allocated");
    else
    {
        printf("enter data for node1 :");
        scanf("%d",&num);
        START->INFO=num;
        START->NEXT=NULL;
        START->PREV=NULL;
        temp=START;
        END=START;
    for(i=2;i<=n;i++)
    {
        new_node=(struct node *)malloc(sizeof(struct node));
        if(new_node==NULL)
            printf("memory can not be allocated");
        else
        {
            printf("input data for node %d :",i);
            scanf("%d",&num);
            temp->NEXT=new_node;
            new_node->INFO=num;
            new_node->PREV=temp;
            new_node->NEXT=NULL;
            END=new_node;
            temp=temp->NEXT;
        }

       }
    }
}
void displaylist(struct node *START)
{
    struct node *temp;
    if(START==NULL)
    {
        printf("list is empty ");
    }
    else
    {
        temp=START;
        while(temp!= NULL)
        {

            printf("%d->",temp->INFO);
            temp=temp->NEXT;
        }
        printf("NULL");

    }
}
