#include <stdio.h>

int main()
{
	int n;
	int a;
	int i;
	int max,min;
	int maxLoc,minLoc;

	scanf("%d",&n);
	for(i=1; i<=n; i++)
	{
		if(i==1)
		{
			scanf("%d",&a);
			max=a;
			maxLoc=1;
			min=a;
			minLoc=1;
		}
		else
		{
			scanf("%d",&a);
			if(max<a)
			{
				max=a;
				maxLoc=i;
			}
			if(min>=a)
			{
				min=a;
				minLoc=i;
			}
		}
	}
	if(maxLoc<minLoc)
	    printf("%d\n",maxLoc-1+n-minLoc);
	else
		printf("%d\n",maxLoc-1+n-minLoc-1);

	return 0;
}

			

