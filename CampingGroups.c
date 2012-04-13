#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct member
{
	int age;
	int value;
};

struct member a[100008];
int n,k;

int max(int a, int b)
{
	if(a>=b)
		return a;
	return b;
}

int biggestSize(struct member leader)
{
	int i;
	int size=0;

	for(i=1; i<=n; i++)
	{
		if(a[i].value<=leader.value && abs(a[i].age-leader.age)<=k)
			size++;
	}

	return size;
}
	

int main()
{

	scanf("%d%d",&n,&k);
	int i;
	for(i=1; i<=n; i++)
		scanf("%d",&(a[i].value));
	for(i=1; i<=n; i++)
		scanf("%d",&(a[i].age));

	int q,x,y;
	scanf("%d",&q);
	struct member leader;
	for(i=1; i<=q; i++)
	{
		scanf("%d%d",&x,&y);
		if(abs(a[x].age-a[y].age)>k)
		{
			printf("-1\n");
			continue;
		}
		if(a[x].value>a[y].value)
		{
			leader.value=a[x].value;
			leader.age=a[x].age;
			printf("%d\n",biggestSize(leader));
		}
		else if(a[x].value<a[y].value)
		{
			leader.value=a[y].value;
			leader.age=a[x].age;
			printf("%d\n",biggestSize(leader));
		}
		else
		{
			printf("%d\n",max(biggestSize(a[x]),biggestSize(a[y])));
		}
	}

	return 0;
}


