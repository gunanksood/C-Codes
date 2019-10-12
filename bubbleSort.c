#include <stdio.h>

void swap(int * a,int *b)
{
    int c = *a;
    *a = *b;
    *b = c;

    return ;
}

void bubbleSort(int n,int arr[])
{
    int i,j; 
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

int main() {
	int ar_size = 4, i;
	int a[4] = {2, 3, 0, 4};
	bubbleSort(ar_size, a);

	for (i=0; i<ar_size; i++){
		printf("%d\n", a[i]);
	}

	return 0;
}