#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

void swap(int *p1, int *p2)
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int randomPartition(int a[], int n)
{
	int m;

	m = rand();
	printf("m: %d\n",m);
	int r = m%n;
	printf("r: %d\n", r);
	swap(&a[n-1], &(a[r]));
	printf("after: \n");
	int i;
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
	int x = a[n-1];

	int j;
	j = -1;
	for (i=0; i<n; i++) {
		if (a[i] < x) {
			j++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[j+1], &a[n-1]);

	return j+1;
			
}


void findK(int a[], int n, int k)
{
	int p = randomPartition(a,n);
	printf("partition: %d\n", p);
	printf("after p: \n");
	int i;
	for (i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
	if (p+1 == k)
		return ;
	else if (p+1 > k)
		findK(a, p+1, k);
	else
		findK(&a[p+1], n-p-1, k-p-1);
}

int main()
{
	int a[N];
	int n;
	int k;
	srand((unsigned int)time(NULL));

	scanf("%d%d", &n, &k);
	int i = 0;
	for (i=0; i<n; i++) 
		scanf("%d",&a[i]);

	findK(a,n,k);
	for(i=0; i<k; i++)
		printf("%d ", *(a+i));
	printf("\n");

	return 0;
}
