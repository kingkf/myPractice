#include <stdio.h>
#include <stdlib.h>

int maxNum(int max, int min)
{
	int m=max;
	int n=min;
	if(max==1&&min==1)
		return 0;
	if(max==0 || min==0)
		return 0;
	if(max-2>min)
		max=max-2;
	else
	{
		int temp=max;
		max=min;
		min=temp-2;
	}
	//printf("max :%d ; min :%d\n",max,min);
	return n+maxNum(max,min);
}
int main()
{
	int m,n;
	int max,min;

	scanf("%d%d",&m,&n);
	if(m>n)
	{
		max=m;
		min=n;
	}
	else
	{
		max=n;
		min=m;
	}

	printf("%d\n",maxNum(max,min));
	return 0;
}
