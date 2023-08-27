#include <stdio.h>
#include <math.h>

void Ler_inteiros(float*a, float*b ,float*c){
    
    scanf("%f %f %f", a, b, c);
    return;
}

float Calcular_delta(float a, float b, float c){
    float X;      //delta
    
    X = pow(b,2)-4*a*c;
    return X;
}

void Calcular_bhaskara(float a, float b, float c, float delta, float*b1, float*b2){
    float D;
    
    if(a <= 0){
        *b1 = -(c / b);
    }

    if(a > 0){
    D = sqrt(delta);
    *b1 = (-b + D) / (a * 2);
    *b2 = (-b - D) / (a * 2);
    }
    
    return;
}

void Condicoes(float a, float delta, float resultado1, float resultado2){       //dizer se tem raiz ou nenhuma, etc
    float raiz;
    if(a > 0 && delta >= 0){        //duas raizes
        printf("Raiz 1: %0.2f\nRaiz 2: %0.2f", resultado1, resultado2);
    }
    if(a <=  0){     //uma raiz
        printf("Raiz: %0.2f", resultado1);
    }
    if(delta < 0){           //nenhuma raiz
        printf("Não existem raízes reais");
    }
    return;
}

/*----------------------------------------------------------------------*/

int main(){
    float a, b, c, delta, resultado1, resultado2;       //resultado do bhaskara
    
    Ler_inteiros(&a, &b, &c);       //mando o endereço deles
    delta = Calcular_delta(a, b, c);
    Calcular_bhaskara(a, b , c ,delta ,&resultado1 ,&resultado2);
    Condicoes(a, delta, resultado1, resultado2);

    return 0;
}
