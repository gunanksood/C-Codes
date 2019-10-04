#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node node;

typedef struct graph graph;

struct node{
  int name;//name of node
  int dis;//its distance from origin
  int size;//list size
  int visit;//visited or not
  int* list;//its adjacent list
  int* wt;//weight of adjacent list
};

struct graph{
  int V;
  int E;
  int* pre;
  node** node_list;
};

node* createnode(int value, int* list,int* wt,int n)
{
  int i= 0;
  //printf("%d\t", n);
  //n = 3;
  node* nptr = (node*)malloc(sizeof(node));
  nptr->visit = 0;
  nptr->dis = INT_MAX;
  nptr->name = value;
  nptr->size = n;
  nptr->list = (int*)malloc(sizeof(int)*n);

  for(i=0; i< n; i++)
  {
    nptr->list[i] = list[i];
  }
  nptr->wt = (int*)malloc(sizeof(int)*n);
  for(i=0; i< n; i++)
  {
    nptr->wt[i] = wt[i];
  }


  return nptr;
}

graph* creategraph()
{
  int i = 0,j=0, e = 0, n=0, k = 0;
  graph* g = (graph*)malloc(sizeof(graph));

  printf("Enter the number of vertices and edges:");
  scanf("%d", &n);
  scanf("%d", &e);
  g->V = n;
  g->E = e;
  g->pre =(int*)calloc(n,sizeof(int));

  g->node_list = (node**)malloc(sizeof(node*)*n);

  printf("Enter the details:\n" );
  for(i=0; i< n; i++)
  {
    printf("For node %d:\n",i+1 );
    printf("Enter the adjacency list size:\n" );
    scanf("%d", &k);

    int* li = (int*)malloc(k*sizeof(int));
    int* w = (int*)malloc(k*sizeof(int));

    printf("Enter the node numbers and weights\n");
    for(j =0; j<k; j++)
    {
      scanf("%d",&li[j]);
      scanf("%d",&w[j]);
      li[j]--;//to  match the starting to zero
    }
    //printf("%d\t",k);
    node* nptr = createnode(i,li,w,k);

    g->node_list[i] = nptr;
    k =0;
    nptr = NULL;
    li = NULL;
    w = NULL;
  }
  return g;
}

int search(node** t,int n)
{
  int i =0; int flag = 0;
  int size = n;
  node* min = (node*)malloc(sizeof(node));
  min->dis=INT_MAX;
  /*for(i=0; i< size; i++)
  {
    min = t[i];
    //printf("TestKey3\n" );
    if(min->visit == 0)
    {
      //printf("TestKey2\n" );
      break;
    }
  }*/
  //printf("%d\n",min->name );
  for(i = 0; i< size; i++)
  {
    //printf("TestKey\n" );
    if(min->dis > t[i]->dis && !t[i]->visit)
    {
      //printf("TestKey1\n" );
      min = t[i];
      flag = 1;
    }
  }
  if(!flag)
    return -1;
  return min->name;
}

void printPath(int* pre, int dest)
{
  if(pre[dest] == -1)
    return;
  printPath(pre, pre[dest]);
  printf("%d-->", dest+1);
}

void dijktra(graph* g, int source, int destination)
{
  int key = source,i=0;
  int n = g->V;
  node* temp = g->node_list[key];
  temp->dis = 0;
  printf("%d\n",temp->name );
  printf("%d\n",temp->dis );
  while (n>0) {

    temp = g->node_list[key];
    printf("temp->name=%d\n",temp->name);
    temp->visit = 1;
    int num = temp->size;
    for(i=0; i< num; i++)
    {
      //printf("temp->dis=%d\n",temp->dis);
      int adj_lable = temp->list[i];
      node* temp1 = g->node_list[adj_lable];//temp1 is the node on the adjacency list of temp
      if(temp1->dis > temp->dis + temp->wt[i])
      {
        printf("temp->dis=%d\ttemp1->name=%d\ttemp->wt[i]=%d\n",temp->dis,temp1->name,temp->wt[i] );
        temp1->dis = temp->dis + temp->wt[i];
        g->pre[adj_lable] = temp->name;//
        printf("temp1=%d\n",temp1->dis );
        //temp->list[i]= temp->dis + temp->wt[i];
      }
    }
    key = search(g->node_list,g->V);
    if(key == -1)
      break;
    //printf("key=%d\n",key );
    /*if(key == destination)
      break;*/
    n--;
  }
  g->pre[source]=-1;
  printf("%d-->", source+1);
  if(g->node_list[destination]->dis != INT_MAX)
    printPath(g->pre,destination);
  else
    printf("No path\n" );
  printf("\n" );
}
void print(graph* g)
{
  int i =0,j=0;
  int n = g->V;
  for(i =0; i<n; i++)
  {
    node* t = g->node_list[i];
    int n1 = t->size;
    //printf("%d\t", n1);
    for(j =0;j<n1;j++)
    {
      printf("node_name=%d--",t->list[j]+1);
      printf("wt=%d\t",t->wt[j] );
    }
    printf("u=%d\t",t->dis );
    t = NULL;
    n1 = 0;
    printf("\n");
  }
}
int main() {
  int starting = 0;
  int ending = 0;
  graph* g = creategraph();
  print(g);
  printf("Enter the starting vertex and enfing vertex:" );
  scanf("%d %d",&starting, &ending);
  dijktra(g,starting-1,ending-1);//vertex numbers starts from 1
  print(g);
  return 0;
}
