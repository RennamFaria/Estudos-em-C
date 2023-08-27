#include <stdio.h>
#include <stdlib.h>

struct nohArvore { // TipoArvore
  char dado;
  struct nohArvore *subArvoreEsq;
  struct nohArvore *subArvoreDir;
};

typedef struct nohArvore TipoNohArvore;

typedef TipoNohArvore *TipoArvore;

int menu();
int arvoreVazia(TipoArvore);
TipoArvore inicializaArvore(TipoArvore);
TipoArvore destroiArvore(TipoArvore);
TipoArvore destroiArvore(TipoArvore);
TipoArvore insereNaArvore(TipoArvore, char);
void imprimeArvorePreOrdem(TipoArvore, int);
void imprimeArvoreEmOrdem(TipoArvore, int);
void imprimeArvorePosOrdem(TipoArvore, int);
