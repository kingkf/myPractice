#include <stdio.h>
int findMax(int n)
{
	if(n==1)
		return 0;
	int i;
	for(i=2; i<=n; i++)
		if(n%i==0)
			return n/i+findMax(n/i);

}
int main()
{
	int n;

	int sum;
	int i;
	for(i=2; i<=25000000; i++)
	{
		sum=i;
	    sum=sum+findMax(n);
	    printf("%d,",sum);

	}

	return 0;
}
