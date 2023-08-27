/////////////////////////arvoreBinaria.h///////////////////////////////

#include <stdio.h>
#include <stdlib.h>

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
void imprimeArvorePreOrdem(TipoArvore);
void imprimeArvoreEmOrdem(TipoArvore);
void imprimeArvorePosOrdem(TipoArvore);


////////////////////////arvoreBinaria.c//////////////////////////

// Funções da Árvore
int arvoreVazia(TipoArvore arvore) {
return arvore == NULL; 
}

TipoArvore inicializaArvore(TipoArvore arvore){ 
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

TipoArvore insereNaArvore(TipoArvore arvore, int dado) {
  if (arvoreVazia(arvore)) { // se arvore vazia
    arvore = (TipoArvore)malloc(sizeof(TipoNohArvore));
    arvore->dado = dado;
    arvore->subArvoreDir = NULL;
    arvore->subArvoreEsq = NULL;
  } 
  else { // se arvore nao vazia, valorAscii > ou <
    if (dado < arvore->dado) {
      arvore->subArvoreEsq = insereNaArvore(arvore->subArvoreEsq, dado);
    }
    if (dado > arvore->dado) {
      arvore->subArvoreDir = insereNaArvore(arvore->subArvoreDir, dado);
    }
  }

  return arvore;
}

void imprimeArvorePreOrdem(TipoArvore arvore){
  if (arvoreVazia(arvore))
    return;
  printf(" %d", arvore->dado);
  imprimeArvorePreOrdem(arvore->subArvoreEsq);
  imprimeArvorePreOrdem(arvore->subArvoreDir);

  return;
}

void imprimeArvoreEmOrdem(TipoArvore arvore){
  if (arvoreVazia(arvore))
    return;
  
  imprimeArvoreEmOrdem(arvore->subArvoreEsq);
  printf(" %d", arvore->dado);
  imprimeArvoreEmOrdem(arvore->subArvoreDir);

  return;
}

void imprimeArvorePosOrdem(TipoArvore arvore){
  if (arvoreVazia(arvore))
    return;
  
  imprimeArvorePosOrdem(arvore->subArvoreEsq);
  imprimeArvorePosOrdem(arvore->subArvoreDir);
  printf(" %d", arvore->dado);
  
  return;
}

////////////////////////////////main.c/////////////////////////////

int main(){
  TipoArvore raiz;
  int qtdTestes, qtdValores, dado, i, f, nada = 0;

  raiz = inicializaArvore(raiz);

  scanf("%d", &qtdTestes);

  for(i = 0; i<qtdTestes; i++){

    scanf("%d", &qtdValores);

    for(f = 0; f < qtdValores; f++){
      scanf("%d", &dado);

      raiz = insereNaArvore(raiz, dado);
    }

    printf("Case %d:", i+1);
    printf("\nPre.:");
      imprimeArvorePreOrdem(raiz);
    printf("\nIn..:");
      imprimeArvoreEmOrdem(raiz);
    printf("\nPost:");
      imprimeArvorePosOrdem(raiz);
    
    raiz = destroiArvore(raiz);
    
  printf("\n");
  }
  return 0;
}