#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIM 1000006
#define LEN 102

struct Element
{
	char fName[LEN];
	char lName[LEN];
	int hIndex;
}*Element;
struct Element *a[LIM];

int ctr=0;
void swap(char*,char*);
void InitHeap(char*,char*);
void Insert(char*,char*);
void FindMin(void);
void Min_Heapify(int);
void DeleteMin(void);
void Delete(int);
int main(void)
{
	int i,t,index;
	char a[11],b[LEN],c[LEN];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%s",a);
		if((strcmp(a,"InitHeap")==0 ))
			scanf("%s %s",b,c),InitHeap(b,c);
		else if((strcmp(a,"Insert")==0))
			scanf("%s %s",b,c),Insert(b,c);
		else if((strcmp(a,"FindMin")==0))
			FindMin();
		else if((strcmp(a,"DeleteMin")==0))
			DeleteMin();
		else if((strcmp(a,"Delete")==0))
			scanf("%d",&index),Delete(index);
	}
	return 0;
}
void swap(char *a, char *b)
{
	char *tmp=(char*)malloc(LEN*sizeof(char));
	strcpy(tmp,a);
	strcpy(a,b);
	strcpy(b,tmp);
}
void InitHeap(char* fName, char* lName)
{
	struct Element *tmp=(struct Element *)malloc(sizeof(struct Element));
	strcpy(tmp->fName,fName);
	strcpy(tmp->lName,lName);
	tmp->hIndex = 1;
	a[1]=tmp;
    ctr++;
}
void Insert(char* fName, char* lName)
{
	struct Element *tmp=(struct Element *)malloc(sizeof(struct Element));
	strcpy(tmp->fName,fName);
	strcpy(tmp->lName,lName);
	ctr++;
	tmp->hIndex=ctr;
	a[ctr]=tmp;
	int i=ctr;
	if(ctr!=1)
	{
		char b[LEN],c[LEN];
		while(i>1)
		{
			if((strcmp(a[i/2]->fName,a[i]->fName)>0) || ((strcmp(a[i/2]->fName,a[i]->fName)==0) && (strcmp(a[i/2]->lName,a[i]->lName)>0)))
			{
				swap(a[i]->fName,a[i/2]->fName);
				swap(a[i]->lName,a[i/2]->lName);
				i/=2;
			}
			else break;
        }
	}
    printf("%d\n",a[i]->hIndex);
}
void FindMin(void)
{
	if(ctr<1)
		printf("-1\n");
	else
		printf("%s %s\n",a[1]->fName,a[1]->lName);
	return;
}
void Min_Heapify(int i)
{
	int smallest=i,l,r;
	l=2*i,r=2*i+1;
	if(l<=ctr && strcmp(a[l]->fName,a[i]->fName)<0)
		smallest=l;
    else
		smallest=i;
	if(l<=ctr && strcmp(a[l]->fName,a[i]->fName)==0)
	{
		if(l<=ctr && strcmp(a[l]->lName,a[i]->lName)<0)
			smallest=l;
		else
			smallest=i;
	}
	if(r<=ctr && strcmp(a[r]->fName,a[smallest]->fName)<0)
			smallest = r;
	else if(r<=ctr && strcmp(a[r]->fName,a[smallest]->fName)==0)
	{
		if(r<=ctr && strcmp(a[r]->lName,a[smallest]->lName)<0 )
				smallest = r;
    }
	if(smallest != i)
	{
		char d[LEN],e[LEN];
		swap(a[i]->fName,a[smallest]->fName);
		swap(a[i]->lName,a[smallest]->lName);
		Min_Heapify(smallest);
	}
}
void DeleteMin()
{
	if(ctr<1)
		printf("-1\n");
	else
	{
		char f[LEN],g[LEN];
		if( (strcmp(a[1]->fName,"\0")!=0) )
			printf("%s %s\n",a[1]->fName,a[1]->lName);
		strcpy(f,a[1]->fName);
		strcpy(a[1]->fName,a[ctr]->fName);
		strcpy(a[ctr]->fName,f);
		strcpy(g,a[1]->lName);
		strcpy(a[1]->lName,a[ctr]->lName);
		strcpy(a[ctr]->lName,g);
		ctr--;
		Min_Heapify(1);
	}
}
void Delete(int index)
{
	int i,x=0;
	for(i=1;i<=ctr;i++)
		if(a[i]->hIndex==index)
			x=1;
    if(x==0)
		printf("-1\n");
	else
	{
		printf("%s %s\n",a[index]->fName,a[index]->lName);
		strcpy(a[index]->fName,"\0");
		strcpy(a[index]->lName,"\0");
		i=index;
		if(i!=1)
		{
			if((strcmp(a[i/2]->fName,a[i]->fName)>0)||(strcmp(a[i/2]->fName,a[i]->fName)==0))
			{
				while(i>1 && (strcmp(a[i/2]->fName,a[i]->fName)>0))
				{
					swap(a[i]->fName,a[i/2]->fName);
					swap(a[i]->lName,a[i/2]->lName);
					i/=2;
				}
			}
		}
		DeleteMin();
	}
}