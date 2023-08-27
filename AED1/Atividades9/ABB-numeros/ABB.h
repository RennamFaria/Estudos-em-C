/////////////////////////ABB.h////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nohArvore { // TipoArvore
  int dado;
  struct nohArvore *subArvoreEsq;
  struct nohArvore *subArvoreDir;
};

typedef struct nohArvore TipoNohArvore;

typedef TipoNohArvore *TipoArvore;

int arvoreVazia(TipoArvore);
TipoArvore inicializaArvore(TipoArvore);
TipoArvore destroiSubArvore(TipoArvore);
TipoArvore destroiArvore(TipoArvore);
TipoArvore insereNaArvore(TipoArvore, int);
int procuraElemento(TipoArvore, int);
TipoArvore removeNos(TipoArvore, int);
TipoArvore removeElemento(TipoArvore, int);
int imprimeArvoreEmOrdem(TipoArvore, int);
void imprimeArvorePreOrdem(TipoArvore, int);
int imprimeArvorePosOrdem(TipoArvore, int);
