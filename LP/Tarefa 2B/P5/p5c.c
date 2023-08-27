#include <stdio.h>

int main(){
    int valor,notas[7]={0},preco[7]={100,50,20,10,5,2,1},i,v;

    scanf("%d",&valor);
    
    v=valor;
    for(i=0, notas[i]=0 ; i < 7 ; i++){
        while(valor >= preco[i]){
        valor-=preco[i];
        notas[i]=notas[i]+1;
        }

    }
    printf("%d\n",v);
    for(i=0 ; i < 7 ; i++){
    printf("%d nota(s) de R$ %d,00\n",notas[i],preco[i]);
    }

    return 0;
}