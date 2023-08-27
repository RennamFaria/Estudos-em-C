#include "FilaDinamicaSenhas.h"

void inicializaFila(TipoFila *fila){
  fila->n = 0;
  fila->senhas = 0;
  fila->inicio = NULL;
  fila->fim = NULL;

  return;
}

void destroiFila(TipoFila *fila){
  TipoItem item;
  while(!filaVazia(fila)){
    retiraDaFila(fila,&item);
  }
  return;
}

void retiraDaFila(TipoFila *fila,TipoItem *item){
  TipoNoh *ptrAux;
  if(!filaVazia(fila)){
    ptrAux = fila->inicio;
    *item = ptrAux->item;
    if(fila->inicio==fila->fim){
      fila->inicio = NULL;
      fila->fim = NULL;
    }
    else{
      fila->inicio = ptrAux->prox;
    }
    free(ptrAux);
    fila->n--;
  }
  return;
}

int filaVazia(TipoFila *fila){
  return fila->n==0;
}

int gerarSenha(TipoFila *fila, TipoItem *item){
  int aux;

    fila->senhas++;
    aux = fila->senhas+1;    //ainda nao tera adicionado o +1 quando entrar aqui
    if(item->tipoSenha == 'P')    //se for preferencial
      item->numeroSenha = aux;
    if(item->tipoSenha == 'N')
      item->numeroSenha = aux;

    return 1;
}

int insereNaFila(TipoFila *fila,TipoItem item){
  TipoNoh *novoNoh;
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  if(novoNoh!=NULL){
    if(!filaVazia(fila)){
      fila->fim->prox = novoNoh;
    }
    else{
      fila->inicio = novoNoh;
    }
    fila->n++;
    novoNoh->item = item;
    novoNoh->prox = NULL;
    fila->fim = novoNoh;
    return 1;
  }
  return 0;
}

int retiraNormal(TipoFila *fila,TipoItem *item){
  TipoNoh *ptrAux;
  if(!filaVazia(fila)){
    ptrAux = fila->inicio;
    while(ptrAux->item.tipoSenha!='N' && ptrAux->prox!=NULL)    //andando na pelos Noh até achar preferencial
      ptrAux = ptrAux->prox;
    if(ptrAux->item.tipoSenha!='N' && ptrAux->prox==NULL)
      return 0;
    *item = ptrAux->item;
    free(ptrAux);
    fila->n--;
    return 1;
  }
  return 0;
}

int retiraPreferencial(TipoFila *fila,TipoItem *item){
  TipoNoh *ptrAux;
  if(!filaVazia(fila)){
    ptrAux = fila->inicio;
    while(ptrAux->item.tipoSenha!='P' && ptrAux->prox!=NULL)    //andando na pelos Noh até achar preferencial
      ptrAux = ptrAux->prox;
    if(ptrAux->item.tipoSenha!='P' && ptrAux->prox==NULL)
      return 0;
    *item = ptrAux->item;
    free(ptrAux);
    fila->n--;
    return 1;
  }
  return 0;
}

int imprimeFila(TipoFila *fila){
  TipoNoh *ptrAux;
  if(!filaVazia(fila)){
    ptrAux = fila->inicio;
    while(ptrAux!=NULL){
      imprimeItem(ptrAux->item);
      ptrAux = ptrAux->prox;
    }
    printf("%c %i\n",fila->inicio->item.tipoSenha, fila->inicio->item.numeroSenha);
    return 1;
  }
  return 0;
}

void imprimeItem(TipoItem item){
  if(item.tipoSenha=='P'||item.tipoSenha=='N')
    printf("%c %i\n",item.tipoSenha,item.numeroSenha);
}