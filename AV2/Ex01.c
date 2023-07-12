/**Desenvolver uma fun��o recursiva que, dado um n�mero inteiro n1, �crie� um novo n�mero inteiro, n2, consistindo no
primeiro com os algarismos invertidos.

1- decompor o numero 
2- somar as partes
*/

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipo das fun��es
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

