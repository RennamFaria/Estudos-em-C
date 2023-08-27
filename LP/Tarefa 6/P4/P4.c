#include <stdio.h>
#include <string.h>
 
void Zerar_S(char S1[], char S2[]){
//função que irá zerar todos os numeros de N do main
    int i;
     
    for(i = 0; i < 101; i++){
        S1[i] = ' ';
        S2[i] = ' ';
    }
    return;
}
 
void Ler_entrada(char S1[], char S2[]){
//lendo teclado
    scanf("%s", S1);
    scanf("%s", S2);
    
    return;
}
int Contador(char S1[], char S2[], int N){
//checa quantas vezes a string2 aparece na string 1
    int i, f, qtd1 = 0, qtd2 = 0;
    
    qtd2 = strlen(S2);  // quantidade de char na string

    for(i = 0, f = 0; S1[i] != '\0'; i++){
        for(f = 0; S1[i] == S2[f] ; f++, i++)  
                if(f == (qtd2-1)){     //checa se a string2 está em string1 e soma +1  em N
                N++;   

                if(qtd2 != 1){  
                    /*resolve o problema que acontece quando a string2 possui apenas
                    um char e começa um loop infinito que soma +1 e subtrai -1.*/

                    i--;
                }
                break;
            }

    }
    return N;   
}
 
void Imprimir_valores(int N){
    
    printf("Número de ocorrência: %d", N);
 
    return;
}
/*--------------------------------------------------------------------------------*/
int main(){
    char string1[101], string2[101], rpt; //rpt = numero de repetiçoes da string digitrada
    
    Zerar_S(string1, string2);
    Ler_entrada(string1, string2);
    rpt = Contador(string1, string2, rpt);
    Imprimir_valores(rpt);
    
    return 0;   
}