#include<bits/stdc++.h>
#define N 200001
using namespace std;
struct node
 {
 	int number;
 	int parent;
 	int rank;
 };
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
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		V[i].number=i;
		V[i].parent=i;
		V[i].rank=0;
	}
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
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
			cout<<"edge <"<<a+1<<" "<<b+1<<"> included\n";
		}
		else
			cout<<"edge <"<<a+1<<" "<<b+1<<"> excluded\n";
	}
	return 0;
}
