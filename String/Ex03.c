/*Desenvolver uma função que, dada uma string
s, crie uma substring que inicie na posição p de
s e contenha n caracteres.
Observações: se p e/ou n forem inválidos, a
substring será vazia; ii) se s não possuir n
caracteres além de p, a substring a ser criada
começará em p e terminará no final de s. 

1º passo:pegar a string, perguntar a posição q a proxima vai começar
2º passo: perguntar qnts caracteres vai ter a sub
3º passo: se for invalido, deixar vazio
4º passo: começar a preencher dados os termos
5º passo: SE a string nao ter n caracteries alem de p, terminar no final de s mesmo

*/

#include <stdio.h>
#include <string.h>

void criarSubstring (char s[], char sub[], int p, int n);

void main ()
{
  char string[20], substring[20];
  int posicao, numero;

    printf("Entre com uma palavra: ");
    fflush(stdin);
    gets(string);
    printf("Entre com a posição: ");
    scanf("%d", &posicao);
    printf("Entre com o numero de caracteres: ");
    scanf("%d", &numero);
    criarSubstring (string, substring, posicao, numero);
  
}
//strlen, pra P
void criarSubstring (char s[], char sub[], int p, int n)
{
  int i, j;
  
    if (p>=strlen(s) || p<0 || n<=0 || n>strlen(s))
    {
      sub[0] = '\0';// a sub fica vazia
    }
    for (i=p, j=0; s[i] != '\0' && j<n; i++, j++)
    {
      sub[j] = s[i];
    }
    sub[j] = '\0';
    printf("Substring: %s\n", sub);
}
