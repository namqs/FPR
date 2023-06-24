/*Pede-se a implementação de uma função
recursiva que, dada uma lista do tipo TLista,
ordenada crescentemente, determine a
quantidade de valores distintos na lista.*/

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
void ordena(TLista *L);
void exibir (TLista L);
int contarValoresDistintos(TLista lista, int valor, int ocorreu);

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
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Determinar Valores: ordenar, exibir e determinar
			case 2:
			        //chamando as funçes
			        ordena(&L);
			        exibir (L);
			        int quantidade = contarValoresDistintos(L, L->valor, 0);
                    printf("Quantidade de valores distintos: %d\n", quantidade);
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

void ordena(TLista *L)
{
    //Definição das variáveis
    TLista atual, seguinte, temporario;

    //Alocação de memória temporária para manipulação dos ponteiros posteriormente
    temporario = (TLista) malloc (sizeof(TNo));

    // 'atual' iniciando na cabeça da lista L
    atual = *L;

    //Enquanto a lista L não chegar ao fim
     while( atual != NULL) {
            //O ponteiro 'seguinte' recebe a próxima caixinha da lista L, na qual será importante para posteriormente comparar o número atual com o próximo
            seguinte = atual->prox;

            while (seguinte != NULL)
                {
                    //Compara o valor atual com o próximo
                   if (atual->valor > seguinte->valor)
                   {
                        *temporario = *atual ; // copia valor de 'atual' em 'temporario'.
                        *atual =  *seguinte; // copia valor de 'seguinte' em 'atual'.
                        atual->prox = temporario->prox; // altera ponteiro do próximo de 'atual' para que ele continue sendo o mesmo que era antes da copia
                        temporario->prox = seguinte->prox; // copia o valor do ponteiro do proximo 'seguinte'
                        *seguinte = *temporario; // copia valor de temporario em 'seguinte'.
                        seguinte->prox = temporario->prox; // altera ponteiro do próximo de 'atual' para que ele continue sendo o mesmo que era antes da copia

                        printf("\nseguinte %d \n", seguinte->valor);
                        printf("\atual %d \n", atual->valor);
                   }
                   seguinte = seguinte->prox;
            }
      atual = atual->prox;
    }
    //Liberando memória alocada temporariamente
    free(temporario);
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

int contarValoresDistintos(TLista lista, int ultimoValor, int quantidade) {
    if (lista == NULL) {
        return quantidade;
    }

    if (lista->valor != ultimoValor) {
        quantidade++;
        ultimoValor = lista->valor;
    }

    return contarValoresDistintos(lista->prox, ultimoValor, quantidade);
}


int menu ()
{
	//declaração de variáveis
	int opcao;

	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Determinar Valores Distintos\n");
	printf ("(3) Sair\n\n");

	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);

	//retornando a opção escolhida
	return opcao;
}
