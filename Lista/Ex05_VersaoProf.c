/*
	FAETERJ-Rio
	FPR - Turmas Manhã e Noite
	Data: 24/06/2023 (aula extra)
	
	Lista de Exercícios X (Listas Encadeadas)
	
	QUESTÃO 05:
	Implementar uma função que, dadas duas listas dinâmicas do tipo 
	TLista, verifique se elas possuem os mesmos elementos, 
	independente da ordem na qual apareçam.
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//definição de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

//protótipos das funções
int mesmosElementos (TLista L1, TLista L2);
int estaContido (TLista primeira, TLista segunda);

int inserir (TLista *L, int numero);
int buscar (TLista L, int numero);

//main
void main ()
{
	//declaração de variáveis
	TLista lista1 = NULL,
	       lista2 = NULL,
	       lista3 = NULL,
		   lista4 = NULL;
	       
	//inserindo elementos em 'lista1'
	inserir (&lista1, 1);
	inserir (&lista1, 2);
	inserir (&lista1, 3);
	
	//inserindo elementos em 'lista2'
	inserir (&lista2, 1);
	inserir (&lista2, 2);
	inserir (&lista2, 3);
	
	//inserindo elementos em 'lista3'
	inserir (&lista3, 3);
	inserir (&lista3, 2);
	inserir (&lista3, 1);
	inserir (&lista3, 3);
	
	//inserindo elementos em 'lista4'
	inserir (&lista4, 1);
	inserir (&lista4, 2);
	inserir (&lista4, 3);
	inserir (&lista4, 4);
	
	//testando
	
	printf ("L1 x L2: %d\n", mesmosElementos (lista1, lista2));
	printf ("L1 x L3: %d\n", mesmosElementos (lista1, lista3));
	printf ("L1 x L4: %d\n", mesmosElementos (lista1, lista4));
}

//implementação das funções
int mesmosElementos (TLista L1, TLista L2)
{
	if ((estaContido (L1, L2) == 1) &&
	    (estaContido (L2, L1) == 1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int estaContido (TLista primeira, TLista segunda)
{
	//declaração de variáveis
	TLista aux = primeira;
	
	while (aux)
	{
		if (buscar (segunda, aux->valor) == 0)
		{
			return 0;
		}
		
		aux = aux->prox;
	}
	
	return 1;
}

int inserir (TLista *L, int numero)
{
	//declaração de variáveis
	TLista aux;
	
	//Passo 1: alocando memória
	aux = (TLista) malloc (sizeof(TNo));
	
	//verificando se houve erro na alocação
	if (!aux)
	{
		return 0;
	}
	else
	{
		//Passo 2: armazenar 'numero' na memória recém-alocada
		aux->valor = numero;
		
		//Passo 3: fazer com que o campo 'prox' do novo nó aponte
		//para o 'antigo' primeiro nó
		aux->prox = *L;
		
		//Passo 4: fazer com que L aponte para o novo nó
		*L = aux;		
		
		return 1;
	}
}

int buscar (TLista L, int numero)
{
	//declaração de variáveis
	TLista aux;
	
	//fazendo 'aux' apontar para o primeiro ná da lista
	aux = L;
	
	//enquanto não chegar ao final da lista...
	while (aux)
	{
		//comparando cada elemento da lista com 'numero'
		if (aux->valor == numero)
		{
			return 1;
		}
		
		//atualizando 'aux'
		aux = aux->prox;
	}
	
	return 0; //se chegou aqui, o elemento não pertence à lista
}

