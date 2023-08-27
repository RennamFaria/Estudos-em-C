#include "posfixa.h"

int main() {
  char string[50];

  printf("Digite uma expressao posfixa espaçadas(Ex: 1 2 +): ");
  fgets(string, sizeof(string), stdin);
  printf("%0.1f\n", resolver_expressao(string));
}