#include <stdio.h>
 
//--------------------------------------------------------
typedef int Valor;
typedef long int Fatorial;
//--------------------------------------------------------
 
long int Calcular_fatorial(Valor n){
    if (n == 0)
        return 1;
    else
        return n*Calcular_fatorial(n-1);
}

void Imprimir(Valor n, Fatorial f){
    if(n < 0)
        printf("Não existe fatorial de %d", n);
    else
        printf("O fatorial de %d é: %li", n, f);

    return;
}
//--------------------------------------------------------
int main(){
    Valor N;
    Fatorial F;
    
    scanf("%d", &N);
    
    if(N < 0){
        N = -1;
        Imprimir(N,F);
    }
    else{
        F = Calcular_fatorial(N);
        Imprimir(N,F);
    }

    return 0;
}