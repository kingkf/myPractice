#include <stdio.h>

int main()
{
	int a = 0b11111111110000000000111111111100;
	short b = 0b0111111111111111;
	int c = 0b11111111110000000000111111111100;
	int e = 0b01111111111111111111111111111111;
	short d = c;
	//printf("%d\n",c-1);
	c = b;
	printf("%d\n",b);
	printf("%d\n",c);
	printf("%d\n",d);
	printf("%d\n",e);

	a=b;
	printf("%d\n", a);
	printf("%d\n", sizeof(int*));

	return 0;
}
