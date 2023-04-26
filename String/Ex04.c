/*Implementar uma função que remova todas as
ocorrências de determinado caracter em uma
string.*/

#include <stdio.h>
#include <string.h>

remover (char s[], char c);

void main ()
{
  char string[20];
  char caracter;

    printf("Informe a string: ");
    fflush(stdin);
    gets(string);

    printf("Digite o caracter a ser removido: ");
    scanf("%c", &caracter);
    remover(string, caracter);
    printf("Nova string: %s", string);
}

remover (char s[], char c)
{
  char auxiliar[20];
  int i, j;
  
  for (i=0, j=0; i<strlen(s); i++)
    {
      if (s[i] != c)
      {
        auxiliar[j] = s[i];
        j++;
      }
    }
  auxiliar[j] = '\0'; 
  strcpy(s, auxiliar);
}
