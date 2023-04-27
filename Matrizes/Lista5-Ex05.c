/*Implementar uma função que, dada uma matriz
M10×8, gere um vetor V de tamanho 8, onde
cada elemento do vetor consiste na soma dos
elementos de uma coluna de M. Ou seja, o
elemento V[0] consiste na soma dos elementos
da primeira coluna de M, o elemento V[1]
consiste na soma dos elementos da segunda
coluna de M, e assim por diante.*/
#include <stdio.h>

#define L 10
#define C 8

void preencherM(int m[L][C]);
void exibir(int matriz[L][C]);
void preencherV(int matriz[L][C], int vet[C]);
void exibirV(int vet[C]);

int main ()
{
  int m[L][C];
  int vetor[C];
  
  preencherM(m);
  exibir(m);
  preencherV(m, vetor);
  exibirV(vetor);
  
  return 0;
}

void preencherM(int m[L][C])
{
  int i, j;

  //garantindo que as sequências aleatórias são diferentes
  srand (time(NULL));

  //percorrendo as linhas da matriz
  for (i=0;i<L;i++)
  {
    //percorrendo as colunas da matriz
    for (j=0;j<C;j++)
    {
      m[i][j] = rand()%9 + 1;   //inserindo valores de 1 a 9 na matriz
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

void preencherV(int matriz[L][C], int vet[C])
{
  int i, j;

  for (j=0; j<C; j++)
  {
    int soma = 0;
    for (i=0; i<L; i++)
    {
      soma = soma + matriz[i][j];
    }
    vet[j] = soma;
  }
}

void exibirV(int vet[C])
{
  int i;

  for (i=0; i<C; i++)
  {
    printf("%d ", vet[i]);
  }
  printf("\n");
}
