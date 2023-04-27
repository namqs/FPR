/* Desenvolver uma função que, dada uma matriz
M15×20, determine se um número X se encontra
na linha L da matriz.*/

#include <stdio.h>

#define L 15
#define C 20

void preencherMatriz (int m[L][C]);
void exibir(int matriz[L][C]);
int buscar (int matriz[L][C], int num, int linha);

void main ()
{
  int m [L][C];
  int n, linha;

    printf("Entre com o numero a ser procurado: ");
    scanf("%d", &n);
    printf("Digite a linha que ele deve ser procurado: ");
    scanf("%d", &linha);
    preencherMatriz(m);
    exibir(m);
   
    if (buscar (m, n, linha) ==1)
    {
      printf("o numero foi encontrado.");
    } else
    {
      printf("o numero nao foi encontrado.");
    }
    
      
}

void preencherMatriz (int m[L][C])
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
			m[i][j] = rand()%20 + 1;   //inserindo valores de 1 a 20 na matriz
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

int buscar (int matriz[L][C], int num, int linha)
{
  int j;
  
    for (j=0; j<C; j++)
      {
        if (matriz[linha][j]==num)
        {
          return 1;
        }
      }
    return 0;
}
