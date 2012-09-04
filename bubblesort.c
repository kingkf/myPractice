#include <stdio.h>

void swap(int *p1, int *p2)
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void bubblesort(int a[], int n)
{
	int i, j;

	for(i=0; i<n; i++)
		for(j=1; j<n-i; j++)
			if(a[j-1]>a[j])
				swap(&a[j-1], &a[j]);
}
			
int main()
{
	int a[10];
	int i;

	for (i=0; i<10; i++)
		scanf("%d", &a[i]);
	bubblesort(a, 10);
	printf("bubble sort result:\n");
	for (i=0; i<10; i++)
	    printf("%d ", a[i]);

	printf("\n");
	


	return 0;
}
