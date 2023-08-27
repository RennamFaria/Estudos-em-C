#include <stdio.h>

void Receber_valores(int *ptrX, int *ptrY){
    printf("Digite dois valores inteiros: ");

    scanf("%d", ptrX);
    scanf("%d", ptrY);

    return;
}

int Checar_maior(int X, int Y){
    int aux = 0;

    if(X > Y){
        aux++;
    }

    return aux;
}

void Imprimir_variaveis(int x, int y, int box){
    if(box > 0){
        printf("maior: %d  menor: %d", x, y);
    }
    else
        printf("maior: %d  menor: %d", y, x);

    return;
}

int main(){
    int x, y, box;

    Receber_valores(&x ,&y);
    box = Checar_maior(x, y);
    Imprimr_variaveis(x, y, box);

    return 0;
}

/********************************************************************************

Faça um programa que leia 2 valores inteiros e chame uma funçao
que receba estes 2 valorees de entrada e retorne o maior valor na primeira 
variável e menor valor na segunda variáve. Escreva o conteudo das 2 variaveis
na tela. 

*******************************************************************************/