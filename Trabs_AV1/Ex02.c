/*Desenvolver uma função que, dada uma string
str, substitua uma substring s1 de str (definida
pelas posições inicial e final) por outra string,
s2.
*/
#include <stdio.h>
#include <string.h>

void mudarSubstring (char s[], char sub[], int posicao1, int posicao2);

void main ()
{
  char str[50], substring[20];
  int inicio, fim;
  int tamS2= strlen(substring);

    printf("Entre com uma string: ");
    fflush(stdin);
    fgets(str, sizeof(str), stdin);

    printf("Entre com a posição inicial da substring s1: ");
    fflush(stdin);
    scanf("%d", &inicio);

    printf("Entre com a posição final da substring s1: ");
    fflush(stdin);
    scanf("%d", &fim);

    printf("Entre com a nova substring s2: ");
    fflush(stdin);
    fgets(substring, sizeof(substring), stdin);

    // Remover o caractere de nova linha (\n) da nova substring
    if (tamS2 > 0 && substring[tamS2 - 1] == '\n')
    {
        substring[tamS2 - 1] = '\0';
    }

    mudarSubstring(str, substring, inicio, fim);

    printf("String modificada: %s\n", str);
}

void mudarSubstring(char s[], char subs2[], int posicao1, int posicao2)
{
    int i, j;
    int tamS=strlen(s);
    int tamS2 = strlen(subs2);
    int len3 = posicao1 - posicao2 + 1;

    if (posicao1< 0 || posicao1>=tamS || posicao2 < 0 || posicao2 >= tamS || posicao1 > posicao2)
    {
        printf("Posição invalida.");
    }
       else if (tamS2 > len3)
        {
            for (i = tamS - 1; i >= posicao2 + tamS2; i--)
            {
                s[i] = s[i -tamS2 + len3];
            }
        }
            else if (tamS2< len3)
            {
                for (i = posicao1+ tamS2; i <= tamS- len3 + tamS2; i++)
                {
                    s[i] = s[i + len3 - tamS2];
                }
            }

    for (i = posicao1, j = 0; j <tamS2; i++, j++)
    {
        s[i] = subs2[j];
    }
}
