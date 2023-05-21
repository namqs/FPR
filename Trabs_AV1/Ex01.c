/*Dada uma matriz MLINHAxCOLUNA, onde LINHA e
COLUNA são constantes, e uma coluna C,
desenvolver uma função que desloque todos os
elementos da coluna C para a última coluna da
matriz.
Consequentemente, as colunas C+1 à última
deverão serão deslocadas uma posição para a
esquerda, conforme ilustrado no exemplo
abaixo:*/
#include <stdio.h>

#define L 5
#define C 5

void preencherM(int m[L][C]);
void exibir(int matriz[L][C]);
int deslocar(int matriz[L][C], int col);

int main ()
{
  int m[L][C];
  int coluna;

  preencherM(m);
  printf("Informe qual coluna deseja colocar como última: ");
  scanf("%i", &coluna);
  printf("\nMatriz antes: \n");
  exibir(m);
  deslocar (m, coluna);
  printf("\nMatriz depois: \n");
  exibir(m);


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

int deslocar (int matriz[L][C], int col)
{
    int i, j, aux=0;

        //verificando se o numero da Coluna é válido
        if ((col < C) && (col >= 0))
          {
            for (i=0; i<L; i++)
            {
              aux = matriz[i][col]; //guardando o numero em variavel aux

              for (j=col; j<C-1; j++) //coluna começa a ser percorrida a partir da C digitada e para na penultima
              {
                matriz[i][j] = matriz[i][j + 1]; //passando o valor do proximo para a esquerda
              }

              matriz[i][C - 1] = aux; //atribui o valor desejado na ultima
            }
            return 1;
          }
          else
            {
                return 0;
            }
}
