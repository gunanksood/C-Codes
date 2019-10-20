#include<stdio.h>
#include<conio.h>
int a[5];

void bubble_sort()
{
int i, j, t;
for(i=0; i<5-1; i++)
{
	for(j=i; j<5; j++)
	{
		if(a[i] > a[j])
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
}
}

void main()
{
int i;
clrscr();

printf("Enter the unsorted array :: ");
for(i=0; i<5; i++)
	scanf("%d",&a[i]);

bubble_sort();

printf("Sorted Array is :: ");
for(i=0; i<5; i++)
	printf("%d ",a[i]);

getch();
}