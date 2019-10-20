#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define INFINITE 10000000
int search( char nodes[] , int size , char ch )
{
	int index = -1;
	int i;
	for( i = 0; i < size; i++ )
	{
		if( ch == nodes[i] )
		{
			index = i;
			break;
		}
	}
	return index;
}
int main()
{
	char nodes[MAX],ch,start,end;
	int graph[MAX][MAX] = {};
	int weights[MAX][MAX] = {};
	int size , i , j , k,weight,choice;
	printf("\n Enter Total Number of Vertices : ");
	scanf("%d",&size);
	i = 0;
	while( 1 )
	{
		if( i == size )
		{
			break;
		}
		fflush(stdin);
		printf("\n Enter Node Name : ");
		scanf("%c",&ch);
		if( search( nodes , i , ch ) == -1 )
		{
			nodes[i] = ch;
			i++;
		}
		else
		{
			printf("\n This Node Name is used Try With Different Name \n");
		}
	}
	printf("\n Nodes List : ");
	for( i = 0; i < size; i++ )
	{
		printf(" [ %c ] ",nodes[i]);
	}
	printf("\n");
	while( 1 )
	{
		fflush(stdin);
		printf("\n Enter Start Node : ");
		scanf("%c",&start);
		fflush(stdin);
		printf("\n Enter End Node : ");
		scanf("%c",&end);
		i = search( nodes , size , start );
		j = search( nodes , size , end );
		if( i != -1 && j != -1 )
		{
			printf("\n Enter Weight : ");
			scanf("%d",&weight);
			graph[i][j] = weight;			
		}
		else
		{
			printf("\n Invalid Node Name Given \n");
		}
		printf("\n Press 1 For Add More Edges. Enter Your Choice : ");
		scanf("%d",&choice);
		fflush(stdin);
		if( choice != 1 )
		{
			break;
		}
	}
	printf("\n Weighted Graph Adjacency Matrix \n ");
	for( i = 0; i < size; i++ )
	{
		printf("\t%c",nodes[i]);
	}
	for( i = 0; i < size; i++ )
	{
		printf("\n %c",nodes[i]);
		for( j = 0; j < size; j++ )
		{
			printf("\t%d",graph[i][j]);
		}
		printf("\n");
	}
	// Shortest Path 
	for( i = 0; i < size; i++ )
	{
		for( j = 0; j < size; j++ )
		{
			if( graph[i][j] == 0 )
			{
				weights[i][j] = INFINITE;
			}
			else
			{
				weights[i][j] = graph[i][j];
			}
		}		
	}
	for( k = 0; k < size; k++ )
	{
		for( i = 0; i < size; i++ )
		{
			for( j = 0; j < size; j++ )
			{
				if( weights[i][j] > ( weights[i][k] + weights[k][j] ))
				{
					if( weights[i][k] == INFINITE || weights[k][j] == INFINITE )
					{
						weights[i][j] = INFINITE;
					}
					else
					{
						weights[i][j] = weights[i][k] + weights[k][j];
					}
				}
			}
		}
	}
	for( i = 0; i < size; i++ )
	{
		for( j = 0; j < size; j++ )
		{
			if( weights[i][j] == INFINITE )
			{
				weights[i][j] = 0;
			}
		}		
	}
	printf("\n Shortest Path Graph Adjacency Matrix \n ");
	for( i = 0; i < size; i++ )
	{
		printf("\t%c",nodes[i]);
	}
	for( i = 0; i < size; i++ )
	{
		printf("\n %c",nodes[i]);
		for( j = 0; j < size; j++ )
		{
			printf("\t%d",weights[i][j]);
		}
		printf("\n");
	}
	return 0;
}