#include <stdio.h>

void Limpar_vetor(int []);
void Receber_valores(int []);
void Armazenamento(int [],int * ,int *);
void Mostrar_valores(int, int);

int main(){
    int min, max, V[10];

    Limpar_vetor(V);
    Receber_valores(V);
    Armazenamento(V , &min, &max);
    Mostrar_valores(min, max);

    return 0;
}

//--------------------------------------------------

void Limpar_vetor(int v[]){
    //função que irá zerar todos os numeros de N do main
    int i;
        
    for(i = 0; i < 10; i++){
        v[i] = 0;
        }
    return;
}

void Receber_valores(int ptrV[]){
    int i; 

    printf("Digite 10 numeros inteiros: ");

    for(i = 0; i < 10; i++){
        scanf("%d", &ptrV[i]);
    }
    return;
}

void Armazenamento(int v[], int *ptrMin, int *ptrMax){
    int i;         //Auxiliares
    
    *ptrMin = v[0];     //Não adianta colocar qualquer número grande pois quem 
    //digitar pode colocar um número maior e bugar a condição 
    *ptrMax = 0;

    for(i = 0; i < 10 ; i++){
        if(*ptrMin > v[i]){
            *ptrMin = v[i];
        }
        if(*ptrMax < v[i]){
            *ptrMax = v[i];
        }
    }
    return;
}

void Mostrar_valores(int min, int max){
    printf("O menor valor do vetor é %d e o maior é %d", min, max);

    return;
}

/******************************************************************************

Escreva uma funçao que receba um array de inteiros V e os endereços de duas variaveis
inteiras, min e max, e armazene nessas variáveis o valor mínimo e máximo do array.
Escreva tambem uma funçao main que use essa funçao

*******************************************************************************/