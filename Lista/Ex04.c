/*
Implementar uma função que, dadas duas listas dinâmicas do tipo TLista, verifique se estas são
iguais; isto é, contêm os mesmos elementos, na mesma ordem.
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
int inserir (TLista *L, int numero);// tem * pois vamos alterar o endereço ao adicionar um novo item na lista
int verificarIgualdade (TLista L1, TLista L2);

int menu ();

//main
void main ()
{
    TLista lista1 =  NULL, //iniciando a lista vazia
           lista2 = NULL;

           //inserindo na lista 1
           inserir (&lista1, 3);
           inserir (&lista1, 4);
           inserir (&lista1, 5);
           inserir (&lista1, 6);

           //inserindo na lista 2
           inserir (&lista2, 3);
           inserir (&lista2, 4);
           inserir (&lista2, 5);
           inserir (&lista2, 6);

           printf("L1 x L2: %d \n", verificarIgualdade (lista1, lista2));

}

//implementação das funções

//inserindo no início da lista
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

int verificarIgualdade (TLista L1, TLista L2) //os parametros vão ser as 2 listas, e sem * pois não vamos alterar o endereço de nada
{
    //declaração de variáveis
	TLista aux1 = L1, aux2 = L2;

    while (aux1 && aux2) //se uma das listas chegar ao fim, acaba
    {
        if (aux1 -> valor != aux2 -> valor)
        {
            return 0; //acaba, pois achou um item diferente
        } else
          {
            //andando com os dois auxiliares
			aux1 = aux1->prox;
			aux2 = aux2->prox;
          }
    }

    if (!aux1 && !aux2)
    {
        return 1; //aqui, os 2 já acabaram!
    } else
      {
          return 0; //aqui, só uma lista terminou, logo, as 2 listas não sao iguais.
      }
}
