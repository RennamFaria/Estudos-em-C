#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//pilha dinamica

typedef struct{
  char valor;
} TipoItem;

struct noh{
  TipoItem item;
  struct noh *prox;
};

typedef struct noh TipoNoh;

typedef TipoNoh *TipoPilha;

TipoPilha inicializaPilha(TipoPilha);
TipoPilha destroiPilha(TipoPilha);
int pilhaVazia(TipoPilha);
TipoPilha empilha(TipoPilha,TipoItem);
TipoPilha desempilha(TipoPilha,TipoItem*);
void imprimePilha(TipoPilha);
void imprimeItem(TipoItem);
int calculoPosfixa(char *);
