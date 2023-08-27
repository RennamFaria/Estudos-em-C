#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TorreHanoi.h"

int main(){
    TipoPilha pilha;
    TipoTorre torre;
    int qtd, mov, i, f;
    int po, pd;         //posicao original e destino

    inicializaPilha(&pilha);

    printf("\nDigite a quantidade de Discos: ");
    scanf("%d", &qtd);
    if(0 < qtd && qtd <= 10){
        printf("\nDigite a quantida de Movimentos: ");
        scanf("%d", &mov);
        if(0 < mov && mov <= 2000){
            gerarPosicoes(&torre, qtd);
            posicionaDiscos(&pilha, torre, qtd, mov);
            //printf("\n%d", pilha.movimentos);
            //printf("\n%d", pilha.torre[0].topo);
            //printf("\n%d", pilha.torre[0].quantidade);
            //for(i = 0; i < 10; i++){
            //    printf("\n%d", pilha.torre[0].posicoes[i]);
            //}
        }
        else
            printf("\nQuantidade de Movimentos invallida!");
    }
    else
        printf("\nQuantidade de Discos invalida!");

    for(i = mov; i > 0; i--){
        receberPassos(&po, &pd, mov);
        if(moverDisco(&pilha, po, pd)){
            printf("\n\ncerto");

            for(i = 0; i<3; i++){
                printf("\n\ntorre[%d]", i);
            printf("\ntopo[%d]: %d", i, pilha.torre[i].topo);
            printf("\nquantidade[%d]: %d", i, pilha.torre[i].quantidade);
            for(f = 0; f < 3; f++){
                printf("\n%d", pilha.torre[i].posicoes[f]);
            }
            }
        }
        else{
            printf("wrong move");
            return 0;
        }
    }
    if(checarFinalizacao(&pilha, qtd)){
        printf("Solved");
    }
    else
        printf("Unfinished");

    return 0;
}

void receberPassos(int *po, int *pd, int mov){
    printf("\nposicao origem: ");
    scanf("%d", po);
    if(*po >= 1 && *po <= 3){
        printf("\nposicao desino: ");
        scanf("%d", pd);
        if(*pd >= 1 && *po <= 3){
        }
        //else{
        //    printf("valor diferente de 1,2 ou 3");      //  wrong move
        //    return;
        //}
    }
    //else{
    //printf("valor diferente de 1,2 ou 3");      //wrong move
    //return;
    //}
    return;
}