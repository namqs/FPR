/*Uma Clínica Veterinária mantém um vetor de
structs, do qual cada posição armazena as
seguintes informações: código do cadastro,
nome do pet, nome do tutor, e-mail de contato,
data da última vacina.
Desenvolver uma função que, dado um vetor
com esta estrutura, gere um arquivo texto com
os dados dos pets com vacina vencida (mais de
um ano da última).
Cada linha do arquivo terá a seguinte sintaxe:

email|mensagem

E a mensagem terá o formato apresentado
abaixo:
Prezado <nome_tutor>, a vacina do pet
<nome_pet> venceu no dia dd/mm/aaaa.
Podemos agendar a nova dose?
*/

#include <stdio.h>
#include <string.h>

//definição de tipos
typedef struct {
	int dia, mes, ano;
} TData;

typedef struct {
	int  codigo;
	char nomePet[20];
	char nomeTutor[50];
	char email[50];
	TData data;
} TDados;

#define TAM 5

void preencher (TDados vetor[]);
void gerarArq (TDados vetor[]);

void main ()
{
    TDados vet[TAM];

    //chamando funções:
    preencher(vet);
    gerarArq (vet);
}

void preencher (TDados vetor[]) //preenchendo struct com dados pré definidos
{
    //primeiro pet
    strcpy (vetor[0].nomePet, "Jujuba");
    strcpy (vetor[0].nomeTutor, "Carlos Marques");
    strcpy (vetor[0].email, "carlosmqs@gmail.com");
    vetor[0].codigo = 01;
	vetor[0].data.dia = 11;
	vetor[0].data.mes = 02;
	vetor[0].data.ano = 2022;

	//segundo pet
    strcpy (vetor[1].nomePet, "Thor");
    strcpy (vetor[1].nomeTutor, "Suzana Oliveira");
    strcpy (vetor[1].email, "su@gmail.com");
    vetor[1].codigo = 02;
	vetor[1].data.dia = 1;
	vetor[1].data.mes = 3;
	vetor[1].data.ano = 2023;

	//terceiro pet
    strcpy (vetor[2].nomePet, "Jaime");
    strcpy (vetor[2].nomeTutor, "Vinicius Cavalcante");
    strcpy (vetor[2].email, "vidino@gmail.com");
    vetor[2].codigo = 03;
	vetor[2].data.dia = 31;
	vetor[2].data.mes = 8;
	vetor[2].data.ano = 2022;

	//quarto pet
    strcpy (vetor[3].nomePet, "Jimmy");
    strcpy (vetor[3].nomeTutor, "Natalie Marques");
    strcpy (vetor[3].email, "namqsf@gmail.com");
    vetor[3].codigo = 04;
	vetor[3].data.dia = 30;
	vetor[3].data.mes = 8;
	vetor[3].data.ano = 2020;

	//quinto pet
    strcpy (vetor[4].nomePet, "Mel");
    strcpy (vetor[4].nomeTutor, "Natalie Marques");
    strcpy (vetor[4].email, "namqsf@gmail.com");
    vetor[4].codigo = 05;
	vetor[4].data.dia = 15;
	vetor[4].data.mes = 2;
	vetor[4].data.ano = 2020;
}

void gerarArq (TDados vetor[])
{
    int i;

    FILE *arquivo;//variavel que representa o arquivo
    arquivo = fopen ("VacinasVencidas.txt", "w");

        for(i=0;i<TAM;i++)
        {
            if ((vetor[i].data.ano<2023) && (vetor[i].data.mes<=5) && (vetor[i].data.dia<22)) //verificando se tem 1 ano
            {
                if (arquivo)
                {
                    fprintf(arquivo, "%s | Prezado %s, a vacina do pet %s venceu no dia %d/%d/%d. Podemos agendar a nova dose?\n\n", vetor[i].email, vetor[i].nomeTutor, vetor[i].nomePet, vetor[i].data.dia, vetor[i].data.mes, vetor[i].data.ano+1);
                }
                else
                {
                    printf ("\nO arquivo nao foi aberto!");
                }

            }
        }
        fclose (arquivo);
}
