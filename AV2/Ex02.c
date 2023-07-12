/*Implementar uma função recursiva que, dada uma lista encadeada L, do tipo TLista, e um número inteiro n, remova de L
todos os valores maiores do que n.*/
//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//definição de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

//protótipos das funções
int inserir (TLista *L, int numero);
void exibir (TLista L);
int remover (TLista *L, int numero);
int menu ();

void main ()
{
	//declaração de variáveis
	TLista L = NULL;  //representando a lista inicialmente vazia
	int num1, op, quant;

	do
	{
		system ("CLS");		//limpar tela    clrscr();

		//exibindo o menu ao usuário
		op = menu ();

		//verificando a opção escolhida
		switch (op)
		{
			//Inserção
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num1);

			        //chamando a função
			        if (inserir (&L, num1) == TRUE)
			        {
			        	printf ("\n\tInsercao realizada com sucesso!");
			        	exibir (L);
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Remover valores maiores que N
			case 2:  printf ("\nEntre com o valor de N para remover os números maiores que ele: ");
			         scanf ("%d", &num1);
			         remover(&L, num1);
			         exibir (L);
			         
					break;

			//Saída
			case 3: printf ("\n\nPrograma finalizado!");
			        break;

			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}

		system ("PAUSE");
	}
	while (op != 3);
}

int inserir (TLista *L, int numero)
{
	//declaração de variáveis
	TLista aux;

	//Passo 1: alocar memória para o novo valor
	aux = malloc (sizeof(TNo));

	//verificar se a memória foi alocada
	if (!aux)
	{
		return FALSE;
	}
	else
	{
		//Passo 2: inserir o novo valor no campo 'valor' da memória rcém-alocada
		aux->valor = numero;

		//Passo 3: fazer com que o campo 'prox' da memória recém-alocada
		//aponte para o "antigo" primeiro nó da lista
		aux->prox = *L;

		//Passo 4: Faz a lista apontar para o novo nó
		*L = aux;

		return TRUE;
	}
}
void exibir (TLista L)
{
	//declaração de variáveis
	TLista aux;

	//verificando se a lista está vazia
	//if (L == NULL)
	if (!L)
	{
		printf ("\n\nLista vazia!\n");
	}
	else
	{
		printf ("\n\nLista: ");

		//fazendo 'aux' apontar para o primeiro nó
		aux = L;

		//percorrendo toda a lista
		//while (aux != NULL)
		while (aux)
		{
			//exibindo cada elemento da lista
			printf ("%d ", aux->valor);

			//atualizar o aux
			aux = aux->prox;
		}
	}
}

int remover(TLista *L, int numero) 
{
    if (*L == NULL) 
	{
        return FALSE;
    }

    if ((*L)->valor > numero) 
	{
        TLista aux = *L;
        *L = (*L)->prox;
        free(aux);
        return remover(L, numero); 
    }
	return remover(&(*L)->prox, numero);
}


int menu ()
{
	//declaração de variáveis
	int opcao;

	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Remover valores maiores que N\n");
	printf ("(3) Sair\n\n");

	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);

	//retornando a opção escolhida
	return opcao;
}

