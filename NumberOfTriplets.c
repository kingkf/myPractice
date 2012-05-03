#include <stdio.h>
#include <string.h>
#include <math.h>

struct coordinate
{
	int x;
	int y;
};

int zxzy[1001][1001];
int zyfx[1001][1001];
int fxfy[1001][1001];
int fyzx[1001][1001];
struct coordinate num[3001];

int main()
{
	int n;
	scanf("%d",&n);
	int i,j;

	for(i=0; i<n; i++)
	{
		scanf("%d%d",&(num[i].x),&(num[i].y));
		if(num[i].x>=0 && num[i].y>=0)
			zxzy[num[i].x][num[i].y]=1;
		else if(num[i].x<=0 && num[i].y>=0)
			zyfx[abs(num[i].x)][num[i].y]=1;
		else if(num[i].x<=0 && num[i].y<=0)
			fxfy[abs(num[i].x)][abs(num[i].y)]=1;
		else if(num[i].x>=0 && num[i].y<=0)
			fyzx[num[i].x][abs(num[i].y)]=1;
	}

	int midx,midy;
	int count=0;

	for(i=0; i<n; i++)
		for(j=i+1; j<n; j++)
		{
			if( (num[i].x+num[j].x)%2==0 && (num[i].y+num[j].y)%2==0)
			{
				midx=(num[i].x+num[j].x)/2;
				midy=(num[i].y+num[j].y)/2;
				if(midx>=0 && midy>=0)
				{
					if(zxzy[midx][midy]==1)
						count++;
				}
			    else if(midx<=0 && midy>=0)
				{
			    	if(zyfx[abs(midx)][midy]==1)
			    		count++;
				}
				else if(midx<=0 && midy<=0)
				{
					if(fxfy[abs(midx)][abs(midy)]==1)
						count++;
				}
				else if(midx>=0 && midy<=0)
				{
					if(fyzx[midx][abs(midy)]==1)
						count++;
				}
			}
		}

	printf("%d\n",count);

	return 0;
}



