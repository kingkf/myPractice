#include <stdio.h>
#define N 10

void swap(int *p1, int *p2)
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int partition(int a[], int p, int q)
{
	int i, j;
	int key;

	i=p;
	j=p-1;
	key = a[p];
	while (i<q) {
		if (a[i] <= key) {
			j++;
			swap(&a[i], &a[j]);
		}
		i++;
	}
	swap(&a[j], &a[p]);
	return j;
}


	
void quicksort(int a[], int p, int q)
{
	if (p < q) {
	int r;
	r = partition(a, p, q);
	quicksort(a, p, r);
	quicksort(a, r+1, q);
	}
}
int main()
{
	int a[N];
	int i;

	for (i=0; i<N; i++)
		scanf("%d", &a[i]);

	quicksort(a, 0, N);
	printf("Quicksort Result:\n");
	for (i=0; i<N; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}

