#include "posfixa.h"

void inicializaPilha(TipoPilha *pilha){
    pilha->topo = NULL;
}

int pilhaVazia(TipoPilha *pilha){
  return pilha->topo==NULL;  
}

void destroiPilha(TipoPilha *pilha){
  TipoNoh *ptrAux;
  if(!pilhaVazia(pilha)){
    ptrAux = pilha->topo;
    while(ptrAux!=NULL){
      pilha->topo = ptrAux->prox;
      free(ptrAux);
      ptrAux = pilha->topo;
    }
  }
  return;
}
/*
void limparString(char string[]){
  int i;

  for(i = 0; i<=99; i++){
    string[i]=NULL;
  }
  return;
}
*/

int empilha(TipoPilha *pilha, char string[]){
  TipoNoh *novoNoh;
  int i;

    for(i = 0; string[i] != '\0'; i++){
      novoNoh = (TipoNoh *) malloc(sizeof(TipoNoh));
      if(novoNoh!=NULL){
        novoNoh->item.valor = string[i];
        novoNoh->prox = pilha->topo;
        pilha->topo = novoNoh;
        //printf("%d   %c", i, string[i]);
      }
      else
        return 0;
  }
  return 1;
}

int desempilha(TipoPilha *pilha,TipoItem *item){
  TipoNoh *ptrAux;
  if(!pilhaVazia(pilha)){
    ptrAux = pilha->topo;
    *item = ptrAux->item;
    pilha->topo = ptrAux->prox;
    free(ptrAux);
    return 1;
  } 
  return 0;
}

int calculoPosfixa(TipoPilha *pilha, TipoItem *item){
  int resultado;

  
  //voltar até o primiero valor do pilha
  //LEMBRAR DE USAR RECURSIVIDADE



  return resultado;
}

int consultaTopo(TipoPilha *pilha,TipoItem *item){
  if(!pilhaVazia(pilha)){
    *item = pilha->topo->item;
    return 1;
  } 
  return 0;
}

int imprimePilha(TipoPilha *pilha){
  TipoNoh *ptrAux;
  if(!pilhaVazia(pilha)){
    ptrAux = pilha->topo;
    while(ptrAux!=NULL){
      imprimeItem(ptrAux->item);
      ptrAux = ptrAux->prox;
    }
    return 1;
  } 
  return 0;
}

void imprimeItem(TipoItem item){
  printf("%c\n",item.valor);
  return;
}