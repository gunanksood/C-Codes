#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *linked_list() {
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;

    head = (struct node*) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    return head;
}

void print(struct node* head)
{
    struct node* temp;
    temp = head;
    while(temp != NULL)
    {
        printf("%d  ",temp->data);
        temp = temp -> next;
    }
}

void reverse_ll(struct node **head)
{
    struct node* first;
    struct node* rest;
    if(*head == NULL)
        return;
 
    first = *head;
    rest = first -> next;
    
    if(rest == NULL)
        return;
    reverse_ll(&rest);
    first->next->next =first;
    first -> next =NULL;
    *head = rest;
    
}

int main(void) {
    struct node *p = linked_list();
    print(p);
    reverse_ll(&p);
    printf("\n After reverse linked list is : \n");
    print(p);
    return 0;
}
