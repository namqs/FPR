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

//STRCPY, copia a string

#include <stdio.h>
copiar (char str1[], char str2[]); //prototipo

void main ()
{
  char string1[20], string2[20];

    printf("Entre com o nome: ");
    fflush(stdin); //nao incluir o enter
    gets(string1);
    copiar(string1, string2);
    printf("Nome digitado: %s", string2);

 }

copiar (char str1[], char str2[])
{
  int i;
    for(i=0; str1[i]!='\0'; i++)
    {
      str2[i] = str1[i];
    }
    str2[i] = '\0';
}

