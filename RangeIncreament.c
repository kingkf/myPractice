#include <stdio.h>

struct result
{
	int start;
	int end;
};

struct result res[100008];
int main()
{
	int n;
	int now;
    int pre;
    int stack[100008];
    int top=-1;
    int count=-1;

	scanf("%d",&n);
	int i,j;

	now=0;
	pre=0;
	for(i=0; i<=n; i++)
	{
		if(i<n)
			scanf("%d",&now);
		else
			now=0;
		if(now==pre)
			continue;
		if(now>pre)
		{
			for(j=pre; j<now; j++)
			{
				top++;
				stack[top]=i;
			}
		}
		if(now<pre)
		{
			for(j=pre; j>now; j--)
			{
				count++;
			    res[count].start=stack[top]+1;
			    res[count].end=i;
			    top--;
			}
		}
		pre=now;
	}

	printf("%d\n",count+1);
	for(i=0; i<=count; i++)
		printf("%d %d\n",res[i].start, res[i].end);

	return 0;
}
		

