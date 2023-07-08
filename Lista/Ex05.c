/*
Implementar uma função que, dadas duas listas dinâmicas do tipo TLista, verifique se elas
possuem os mesmos elementos, independente da ordem na qual apareçam.
obs: entendendo que não há repetição

1- verificar se uma lista eh maior q a outra. Se sim, não possuem os mesmos elementos.
2- pegar o primeiro elemento da primeira lista e ver se acha ele na outra. Depois, percorrer procurando o segundo elemento, e por ai vai
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
int verificarElementos (TLista L1, TLista L2);

int menu ();

//main
void main ()
{
    TLista lista1 =  NULL, //iniciando a lista vazia
           lista2 = NULL;

           //inserindo na lista 1
           inserir (&lista1, 5);
           inserir (&lista1, 4);
           inserir (&lista1, 3);
           inserir (&lista1, 6);

           //inserindo na lista 2
           inserir (&lista2, 3);
           inserir (&lista2, 4);
           inserir (&lista2, 5);
           inserir (&lista2, 6);

          printf("L1 x L2: %d \n", verificarElementos (lista1, lista2));

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

int verificarElementos (TLista L1, TLista L2) //os parametros vão ser as 2 listas, e sem * pois não vamos alterar o endereço de nada
{
    //declaração de variáveis
	TLista aux1 = L1, aux2 = L2;
	int contador1=0, i=0, contador2=0;

    while (aux1 && aux2) //se uma das listas chegar ao fim, acaba
    {

        aux1 = aux1 -> prox; //apontando para o proximo
        aux2 = aux2 -> prox;
        contador1++;
    }

    if (!aux1 && !aux2)
    { //se chegou aqui, os dois tem o mesmo tamanho!
         aux1 = L1; //fazendo 'aux' apontar para o primeiro nó de novo
         aux2 = L2;
        for (i=0; i<contador1; i++)
        {
            aux1 = aux1 -> prox; //indo pro primeiro elemento, o qual vamos caçar na L2
            aux2 = L2;
            while (aux2)
            {
                if (aux1 -> valor == aux2 -> valor) //se o valor do aux 1 for igual do aux 2
                {
                    contador2 ++; //incrementa o contador
                    break; //fim do loop
                }
                else
                    {
                        aux2 = aux2 -> prox;
                    }
            }
        }
        if (contador2 == contador1)
        {
            return 1;
        } else
            {
                return 0;
            }
    } else
      {
          return 0; //aqui, só uma lista terminou, logo, as 2 listas não sao iguais.
      }
}
