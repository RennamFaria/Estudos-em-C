#include <stdio.h>
#include <stdlib.h>
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct nohArvore {
    char dado;
    struct nohArvore *subArvoreEsq;
    struct nohArvore *subArvoreDir;
    struct nohArvore *prox;
};

struct auxnohArvore{
  struct nohArvore *pilha;
};

typedef struct nohArvore TipoNohArvore;
typedef TipoNohArvore *TipoArvore;


int arvoreVazia(TipoArvore);
TipoArvore inicializaArvore(TipoArvore);
TipoArvore destroiSubArvore(TipoArvore);
TipoArvore destroiArvore(TipoArvore);
TipoArvore criaArvore(TipoArvore, char);
void empilha(TipoArvore);
TipoArvore removeNoh();
int qtdNiveis(TipoArvore, int, int, int);
int imprimeArvoreEmOrdem(TipoArvore, int, int, int);
