/*Desenvolver uma função que, dado um arquivo
texto contendo números, determine se estes
encontram-se ordenados crescentemente.
*/
#include <stdio.h>

int VerificarOrdenacao (char nomeArq[]);

void main ()
{
    char nomeArquivo[30];
    int retorno;

        printf("Digite o nome do arquivo: ");
        fflush(stdin);
        fgets(nomeArquivo, 30, stdin);

        retorno = VerificarOrdenacao(nomeArquivo);

        if (retorno==-1)
        {
            printf("Nao foi possivel abrir.");
        }
            else if (retorno ==0)
            {
                printf("O arquivo nao esta ordenado.");
            }
                else
                {
                    printf("O arquivo esta ordenado.");
                }
}

int VerificarOrdenacao (char nomeArq[])
{
    int cont=0;
    int num, anterior;

        FILE *arq; // atribuindo um nome à variavel q reprenta o arquivo

        arq = fopen (nomeArq, "r"); //read pra ler e contaras letras

        if (arq == NULL)
        {
            return -1;//se nao for possivel abrir o arq
        }
            else
            {
                fscanf(arq, "%d", &anterior); //le o primeiro numero e salva como anterior.

                while (fscanf(arq, "%d", &num) != EOF)
                {

                    if (num < anterior)
                    {
                        fclose(arq);
                        return 0;
                    }
                    else
                    {
                        anterior = num; //atualizando o anterior
                    }
                }
                //se chegou aqui, os elementos estão ordenados
                fclose (arq);

                return 1;
            }
}

