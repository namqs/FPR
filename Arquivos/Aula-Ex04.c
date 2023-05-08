//copiar um arq pro outro
#include <stdio.h>

int copiarArquivo (char nomeArqDestino[], char nomeArqOrigem[]);

void main  ()
{
	int retorno = copiarArquivo ("novo.txt", "numeros.txt");
	
	//veificando retorno
	if (retorno ==1)
	{
		printf("Arquivo copiado com sucesso!");
	}
	else
	{
		printf("O arquivo n foi copiado com sucesso");
	}
}

int copiarArquivo (char nomeArqDestino[], char nomeArqOrigem[])
{
	FILE *arqO, *arqD;
	int numero;
	
	//abrindo
	arqD = fopen (nomeArqDestino, "w"); 
	arqO = fopen (nomeArqOrigem, "r");
	
	//verificando se houve erro na abertura
	if ((!arqD) || (!arqO))
	{
		return 0;
	} else
	{
		while(fscanf (arqO,"%d", &numero !=EOF))
		{
			fprintf(arqD, "%d\n", numero);
		}
		fclose (arqO);
		fclose (arqD);
		return 1;
	}
	
}
