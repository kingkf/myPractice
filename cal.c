#include <stdio.h>

#define MAXLINE 100

/*simple calculate*/

double atof(char []);
int getLine(char line[], int max);

int main()
{
	double sum;
	char line[MAXLINE];

	sum = 0;
	while (getLine(line, MAXLINE) > 0)
		printf("\t%g\n", sum += atof(line));

	return 0;
}
