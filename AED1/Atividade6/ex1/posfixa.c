#include "posfixa.h"

TipoPilha inicializaPilha(TipoPilha pilha){
  return NULL;  
}

int pilhaVazia(TipoPilha pilha){
  return pilha==NULL;
}

TipoPilha destroiPilha(TipoPilha pilha){
  TipoNoh *ptrAux;
  while(pilha!=NULL){
    ptrAux = pilha;
    pilha = pilha->prox;
    free(ptrAux);
  }
  return NULL;
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

TipoPilha empilha(TipoPilha pilha,TipoItem item){
  TipoNoh *novoNoh;

  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  novoNoh->item = item;
  novoNoh->prox = pilha;

  return novoNoh;
}

TipoPilha desempilha(TipoPilha pilha,TipoItem *item){
  TipoNoh *ptrAux;

  if(!pilhaVazia(pilha)){
    ptrAux = pilha;
    pilha = ptrAux->prox;
    *item = ptrAux->item;
    free(ptrAux);

    return pilha;
  }

  return NULL;
}

int calculoPosfixa(char *string){
  TipoPilha pilha, pilhaAux;
  TipoItem item;
  int i, n1, n2, resultado;

  pilha = inicializaPilha(pilhaAux);
  pilhaAux = inicializaPilha(pilhaAux);
  
  for(i=0;i<strlen(string);i++){
    item.valor = string[i];
    pilha = empilha(pilha, item);
  }

  while(!pilhaVazia(pilha)){
    pilha = desempilha(pilha, &item);
    if(item.valor=='+'||item.valor=='-'||item.valor=='*'||item.valor=='/'){
      pilhaAux = empilha(pilhaAux,item);
    }
    else{
      n1 = item.valor;
      pilha = desempilha(pilha,&item);

      n2 = item.valor;
      pilhaAux = desempilha(pilhaAux,&item);
      switch(item.valor){
        case '+':
          resultado = n1+n2;
          break;
        case '-':
          resultado = n1-n2;
          break;
        case '*':
          resultado = n1*n2;
          break;
        case '/':
          resultado = n1/n2;
          break;
      }
      item.valor = resultado + '0';
      if(pilhaVazia(pilha)){
        break;
      }
      else{
        pilha = empilha(pilha, item);
      }
    }
    printf("\nPilha 1:\n");
    imprimePilha(pilha);

    printf("\nPilha Aux:\n");
    imprimePilha(pilha);
  }
  
  pilha = destroiPilha(pilha);
  pilhaAux = destroiPilha(pilhaAux);

  return resultado;
}

void imprimePilha(TipoPilha pilha){
  TipoNoh *ptrAux;
  
  ptrAux = pilha;
  while(ptrAux!=NULL){
    imprimeItem(ptrAux->item);
    ptrAux = ptrAux->prox;
  }
  return;
}

void imprimeItem(TipoItem item){
  printf("%c\n",item.valor);
  return;
}