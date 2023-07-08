/*Desenvolver uma função que, dada uma lista L1, crie uma nova lista L2, cópia de L1.
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct No {
    int valor;
    struct No* prox;
} TNo;

typedef TNo* TLista;

int inserir(TLista* L, int numero);
int CriarCópia(TLista L1, TLista* L2);
void exibir(TLista L);

void main() {
    TLista lista1 = NULL;
    TLista lista2 = NULL;

    inserir(&lista1, 1);
    inserir(&lista1, 2);
    inserir(&lista1, 3);
    inserir(&lista1, 4);
    inserir(&lista1, 5);
    inserir(&lista1, 6);

    CriarCópia(lista1, &lista2);

    printf("Primeira Lista: ");
    exibir(lista1);
    printf("\nSegunda lista: ");
    exibir(lista2);
}

int inserir(TLista* L, int numero) {
    TLista aux;

    aux = malloc(sizeof(TNo));
    if (!aux) {
        return FALSE;
    } else {
        aux->valor = numero;
        aux->prox = *L;
        *L = aux;
        return TRUE;
    }
}

void exibir(TLista L) {
    TLista aux;
    if (!L) {
        printf("\n\nLista vazia!\n");
    } else {
        printf("\n\nLista: ");
        aux = L;
        while (aux) {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
    }
}

int CriarCópia(TLista L1, TLista* L2) {
    TLista aux1, aux2;

    aux1 = L1;
    *L2 = NULL;

    while (aux1) {
        aux2 = malloc(sizeof(TNo));
        if (!aux2) {
            return FALSE;
        } else {
            aux2->valor = aux1->valor;
            aux2->prox = NULL;
            if (*L2 == NULL) {
                *L2 = aux2;
            } else {
                TLista temp = *L2;
                while (temp->prox != NULL) {
                    temp = temp->prox;
                }
                temp->prox = aux2;
            }
            aux1 = aux1->prox;
        }
    }
    return TRUE;
}
