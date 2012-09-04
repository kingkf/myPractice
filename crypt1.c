/*
ID: jin_pai1
LANG: C
TASK: crypt1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isvalid(int isused[], int num)
{
	while(num)
	{
		if (isused[num%10]==0)
			return 0;
		num=num/10;
	}
	return 1;
}

int isvalid1(int isused[], int num)
{
	int c=0;
	while(num)
	{
		if (isused[num%10]==0)
			return 0;
		num=num/10;
		c++;
	}
	if (c!=3)
		return 0;
	else
		return 1;
}

int isvalid2(int isused[], int num)
{
	int c=0;
	while(num)
	{
		if (isused[num%10]==0)
			return 0;
		num = num/10;
		c++;
	}

	if (c!=4)
		return 0;
	else
		return 1;
}
int main()
{
	FILE *fin = fopen("crypt1.in", "r");
	FILE *fout = fopen("crypt1.out", "w");

	int n;
	int i,j;
	int temp;
	int isused[10];

	memset(isused, 0, sizeof(isused));
	fscanf(fin, "%d", &n);
	int count = 0;
	for (i=0; i<n; i++)
	{
		fscanf(fin, "%d", &temp);
		isused[temp]=1;
	}

	for (i=100; i<=999; i++)
	{
		if(isvalid(isused, i))
		{
			for (j=10; j<=99; j++)
			{
				if (isvalid(isused, j))
				{
					temp = j%10*i;
					if (isvalid1(isused, temp))
					{
						temp = j/10*i;
						if (isvalid1(isused, temp))
						{
							temp = j*i;
							if (isvalid2(isused, temp))
								count++;
						}
					}
				}
			}
		}
	}

	fprintf(fout,"%d\n", count);

	return 0;
}
						

