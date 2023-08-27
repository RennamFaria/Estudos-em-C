#include <stdio.h>

void Receber_valores(int *ptrX, int *ptrY){
    printf("Digite dois valores inteiros: ");

    scanf("%d", ptrX);
    scanf("%d", ptrY);

    return;
}

void Somar_variaveis(int *X, int *Y){
    *X = *X + *Y;

    return;
}

void Imprimir_variaveis(int x, int y){
    printf("soma dos dois valores: %d       valor de B: %d", x, y);

    return;
}

int main(){
    int x, y;

    Receber_valores(&x ,&y);
    Somar_variaveis(&x, &y);
    Imprimir_variaveis(x, y);

    return 0;
}

/******************************************************************************

Crie um programa que contenha uma funçao que permita passar por parametro dois
numeros inteiros A e B. A funçao devera calcular a soma entre estes dois numeros e 
armazenar o resultado na variavel A. Esta funçao nao devera possuir retorno, mas devera
modificar o valor do primeiro parametro. Imprima os valores de A e B na funçao principal

*******************************************************************************/