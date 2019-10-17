#include<stdio.h>

int main () {

	int a,b,c,num1,num2;

//	scanf("%d %d",&a,&b); 
	scanf("%d %d",&num1,&num2);

/*	for(;b!=0;)
	{

		c=b;
		b=a%b;
		a=c;

	}*/
	while (num1!=0)
	{
		c=num1;
		num1=num2%num1;
		num2=c;
	}

	printf("%d",c);

	return 0 ;

}


