#include<stdio.h>
#include<stdlib.h>
struct snode
{
	int INFO;
	struct snode *LINK;
};
typedef struct snode SNODE;
SNODE* PUSH( SNODE *TOP , int ITEM )
{
	SNODE *NEW = (SNODE*)malloc(sizeof(SNODE));
	if( NEW == NULL )
	{
		printf("\n STACK OVERFLOW \n");
	}
	else
	{
		NEW->INFO = ITEM;
		NEW->LINK = TOP;
		TOP = NEW;
		printf("\n [ %d ] PUSHED into STACK \n",ITEM);
	}
	return TOP;
}
int POP( SNODE **TOP )
{
	int ITEM = -1;
	SNODE *TEMP;
	if( *TOP == NULL )
	{
		printf("\n STACK UNDERFLOW \n");
	}
	else
	{
		ITEM = (*TOP)->INFO;
		TEMP = *TOP;
		*TOP = (*TOP)->LINK;
		free(TEMP);
	}
	return ITEM;
}
int main()
{
	SNODE *TOP = NULL;
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
				TOP = PUSH( TOP , item );
				break;
			case 2:
				item = POP( &TOP );
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