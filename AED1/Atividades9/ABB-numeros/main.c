#include "ABB.h"

int main() {
  TipoArvore raiz;
  int dado, aux = 0;
  char opcao[10] = {"         "};

  raiz  = inicializaArvore(raiz);

   while(scanf("%s", opcao)!=EOF){
     //printf("o que foi escrito: %s\n\n", opcao);
    if (strcmp("I", opcao) == 0) { // se exatamente iguais retorna 0, logo entrara
      scanf("%d", &dado);    //que sera adicionada
      raiz = insereNaArvore(raiz, dado);
    }

    if (strncmp("INFIXA", opcao, 6) == 0) { // imprimir em Ordem
      if (!arvoreVazia(raiz))
        imprimeArvoreEmOrdem(raiz, 1);
        printf("\n");
    }

    if (strncmp("PREFIXA", opcao, 7) == 0) { // imprimir em Pre-Ordem
      if (!arvoreVazia(raiz))
        imprimeArvorePreOrdem(raiz, 1);
        printf("\n");
    }

    if (strncmp("POSFIXA", opcao, 7) == 0) { // imprimir em Pós-Ordem
      if (!arvoreVazia(raiz)) // se arvore nao esta vazia
        imprimeArvorePosOrdem(raiz, 1);
        printf("\n");
    }

    if (strcmp("P", opcao) == 0) {
      scanf("%d", &dado);
        if(procuraElemento(raiz, dado))
          printf("%d existe\n", dado);
        else
          printf("%d nao existe\n", dado);
        }
    if (strcmp("R", opcao) == 0) {
      if (!arvoreVazia(raiz)){ // se arvore nao esta vazia
        scanf("%d", &dado);    //que sera procurada
        raiz  = removeElemento(raiz, dado);
      }
    }
    }

  raiz = destroiArvore(raiz);

  return 0;
}