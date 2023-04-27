/*Fazer uma função que, dada uma matriz M6×6,
determine se ela é simétrica. simetrica = qnd a matriz transposta eh igual*/


#include <stdio.h>

#define L 6
#define C 6

void preencher(int m[L][C]);
void exibir(int transposta[C][L]);
void transpor(int matriz[L][C], int transposta[C][L]);
int conferir(int matriz[L][C], int transposta[C][L]);


void main ()
{
  int m[L][C], m2[C][L];

  preencher(m);
  transpor (m, m2);
  exibir (m2);
  if (conferir (m, m2) ==1)
    {
      printf("É simétrica!");
    } else
    {
      printf("Não é simétrica.");
    }

}

void preencher(int m[L][C])
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
void transpor(int matriz[L][C], int transposta[C][L])
{
  int i, j;

    for(i=0; i<C; i++)
    {
      for(j=0; j<L; j++)
      {
        transposta[i][j] = matriz[i][j];
      }
    }
}

void exibir(int transposta[C][L])
{
  int i, j;

    for (i=0; i<C; i++)
    {
      for(j=0; j<L; j++)
      {
        printf("%3d ", transposta[j][i]);
      }
      printf("\n");
    }
    printf("\n\n");
}

int conferir(int matriz[L][C], int transposta[C][L])
{
  int i, j, aux=0;

    for (i=0;i<C; i++)
      {
        for (j=0; j<L; j++)
          {
            if (matriz[i][j] != transposta[i][j])
             aux++;
          }
      }
  return aux;
}
