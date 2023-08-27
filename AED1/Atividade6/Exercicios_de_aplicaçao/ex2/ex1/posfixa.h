#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//pilha dinamica

typedef struct{
  char valor;
}TipoItem;

struct noh{
  TipoItem item;
  struct noh *prox;
};

typedef struct noh TipoNoh;

typedef struct{
  TipoNoh *topo;
  int qtd;
}TipoPilha;


void inicializaPilha(TipoPilha*);
int pilhaVazia(TipoPilha*);
void destroiPilha(TipoPilha*);
int empilha(TipoPilha*, char*);
int desempilha(TipoPilha*,TipoItem*);
int calculoPosfixa(TipoPilha* ,TipoItem*);
int consultaTopo(TipoPilha*,TipoItem*);
int imprimePilha(TipoPilha*);
void imprimeItem(TipoItem);