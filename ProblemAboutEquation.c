#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,b;
	int a[108];
	double result[108];

	scanf("%d%d",&n,&b);
	int i,sum;
	for(i=0,sum=0; i<n; i++)
	{
		scanf("%d",&a[i]);
		sum=sum+a[i];
	}
	double avg=(double)(sum+b)/(double)n;
	int sus=1;
	for(i=0; i<n; i++)
	{
		result[i]=avg-a[i];
		if(result[i]<0)
		{
			printf("-1\n");
			sus=0;
			break;
		}
	}

	if(sus==1)
	{
		for(i=0; i<n; i++)
			printf("%.6lf\n",result[i]);
	}

	return 0;
}
