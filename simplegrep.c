#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main()
{
	char line[MAXLINE];
	int found = 0;
	int index;

	while (getLine(line, MAXLINE) > 0) {
		index = strindex(line, pattern);
		printf("%d\n", index);
		if (index >=0) {
			printf("%s", line);
			found++;
		}
	}
	return found;
}
