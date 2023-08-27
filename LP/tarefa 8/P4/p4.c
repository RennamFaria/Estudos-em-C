#include <stdio.h>
//-----------------------------types and defines------------------------------------------------------
#define VAL "%d"
 
typedef int Num;
typedef float Med;
//-----------------------------functions------------------------------------------------------
void Limpar_vetor(Num n[]){
//função que irá zerar todos os numeros de N do main
    int i;
        
    for(i = 0; i < 100; i++){
        n[i] = 0;
        }
    return;
}
 
int Receber_ate_zero(Num n[]){
    int i = 0;
    
    do{     //scanea até ser digitado 0
        scanf(VAL, &n[i]);
        i++;
    }while(n[i-1]!=0);
    i--;    //para retirar o zero que foi contado

    return i;
}

int Calculo_aritmetico(Num n[]){
    Med valor = 0;

    if(n[0] == 0)
        return 0;

    else{
        valor = n[0];
        return valor+Calculo_aritmetico(++n);
    }
}
void Imprimir(Num i, Med valor){

    printf("A media aritmética dos %d valores é: %0.1f", i, (valor/i));

    return;
}
//------------------------------main----------------------------------
int main(){
    Num N[100], I = 0;
    Med Valor;
    
    Limpar_vetor(N);
    I = Receber_ate_zero(N);    //I recebe o numeros de inputs
    Valor = Calculo_aritmetico(N);
    Imprimir(I, Valor); 
    
    return 0;
}
/*
Descrição
Problema 5: Escreva um programa recursivo que calcule a média
aritmética de qualquer quantidade de valores presntes em um
VETOR (Loop com final indeterminado). Para terminar o cálculo,
digita-se 0.

Exemplo
Entrada 1:
20
15
30
13
29
0

Saída 1:
A media aritmética dos 5 valores é: 21.4

Entrada 2:
8
28
67
54
9
73
23
11
72
48
0

Saída 2:
A media aritmética dos 10 valores é: 39.3
*/