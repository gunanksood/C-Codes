#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;

};
struct node* head;
struct node* create_ll(int d)
{
    struct node* ins =(struct node *) malloc(sizeof(struct node));
    ins->data = d;
    if(head == NULL)
    {
        head=ins;
        ins->next = NULL;
    }
    else
    {
        struct node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        ins->next = NULL;
        temp->next = ins;

    }
    return head;
}

void print()
{
    struct node* temp = head;
    while(temp != NULL)
    {
        printf("%d  ",temp->data);
        temp = temp->next;

    }
printf("\n");

}

struct node* reverse(struct node* head)
{
    if(head == NULL)
        return NULL;
    struct node* new_head;
    if(head->next == NULL)
        {
            new_head = head;
            return new_head;
        }
    new_head = reverse( head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}

int main(void)
{
    int n,i;

    printf("enter the no. of nodes");
    scanf("%d",&n);
    head=NULL;
    for(i = 0; i < n; i++)
    {
        int d;
        scanf("%d",&d);
        head = create_ll(d);
    }
    printf("linked list is : ");
    print();
    head = reverse(head);
    printf("\nafter reverse linked list is : ");
    print();
    return 0;
}
