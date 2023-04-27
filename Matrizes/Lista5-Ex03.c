/*Desenvolver uma função que gere a seguinte
matriz M55:
1 2 3 4 5
2 3 4 5 6
3 4 5 6 7
4 5 6 7 8
5 6 7 8 9
  */

#include <stdio.h>

#define L 5
#define C 5

void preencher(int m[L][C]);
void exibir(int matriz[L][C]);

void main ()
{
  int m [L][C];
  
    preencher(m);
    exibir(m);
      
}

void preencher(int matriz[L][C])
{
  int i, j;

    for (i=0; i<L; i++)
    {
      for (j=0; j<C; j++)
        {
          matriz[i][j] = j+i+1;
        }
    }
}
void exibir(int matriz[L][C])
{
  int i, j;

    for (i=0; i<L; i++)
    {
      for(j=0; j<C; j++)
      {
        printf("%3d ", matriz[i][j]);
      }
      printf("\n");
    }
    printf("\n\n");
}
