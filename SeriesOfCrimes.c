#include <stdio.h>
#include <string.h>

int main()
{
	int n,m;
	char s[108][108];
	int x[4];
	int y[4];
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=0; i<n; i++)
		scanf("%s",s[i]);
	int count=0;
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
		{
			if(s[i][j]=='*')
			{
				x[count]=i;
				y[count]=j;
				count++;
			}
		}
	int r,c;
	r=x[0];
	c=y[0];

	for(i=1; i<=2; i++)
	{
		r=r^x[i];
		c=c^y[i];
	}

	printf("%d %d\n",r+1,c+1);

	return 0;
}
