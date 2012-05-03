#include <stdio.h>

void inplace_swap(int *x, int *y)
{
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

void swap2(int *x, int *y)
{
	int *temp;
	temp = x;
	x = y;
	y = temp;
}

int main()
{
	int x=3;
	int y=4;

	short int b = 0b1100111111000111;
	char a = 0b11111111;

	printf("%d\n",b);

//	inplace_swap(&x, &y);
	swap2(&x,&y);
	printf("%d %d\n",x,y);

	return 0;
}
