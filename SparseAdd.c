#include<stdio.h>
void read_sp_mat(int sp[10][3]);
void print_sp_mat(int sp[10][3]);
void add_sp_mat(int sp1[10][3],int sp2[10][3],int sp3[10][3]);
int main()
{
	int sp1[10][3],sp2[10][3],sp3[10][3];
	
	printf("\nEnter first sparse matrix");
	read_sp_mat(sp1);
	printf("\nEnter second sparse matrix");
	read_sp_mat(sp2);
	add_sp_mat(sp1,sp2,sp3);
	
	printf("\nFirst sparse matrix is");
	print_sp_mat(sp1);
	printf("\nSecond sparse matrix is");
	print_sp_mat(sp2);
	printf("\nThird sparse matrix is");
	print_sp_mat(sp3);
	return 0;
} // main
void read_sp_mat(int sp[10][3])
{
	int r,c,i,j,k,t;	
	
	printf("\nEnter r and c : ");
	scanf("%d%d",&r,&c);
	printf("\nEnter the data \n");
	k=1;
	for(i=0;i < r;i++)
	{
		for(j=0;j < c;j++)
		{
			scanf("%d",&t);
			if( t != 0 )
			{
				sp[k][0] = i;
				sp[k][1] = j;
				sp[k][2] = t;
				k++;
			} // if
		} // for
	}
	sp[0][0] = r;
	sp[0][1] = c;
	sp[0][2] = k-1;
	return;
} // read_sp_mat
void print_sp_mat(int sp[10][3])
{
	int r,c,i,j,tot_val,k;
	
	r = sp[0][0];
	c = sp[0][1];
	tot_val = sp[0][2];
	
	for(i=0;i < r;i++)
	{
		printf("\n");
		for(j=0;j < c;j++)
		{
			for(k=1;k<=tot_val;k++)
			{
				if( sp[k][0] == i && sp[k][1] == j )
				{
					break;
				}
			}
			if( k > tot_val)
				printf("%4d",0);
			else
				printf("%4d",sp[k][2]);
		} // for
	} // for
	
} //print_sp_mat
void add_sp_mat(int sp1[10][3],int sp2[10][3],int sp3[10][3])
{
	int r,c,i,j,k1,k2,k3,tot1,tot2;
	
	if( sp1[0][0] != sp2[0][0] || sp1[0][1] != sp2[0][1] )
	{
		printf("Invalid matrix size ");
		return;
	}
	tot1 = sp1[0][2];
	tot2 = sp2[0][2];	
	k1 = k2 = k3 = 1;
	while ( k1 <= tot1 && k2 <= tot2)
	{
		if ( sp1[k1][0] < sp2[k2][0] )
		{
			sp3[k3][0] = sp1[k1][0];
			sp3[k3][1] = sp1[k1][1];
			sp3[k3][2] = sp1[k1][2];
			k3++;k1++;
		}
		else
		if ( sp1[k1][0] > sp2[k2][0] )
		{
			sp3[k3][0] = sp2[k2][0];
			sp3[k3][1] = sp2[k2][1];
			sp3[k3][2] = sp2[k2][2];
			k3++;k2++;
		}
		else if ( sp1[k1][0] == sp2[k2][0] )
		{
		if ( sp1[k1][1] < sp2[k2][1] )
		{
			sp3[k3][0] = sp1[k1][0];
			sp3[k3][1] = sp1[k1][1];
			sp3[k3][2] = sp1[k1][2];
			k3++;k1++;
		}
		else
		if ( sp1[k1][1] > sp2[k2][1] )
		{
			sp3[k3][0] = sp2[k2][0];
			sp3[k3][1] = sp2[k2][1];
			sp3[k3][2] = sp2[k2][2];
			k3++;k2++;
		}
		else
		{
			sp3[k3][0] = sp2[k2][0];
			sp3[k3][1] = sp2[k2][1];
			sp3[k3][2] = sp1[k1][2] + sp2[k2][2];
			k3++;k2++;k1++;
		}
		} // else
	} // while
	while ( k1 <=tot1 )
	{
		sp3[k3][0] = sp1[k1][0];
		sp3[k3][1] = sp1[k1][1];
		sp3[k3][2] = sp1[k1][2];
		k3++;k1++;
	} //while
	
	while ( k2 <= tot2 )
	{
		sp3[k3][0] = sp2[k2][0];
		sp3[k3][1] = sp2[k2][1];
		sp3[k3][2] = sp2[k2][2];
		k3++;k2++;
	} // while
	sp3[0][0] = sp1[0][0];
	sp3[0][1] = sp1[0][1];
	sp3[0][2] = k3-1;
	
} // add_sp_mat