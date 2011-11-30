#include<stdio.h>
#include<string.h>

int pal (char str[88], int p, int q)
{
  if (p >= q)
    return 1;
  else
    {
      if (str[p] != str[q])
	return 0;
      else
	return pal (str, p + 1, q - 1);
    }
}

int main(void)
{
    char a[88];
    memset(a,0,sizeof(a));

    scanf("%s",a);
    printf("%d\n",pal(a,0,strlen(a)-1));

    return 0;
}
