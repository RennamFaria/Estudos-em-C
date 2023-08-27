#include "AB.h"

int arvoreVazia(TipoArvore arvore){
  return arvore==NULL;
}

TipoArvore inicializaArvore(){
  return NULL;
}

void limparVetor(char p[]){
//função que irá zerar todos os numeros de N do main
    int i;
        
    for(i = 0; i < 100; i++){
        p[i] = NULL;
        }
    return;
}

TipoArvore destroiArvore(TipoArvore arvore){
  if(!arvoreVazia(arvore)){
    destroiArvore(arvore->subArvoreEsq);
    destroiArvore(arvore->subArvoreDir);
    free(arvore);
  }
  return NULL;
}

TipoArvore instanciaArvore(char dado){
  TipoArvore arvore = (TipoArvore) malloc(sizeof(TipoNohArvore));
  arvore->subArvoreEsq = NULL;
  arvore->subArvoreDir = NULL;
  arvore->dado = dado;
  return arvore;
}

TipoArvore insereSubArvoreEsq(TipoArvore raiz,TipoArvore subArvoreEsq){
  if(!arvoreVazia(raiz)){
    raiz->subArvoreEsq = subArvoreEsq;
    return raiz;
  }
  return NULL;
}

TipoArvore insereSubArvoreDir(TipoArvore raiz,TipoArvore subArvoreDir){
  if(!arvoreVazia(raiz)){
    raiz->subArvoreDir = subArvoreDir;
    return raiz;
  }
  return NULL;
}

/*TipoArvore montaArvore(TipoArvore raiz,TipoArvore subArvoreEsq,TipoArvore subArvoreDir){
  if(arvoreVazia(raiz)){
    return NULL;
    }
  raiz->subArvoreEsq = subArvoreEsq;
  raiz->subArvoreDir = subArvoreDir;

  return raiz;
}*/

TipoArvore montaArvore(TipoArvore arvore, char dado){
  if(arvoreVazia(arvore)){
    instanciaArvore(dado);
    return;
  }

  montaArvore(arvore->subArvoreEsq, dado);
  montaArvore(arvore->subArvoreDir, dado);

  return;
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