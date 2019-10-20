#include <stdio.h>

void swap(int * a,int *b)
{
    int c = *a;
    *a = *b;
    *b = c;

    return ;
}

void selectionSort(int n,int arr[])
{
    int i, j, m_idx;  
  
    for (i = 0; i < n-1; i++)  
    {
        m_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[m_idx])  
            m_idx = j;     
        swap(&arr[m_idx], &arr[i]);  
    }
}

int main() {
	int ar_size = 4, i;
	int a[4] = {2, 3, 0, 4};
	selectionSort(ar_size, a);

	for (i=0; i<ar_size; i++){
		printf("%d\n", a[i]);
	}

	return 0;
}