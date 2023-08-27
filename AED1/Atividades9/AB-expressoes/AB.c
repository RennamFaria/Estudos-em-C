#include <stdio.h>
#include <stdlib.h>
#include "AB.h"

//struct nohArvore *pilha = NULL;

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

TipoArvore criaArvore(TipoArvore arvore, char dado){
    arvore = (TipoArvore)malloc(sizeof(TipoNohArvore));
    arvore->dado = dado;
    arvore->subArvoreEsq = NULL;
    arvore->subArvoreDir = NULL;
    arvore->prox = NULL;
     
    return arvore;
}

int qtdNiveis(TipoArvore arvore, int nivel, int parametro, int n){
    if (arvore == NULL)
        return n;
    n = qtdNiveis(arvore->subArvoreEsq, nivel+1, parametro, n);
    if(nivel == parametro){
        n++;
    }
    n = qtdNiveis(arvore->subArvoreDir, nivel+1, parametro, n);
    return n;
}

int imprimeArvoreEmOrdem(TipoArvore arvore, int nivel, int parametro, int n){
    if (arvore == NULL)
        return n;
    n = imprimeArvoreEmOrdem(arvore->subArvoreEsq, nivel+1, parametro, n);
    if(nivel == parametro){
        n++;
        printf("%c ", arvore->dado, n);
    }
    n = imprimeArvoreEmOrdem(arvore->subArvoreDir, nivel+1, parametro, n);
    return n;
}

 
void empilha(TipoArvore arvore){
    if(pilha == NULL){
        pilha = arvore;
    }
    else{
        arvore->prox = pilha;
        pilha = arvore;
    }
}

TipoArvore removeNoh(){
    // Popping out the top most[ pointed with head] element
    TipoArvore aux;
    
    aux = pilha;
    pilha = pilha->prox;

    return aux;
}
