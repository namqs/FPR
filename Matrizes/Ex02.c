//Desenvolver uma função que armazene o valor 1 em todas as posições da 1° com 1 da 2° com 2 e por ai vai
#include <stdio.h>

#define L 20
#define C 15

void preencher (int matriz[L][C]);
void exibir (int matriz[L][C]);

void main ()
{
  int m[L][C];

  exibir (m);
  preencher (m);
  exibir (m);
}

void exibir (int matriz[L][C])
{
  int i, j;

    for (i=0; i<L; i++)
    {
      for (j=0; j<C; j++)
      {
        printf("%d ", matriz[i][j]);
      }
      printf("\n");
    }
    printf("\n\n");
}

void preencher (int matriz[L][C])
{
  int i, j;

    for (i=0; i<L; i++)
    {
      for (j=0; j<C; j++)
      {
        matriz[i][j] = i+1;
      }
    }
}
