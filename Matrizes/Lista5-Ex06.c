/*Considere uma loja que mantém em uma
matriz o total vendido por cada funcionário
pelos diversos meses do ano. Ou seja, uma
matriz de 12 linhas (uma por mês) e 10 colunas
(10 funcionários). Pede-se o desenvolvimento
de uma função para cada item abaixo:

a. Calcular o total vendido durante o ano (soma todos os itens da matriz)

b. Dado um mês fornecido pelo usuário, determinar o total vendido nesse mês

c. Dado um funcionário fornecido pelo usuário, determinar o total vendido por ele durante o ano

d. Determinar o mês com maior índice de vendas

e. Determinar o funcionário que menos vendeu durante o ano.
*/

#include <stdio.h>

#define L 12
#define C 10

void preencherM(float matriz[L][C]);
void exibirMatriz(float matriz[L][C]);
void calcularTotal (float matriz[L][C]);
void calcularTotalMes(float matriz[L][C], int mes);
void calcularTotalFun(float matriz[L][C], int fun);
void calcularMelhorMes (float matriz[L][C]);
void calcularPiorFuncionario (float matriz[L][C]);

void main ()
{
    int menu=0, mes, funcionario;
    float m[L][C];

    preencherM(m);

        while (menu != '7')
        {
            printf("        Loja\n\n");
            printf("   Digite a opcao desejada: ");
            printf("Mostrar tabela - Digite 1\n");
            printf("Mostrar total vendido no ano - Digite 2\n");
            printf("Mostrar total vendido em determinado mês - Digite 3\n");
            printf("Mostrar total de vendas anual de determinado funcionario - Digite 4\n");
            printf("Mostrar mês com mais vendas - Digite 5\n");
            printf("Mostrar funcionário que menos vendeu - Digite 6\n");
            printf("Sair - Digite 7");
            printf("\n\nOpcao:");
            scanf("%d", &menu);

            switch (menu)
            {

                case 1: exibirMatriz(m);
                        break;

                case 2: calcularTotal(m);
                        break;

                case 3: printf("Digite o numero correspondente ao mes (0-11): ");
                        scanf("%d", mes);
                        calcularTotalMes(m, mes);
                        break;

                case 4: printf("Digite o numero correspondente ao funcionario (0-9): ");
                        scanf("%d", &funcionario);
                        calcularTotalFun(m, funcionario);
                        break;

                case 5: calcularMelhorMes(m);
                        break;

                case 6: calcularPiorFuncionario(m);
                        break;

                default: printf("Opcao invalida.");
            }
        }
}

void preencherM(float matriz[L][C])
{
  int i, j;

  //garantindo que as sequências aleatórias são diferentes
  srand (time(NULL));

  //percorrendo as linhas da matriz
  for (i=0;i<L;i++)
  {
    //percorrendo as colunas da matriz
    for (j=0;j<C;j++)
    {
      matriz[i][j] = rand()%100 + 1;   //inserindo valores de 1 a 100 na matriz
    }
  }
}

void exibirMatriz(float matriz[L][C])
{
  int i, j;

  for (i=0; i<L; i++)
  {
    for(j=0; j<C; j++)
    {
      printf("%2.f\t", matriz[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");
}

void calcularTotal (float matriz[L][C])
{
    int i, j;
    float soma=0;

        for (i=0; i<L; i++)
        {
            for (j=0; j<C; j++)
            {
                soma = soma + matriz[i][j];
            }
        }

        printf("\n\nO valor total vendido no ano foi: R$ %2.f", soma);
}

void calcularTotalMes(float matriz[L][C], int mes)
{
    int j;
    float soma;

        for (j=0; j<C; j++)
        {
            soma += matriz[mes][j];
        }
        printf("\n\nO valor total vendido nesse mes foi de R$ %2.f", soma);
}
void calcularTotalFun(float matriz[L][C], int fun)
{
    int i;
    float soma;

        for (i=0; i<L; i++)
        {
            soma = soma + matriz[L][fun];
        }
        printf("\n\nO valor total anual vendido pelo funcionario %d foi de R$ %2.f", fun, soma);
}

void calcularMelhorMes (float matriz[L][C])
{
    int i, j, melhor=0;
    float soma=0, vetorAux[L];

        for (i=0; i<L; i++)
        {
            for (j=0; j<C; j++)
            {
                soma = soma + matriz[i][j]; //após percorrer uma linha, a soma contem a soma de todos os valores de 1 mes
            }
            vetorAux[i] = soma; // salva o valor de cada mes, para posterior comparação
        }
        i=0; //zerando o i

        for (i=0; i<L; i++)
        {
            if (vetorAux[i]<vetorAux[i+1]) //se o proximo cara for maior, ele foi um mes melhor entao ele vai ficar atribuido à variavel
            {
                melhor = i+1;
            }
        }
        printf("\n\nO melhor mes foi o mes de numero %d", melhor);
}

void calcularPiorFuncionario (float matriz[L][C])
{
    int i, j, pior=0;
    float soma=0, vetorAux[C];

        for (j=0; j<C; j++)
        {
            for (i=0; i<L; i++)
            {
                soma = soma + matriz[i][j]; //após percorrer uma coluna, a soma contem a soma de todos os valores da coluna
            }
            vetorAux[j] = soma; // salva o valor de cada funcionario, para posterior comparação
        }
        j=0; //zerando o i

        for (j=0; j<C; j++)
        {
            if (vetorAux[j]>vetorAux[j+1]) //se o proximo cara for maior, ele foi menor entao ele vai ficar atribuido à variavel
            {
                pior = i+1;
            }
        }
        printf("\n\nO pior funcionario foi o de numero %d", pior);
}
