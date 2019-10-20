#include<stdio.h> 
int main() 
{ 
    // Assume 4x5 sparse matrix 
    int sparseMatrix[4][5] = 
    { 
        {0 , 0 , 3 , 0 , 4 }, 
        {0 , 0 , 5 , 7 , 0 }, 
        {0 , 0 , 0 , 0 , 0 }, 
        {0 , 2 , 6 , 0 , 0 } 
    };   
    int size = 0; 
	int i,j;
    for ( i = 0; i < 4; i++)
	{
        for ( j = 0; j < 5; j++) 
		{
            if (sparseMatrix[i][j] != 0) 
			{
                size++; 
			}
		}
	}
  
    // number of columns in compactMatrix (size) must be 
    // equal to number of non - zero elements in 
    // sparseMatrix 
    int compactMatrix[3][size+1]; 
  
    // Making of new matrix 
	int k = 0; 
	compactMatrix[0][k] = 4;
	compactMatrix[1][k] = 5;
	compactMatrix[2][k] = size;
	k++;
    for ( i = 0; i < 4; i++) 
        for ( j = 0; j < 5; j++) 
            if (sparseMatrix[i][j] != 0) 
            { 
                compactMatrix[0][k] = i; 
                compactMatrix[1][k] = j; 
                compactMatrix[2][k] = sparseMatrix[i][j]; 
                k++; 
            } 
  
    for ( i=0; i<3; i++) 
    { 
        for ( j=0; j<size+1; j++) 
            printf("%d ", compactMatrix[i][j]); 
  
        printf("\n"); 
    } 
    return 0; 
} 