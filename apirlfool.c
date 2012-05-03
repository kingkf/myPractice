#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);

	switch(a)
	{
		case 1:
			printf("2\n");
			break;
		case 2:
			printf("3\n");
			break;
		case 3:
			printf("1\n");
			break;
		case 5:
			printf("1\n");
			break;
		default:
			printf("%d\n",a-2);
			break;
	}

	return 0;
}

