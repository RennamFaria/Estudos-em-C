/////////////////////////ABB.h////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nohArvore { // TipoArvore
  char dado;
  struct nohArvore *subArvoreEsq;
  struct nohArvore *subArvoreDir;
};

typedef struct nohArvore TipoNohArvore;

typedef TipoNohArvore *TipoArvore;

int arvoreVazia(TipoArvore);
TipoArvore inicializaArvore(TipoArvore);
TipoArvore destroiSubArvore(TipoArvore);
TipoArvore destroiArvore(TipoArvore);
TipoArvore insereNaArvore(TipoArvore, char);
int procuraElemento(TipoArvore, char);
int imprimeArvoreEmOrdem(TipoArvore, int);
int imprimeArvorePreOrdem(TipoArvore, int);
int imprimeArvorePosOrdem(TipoArvore, int);
