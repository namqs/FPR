/*
Dadas duas pilhas P1 e P2, ambas do tipo TLista, desenvolver uma fun��o que determine quantos elementos de P1
tamb�m est�o em P2.
Notas:
1. Caso determinado valor apare�a mais de uma vez em P1, a solu��o final poder� cont�-lo tantas vezes
quantas forem as suas ocorr�ncias;
2. Caso alguma estrutura auxiliar seja necess�ria, esta ser� obrigatoriamente uma pilha ou uma fila;
3. A solu��o apresentada deve respeitar as regras de manipula��o de pilhas e/ou filas, em sua vers�o
cl�ssica.*/
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
int empilhar(TLista *P, int numero);
int verificar(TLista P1, TLista P2);

void main()
{
	//declara��o de vari�veis
	TLista P1 = NULL, P2 = NULL;
	
	//empilhando elementos em 'P1'
	empilhar(&P1, 7);
	empilhar(&P1, 10);
	empilhar(&P1, 12);
	empilhar(&P1, 15);
	empilhar(&P1, 10);

	//inserindo elementos em 'lista2'
	empilhar(&P2, 18);
	empilhar(&P2, 10);
	empilhar(&P2, 15);
	empilhar(&P2, 8);

	printf("Foram encontrados %d elementos da pilha 1 na pilha 2\n", verificar(P1, P2));
}

int empilhar(TLista *P, int numero)
{
	TLista aux = malloc(sizeof(TNo));

	if (!aux)
	{
		return FALSE;
	}
	else
	{
		aux->valor = numero;
		aux->prox = *P;
		*P = aux;
		return TRUE;
	}
}

int verificar(TLista P1, TLista P2)
{
	TLista aux1 = P1, aux2 = P2;
	int cont = 0;

	while (aux1) 	//enquanto n�o chegar ao final da p1...
	{
		while (aux2)
		{
			if (aux1->valor == aux2->valor)  //comparando o elemento da p1 com todos da p2, 1 por vez
			{
				cont++;
				break;
			}
			aux2 = aux2->prox;
		}
		aux1 = aux1->prox;
		aux2 = P2; //fazendo aux2 voltar pro inicio
	}

	return cont;
}

