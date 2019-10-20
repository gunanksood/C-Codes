/* C Program to implement a queue using two stacks */
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **top_ref, int new_data);

int pop(struct Node **top_ref);

struct queue
{
    struct Node *stack1;
    struct Node *stack2;
};

void enQueue(struct queue *q, int val)
{
    push(&q->stack1, val);
}

int deQueue(struct queue *q)
{
    int val;

    if (q->stack1 == NULL && q->stack2 == NULL)
    {
        printf("Q is empty");
        getchar();
        exit(0);
    }

    if (q->stack2 == NULL)
    {
        while (q->stack1 != NULL)
        {
            val = pop(&q->stack1);
            push(&q->stack2, val);
        }
    }

    val = pop(&q->stack2);
    return val;
}

void push(struct Node **top_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        printf("Stack overflow \n");
        getchar();
        exit(0);
    }

    new_node->data = new_data;

    new_node->next = (*top_ref);

    (*top_ref) = new_node;
}

int pop(struct Node **top_ref)
{
    int res;
    struct Node *top;

    if (*top_ref == NULL)
    {
        printf("Stack underflow \n");
        getchar();
        exit(0);
    }
    else
    {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;
    }
}

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->stack1 = NULL;
    q->stack2 = NULL;
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);

    printf("%d ", deQueue(q));
    printf("%d ", deQueue(q));
    printf("%d ", deQueue(q));

    return 0;
}
