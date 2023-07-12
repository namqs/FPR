/**Desenvolver uma função recursiva que, dado um número inteiro n1, “crie” um novo número inteiro, n2, consistindo no
primeiro com os algarismos invertidos.

1- decompor o numero 
2- somar as partes
*/

//importação de bibliotecas
#include <stdio.h>

//protótipo das funções
int inverter(int Num1, int Num2);

void main() 
{
    int n1;
	
    printf("Digite o numero inteiro: ");
    scanf("%d", &n1);
    printf("O numero invertido fica: %d\n", inverter(n1, 0));
}

int inverter(int Num1, int Num2) 
{
    if (Num1 == 0) 
	{
        return Num2;
    } else 
	{
        return inverter(Num1 / 10, Num2 * 10 + (Num1 % 10));
    }
}

