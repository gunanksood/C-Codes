#include<stdio.h>
#include<conio.h>
#define n 5
int top = -1,a[2];
void push();
void pop();
void tp();
void print();
void main(){
int ch;
clrscr();
do{
printf("enter 1 to insert data into stack\n");
printf("enter 2 to remove data from stack\n");
printf("enter 3 to print the data at topmost position\n");
printf("enter 4 to dispaly the stack\n");
printf("enter 5 to exit\n");
scanf("%d",&ch);
switch(ch){
case 1:push();
       break;
case 2:pop();
       break;
case 3:tp();
       break;
case 4:print();
       break;
case 5:printf("BYE BYE!....");
       break;
default:printf("invalid choice\n");
	break;
}
}
while(ch!=5);
getch();
}
void push(){
int data;
printf("enter data\n");
scanf("%d",&data);
top++;
a[top]=data;
}
void pop(){
top--;
}
void tp(){
int dat;
dat=a[top];
printf("the data at top is %d\n",dat);
}
void print(){
int i;
for(i=top;i>=0;i--){
printf("%d",a[i]);
}
}
