/*Desenvolver uma função recursiva que, dado
um número inteiro n, determine a quantidade
de divisores deste número.
*/
#include <stdio.h>

int QuantDivisores(int n, int aux, int quant);

void main()
{
    int num, auxiliar, contador = 0, quantidade;

    printf("Escolha um numero para determinar a quantidade de divisores: ");
    scanf("%d", &num);
    auxiliar = num;
    quantidade = QuantDivisores(num, auxiliar, contador);
    printf("A quantidade de divisores desse numero eh: %d\n", quantidade);
}

int QuantDivisores(int n, int aux, int quant)
{
    if (aux > 0) //caso geral
    {
        quant = QuantDivisores(n, aux - 1, quant); //chamando a função recursivamente

        if (n % aux == 0)
        {
            quant++;
            printf("%d ", aux); //para acompanhar o funcionamento da função
        }
    }
    return quant; //caso base
}

