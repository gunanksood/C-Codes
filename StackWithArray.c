#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int TOP = -1;
void PUSH( int STACK[] , int ITEM )
{
	if( TOP == MAX - 1 )
	{
		printf("\n STACK OVERFLOW \n");
	}
	else
	{
		TOP = TOP + 1;
		STACK[TOP] = ITEM;
		printf("\n [ %d ] PUSHED into STACK \n",ITEM);
	}
}
int POP( int STACK[] )
{
	int ITEM = -1;
	if( TOP == -1 )
	{
		printf("\n STACK UNDERFLOW \n");
	}
	else
	{
		ITEM = STACK[TOP];
		TOP = TOP - 1;
	}
	return ITEM;
}
int main()
{
	int STACK[MAX];
	int run , choice , item;
	run = 1;
	while( run )
	{
		printf("\n Press 1 For PUSH Item to STACK ");
		printf("\n Press 2 For POP Item From STACK ");
 		printf("\n Press 3 For Exit \n");
		printf("\n Enter Your Choice : ");
		scanf("%d",&choice);
		switch( choice )
		{
			case 1:
				printf("\n Enter Item : ");
				scanf("%d",&item);
				PUSH( STACK , item );
				break;
			case 2:
				item = POP( STACK );
				if( item != -1 )
				{
					printf("\n [ %d ] Popped From STACK \n",item);
				}
				break;
			case 3:				
				run = 0;
				break;
			default:
				printf("\n Invalid Choice. Try Again. \n");
		}
	}
	return 0;
}