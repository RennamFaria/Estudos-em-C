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
  int i, j, n1, n2, resultado = 'c';

  pilha = inicializaPilha(pilha);
  pilhaAux = inicializaPilha(pilhaAux);
  
  for(i = 0; i<strlen(string); i++){
    item.valor[0] = string[i];
    item.valor[1] = '\n';
    item.valor[2] = '\n';
    pilha = empilha(pilha, item);
  }

  while(!pilhaVazia(pilha)){
    pilha = desempilha(pilha, &item);
    if(item.valor[0]=='+'||item.valor[0]=='-'||item.valor[0]=='*'||item.valor[0]=='/'){
      pilhaAux = empilha(pilhaAux,item);
    }
    else{
      for(j = 0; item.valor[j] != '\n'; j++){
      }
      printf("%d", j);
      if(j < 2){
        //printf("valor %c     valor %c", item.valor[0], item.valor[1]);
      n1 = item.valor[0];
      pilha = desempilha(pilha,&item);

      n2 = item.valor[0];
      pilhaAux = desempilha(pilhaAux,&item);
      }
      else{
      n1 = ((item.valor[3]*1000)+(item.valor[2]*100)+(item.valor[1]*10)+item.valor[0]);
      printf("n1: %d", n1);
      pilha = desempilha(pilha,&item);

      n2 = ((item.valor[3]*1000)+(item.valor[2]*100)+(item.valor[1]*10)+item.valor[0]);
      printf("n2: %d", n2);
      pilhaAux = desempilha(pilhaAux,&item);
      }

      switch(item.valor[0]){
        case '+':
          resultado = resultado+n2;
          break;
        case '-':
          resultado = resultado-n2;
          break;
        case '*':
          resultado = resultado*n2;
          break;
        case '/':
          resultado = resultado/n2;
          break;
      }
      for(i = 0, j = 10; j<resultado; i++, j*10){
        item.valor[i] = resultado + '0';

      }
      item.valor[0] = resultado + '0';
      if(pilhaVazia(pilha)){
        break;
      }
      else{
        printf("reesultado: %d", resultado);
        //pilha = empilha(pilha, item);
      }
    }
    printf("\nPilha 1:\n");
    imprimePilha(pilha);

    printf("\nPilha Aux:\n");
    imprimePilha(pilhaAux);
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
  printf("%c\n",item.valor[0]);
  return;
}