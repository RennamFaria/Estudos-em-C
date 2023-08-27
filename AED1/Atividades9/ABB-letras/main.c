#include "ABB.h"

int main() {
  TipoArvore raiz;
  int aux = 0;
  char dado, opcao[10] = {"         "};

  raiz  = inicializaArvore(raiz);

   while(scanf("%s", opcao)!=EOF){
    
    if (strcmp("I", opcao) == 0) { // se exatamente iguais retorna 0, logo entrara
      scanf("%s", &dado);    //que sera adicionada
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
      scanf("%s", &dado);
        if(procuraElemento(raiz, dado))
          printf("%c existe\n", dado);
        else
          printf("%c nao existe\n", dado);
        }
    }

  raiz = destroiArvore(raiz);

  return 0;
}