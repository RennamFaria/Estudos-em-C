#include "infixa.h"

TipoNoh* empilhar(TipoNoh *pilha, float num){
                            
    TipoNoh *novo = malloc(sizeof(TipoNoh));

    if(novo){
        novo->valor = num;
        novo->proximo = pilha;
        return novo;
    }
    else
        printf("\tErro ao alocar memoria!\n");
    return NULL;
}

TipoNoh* desempilhar(TipoNoh **pilha){
    TipoNoh *remover = NULL;

    if(*pilha){
        remover = *pilha;
        *pilha = remover->proximo;
    }
    else
        printf("\tPilha vazia\n");
    return remover;
}

float operacao(float a, float b, char x){
    switch(x){
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '/':
        return a / b;
        break;
    case '*':
        return a * b;
        break;
    default:
        return 0.0;
    }
}

float resolver_expressao(char x[]){
    char *pt;
    float num;
    TipoNoh *n1, *n2, *pilha = NULL;

    pt = strtok(x, " ");
    while(pt){
        if(pt[0] == '+' || pt[0] == '-' || pt[0] == '/' || pt[0] == '*'){
            n1 = desempilhar(&pilha);
            n2 = desempilhar(&pilha);
            num = operacao(n2->valor, n1->valor, pt[0]);
            pilha = empilhar(pilha, num);
            free(n1);
            free(n2);
        }
        else{
            num = strtol(pt, NULL, 10);
            pilha = empilhar(pilha, num);
        }
        pt = strtok(NULL, " ");
    }
    n1 = desempilhar(&pilha);
    num = n1->valor;
    free(n1);
    return num;
}

void imprimePilha(TipoPilha pilha){
  TipoNoh *ptrAux;
  ptrAux = pilha;
  while(ptrAux!=NULL){
    imprimeItem(ptrAux->item);
    ptrAux = ptrAux->prox;
  }
}

void imprimeItem(TipoItem item){
  printf("%c\n",item.caracter);
}