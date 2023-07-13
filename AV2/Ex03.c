/*
Implementar uma função que, dada uma lista encadeada L, do tipo TLista, e um número inteiro n, determine se todos
os valores inferiores ou maiores do que n estão nos primeiros nós de L, assim como os maiores ao final da lista.

Notas: caso todos os valores da lista sejam menores ou iguais a n, a função deverá retornar 1; o mesmo aplica-
se quando todos os elementos forem maiores do que n.
*/
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
int inserir(TLista* L, int numero);
void exibir(TLista L);
int verificar(TLista L, int numero);
int menu();

int main()
{
	TLista L = NULL;
	int num1, op;

	do
	{
		system("CLS"); 	//limpar tela    clrscr();

		op = menu(); //exibindo o menu ao usuário

		//verificando a opção escolhida
		switch (op)
		{
			case 1:
				printf("Entre com o valor a ser inserido: ");
				scanf("%d", &num1);

				if (inserir(&L, num1) == TRUE)
				{
					printf("Insercao realizada com sucesso!\n");
				}
				else
				{
					printf("ERRO: insercao nao realizada!\n");
				}
				break;

			case 2:
				printf("Digite o valor de N: ");
				scanf("%d", &num1);
				exibir(L);

				if (verificar(L, num1) == TRUE)
				{
					printf("\nTodos os valores inferiores ou maiores que N estao nos primeiros nos e os maiores no final.\n");
				}
				else
				{
					printf("\nA lista nao esta conforme o desejado.\n");
				}
				break;

			case 3:
				printf("Programa finalizado!\n");
				break;

			default:
				printf("Opcao invalida! Tente novamente.\n");
		}

		system("PAUSE");
	} while (op != 3);

	return 0;
}

int inserir(TLista* L, int numero)
{
	TLista aux;

	aux = malloc(sizeof(TNo));

	if (!aux)
	{
		return FALSE;
	}
	else
	{
		aux->valor = numero;
		aux->prox = *L;
		*L = aux;

		return TRUE;
	}
}

void exibir(TLista L)
{
	TLista aux;

	if (!L)
	{
		printf("Lista vazia!\n");
	}
	else
	{
		printf("Lista: ");

		aux = L;

		while (aux)
		{
			printf("%d ", aux->valor);
			aux = aux->prox;
		}

		printf("\n");
	}
}

int verificar(TLista L, int numero)
{
	TLista aux;
	int cont=0, tam=0;

	if (!L)
	{
		printf("Lista vazia!\n");
		return FALSE;
	}

	aux = L; //fazendo 'aux' apontar para o primeiro nó

	while (aux) //descobrir o tamanho da lista pra determinar uma referencia de "meio"
	{
		tam++; 
		aux = aux->prox;
	}

	aux = L;

	while (aux && cont < tam / 2) //enquanto estiver no inicio da lista
	{
		if (aux->valor > numero && aux->prox->valor > numero) //se o valor do nó for maior e o prox tambem, entao a condição nao ta verdadeira
		{
			return FALSE;
		}

		aux = aux->prox;
		cont++;
	}

	return TRUE;
}

int menu()
{
	int opcao;

	printf("Menu de Operacoes:\n\n");
	printf("(1) Inserir\n");
	printf("(2) Verificar condicao\n");
	printf("(3) Sair\n\n");

	printf("Entre com a sua opcao: ");
	scanf("%d", &opcao);

	return opcao;
}


