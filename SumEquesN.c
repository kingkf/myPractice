/* 输入两个整数 n 和 m ，从数列 1 ， 2 ， 3.......n 中随意取几个数 , 使其和等于 m , 要求将其中所有的可能组合列出来 */

#include <stdio.h>
int n,m;
void sum(int a[],int s,int j )
{
	int i;
	if(s==m)
	{
		for(i=1; i<=n; i++)
			if(a[i]==1)
				printf("%d ",i);
		printf("\n");
	}
	else if(s>m)
		return;
	else
		for(i=j; i<=n; i++)
			if(a[i]==0)
			{
				a[i]=1;
				sum(a,s+i,i);
				a[i]=0;
			}
}
				
	
int main()
{
	int a[100];
	int i;

	for(i=0; i<100; i++)
		a[i]=0;

	scanf("%d%d",&n,&m);
	for(i=1; i<=n; i++)
	{
		if(a[i]==0)
		{
			a[i]=1;
			sum(a,i,i);
			a[i]=0;
		}
	}

	return 0;
}

