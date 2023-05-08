#include <stdio.h>

//protótipos das funções
int copiarArquivo (char nomeArqDestino[], char nomeArqOrigem[]);

//main
void main ()
{
	//declaração de variáveis
	char nomeArq1[20], nomeArq2[20];
	
	//lendo os nomes dos arquivos
	printf ("Entre com o arquivo de origem: ");
	fflush (stdin);
	gets (nomeArq1);
	
	printf ("Entre com o arquivo de destino: ");
	fflush (stdin);
	gets (nomeArq2);
	
	//chamando a função
	if (copiarArquivo (nomeArq2, nomeArq1))
	{
		printf ("Arquivo copiado com sucesso!");
	}
	else
	{
		printf ("Erro na copia entre os arquivos.");
	}
}

//implementação das funções
int copiarArquivo (char nomeArqDestino[], char nomeArqOrigem[])
{
	//declaração de variáveis
	FILE *arqO, *arqD;
	char caracter;
	
	//abrino os arquivos
	arqD = fopen (nomeArqDestino, "w");
	arqO = fopen (nomeArqOrigem, "r");
	
	//verificando se houve erro na abertura dos arquivos
	if ((!arqD) || (!arqO))
	{
		return 0;
	}
	else
	{
		//lendo todos os caracteres do arquivo de origem...
		while (fscanf (arqO, "%c", &caracter) != EOF)
		{
			//... e copiando para o arquivo de destino
			fprintf (arqD, "%c", caracter);
		}
		
		//fechando os arquivos
		fclose (arqO);
		fclose (arqD);
		
		return 1;
	}
}
