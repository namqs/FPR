/*Considere a existência de um vetor no qual cada posição pode armazenar o nome do aluno,
as notas de AV1 e AV2, sua média e a situação (aprovado, reprovado ou em AVF). Pede-se:

A declaração do vetor, assim como de todos os tipos de dados necessários, caso
existam;

Uma função que leia os dados de todos os alunos da turma;

Uma função que calcule a média de cada aluno (e a armazene no vetor), assim como a
sua situação;

Uma função que, dado um número inteiro (1-aprovado;2-reprovado;3-em AVF), exiba
todos os alunos que estão nesta situação.

*/
#include <stdio.h>
#include <string.h>
#define TAM_ALUNO 5

typedef struct {
    char nome[50];
    float AV1, AV2, media;
    char status[15];
} TAluno;

void ler (TAluno vetor[], int tam);
void CalcularMediaStatus (TAluno vetor[], int tam);
void ExibirPorStatus (TAluno vetor [], int tam, int sta);

void main ()
{
    TAluno aluno[TAM_ALUNO];
    int status;

    ler(aluno, TAM_ALUNO);
    CalcularMediaStatus (aluno, TAM_ALUNO);
    printf("Digite o numero correspondente ao o que deseja ver: \n\n");
    printf("1-Aprovados\n2-Reprovados\n3-AVF\n: ");
    scanf("%d", &status);
    ExibirPorStatus (aluno, TAM_ALUNO, status);

}

void ler(TAluno vetor[], int tam) {
    int i;

    for (i = 0; i < tam; i++) {
        fflush(stdin);
        printf("Nome: ");
        gets(vetor[i].nome);
    }

    for (i = 0; i < tam; i++) {
        fflush(stdin);
        printf("Av1: ");
        scanf("%f", &vetor[i].AV1);
    }

    for (i = 0; i < tam; i++) {
        fflush(stdin);
        printf("Av2: ");
        scanf("%f", &vetor[i].AV2);
    }
}

void CalcularMediaStatus(TAluno vetor[], int tam) {
    int i;

    for (i = 0; i < tam; i++) {
        vetor[i].media = (vetor[i].AV1 + vetor[i].AV2)/2;

        if (vetor[i].media >= 6) {
            strcpy(vetor[i].status, "APROVADO");
        }
        else if (vetor[i].media < 4) {
            strcpy(vetor[i].status, "REPROVADO");
        }
        else {
            strcpy(vetor[i].status, "AVF");
        }
    }
}

void ExibirPorStatus(TAluno vetor[], int tam, int sta) {
    char busca[15];
    int i;

    switch (sta) {
        case 1:
            strcpy(busca, "APROVADO");
            break;

        case 2:
            strcpy(busca, "REPROVADO");
            break;

        case 3:
            strcpy(busca, "AVF");
            break;
    }

    for (i = 0; i < tam; i++) {
        if (strcmp(vetor[i].status, busca) == 0) {
            printf("\nNome: %s \nAv1: %.1f - Av2: %.1f - Media: %.1f",
                vetor[i].nome, vetor[i].AV1, vetor[i].AV2, vetor[i].media);
        }
    }
}

