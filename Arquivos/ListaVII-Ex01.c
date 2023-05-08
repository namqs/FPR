/*Desenvolver uma função que, dado um arquivo
texto, verifique o número de caracteres no
mesmo.*/

#include <stdio.h>

int ContarCaracteres (char nomeArq[]);

void main ()
{
    char nomeArquivo[30];
    int retorno;

        printf("Digite o nome do arquivo: ");
        fflush(stdin);
        fgets(nomeArquivo, 30, stdin);

        retorno = ContarCaracteres(nomeArquivo);

        if (retorno==-1)
        {
            printf("Nao foi possivel abrir.");
        }
            else if (retorno ==0)
            {
                printf("O arquivo esta vazio.");
            }
                else
                {
                    printf("O arquivo selecionado possui %d caracteres.", retorno);
                }
}

int ContarCaracteres (char nomeArq[])
{
    int cont=0;
    char caracter;

        FILE *arq; // atribuindo um nome à variavel q reprenta o arquivo

        arq = fopen (nomeArq, "r"); //read pra ler e contar os carcteres

        if (arq == NULL)
        {
            return -1;//se nao for possivel abrir o arq
        } else
            {
                while (fscanf(arq, "%c", &caracter) != EOF)
                {
                    cont++;
                }
                return cont;
            }
}

