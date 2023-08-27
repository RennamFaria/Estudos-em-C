#include "infixa.h"

int main() {
  char string[50];

  printf("Digite uma expressao posfixa espaçadas(Ex: 1 2 +): ");
  fgets(string, sizeof(string), stdin);
  resolver_expressao(string);
  imprimePilha();
  
  return 0;
}