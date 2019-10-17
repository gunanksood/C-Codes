/*
*C Program to find the nth number in fibonacci series using recursion
*/
#include<stdio.h>
#include<conio.h>
int fibo(int);
int main()
{
int num;
int result;
printf("Enter the nth number in fibonacci series:");
scanf("%d",&num);
if(num<0)
{
printf("Fibonacci of negative number is not possible");
}
else
{
result=fibo(num);
printf("\nThe %d number in Fibonacci series is %d:\n",num,result);
}
getch();
return 0;
}
int fibo(int num)
{
if(num ==0)
{
return 0;
}
else if(num ==1)
{
return 1;
}
else
{
return(fibo(num-1)+fibo(num -2));
}
}