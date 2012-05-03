#include <stdio.h>


int a[108][108];

int main()
{
	int n;

	scanf("%d",&n);

	int i,j;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			scanf("%d",&a[i][j]);
	int sum=0;

	for(i=0; i<n; i++)
		sum=sum+a[i][i];
	for(i=0; i<n; i++)
		sum=sum+a[i][n-1-i];
	j=(n-1)/2;
	for(i=0; i<n; i++)
		sum=sum+a[i][j];
	i=j;
	for(j=0; j<n; j++)
		sum=sum+a[i][j];

	sum=sum-a[i][i]*3;

	printf("%d\n",sum);

	return 0;
}
