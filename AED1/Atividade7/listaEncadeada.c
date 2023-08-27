#include "listaEncadeada.h"

int listaVazia(TipoLista lista){
  return lista==NULL;
}

TipoLista inicializaLista(TipoLista lista){
  return NULL;
}

TipoLista destroiLista(TipoLista lista){
  TipoNoh *ptrAux1, *ptrAux2;
  if(!listaVazia(lista)){
    ptrAux1 = lista;
    ptrAux2 = ptrAux1->prox;
    while(ptrAux1->prox != NULL){
      free(ptrAux1);
      ptrAux1 = ptrAux2;
      ptrAux2 = ptrAux1->prox;
    }
    free(ptrAux1);
  }
  return NULL;
}

void imprimeItem(TipoItem item){
  printf("%i\t",item.coluna,item.elemento);
}

void imprimeLista(TipoLista lista){
  TipoNoh *ptrAux;
  if(!listaVazia(lista)){
    ptrAux = lista;
    while(ptrAux != NULL){
      imprimeItem(ptrAux->item);
      ptrAux = ptrAux->prox;
    }
  }
}

TipoLista insereOrdenado(TipoLista lista,TipoItem item){//nao sei se vai funcionar 
                //pois caso nao necessariamente o item.coluna+1 sera o proximo vazio
  TipoNoh *novoNoh, *ptrAux, *ptrAux2;
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));

  ptrAux = lista;
  ptrAux2 = ptrAux->prox;
  if(!listaVazia(lista)){
    while(ptrAux->prox != NULL ){
    
    if(ptrAux->item.coluna == item.coluna){
      lista->item.elemento = item.elemento;    //substitui o elemento da lista
      //com o novo elemento
      return lista;
      }
    
    if(ptrAux->item.coluna < item.coluna && ptrAux2->item.coluna > item.coluna){
//ptrAux->item.coluna > item.coluna && ptrAux2->item.coluna < item.coluna

        ptrAux->prox = novoNoh;
        novoNoh->item = item;
        novoNoh->prox = ptrAux2;

      //posiciona o novo elemento entre outros dois elementos existentes 
      //na ordem crescente Ex: colocar a coluna6 depois da coluna5, 
      //SE EXISTIR COLUNA5!
      return lista;
    }
    if(ptrAux2->prox != NULL){
      ptrAux2->prox = novoNoh;
      novoNoh->item = item;
      novoNoh->prox = NULL;
    }

    ptrAux = ptrAux->prox;
    ptrAux2 = ptrAux->prox;
    }
  }
  else
    lista = novoNoh;
  
  return lista;
}
/*
TipoLista insereNoInicio(TipoLista lista,TipoItem item){
  TipoNoh *novoNoh;
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  novoNoh->item = item;
  novoNoh->prox = lista;
  lista = novoNoh;
  return lista;
}
*/

TipoLista removeEspecifico(TipoLista lista,int coluna,TipoItem *item){
  TipoNoh *ptrAux;
  
  if(!listaVazia(lista)){
    if(lista->item.coluna==coluna){
      ptrAux = lista;
      *item = ptrAux->item;
      lista = ptrAux->prox;
      free(ptrAux);
      return lista;
    }
    lista->prox = removeEspecifico(lista->prox,coluna,item);
    return lista;
  }
  return NULL;
}

TipoLista removeDoInicio(TipoLista lista, TipoItem *item){
  TipoNoh *ptrAux;
  if(!listaVazia(lista)){
    ptrAux = lista;
    *item = ptrAux->item;
    lista = ptrAux->prox;
    free(ptrAux);
    return lista;
  }
  return NULL;
}