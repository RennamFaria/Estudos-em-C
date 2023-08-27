#include <stdio.h>
#include <stdlib.h>

struct nohArvore {
  char dado;
  struct nohArvore *subArvoreEsq;
  struct nohArvore *subArvoreDir;
};

typedef struct nohArvore TipoNohArvore;

typedef TipoNohArvore *TipoArvore;

int arvoreVazia(TipoArvore);
void limparVetor(char[]);
TipoArvore inicializaArvore();
TipoArvore destroiArvore(TipoArvore);
TipoArvore instanciaArvore(char);
TipoArvore insereSubArvoreEsq(TipoArvore,TipoArvore);
TipoArvore insereSubArvoreDir(TipoArvore,TipoArvore);
TipoArvore montaArvore(TipoArvore, char);
void imprimeArvorePreOrdem(TipoArvore, int);
void imprimeArvoreEmOrdem(TipoArvore, int);
void imprimeArvorePosOrdem(TipoArvore, int);
