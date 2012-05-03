#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,m,c;
	int a[1003];
	int b[1003];

	scanf("%d%d%d",&n,&m,&c);
	int i;
	for(i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for(i=1; i<=m; i++)
		scanf("%d",&b[i]);
	int count=1;
	int j;
	while(count<=n-m+1)
	{
		j=1;
		for(i=count; i<=m+count-1; i++)
		{
			a[i]=a[i]+b[j];
			a[i]=a[i]%c;
			j++;
		}
		count++;
	}
	for(i=1; i<=n; i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}

