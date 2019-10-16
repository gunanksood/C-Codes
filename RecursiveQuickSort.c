#include<stdio.h>
#include<stdlib.h>
void display( int *num , int size )
{
	int i;
	for( i = 0; i < size; i++ )
	{
		printf("{%d} ",num[i]);
	}
	printf("\n");
}
int reduction( int A[] , int BEG , int END )
{
	int LEFT , RIGHT , TEMP , LOC;
	LEFT = LOC = BEG;
	RIGHT = END;
	while( 1 )
	{
		while( A[LOC] <= A[RIGHT] && LOC != RIGHT )
		{
			RIGHT = RIGHT - 1 ;
		}
		if( LOC == RIGHT )
		{
			break;
		}		
		if( A[LOC] > A[RIGHT] )
		{
			TEMP = A[LOC];
			A[LOC] = A[RIGHT];
			A[RIGHT] = TEMP;
			LOC = RIGHT;
		}
		while( A[LEFT] <= A[LOC] && LOC != LEFT )
		{
			LEFT = LEFT + 1 ;
		}
		if( LOC == LEFT )
		{
			break;
		}		
		if( A[LEFT] > A[LOC] )
		{
			TEMP = A[LOC];
			A[LOC] = A[LEFT];
			A[LEFT] = TEMP;
			LOC = LEFT;
		}
	}
	return LOC;
}
void quick_sort( int A[] , int BEG , int END )
{
	int  LOC;
	LOC = reduction( A , BEG , END );
	if( BEG < LOC - 1 )
	{
		quick_sort( A , BEG , LOC - 1);
	}
	if( LOC + 1 < END )
	{
		quick_sort( A , LOC + 1 , END );
	}		
}
int main()
{
	int *num;
	int size , i;
	printf("\n Enter The Size of An Array : ");
	scanf("%d",&size);
	num = (int*)calloc(sizeof(int) , size );
	for( i = 0; i < size; i++ )
	{
		num[i] = rand() % 100;
	}
	printf("\n Array Elements \n");
	display( num , size );
	quick_sort( num , 0 , size - 1 );
	printf("\n After Quick Sort,Array Elements \n");
	display( num , size );
	return 0;
}