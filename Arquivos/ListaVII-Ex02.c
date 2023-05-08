/*Desenvolver uma função que, dado um arquivo
texto, verifique o número de vezes que um
determinado caracter aparece no arquivo.*/

#include <stdio.h>

int ContarCaracteres (char nomeArq[],char car);

void main ()
{
    char nomeArquivo[30], caracter;
    int retorno;

        printf("Digite o nome do arquivo: ");
        fflush(stdin);
        fgets(nomeArquivo, 30, stdin);
        printf("Digite o caracter que deseja contar: ");
        fflush(stdin);
        scanf("%c", &caracter);

        retorno = ContarCaracteres(nomeArquivo, caracter);

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
                    printf("O arquivo selecionado possui %d ocorrencias desse caracter.", retorno);
                }
}

int ContarCaracteres (char nomeArq[],char car)
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
                    if(caracter==car)
                    {
                        cont++;
                    }
                }
                return cont;
            }
}
