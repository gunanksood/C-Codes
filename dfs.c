#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIM 100005

// void merge(int *, int, int , int);
// void msort(int *, int, int);

// int array[LIM];

struct adj
{
	int vertex;
	struct adj *next;
};

struct list
{
	int vertex;
	int d;
	int f;
	char color;
	char col;
	struct adj *next1;
};

// void msort(int *a, int low, int high)
// {
//     int mid;
//     if (low<high)
//     {
//         mid=(low+high)/2;
//         msort(a,low,mid);
//         msort(a,mid+1,high);
//         merge(a,low,high,mid);
//     }
//     return;
// }

// void merge(int *a, int low, int high, int mid)
// { 
//     int i, j, k, b[LIM];
//     i=low;
//     k=low;
//     j=mid+1;
//     while(i<=mid && j<=high)
//     {
//         if(a[i]>a[j])
//         {
//             b[k] = a[i];
//             k++;
//             i++;
//         }
//         else
//         {
//             b[k] = a[j];
//             k++;
//             j++;
//         }
//     }
//     while(i<=mid)
//     {
//         b[k]=a[i];
//         k++;
//         i++;
//     }
//     while(j<=high)
//     {
//         b[k]=a[j];
//         k++;
//         j++;
//     }
//     for(i=low;i<k;i++)
//         a[i]=b[i];
// }


struct list *arr[LIM];
int time=0, ans1=0,ans2;

int ans[LIM];
int tail=0;
// int fail[LIM];

void addEdge (int i, int x)
{
	struct adj *node = (struct adj*)malloc(sizeof(struct adj));
	node->vertex = x;
	node->next = NULL;
	
	if (arr[i]->next1 == NULL)
		arr[i]->next1 = node;
		
	else
	{
		struct adj *ptr = (struct adj*)malloc(sizeof(struct adj));
		// struct adj *tmp = (struct adj*)malloc(sizeof(struct adj));
		node->next=arr[i]->next1;
		arr[i]->next1=node;
		// while (1)
		// {
		// 	if (ptr->next == NULL)
		// 		break;
		// 	ptr = ptr->next;
		// }
		
		// ptr->next = node;
	}
}

void printAdjList (int N)
{
	int i;
	for (i=0;i<N;i++)
	{
		printf("%d : ", arr[i]->vertex);
		struct adj *ptr = arr[i]->next1;
		
		while(1)
		{
			if (ptr != NULL)
				printf("%d-%c  ",ptr->vertex, arr[ptr->vertex]->col);
				
			else
				break;  
				
			ptr = ptr->next;
			
		}
		printf("\n");
	}
}

void DFSVisit(int i,int time, char col)
{
	time++;
	arr[i]->d = time;
	arr[i]->color = 'G';
	struct adj *ptr = arr[i]->next1;
	while(ptr)
	{
		if (ptr == NULL)
			break;
		if (arr[ptr->vertex-1]->color == 'W')
		{
			if(arr[i]->col=='B')
				arr[ptr->vertex-1]->col='R';
			else
				arr[ptr->vertex-1]->col='B';
			int x = ptr->vertex -1;
			// printf("%d-%c\n",arr[ptr->vertex-1]->vertex, arr[ptr->vertex-1]->col);
			// ans2++;
			DFSVisit(x,time,arr[ptr->vertex-1]->col);
		}
		else
		{
			if(arr[ptr->vertex-1]->col == arr[i]->col)
			{
				printf("NO\n");
				exit(0);
			}
		}
		ptr = ptr->next;
	}
	
	arr[i]->color = 'B';
	ans[tail] = arr[i]->vertex;
	tail++;
	
	time++;
	arr[i]->f = time;
}

void DFS(int N)
{
	int i;
	for (i=0;i<N;i++)
	{
		arr[i]->color = 'W';
	}
	
	time = 0;
	
	for (i=0;i<N;i++)
	{
		if (arr[i]->color == 'W')
		{
			//ans1++;
			// ans2=1;
			arr[i]->col='R';
			// printf("DFS Tree for %d\n",arr[i]->vertex);
			// printf("%d-%c\n",arr[i]->vertex,arr[i]->col);
			DFSVisit(i,time,arr[i]->col);
			// printf("\n");
			// array[ans1++]=ans2;
		}
	}
	// msort(array,0,ans1-1);
	// printf("%d\n",ans1);
	// for(i=0;i<ans1;i++)
	// 	printf("%d\n",array[i]);
	
}


int main(void)
{
	int v,e,i,x,y;
	scanf("%d %d",&v,&e);
	for(i=0;i<=v;i++)
	{
		arr[i] = (struct list*)malloc(sizeof(struct list));
		arr[i]->vertex = i+1;
		arr[i]->next1 = NULL;
		// arr[i]->col='R';
	}
	for(i=0;i<e;i++)
	{
		scanf("%d %d",&x,&y);
		addEdge(x-1,y);
		addEdge(y-1,x);
	}
	// printAdjList(v);
	DFS(v);
	printf("YES\n");
	// printf("\n");
	// printAdjList(v);
}