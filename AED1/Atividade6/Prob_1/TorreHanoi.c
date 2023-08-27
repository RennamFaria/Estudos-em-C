#include "TorreHanoi.h"

void inicializaPilha(TipoPilha *pilha){
    int i,f;
    for(i = 0; i < 3; i++){
    pilha->torre[i].topo = 11;      //ja que entra apenas se topo for > pd
    //entao basta colocar um valor alto inacansavel
    pilha->torre[i].quantidade = 0;
        for(f = 0; f < 10; f++)
            pilha->torre[i].posicoes[f] = 0;
    }
    return;
}

void gerarPosicoes(TipoTorre *torre, int qtd){
    int i, f;
    for(f = 0, i = qtd; i > 0; f++, i--){
        torre->posicoes[f] = i;

    }
    return;
}

void posicionaDiscos(TipoPilha *pilha, TipoTorre torre, int qtd, int mov){
    int i;
    
    torre.quantidade = qtd;
    torre.topo = torre.posicoes[qtd-1];

    pilha->movimentos = mov;
    pilha->torre[0] = torre;

    return;
}

int moverDisco(TipoPilha *pilha, int po, int pd){
    
    pd--;       //ARRUMARRRRRR
    po--;
    if(pilha->torre[pd].topo > pilha->torre[po].topo){
        pilha->torre[pd].topo = pilha->torre[po].topo;
        pilha->torre[po].topo = pilha->torre[po].posicoes[(pilha->torre[po].quantidade)-1];

        pilha->torre[pd].posicoes[pilha->torre[pd].quantidade] = pilha->torre[po].posicoes[pilha->torre[po].quantidade+1];
        pilha->torre[po].posicoes[(pilha->torre[po].quantidade)+1] = 0;   //limpa a posicao que ficava o topo
        pilha->torre[pd].quantidade ++;
        pilha->torre[po].quantidade --;
    }
    else
        return 0;

    return 1;
}

int checarFinalizacao(TipoPilha *pilha, int qtd){
    int i;

    for(i = 1; i < 3; i++){
        if(pilha->torre[i].quantidade = qtd) {
//checa se na torre destino possui a mesma quantidade de 
//discos do que o original e nao tera problema em posiçoes pois o codigo anterior certifica que nao ocorre
//durante a alocaçao dos discos
            return 1;
        }
    }
    return 0;
}