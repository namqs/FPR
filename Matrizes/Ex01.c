#include <stdio.h> //Desenvolver uma função que altere os todos os valores de uma Matriz [10][5] pra zero

//definindo constantes
#define L 10
#define C 5

//protótipo funções
void zerar (int matriz[L][C]);
void exibir (int matriz[L] [C]);

void main ()
{
  int M [L][C];

    exibir(M);
    zerar (M);
    exibir (M);
}

void zerar (int matriz[L][C])
{

  int i, j;

  for (i=0; i<L; i++)
  {
    for (j=0; j<C; j++)
    {
      matriz[i][j] = 0;
    }
  }
}

void exibir (int matriz[L] [C])
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
}
