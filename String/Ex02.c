//verificar se a palavra é igual de trás pra frente
#include <stdio.h>
#include <string.h>

int verificar (char string[]);

void main ()
{
  char str[20];

    printf("Entre com uma palavra: ");
    fflush(stdin);
    gets(str);
    verificar(str); 
}

int verificar (char string[])
{
  int i, j;

   for (i = 0, j = strlen(string) - 1; i < j; i++, j--)
    {
        if (string[i] != string[j])
        {
            printf("A palavra não é igual de trás para frente\n");
            return 0;
        }
    }
    printf("A palavra é igual de trás para frente\n");
    return 1;
}
