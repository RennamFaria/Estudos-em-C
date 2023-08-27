#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//pilha estatica
typedef struct{
    int posicoes[10];      //cada disco tera um numero que marca sua posicao
    int topo;       //marca a posicao do topo
    int quantidade; //(0 ≤ N ≤ 10)
}TipoTorre;

typedef struct{
  TipoTorre torre[3];
  int movimentos;    //(0 ≤ M ≤ 2.000)
}TipoPilha;

void receberPassos(int *, int *, int);
void inicializaPilha(TipoPilha *);
void gerarPosicoes(TipoTorre *, int);
void posicionaDiscos(TipoPilha *, TipoTorre ,int , int );
int moverDisco(TipoPilha *, int, int);
int checarFinalizacao(TipoPilha *, int);