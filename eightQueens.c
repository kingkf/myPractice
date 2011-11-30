#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 8
int count = 0;

int
isOk (int queens[N][N], int row, int col)
{
  int i, j;
  /*  printf("okokokok\n");
     for(i=0; i<N; i++)
     {
     for(j=0; j<N; j++)
     printf("%d ",queens[i][j]);
     printf("\n");
     }
     printf("%d %d\n",row,col);
   */

  i = row;
  j = col;
  while (i >= 0 && j >= 0)
    {
      if (queens[i][j] == 1)
	return 0;
      i--;
      j--;
    }

  i = row;
  j = col;
  while (i < N && j < N)
    {
      if (queens[i][j] == 1)
	return 0;
      i++;
      j++;
    }

  i = row;
  j = col;
  while (i >= 0 && j < N)
    {
      if (queens[i][j] == 1)
	return 0;
      i--;
      j++;
    }

  i = row;
  j = col;
  while (i < N && j >= 0)
    {
      if (queens[i][j] == 1)
	return 0;
      i++;
      j--;
    }

  i = row;
  j = col;
  while (i < N)
    {
      if (queens[i][j] == 1)
	return 0;
      i++;
    }
  i = row;
  while (i >= 0)
    {
      // printf("kkk %d\n",queens[i][j]);
      if (queens[i][j] == 1)
	{
	  //printf("sb\n");
	  return 0;
	}
      i--;
    }

  return 1;
}

void
place (int queens[N][N], int row)
{
  int i, j, k;
  int isPlace;
  if (row == N)
    {
      count++;
      printf ("***number: %d\n", count);
      for (i = 0; i < N; i++)
	{
	  for (j = 0; j < N; j++)
	    printf ("%d ", queens[i][j]);
	  printf ("\n");
	}
      return;
    }

  isPlace = 0;
  for (i = 0; i < N; i++)
    {
      //  printf("^^^^^%d\n",isOk(queens,row,i));
      /* printf("Before isOk\n");
         for(j=0; j<N; j++)
         {
         for(k=0; k<N; k++)
         printf("%d ",queens[j][k]);
         printf("\n");
         }
         printf("@@@@@%d\n",row);
       */
      if (isOk (queens, row, i))
	{
	  isPlace = 1;
	  queens[row][i] = 1;
	  /* printf("After isOk\n");
	     for(j=0; j<N; j++)
	     {
	     for(k=0; k<N; k++)
	     printf("%d ",queens[j][k]);
	     printf("\n");
	     }
	   */
	  place (queens, row + 1);
	  queens[row][i] = 0;
	}
    }
  if (isPlace == 0)
    return;
}

int
main (void)
{
  int queens[N][N];
  int i;

  memset (queens, 0, sizeof (queens));
  place (queens, 0);

  printf ("total: %d\n", count);

  return 0;
}
