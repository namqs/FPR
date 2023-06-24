/*
Implementar uma função que, dada uma lista L1
do tipo TLista, crie uma nova lista, L2 (de tipo
diferente de TLista), contendo, em cada nó, um
elemento de L1 e a quantidade de vezes que
este aparece em L1.
Exemplo:
Elementos de L1: 1 4 5 7 4 3 2 5 4 7 1 2
A lista L2 conterá os seguintes nós:
• Um nó contendo o valor 1 e a
quantidade 2 (pois o número 1
aparece 2 vezes em L1);
• Um nó contendo o valor 4 e a
quantidade 3;
• Um nó contendo o valor 5 e a
quantidade 2;
• Um nó contendo o valor 7 e a
quantidade 2;
• Um nó contendo o valor 3 e a
quantidade 1;
• Um nó contendo o valor 2 e a
quantidade 2.
Observação: não há ordem definida para os nós
de L2. Ou seja, o primeiro elemento da lista L1
não precisa estar na primeira posição de L2.
*/
#include <stdio.h>
#include <stdlib.h>

// Definição de tipos
typedef struct No {
    int valor;
    int quantidade;
    struct No* prox;
} TNo;

typedef TNo* TLista;

// Protótipos das funções
void inserir(TLista* L2, int numero);
void exibir(TLista L2);
void converterLista(TLista L1, TLista* L2);
TNo* buscar(TLista L, int numero);

int main() {
    TLista L1 = NULL;
    TLista L2 = NULL;
    int option, num;

    do {
        printf("\n\nMenu de Operações:\n\n");
        printf("(1) Inserir na lista\n");
        printf("(2) Exibir lista L2\n");
        printf("(3) Sair\n\n");
        printf("Entre com a sua opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nEntre com o valor a ser inserido: ");
                scanf("%d", &num);
                inserir(&L1, num);
                converterLista(L1, &L2);
                printf("\nInserção realizada com sucesso!");
                break;

            case 2:
                exibir(L2);
                break;

            case 3:
                printf("\n\nPrograma finalizado!\n");
                break;

            default:
                printf("\n\nOpção inválida! Tente novamente.\n");
        }
    } while (option != 3);

    return 0;
}

void inserir(TLista* L2, int numero) {
    TNo* aux = buscar(*L2, numero);

    if (aux != NULL) {
        aux->quantidade++;
    } else {
        aux = (TNo*)malloc(sizeof(TNo));
        aux->valor = numero;
        aux->quantidade = 1;
        aux->prox = *L2;
        *L2 = aux;
    }
}

void exibir(TLista L2) {
    TNo* aux = L2;

    if (aux == NULL) {
        printf("Lista vazia!\n");
    } else {
        printf("Elementos da lista L2: ");

        while (aux != NULL) {
            printf("%d (%d vez(es)) ", aux->valor, aux->quantidade);
            aux = aux->prox;
        }

        printf("\n");
    }
}


void converterLista(TLista L1, TLista* L2) {
    TLista aux = L1;

    while (aux != NULL) {
        inserir(L2, aux->valor);
        aux = aux->prox;
    }
}

TNo* buscar(TLista L, int numero) {
    TNo* aux = L;

    while (aux != NULL) {
        if (aux->valor == numero) {
            return aux;
        }
        aux = aux->prox;
    }

    return NULL;
}
