/*Implementar uma fun��o recursiva que, dada uma lista encadeada L, do tipo TLista, e um n�mero inteiro n, remova de L
todos os valores maiores do que n.*/
//importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//defini��o de constantes
#define TRUE 1
#define FALSE 0

//defini��o de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

//prot�tipos das fun��es
int inserir (TLista *L, int numero);
void exibir (TLista L);
int remover (TLista *L, int numero);
int menu ();

void main ()
{
	//declara��o de vari�veis
	TLista L = NULL;  //representando a lista inicialmente vazia
	int num1, op, quant;

	do
	{
		system ("CLS");		//limpar tela    clrscr();

		//exibindo o menu ao usu�rio
		op = menu ();

		//verificando a op��o escolhida
		switch (op)
		{
			//Inser��o
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num1);

			        //chamando a fun��o
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
			case 2:  printf ("\nEntre com o valor de N para remover os n�meros maiores que ele: ");
			         scanf ("%d", &num1);
			         remover(&L, num1);
			         exibir (L);
			         
					break;

			//Sa�da
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
	//declara��o de vari�veis
	TLista aux;

	//Passo 1: alocar mem�ria para o novo valor
	aux = malloc (sizeof(TNo));

	//verificar se a mem�ria foi alocada
	if (!aux)
	{
		return FALSE;
	}
	else
	{
		//Passo 2: inserir o novo valor no campo 'valor' da mem�ria rc�m-alocada
		aux->valor = numero;

		//Passo 3: fazer com que o campo 'prox' da mem�ria rec�m-alocada
		//aponte para o "antigo" primeiro n� da lista
		aux->prox = *L;

		//Passo 4: Faz a lista apontar para o novo n�
		*L = aux;

		return TRUE;
	}
}
void exibir (TLista L)
{
	//declara��o de vari�veis
	TLista aux;

	//verificando se a lista est� vazia
	//if (L == NULL)
	if (!L)
	{
		printf ("\n\nLista vazia!\n");
	}
	else
	{
		printf ("\n\nLista: ");

		//fazendo 'aux' apontar para o primeiro n�
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
	//declara��o de vari�veis
	int opcao;

	//exibindo o meu ao usu�rio
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Remover valores maiores que N\n");
	printf ("(3) Sair\n\n");

	//lendo a op��o do usu�rio
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);

	//retornando a op��o escolhida
	return opcao;
}

