#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *PREV;
	int INFO;
	struct node *NEXT;
};
typedef struct node NODE;
void traversef( NODE *FIRST )
{
	NODE *PTR = FIRST;
	while( PTR != NULL )
	{
		printf(" [ %d ]",PTR->INFO );
		PTR = PTR->NEXT;
	}
}
void traverseb( NODE *LAST )
{
	NODE *PTR = LAST;
	while( PTR != NULL )
	{
		printf(" [ %d ]",PTR->INFO );
		PTR = PTR->PREV;
	}
}
void addBeginning(NODE **FIRST , NODE **LAST , int ITEM )
{
	NODE *NEW = (NODE*)malloc(sizeof(NODE));
	if( NEW == NULL )
	{
		printf("\n OVERFLOW \n");
	}
	else
	{
		NEW->INFO = ITEM;		
		NEW->PREV = NULL;
		if( *FIRST == NULL || *LAST == NULL )
		{
			*FIRST = *LAST = NEW;			
			NEW->NEXT = NULL;
		}
		else
		{
			NEW->NEXT = *FIRST;
			(*FIRST)->PREV = NEW;
			*FIRST = NEW;
		}
		printf("\n New Node is added at Beginning of Two Way Linked List \n");
	}
}
void deleteLast( NODE **FIRST , NODE **LAST )
{
	NODE *TEMP;
	if( *FIRST == NULL || *LAST == NULL )
	{
		printf("\n UNDERFLOW \n");
	}
	else
	{
		TEMP = *LAST;
		if( *LAST == *FIRST )
		{
			*LAST = *FIRST = NULL;
		}
		else
		{
			(*LAST)->PREV->NEXT = NULL;
			(*LAST) = (*LAST)->PREV;
		}
		free(TEMP);
		printf("\n NODE is REMOVED from last of the Two Way Linked List \n");
	}
}
int main()
{
	NODE *FIRST = NULL;
	NODE *LAST = NULL;
	int item , choice , run = 1;
	while( run )
	{
		printf("\n Press 1 For Add New Node at Beginning of Two Way Linked List ");
		printf("\n Press 2 For Traverse Forward the Two Way Linked List ");
		printf("\n Press 3 For Traverse Backward the Two Way Linked List ");
		printf("\n Press 4 For Delete Last Node from the Two Way Linked List ");
		printf("\n Press 5 For Exit \n");
		printf("\n Enter Your Choice : ");
		scanf("%d",&choice);
		switch( choice )
		{
			case 1:
				printf("\n Enter Item : ");
				scanf("%d",&item);
				addBeginning( &FIRST , &LAST , item );
				break;
			case 2:
				printf("\n Content of Two Way Linked List in Forward Manner \n");
				if(FIRST == NULL || LAST == NULL )
				{
					printf(" EMPTY LIST ");
				}
				else
				{
					traversef( FIRST );
				}
				printf("\n");
				break;
			case 3:
				printf("\n Content of Two Way Linked List in Backward Manner \n");
				if(FIRST == NULL || LAST == NULL )
				{
					printf(" EMPTY LIST ");
				}
				else
				{
					traverseb( LAST );
				}
				printf("\n");
				break;
			case 4:
				deleteLast( &FIRST , &LAST );
				break;
			case 5:
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