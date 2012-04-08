#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[30000][108];
int res(int len,int n)
{
	int i,j;
	int count=0;

	for(i=0; i<len; i++)
	{
		int temp=s[0][i];
		for(j=1; j<n; j++)
		{
			if(temp!=s[j][i])
				return count;
		}
		count++;
	}
	return count;
}
		
int main()
{
	int n;

	scanf("%d",&n);
	int i;
	for(i=0; i<n; i++)
		scanf("%s",s[i]);
	int len;
	len=strlen(s[0]);
	if(len>20)
		len=20;
	int count;
	count=res(len,n);
	printf("%d\n",count);

	return 0;
}

