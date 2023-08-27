#include <stdio.h>

void Checar_tamanho_endereco(int X, int Y){

    if(X > Y){
        printf("\nA variavel 1 possui o endereço maior");

    }
    else 
        printf("\nA variavel 2 possui o endereço maior");


    return;
}

int main(){
    int x, y;
    
    printf("X: %d   Y: %d",   &x, &y);
    Checar_tamanho_endereco(&x, &y);

    return 0;
}

/******************************************************************************

Escreva um programa que contenha duas variaveis inteiras. Compare seus endereços e
exiba o maior endereço.

*******************************************************************************/