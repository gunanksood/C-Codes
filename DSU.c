#include<stdio.h>
#define N 200001
typedef struct node
 {
 	int number;
 	int parent;
 	int rank;
 } node;
int findRoot(node a[N],int x)
{
	if(a[x].parent==x)
		return x;
	else
		return findRoot(a,a[x].parent);
}
int main()
{
	int t,m,n,i,a,b,aroot,broot;
	node V[N];
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		V[i].number=i;
		V[i].parent=i;
		V[i].rank=0;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		a--;b--;
		aroot=findRoot(V,a);
		broot=findRoot(V,b);		
		if(aroot!=broot)
		{
			if( V[aroot].rank < V[broot].rank )
				V[aroot].parent = broot;
			else if( V[aroot].rank > V[broot].rank)
				V[broot].parent = aroot;
			else
			{
				V[aroot].parent = broot;
				V[broot].rank++;
			}
			printf("edge <%d %d> included\n",a+1,b+1);
		}
		else
			printf("edge <%d %d> excluded\n",a+1,b+1);
	}
	return 0;
}
