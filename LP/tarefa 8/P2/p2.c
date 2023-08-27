#include <stdio.h>
//-----------------------------------------------------------------------------------
#define NPrimo "O número %d não é primo!"
 
typedef int Num;
//-----------------------------------------------------------------------------------
int Checar_se_primo(Num n, Num i){
    //ele vai repetir a função até achar um que entre e encerrar ela
    
    if(i == n)      //se n consegue dividir e dar zero apenas com ele = primo
        return 1;
        
    if((n % i) == 0 || n < 2)    
//se ele consegue dividir e dar zero com outro numero sem ser ele mesmo = ele não é primo
        return 0;
        
    else            //se nao entrar em nenhum repita adicionando +1 em i
        return n+Checar_se_primo(n, i+1);
}
int main(){
    Num N, result, aux = 2;
    
    scanf("%d", &N);
    
    result = Checar_se_primo(N, aux);
    
    if (result > 0)
        printf("O número %d é primo!", N);
    else 
        printf("O número %d não é primo!", N);
    
    return 0;
}
 
/*
Problema 2: Escreva um programa recursivo que dado um número inteiro N, imprimir se é primo ou não-primo.
Exemplo
 
Entrada 1:
0
 
Saída 1:
O número 0 não é primo!
 
Entrada 2:
691
 
Saída 2:
O número 691 é primo!
*/