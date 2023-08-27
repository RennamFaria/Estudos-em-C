#include <stdio.h>

void Receber_valores(int *ptrA, int *ptrB){
    printf("Digite dois valores inteiros: ");

    scanf("%d", ptrA);
    scanf("%d", ptrB);

    return;
}

void Imprimir_variaveis(int A, int B){
    int Soma;

    A *= 2;
    B *= 2;
    Soma = A + B;
    printf("A: %d    B: %d  Soma dos dois: %d", A, B, Soma);
    return;
}

int main(){
    int A, B;

    Receber_valores(&A ,&B);
    Imprimir_variaveis(A,B);

    return 0;
}

/********************************************************************************

Elabora um programa que leia dois valores inteiros(A e B). Em seguida faça uma
funçao que retorme a somaa do dobro dos dois numeros lidos. A funçao devera armazenar
o dobro ded A na propria variavel A e o dobro de B na propria variavel B.

*******************************************************************************/