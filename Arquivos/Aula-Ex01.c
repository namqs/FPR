#include <stdio.h>

void main () {
    int i;
    FILE *arquivo; //passo 1

    //passo 2: associar a variavel a um caminho que represente o arq
    arquivo = fopen("numeros.txt", "w" ); 
	/*pode ser escrita-write(apaga td e reescreve); leitura-read(o unico q n cria um arq) ou
	 append-a(tb eh uma escrita mas este passa a escrever a partir do final do arq)*/
	 
	 //passo 3: verificar se o arq foi aberto
	 if( arquivo) 
	 {
	    for (i=1; i<=1000;i++)
		{
	    	fprintf(arquivo, "%d\n", i);
		}
    }
    
    //passo 5: fechar o arq, pq se deixar aberto pode haver um conflito de processos além de tlvz alguma info ficar perdida no buffer e n ir pro arq
    fclose (aquivo);
}
