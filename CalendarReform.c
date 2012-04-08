#include <stdio.h>
#include <stdlib.h>

long long month(long long a)
{
	long long i;

	long long months=a;
	long long days=1;
	for(i=2; i*i<=a; i++)
	{
		long long temp;
		temp=i*i;
		if(a%temp==0)
		{
			months=a/temp;
		}
	}

	return months;
}


	
int main()
{
	long long a,n;

	scanf("%I64d%I64d",&a,&n);
	long long p=0;
	long long i=0;
	for(i=0; i<n; i++)
	{
		if(i==0)
		    a=a+i;
		else
			a=a+1;
		p=p+month(a);
	}

	printf("%I64d\n",p);
	return 0;
}
