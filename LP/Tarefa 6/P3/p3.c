#include <stdio.h>
#include <string.h>
 
/*eu preciso primeiro saber quantos char estao na string, exceto o \0
e depois eu tenho que concatenar a string na frente, sem o \0, da própria string,
depois eu copio a string concatenada de tras para frente no lugar em
que ocupa o lugar da string original */
 
void Zerar_S(char S[]){
//função que irá zerar todos os numeros de N do main
    int i;
     
    for(i = 0; i < 101; i++){
        S[i] = ' ';
    }
    return;
}
 
void Ler_entrada(char S[]){
//lendo teclado
 
    gets(S);
    
    return;
}
 
void Invercao(char S[]){
//todo o processo de inversao de string acontecera aqui
    int i, f, n;
    char aux1 = ' ', aux2 = ' ';
    
    n = strlen (S);
    for(i = 0, f = n; i < n/2 ; i++, f--){  
        
        aux1 = S[i];
        aux2 = S[f-1];
        
        S[i] = aux2;
        S[f-1] = aux1;
        
    }
 
    return;
}
void Imprimir_string_inversa(char S[]){
    int i;
 
    puts(S);
    
    return;
}
 
int main(){
    char str[101];      //apenas uma string
 
    Zerar_S(str);
    Ler_entrada(str);
    Invercao(str);
    Imprimir_string_inversa(str);
 
    return 0;
}
/*Inverter a ordem dos seus elementos de uma string. Obs: Não pode criar um vetor para armazenar a string invertida, isto é, a inversão deve ocorrer na própria string.
 
OBS: Criar no mínimo 4 funções;
 
Exemplo
Entrada:
ABCDE
 
Saída:
EDCBA
*/