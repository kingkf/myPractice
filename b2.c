#include <stdio.h>
#include <string.h>
int a[100000008];
int findMax(int n)
{
	if(n==1)
		return 0;
	int i;
	for(i=2; i<=n; i++)
		if(n%i==0)
		{
			if(a[n/i]==0)
			{
			     a[n/i]=n/i+findMax(n/i);
			     return a[n/i];
			}
			else
				return a[n/i];
		}
}



int main()
{
	int n;
	scanf("%d",&n);

	int sum=n;
	memset(a,0,sizeof(a));
	a[n]=n;
	sum=sum+findMax(n);

	printf("%d\n",sum);

	return 0;
}
