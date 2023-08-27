#include "ABB.h"

// Funções da Árvore
int arvoreVazia(TipoArvore arvore) {
     return arvore == NULL; 
     }

TipoArvore inicializaArvore(TipoArvore arvore) {
     return NULL; 
     }

TipoArvore destroiSubArvore(TipoArvore arvore) {
  if (arvoreVazia(arvore)) // se ArvoVaz volte uma recursao
    return NULL;
  destroiSubArvore(arvore->subArvoreEsq);
  destroiSubArvore(arvore->subArvoreDir);
  free(arvore);

  return NULL;
}

TipoArvore destroiArvore(TipoArvore arvore) {
  if (arvoreVazia(arvore)) // se arvore vazia nao ha nada para destruir dinamicamente
    return NULL;
  arvore = destroiSubArvore(arvore);
  free(arvore);
  return NULL;
}

TipoArvore insereNaArvore(TipoArvore arvore, char dado) {
  if (arvoreVazia(arvore)) { // se arvore vazia
    arvore = (TipoArvore)malloc(sizeof(TipoNohArvore));
    arvore->dado = dado;
    arvore->subArvoreDir = NULL;
    arvore->subArvoreEsq = NULL;
  } else { // se arvore nao vazia, valorAscii > ou <

    if (dado < arvore->dado) {
      arvore->subArvoreEsq = insereNaArvore(arvore->subArvoreEsq, dado);
    }
    if (dado >= arvore->dado) {
      arvore->subArvoreDir = insereNaArvore(arvore->subArvoreDir, dado);
    }
  }

  return arvore;
}

void imprimeArvorePreOrdem(TipoArvore arvore, int nivel) {
  int j;
  if (arvoreVazia(arvore))
    return;
  
  for(j=0;j<nivel;j++){
      printf("\t");
    }
  printf("%c\n", arvore->dado);
  imprimeArvorePreOrdem(arvore->subArvoreEsq, nivel+1);
  imprimeArvorePreOrdem(arvore->subArvoreDir, nivel+1);
  nivel--;

  return;
}

void imprimeArvoreEmOrdem(TipoArvore arvore, int nivel) {
  int j;
  if (arvoreVazia(arvore))
    return;
  
  imprimeArvoreEmOrdem(arvore->subArvoreEsq, nivel+1);
  for(j=0;j<nivel;j++){
      printf("\t");
    }
  printf("%c\n", arvore->dado);
  imprimeArvoreEmOrdem(arvore->subArvoreDir, nivel+1);
  nivel--;

  return;
}

void imprimeArvorePosOrdem(TipoArvore arvore, int nivel) {
  int j;
  if (arvoreVazia(arvore))
    return;
  
  imprimeArvorePosOrdem(arvore->subArvoreEsq, nivel+1);
  imprimeArvorePosOrdem(arvore->subArvoreDir, nivel+1);
  for(j=0;j<nivel;j++){
      printf("\t");
    }
  printf("%c\n", arvore->dado);
  nivel--;

  return;
}