#include<stdio.h>
#include<stdlib.h>
struct node
{
	int INFO;
	struct node *LINK;
};
typedef struct node NODE;
NODE *START = NULL;
void traverse()
{
	NODE *PTR = START;
	while( PTR != NULL )
	{
		printf(" [ %d ]",PTR->INFO );
		PTR = PTR->LINK;
	}
}
void add(int ITEM )
{
	NODE *NEW = (NODE*)malloc(sizeof(NODE));
	NODE *PREV , *PTR;
	if( NEW == NULL )
	{
		printf("\n OVERFLOW \n");
	}
	else
	{
		NEW->INFO = ITEM;
		PREV = NULL;
		PTR = START;
		while( PTR != NULL && PTR->INFO < ITEM )
		{
			PREV = PTR;
			PTR = PTR->LINK;
		}
		if( PREV == NULL )
		{
			NEW->LINK = START;
			START = NEW;
		}
		else
		{
			NEW->LINK = PTR;
			PREV->LINK = NEW;
		}
		printf("\n Node is Added at Beginning of Linked List \n");
	}
}
int main()
{
	int item , choice , run = 1;
	while( run )
	{
		printf("\n Press 1 For Add New in Sorted Linked List ");
		printf("\n Press 2 For Traverse the Sorted Linked List ");		
		printf("\n Press 3 For Exit \n");
		printf("\n Enter Your Choice : ");
		scanf("%d",&choice);
		switch( choice )
		{
			case 1:
				printf("\n Enter Item : ");
				scanf("%d",&item);
				add( item );
				break;
			case 2:
				printf("\n Content of Sorted Linked List \n");
				if(START == NULL )
				{
					printf(" EMPTY LIST ");
				}
				else
				{
					traverse( );
				}
				printf("\n");
				break;
			case 3:
				run = 0;
				printf("\n Exit From Program \n");
				break;
			default:
				printf("\n Invalid Choice Try Again \n");
				break;
		}
	}
	return 0;
}