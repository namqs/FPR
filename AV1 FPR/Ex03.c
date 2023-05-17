/*
	FAETERJ-Rio
	FPR - Fundamentos de Programação - Manhã
	Professor Leonardo Vianna
	
	Prova a compor a AV1 (Parte II) - 11/05/2023
	
	Questão 03 [2,5 pontos]:
	Dadas duas strings s1 e s2, implementar uma função que crie duas 
	outras strings - s3 e s4 - com as seguintes características:

	- s3: conterá todos os caracteres de s1 que também estão em s2;
	- s4: conterá todos os caracteres de s1 que não estão em s2.

	Exemplo: 

		s1:	"PROGRAMACAO"				
		s2:	"ALGORITMOS"				

		s3: "ROGRAMAAO" 
		s4: "PC"
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções
void CriandoStrings (char str1[], char str2[], char str3[], char str4[]);

//main
void main ()
{
	//declaração de variáveis
	char string1[20],
	     string2[20],
		 string3[20],
		 string4[20]; 
		 
	//inicializando as duas strings
	strcpy (string1, "PROGRAMACAO");
	strcpy (string2, "ALGORITMOS");
	
	//chamando a função e armazenando os resultados em 'string3' e 'string4'
	CriandoStrings(string1, string2, string3, string4);
	
	//exibindo as novas strings
	printf ("\n\nstring3: %s\n", string3);
	printf ("string4: %s\n", string4);
}
	
//implementação das funções
void CriandoStrings (char str1[], char str2[], char str3[], char str4[])
{
	int i, j, cont1=0, cont2=0, achei=0; 
	int tam1 = strlen (str1);
	int tam2 = strlen (str2);
	
		for(i=0; i<tam1; i++)
		{
			for(j=0; j<tam2; j++) //percorre td a palavra 2
			{
				if (str1[i] == str2[j]) //compara cada letra a cada letra e se for igual, atribui ao str3
				{
					//evitando repeticao
					if ((str3[cont1-1] != str2[j]) || (cont1 == 0))
					{
						str3[cont1] = str1[i]; 
						cont1++;
					}
				}
					else //se nao tiver nos 2, vai pro str4
					{
						if (j<tam2-2) //se eu ainda nao tiver chegado ao final de j
						{
							achei = 1;
						}
						else if ((j == tam2-1) && (achei==1))
						{
							if((str4[cont2-1] != str1[i]) || cont2 == 0 ) 
							{
								str4[cont2] = str1[i];
								cont2++;
							}
						}
					}
			}
		}

		str3[cont1] = '\0';
		str4[cont2] = '\0';
}
