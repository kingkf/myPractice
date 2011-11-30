/*
ID: jin_pai1
LANG: C
TASK: calfflac
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct max {
    int m;
    int start;
    int end;
};

void clean(char str[88], char b[88], int p, int q)
{
    int i;
    int j;

    j = 0;
    for (i = p; i <= q; i++) {
	if ((str[i] >= 'a' && str[i] <= 'z')
	    || (str[i] >= 'A' && str[i] <= 'Z')) {
	    if (str[i] >= 'a') {
		b[j] = str[i] - 32;
		j++;
	    } else {
		b[j] = str[i];
		j++;
	    }
	}
    }
    b[j] = '\0';
}




int pal(char temp[88], int p, int q)
{
    if (p >= q)
	return 1;
    else {
	if (temp[p] != temp[q])
	    return 0;
	else
	    return pal(temp, p + 1, q - 1);
    }
}

int count(char str[88], int p, int q)
{
    int i;
    int j = 0;

    for (i = p; i <= q; i++) {
	if ((str[i] >= 'a' && str[i] <= 'z')
	    || (str[i] >= 'A' && str[i] <= 'Z'))
	    j++;
    }

    return j;
}

int main(void)
{
    FILE *fin = fopen("calfflac.in", "r");
    FILE *fout = fopen("calfflac.out", "w");
    char str[88];
    char temp[88];
    int i, j;
    int ispal=0;
    int length;
    struct max maxpal;

    memset(str, 0, sizeof(str));
    while (fgets(str, sizeof(str), fin)) {
	/* printf("%s\n",str); */
	maxpal.m = 1;
	maxpal.start = 0;
	maxpal.end = 0;
    ispal = 0;
	for (i = 0; i < strlen(str); i++) {
	    if ((str[i] >= 'a' && str[i] <= 'z')
		|| (str[i] >= 'A' && str[i] <= 'Z')) {

		for (j = i + 1; j < strlen(str); j++)
		    if (abs(str[i] - str[j]) == 0
			|| abs(str[i] - str[j]) == 32) {

			memset(temp, 0, sizeof(temp));
			clean(str, temp, i, j);
			ispal = pal(temp, 0, strlen(temp)-1);
            //printf("##### %d %s\n",ispal,temp);
			if (ispal == 1) {
                //printf("^^^%d %s\n",ispal,temp);
			    length = count(str, i, j);
			    if (length > maxpal.m) {
				maxpal.m = length;
				maxpal.start = i;
				maxpal.end = j;
			    }
			}
		    }
	    }
	}
	fprintf(fout, "%d\n", maxpal.m);
	for (i = maxpal.start; i <= maxpal.end; i++)
	    fprintf(fout, "%c", str[i]);
	fputs("\n", fout);
	/* 
	   printf("%d\n",maxpal.m);
	   for(i=maxpal.start; i<=maxpal.end; i++)
	   printf("%c",str[i]);
	   printf("\n");
	 */
	memset(str, 0, sizeof(str));
    }

    return 0;
}
