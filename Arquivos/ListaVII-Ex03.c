/*Desenvolver uma função que, dado um arquivo
texto, verifique o número de letras existentes
no mesmo (entendendo que no arquivo podem
existir letras, algarismos e símbolos).*/

#include <stdio.h>

int ContarLetras (char nomeArq[]);

void main ()
{
    char nomeArquivo[30];
    int retorno;

        printf("Digite o nome do arquivo: ");
        fflush(stdin);
        fgets(nomeArquivo, 30, stdin);

        retorno = ContarLetras(nomeArquivo);

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
                    printf("O arquivo selecionado possui %d letras.", retorno);
                }
}

int ContarLetras (char nomeArq[])
{
    int cont=0;
    char ch;

        FILE *arq; // atribuindo um nome à variavel q reprenta o arquivo

        arq = fopen (nomeArq, "r"); //read pra ler e contaras letras

        if (arq == NULL)
        {
            return -1;//se nao for possivel abrir o arq
        }
            else
            {
                while (fscanf(arq, "%c", &ch) != EOF)
                {
                    ch = toupper (ch);

                    if((ch >= 'A') && (ch <= 'Z')) // se a letra for MAIOR(vir depois) do A ou igual e se ela for MENOR que o Z(vir antes)
                    {
                        cont++;
                    }
                }
                return cont;
            }
}
