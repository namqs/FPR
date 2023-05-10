/*
	FAETERJ-Rio
	FPR - Fundamentos de Programação - Manhã
	Professor Leonardo Vianna
	
	Prova a compor a AV1 (Parte I) - 10/05/2023
	
	Questão 02 [2,5 pontos]:
	Considerando a existência de um arquivo A contendo números inteiros 
	positivos, um por linha, pede-se a implementação de uma função que 
	crie um segundo arquivo, B, com as seguintes características:
	
	- Para cada valor de A, escrever em B uma linha com todos os seus 
	  divisores;
	- Para cada elemento do primeiro arquivo, apenas uma linha de 
	  divisores deve ser inserida em B.

	Exemplo:

		Arquivo A:
			10
			5
			6
			10
			8
			4
			6

		Arquivo B:
			1 2 5 10
			1 5
			1 2 3 6
			1 2 4 8
			1 2 4 
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções
int criarNovo (char nomeArqA[], char nomeArqB[]);

//main
void main ()
{
	//declaração de variáveis
	char nomeArqOriginal[20], nomeArqNovo[20];
	int retorno;
	
	//associando o arquivo "teste.txt" à variável 'nomeArqOriginal'
	strcpy (nomeArqOriginal, "teste.txt");
	
	//associando o arquivo "novo.txt" à variável 'nomeArqNovo'
	strcpy (nomeArqNovo, "novo.txt");
		
	//chamando a função e armazenando o retorno na variável 'retorno'
	retorno = criarNovo (nomeArqOriginal, nomeArqNovo);
	
	//testando o retorno
	if (retorno == 1)
	{
		printf ("\nO arquivo %s foi gerado com sucesso!", nomeArqNovo);
	}
	else
	{
		printf ("\nErro na geracao do arquivo %s.", nomeArqNovo);
	}
}
	
//implementação das funções
int criarNovo (char nomeArqA[], char nomeArqB[])
{
	int i, num;
	
	FILE *arqA, *arqB;
	
	arqA = fopen (nomeArqA, "r");
	arqB = fopen (nomeArqB, "w");
	
		if ((!arqA) || (!arqB)) // se nao abrir...
	{
		return 0;
	}
	else
	{
		//lendo os valores do arquivo
		while (fscanf (arqA, "%d", &num) != EOF)
		{
			for (i=1; i<=num; i++) // i roda todos os numeros de 1 ate  proprio num pra conferir se x eh ou nao divisor
			{
				if (num%i == 0) // se o resto da divisao de num por i for igual a zero
				{
					fprintf(arqB, "%d ", i); // printe o numero
				}
			}
		 fprintf(arqB, "\n");
		}
		
		fclose (arqA);
		fclose (arqB);
	}
}
