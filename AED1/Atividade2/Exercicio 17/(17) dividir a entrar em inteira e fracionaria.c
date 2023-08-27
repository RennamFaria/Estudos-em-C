#include <stdio.h>

void Receber_valores(float *ptrX){
    printf("Digite um valores real qualquer: ");

    scanf("%f", ptrX);

    return;
}

void frac(float num, int *inteiro, float *frac){

  *inteiro = (int)num;    //tranformo o float em int
  
  *frac = num - *inteiro; //subtraio o inteiro com o total para sobrar apenas os decimais

  return;
}

void Imprimir_variaveis(int inteiro, float frac){
    printf("Parte inteira: %d   fracionaria: %0.2f", inteiro, frac);

    return;
}

int main(){
    float x;

    int inteiroX;
    float fracX;

    Receber_valores(&x);
    frac(x, &inteiroX, &fracX);
    Imprimir_variaveis(inteiroX, fracX);

    return 0;
}


/******************************************************************************

 Escreva uma funçao que dado um numero real passado como parametro, retorne a parte
  inteira e a parte fracionaria deste numero. Escreva um programa que chama esta funçao
  Prototipo:

  void frac(float num, int *inteiro, float *frac);

*******************************************************************************/