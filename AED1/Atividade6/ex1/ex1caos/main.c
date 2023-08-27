#include "posfixa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char string[100];
  int resultado;
  // limparString(&string);

  printf("Digite uma expressao posfixa: ");
  fgets(string, sizeof(string), stdin);
  string[strlen(string) - 1] = '\0';

  // imprimePilha(pilha);
  resultado = calculoPosfixa(string);
  printf("\nResultado: %d\n", resultado);

  return 0;
}

/*
if(!(string[i] >= '0' && string[i] <= '9')){
          switch(string[i]){
            case '+':
              printf("\nPositivo");
              simbolo = 1;    //1 = +
              break;

            case '-':
              printf("\nNegativo");
              simbolo = 2;    //2 = -
              break;

            case '*':
              printf("\nvezes");
              simbolo = 3;    //3 = *
              break;

            case '/':
              printf("\nbarra");
              simbolo = 4;    //4 = /
              break;

            case '\n':
              break;

            default:
              printf("Simbolo %c e invalido para a operação", string[i]);
              return 0;
              break;
          }
        }
        calculoPosfixa(pilha, item, simbolo);
      }
      else
        return 0;
      }

*/