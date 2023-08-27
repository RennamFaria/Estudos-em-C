#include <stdio.h>

void Zerar_vetores(char Ent[]){
//função que irá zerar todos os numeros dos vetores
    int i;
 
   for(i = 0; i < 100; i++){
    Ent[i] = 0;
    }
   return;
}
void Ler_entrada(char Ent[]){

    gets(Ent);
    
    return;
}
int Contador(char Ent[], int L, int Q[]){
//Caso o caracter der K irá somar +1 para cara e mesma coisa ao contrário
//e tambem conta o numero de lancamentos
    int i;

    for(i = 0, L = 0; Ent[i] != '\0' ; i++){
        if(Ent[i] == 'K'){
            Q[0] ++;
        }
        if(Ent[i] == 'C'){
            Q[1] ++;
        }
        L = Q[0] + Q[1];
    }
    return L;
}
void Imprimir_valores(int L, int qtds[]){

    printf("Numero de lancamentos: %d\n", L);
    printf("Quantidade de cara: %d\n", qtds[0]);
    printf("Quantidade de coroa: %d\n", qtds[1]);

    return;
}
/*--------------------------------------------------------------------------------*/
int main(){
    char entrada [100];
    int  lanc, qtds [2] = {0,0};  //quantidades vetor 0=caras, vetor 1=coroas

    Zerar_vetores(entrada);
    Ler_entrada(entrada);
    lanc = Contador(entrada, lanc, qtds);
    Imprimir_valores(lanc, qtds);
}
/*Dado uma sequencia de lançamentos de uma moeda, indicar:

a quantidade de lançamentos
o número de ocorrência de cara (K)
o número de ocorrência de coroa (C)
OBS: Criar no mínimo 4 funções;

Exemplo
Entrada:
KCKCKCKK

Saída:
Numero de lancamentos: 8
Quantidade de cara: 5
Quantidade de coroa: 3
*/