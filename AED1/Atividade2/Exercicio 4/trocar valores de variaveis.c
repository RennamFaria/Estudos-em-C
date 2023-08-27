#include <stdio.h>

void Receber_valores(int *ptrX, int *ptrY){
    printf("Digite dois valores inteiros: ");

    scanf("%d", ptrX);
    scanf("%d", ptrY);

    return;
}

void Inverter_variaveis(int *ptrX, int *ptrY){
    int aux;

    aux = *ptrX;
    *ptrX = *ptrY;
    *ptrY = aux;

    return;
}

void Imprimir_variaveis(int x, int y){
    printf("primeiro: %d    segundo: %d", x, y);
    return;
}

int main(){
    int x, y;

    Receber_valores(&x ,&y);
    Inverter_variaveis(&x, &y);
    Imprimir_variaveis(x,y);

    return 0;
}

/********************************************************************************

Faca um programa que leia 2 valores inteiros e chame uma funcao que receba estas 
2 variaveis e troque o seu conteudo, ou seja, esta funcao ̃e chamada passando duas  
variaveis A e B por exemplo e apos a execucao da funcao. A contera o valor de B e B  
tera o valor de A.  

*******************************************************************************/