/*
	FAETERJ-Rio
	FPR - Fundamentos de Programação - Manhã
	Professor Leonardo Vianna
	
	Prova a compor a AV1 (Parte I) - 10/05/2023
	
	Questão 01 [2,5 pontos]:
	Considerando a existência de uma matriz de inteiros M, de ordem 
	N (ou seja, o nº de linhas e o nº de colunas são iguais a N), 
	onde N é uma constante, desenvolver uma função que retorne 1 se 
	a seguinte regra for atendida por M (caso contrário, o valor 0 
	deverá ser retornado):
	
	- A soma dos elementos da diagonal principal deve ser igual à 
	  soma dos elementos que estão acima desta diagonal, assim como 
	  à soma dos elementos abaixo da diagonal.

	Exemplo 1:

		Para a seguinte matriz, a função retornará 1: 

					6	3	1	2	6	
					1	3	5	4	2	
					3	4	4	2	2	
					5	9	1	9	3	
					4	0	2	1	8	

	Exemplo 2:

		Para a seguinte matriz, a função retornará 0: 
	
					1	8	5	9	4	
					2	5	4	6	5	
					4	1	2	3	6	
					4	5	5	8	7	
					4	2	5	6	9	
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define N 5

//protótipos das funções
void exibirMatriz (int m[N][N]);
int somarDiagonais (int m[N][N]);

//main
void main ()
{
	//declaração de variáveis
	int resp;

	int m1[N][N] = {{6, 3, 1, 2, 6},
	                {1, 3, 5, 4, 2},
	                {3, 4, 4, 2, 2},
	                {5, 9, 1, 9, 3},
	                {4, 0, 2, 1, 8}};

	int m2[N][N] = {{1, 8, 5, 9, 4},
	                {2, 5, 4, 6, 5},
	                {4, 1, 2, 3, 6},
	                {4, 5, 5, 8, 7},
	                {4, 2, 5, 6, 9}};

	//exibindo a matriz m1 antes da chamada à função
	exibirMatriz (m1);
	
	//chamando a função com m1 e atribuindo o retorno à variável 'resp'
	resp = somarDiagonais (m1);
	
	//testando o valor retornado
	if (resp == 1)
	{
		printf ("\n\nA matriz m1 atende ao especificado!");
	}
	else
	{
		printf ("\n\nA matriz m1 NAO atende ao especificado!");
	}
	
	//exibindo a matriz m2 antes da chamada à função
	exibirMatriz (m2);
	
	//chamando a função com m2 e atribuindo o retorno à variável 'resp'
	resp = somarDiagonais (m2);
	
	//testando o valor retornado
	if (resp == 1)
	{
		printf ("\n\nA matriz m2 atende ao especificado!");
	}
	else
	{
		printf ("\n\nA matriz m2 NAO atende ao especificado!");
	}
}
	
//implementação das funções
void exibirMatriz (int m[N][N])
{
	//declaração de variáveis
	int i, j;
	
	printf ("Elementos da matriz:\n\n");
	
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
		{
			printf ("%3d ", m[i][j]);
		}
		
		printf ("\n");
	}
	
	printf ("\n\n");
}

int somarDiagonais (int m[N][N])
{
	int i, j, soma1=0, soma2=0, soma3=0;
	
		//somando diagonal:
		for (i=0, j=0; i<N, j<N; i++, j++) //percorre linha E coluna juntos, pois eles variam juntos, somando a diagonal
		{
			soma1 = soma1 + m[i][j]; //guardando o valor da soma 
		}
		
		//somando parte abaixo da diagonal principal:
		for (i=1; i<N; i++)
		{
			for (j=0;j<i;j++) // a coluna correspondente sempre vai ate um numero menos q o i
			{
				soma2 = soma2 + m[i][j];
			}
		}
		
		//somando a parte acima da diagonal principal:
		for (i=0; i<N-1; i++)
		{
			for(j=i+1; j<N; j++) // o valor de J vai começar cada vez mais alto
			{
				soma3 = soma3 +m[i][j];
			}
		}
		
		if ((soma1 == soma2) && (soma2 == soma3))
		{
			return 1;
		}
		 else
		 {
			return 0;
		 }
}
