/* Suponha que não existissem as funções strlen,
strcpy, strcat e strcmp. Pede-se, então, a
implementação de funções que tenham o
mesmo objetivo daquelas.
*/

//STRLEN, retorna o tamahno da string, isto é, o numero de caracteres do string
#include <stdio.h>

int contador (char string[]);

void main ()
{
  char str [30];
  int tam;

    printf("Digite uma palavra: ");
    gets(str);
    tam =  contador(str);
    printf("O tamanho eh: %d", tam);


}

int contador (char string[]) //int pois ele vai retornar um valor
{
  int i = 0;

  while (string[i] != '\0')
  {
    i++;
  }
    return i;
}
