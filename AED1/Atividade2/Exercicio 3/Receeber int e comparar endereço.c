#include <stdio.h>

void Receber_valores(int *ptrX, int *ptrY){
    printf("Digite dois valores inteiros: ");

    scanf("%d", ptrX);
    scanf("%d", ptrY);

    return;
}

int Checar_tamanho_endereco(int X, int Y){
    int i;

    if(X > Y){
        printf("\nA variavel 1 possui o endereço maior,");
        i++;
    }
    else 
        printf("\nA variavel 2 possui o endereço maior,");


    return i;
}

int main(){
    int x, y, box;
    
    Receber_valores(&x ,&y);
    box = Checar_tamanho_endereco(&x, &y);

    if(box > 0){
        printf(" valor de X: %d",x);
    }
    else
        printf(" valor de Y: %d",y);

    return 0;
}

/******************************************************************************

Escreva um programa que contenha duas variaveis inteiras. Leia essas variaveis do  
teclado. Em seguida, compare seus enderec ̧os e exiba o conteudo do maior endereco.

*******************************************************************************/