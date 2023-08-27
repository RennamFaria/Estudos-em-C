#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "posfixa.h"

int main(){
  TipoPilha pilha;
  TipoItem item;
  char string[100];

  inicializaPilha(&pilha);
  //limparString(&string);

  printf("Digite uma expressao posfixa: ");
  fgets(string, 100, stdin);
  if(!empilha(&pilha, string)){
    printf("Erro ao empilhar");
    }
  calculoPosfixa(&pilha, &item);
  imprimePilha(&pilha);
  //fputs(string, stdout);



  destroiPilha(&pilha);

  return 0;
}