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
#define tam 5
void ler (TAluno vetor[], int tam) //função para ler dados
void CalcularMédiaStatus (TAluno vetor[], int tam) //função para ler dados

typedef struct {
    char nome[50];
    float AV1, AV2, media;
    char status[15];
} TAluno;

void main ()
{
    TAluno aluno[tam];
    
        ler(aluno[], tam);
        CalcularMédiaStatus (Taluno vetor[], int tam)
}

void ler (TAluno vetor[], int tam) //função para ler dados
{
    int i;

        for (i=0;i<tam;i++)
        {
            fflush(stdin);
            printf("Nome: ");
            gets (vetor[i].nome);
        }

        for (i=0;i<tam;i++)
        {
            fflush(stdin);
            printf("Av1: ");
            scanf("%f", &vetor[i].AV1);
        }

        for (i=0;i<tam;i++)
        {
            fflush(stdin);
            printf("Av2: ");
            scanf("%f", &vetor[i].AV1);
        }
}
void CalcularMédiaStatus (TAluno vetor[], int tam) //função para ler dados
{
    int i;

        for (i=0;i<tam;i++)
        {
            vetor[i].media = (vetor[i].AV1 +vetor[i].AV2);

            if (vetor[i].media>=6)
            {
                strcpy (vetor[i].status, "APROVADO");
            }
                else if (vetor[i].media < 4)
                {
                    strcpy (vetor[i].status, "REPROVADO");
                }
                else
                {
                    strcpy (vetor[i].status, "AVF");
                }
        }
}
