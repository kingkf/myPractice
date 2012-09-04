#include <stdio.h>

void insertsort(int a[], int n)
{
	int i, j;
	int key;

	for (i=1; i<n; i++) {
		key = a[i];
		j = i-1;

		while (j>=0&&a[j]>key) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}

int main()
{
	int a[10];
	int i;

	for (i=0; i<10; i++)
		scanf("%d", &a[i]);

	insertsort(a, 10);
	printf("Insertsort Result:\n");

	for (i=0; i<10; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}
