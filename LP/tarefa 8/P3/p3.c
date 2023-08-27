#include <stdio.h>
//-----------------------------types and defines------------------------------------------------------
#define VAL "%d"
 
typedef int Num;
//-----------------------------functions------------------------------------------------------
void Limpar_vetor(Num n[]){
//função que irá zerar todos os numeros de N do main
    int i;
        
    for(i = 0; i < 100; i++){
        n[i] = 0;
        }
    return;
}
 
void Receber_ate_zero(Num n[]){
    int i = 0;
    
    do{     //scanea até ser digitado 0
        scanf(VAL, &n[i]);
        i++;
    }while(n[i-1]!=0);
    
    return;
}

void Maior_valor(Num n[], Num *aux){

//printf("aux: %d  n= %d \n", *aux, n[0]);

    if(*aux < n[1])
//checa se o valor de uma casa a frente é > que o atual, e entao salve aux
        *aux = n[1];

    if(n[1] == 0)  
        return;

    return Maior_valor(++n, aux);
}

void Imprimir(Num aux){

    printf(VAL, aux);

    return;
}
//------------------------------main----------------------------------
int main(){
    Num N[100], AUX;
    
    Limpar_vetor(N);
    Receber_ate_zero(N);
    AUX = N[0]; //aux recebe para que use o aux como condiçao na funcao

    Maior_valor(N, &AUX);
    Imprimir(AUX); 
    
    return 0;
}
/*
Problema 3: Escreva um programa recursivo que dado N valores inteiros, coloque em um VETOR e encontre o maior valores presnte nesse VETOR.
Exemplo
 
Entrada 1:
1 2 3 4 5
 
Saída 1:
5
 
Entrada 2:
10 2 1 3 4 8 9 7 6 5 9 11 20 3
 
Sáida 2:
20 
*/