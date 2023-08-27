#include <stdio.h>

void Receber_valores(float *);
void Calc_esfera(float, float *, float *);
void Imprimir_variaveis(float, float, float);

int main(){
    float raio, area, volume;

    Receber_valores(&raio);
    Calc_esfera(raio, &area, &volume);
    Imprimir_variaveis(raio, area, volume);

    return 0;
}

//----------------------------------------------------------

void Receber_valores(float *ptrX){
    printf("Digite o raio da esfera (em cm): ");
    scanf("%f", ptrX);

    return;
}

void Calc_esfera(float R, float *area, float *volume){
  float pi = 3.14;

  *area = 4*pi*(R*R);
  *volume = (4*pi*(R*R*R))/3;

  return;
}

void Imprimir_variaveis(float R, float area, float volume){
    printf("\nO raio %0.2fcm possui a area de %0.2fcm² e o volume de %0.2fcm³", R, area, volume);

    return;
}


/******************************************************************************

Implemente yma funçao que calcule a area da superficie e o ovlume de uma esfera de
raio R. Essa funçao deve ovedecer ao prototipo:

void calc_esfera(float R. float *area. float *volume);

A area da superficie e o volume sao dados, respectivamente. por:

A = 4*p*R²
V = 4/3*p*R²

*******************************************************************************/