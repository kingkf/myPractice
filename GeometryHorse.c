#include<stdio.h>

struct figures
{
	int k;
	int c;
};

struct figures a[108];
int cmp(const void *a, const void *b)
{
	return (*(struct figures *)a).c > (*(struct figures *)b).c ? 1:-1;

}
int main()
{
	int n;
	int j;

	scanf("%d",&n);
	for(j=0; j<n; j++)
		scanf("%d%d",&(a[j].k),&(a[j].c));

	int t;
	int p[108];
	scanf("%d",&t);
	for(j=0; j<t; j++)
		scanf("%d",&p[j]);
	qsort(a,n,sizeof(a[0]),cmp);

	/*for(j=0; j<n; j++)
		printf("%d %d\n",a[j].k,a[j].c);
		*/
	int s[108];
	for(j=1; j<t; j++)
		s[j]=p[j];
	for(j=1; j<t; j++)
		p[j]=s[j]-s[j-1];
	int pi=0;
	int count=1;
	int f=1;
	long long sum=0;
	j=0;
	while(j<n)
	{
		int i;
		/*for(i=0; i<a[j].k; i++)
		{
			if(count<=p[pi])
			{
				sum=sum+a[j].c*f;
			}
			else
			{
				pi=pi+1;
				f=f+1;
				sum=sum+a[j].c*f;
			}
			count=count+1;
		}*/
		if(a[j].k<=p[pi])
		{
			sum=sum+a[j].c*f*(a[j].k);
			p[pi]=p[pi]-a[j].k;
			j++;
		}
    	while(a[j].k>p[pi])
		{
			sum=sum+a[j].c*f*p[pi];
			pi++;
			a[j].k=a[j].k-p[pi];
			f++;
		}
	}

			
	

	printf("%I64d\n",sum);

			

	return 0;
}

