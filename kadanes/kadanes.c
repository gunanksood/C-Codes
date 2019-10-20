#include<stdio.h>

int main () 
{
	int arr[10005],a,b,c,d;
	scanf("%d",&a);

	for (int k=0;k<a;++k)
	{
		scanf("%d",&b);
		for(int j=0; j<b;++j)
		{
			scanf("%d",&arr[j]);
		}

		int max_ending=0;int max_so_far=0;

		for (int j=0;j<b;++j)
		{
			max_ending +=arr[j];

			if(max_ending <0)
			{ max_ending =0;}



			if (max_so_far<max_ending)
			{
				max_so_far=max_ending;
			}

		}

		printf("%d",max_so_far);
	}

	return 0 ;
}




