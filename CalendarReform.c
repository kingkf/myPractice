#include <stdio.h>
#include <stdlib.h>
#define M 10000000
long long x[M+1];
int main()
{
	long long a,n;
	long long i,t,j,k,sum;

	for(i=1; (t=i*i)<=M; i++)
	{
		for(j=1, k=t; k<=M; j++,k=k+t)
			x[k]=j;
	}

	scanf("%I64d%I64d",&a,&n);
	for(sum=0,i=0; i<n; i++)
		sum=sum+x[a+i];
	printf("%I64d\n",sum);

	return 0;
}
