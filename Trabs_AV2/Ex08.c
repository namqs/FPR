/*
Fazer uma função que, dada uma Fila F, do tipo
TLista, e dois valores inteiros num1 e num2,
remova da fila todos os valores pertencentes ao
intervalo definido por num1 e num2, inclusive.
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
int enfilar (TLista *F, TLista *U, int numero);
int desenfilar (TLista *F, TLista *U, int *numero);
int primeiro (TLista F, int *p);
void removerIntervalo(TLista *F, TLista *U, int num1, int num2);

int menu ();

//main
void main ()
{
	//declaração de variáveis
	TLista F = NULL, U = NULL;  //representando a pilha inicialmente vazia
	int numero, op;

	do
	{
		system ("CLS");		//limpar tela    clrscr();

		//exibindo o meu ao usuário
		op = menu ();

		//verificando a opção escolhida
		switch (op)
		{
			//Enfilar
			case 1: printf ("\nEntre com o valor a ser enfilado: ");
			        scanf ("%d", &numero);

			        //chamando a função
			        if (enfilar (&F, &U, numero) == TRUE)
			        {
			        	printf ("\n\tInsercao realizada com sucesso na fila!\n");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada na fila!\n");
					}
					break;

			//Desenfilar
			case 2: //chamando a função
			        if (desenfilar (&F, &U, &numero) == TRUE)
			        {
			        	printf ("\n\tO numero %d foi desenfilado\n", numero);
					}
					else
					{
						printf ("\n\tERRO: Fila vazia!");
					}
					break;

			//Primeiro
			case 3: //chamando a função
			        if (primeiro (F, &numero) == TRUE)
			        {
			        	printf ("\n\tPrimeiro elemento da fila: %d\n", numero);
					}
					else
					{
						printf ("\n\tERRO: Fila vazia!");
					}
					break;

            //Remover intervalo
            case 4:
                printf("\nEntre com o valor do primeiro número do intervalo: ");
                scanf("%d", &numero);
                int num1 = numero;

                printf("Entre com o valor do segundo número do intervalo: ");
                scanf("%d", &numero);
                int num2 = numero;

                removerIntervalo(&F, &U, num1, num2);
                printf("\n\tValores dentro do intervalo [%d, %d] removidos da fila!\n", num1, num2);
                break;

			//Saída
			case 5: printf ("\n\nPrograma finalizado!");
			        break;

			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}

		system ("PAUSE");
	}
	while (op != 5);
}

//implementação das funções

//inserindo no início da lista
int enfilar (TLista *F, TLista *U, int numero)
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
		//Passo 2: inserir o novo valor no campo 'valor' da memória recém-alocada
		aux->valor = numero;

		//Passo 3: fazer o campo 'prox' do novo nó apontar para NULL
		aux->prox = NULL;

		//Passo 4: fazer o 'antigo último elemento' apontar para o novo nó
		if (*U)
		{
			(*U)->prox = aux;
		}
		else
		{
			*F = aux;
		}

		//Passo 5: atualizar o ponteiro 'U'
		*U = aux;   //ou   *U = (*U)->prox;

		return TRUE;
	}
}

int desenfilar (TLista *F, TLista *U, int *numero)
{
	//declaração de variáveis
	TLista aux;

	//verificando se a fila está vazia
	//if (*F == NULL)
	if (!(*F))
	{
		return FALSE;
	}
	else
	{
		aux = *F;
		*F = aux->prox;  //ou   *F = (*F)->prox;

		//verificando se a fila se tornou nula. Ou seja,
		//foi removido o seu último elemento
		if (!(*F))
		{
			*U = NULL;
		}

		//salvando em 'numero' o valor que era o primeiro da fila
		*numero = aux->valor;

		free (aux);

		return TRUE;
	}
}

int primeiro (TLista F, int *p)
{
	//verificando se a fila está vazia
	if (!F)
	{
		return FALSE;
	}
	else
	{
		*p = F->valor;

		return TRUE;
	}
}
void removerIntervalo(TLista *F, TLista *U, int num1, int num2)
{
    TLista atual = *F;
    TLista anterior = NULL;
    TLista temp;

    while (atual != NULL)
        {
        if (atual->valor >= num1 && atual->valor <= num2)
        {
            if (anterior == NULL)
            {
                *F = atual->prox;
            } else
                {
                    anterior->prox = atual->prox;
                }

            if (atual->prox == NULL)
            {
                *U = anterior;
            }

            temp = atual;
            atual = atual->prox;
            free(temp);
        } else
            {
                anterior = atual;
                atual = atual->prox;
            }
    }
}


int menu ()
{
	//declaração de variáveis
	int opcao;

	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Enfilar\n");
	printf ("(2) Desenfilar\n");
	printf ("(3) Primeiro\n");
	printf("(4) Remover intervalo\n");
	printf ("(5) Sair\n\n");

	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);

	//retornando a opção escolhida
	return opcao;
}
