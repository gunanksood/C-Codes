
#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node * next;
};
struct node * head;
void create(int);
void display();
void main()
{
 int ch, num;
 clrscr();
 while(1)
 {
   printf("\n1. create a linked list.");
   printf("\n2. display the linked list.");
   printf("\n3. exit");
   printf("\nenter your choice");
   scanf("%d",&ch);
   switch(ch)
{
case 1 :
	create(num);
	break;
case 2 :
	display();
	break;
case 3 :
	exit(0);
default :
	printf("\ninvalid choice");

}
}
}
void create(int num){
struct node * temp=(struct node*)malloc(sizeof(struct node));
printf("\nEnter the number");
scanf("%d",&num);
temp->data=num;
temp->next=NULL;
while(head!=NULL){
temp->next=head;
}
head=temp;
}
void display(){
struct node * temp=head;
while(temp!=NULL)
{
printf("%d",temp->data);
temp=temp->next;
}
printf("\n");
}
