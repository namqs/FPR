//Faça uma função de M[8][5], que gere sua transposta

#include <stdio.h>

#define L 8
#define C 5

void exibirVelha(int matriz[L][C]);
//void preencher (int m[L][C]);
void exibirNova(int transposta[C][L]);
void transpor(int matriz[L][C], int transposta[C][L]);


void main ()
{
  int m[L][C], m2[C][L];

  //preencher(m);
  exibirVelha (m);
  transpor (m, m2);
  exibirNova (m2);

}
/*
void preencher (int m[L][C])
{
  int i, j;

  srand (time(NULL)); //para as sequencias serem diferentes

  for (i=0;i<L;i++)
  {
    for (j=0;i<C;j++)
    {
      m[i][j] = rand()%100 +1;
    }
  }
}*/
void exibirVelha(int matriz[L][C])
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

void exibirNova(int transposta[C][L])
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
