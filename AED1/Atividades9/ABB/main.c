#include "ABB.h"

//arvore binaria mas com o sistema de organização de busca baseada no valor ASCII de cada caracter e não da ordem que é digitado
//Ex: C < T < W     pois    67 < 84 < 87
int main() {
  TipoArvore raiz;
  int opcao, nada = 0;
  char dado;

  inicializaArvore(raiz);

  do {
    opcao = menu();

    switch (opcao) {
    case 1: // inserir algum caracter
      printf("\nDigite um caracter:");
      scanf("%c", &dado);
      raiz = insereNaArvore(raiz, dado);
      break;

    case 2: // imprimir em Pre-Ordem
      if (!arvoreVazia(raiz))
        imprimeArvorePreOrdem(raiz, nada);
      else
        printf("\nNao ha nenhuma sub-arvore na raiz para que possa imprimir em Pre-Ordem\n");
      break;

    case 3: // imprimir em Ordem
      if (!arvoreVazia(raiz))
        imprimeArvoreEmOrdem(raiz, nada);
      else
        printf("\nNao ha nenhuma sub-arvore na raiz para que possa imprimir em Ordem\n");
      break;

    case 4:                   // imprimir em Pós-Ordem
      if (!arvoreVazia(raiz)) // se arvore nao esta vazia
        imprimeArvorePosOrdem(raiz, nada);
      else
        printf("\nNao exite nenhuma sub-arvore na raiz para que possa imprimir em Pos-Ordem\n");
      break;

    case 0: // sair
      printf("\nEncerrando programa");
      raiz = destroiArvore(raiz);
      break;

    default:
      printf("\nOpcao errada!, encerrando");
      raiz = destroiArvore(raiz);
      break;
    }
  } while (opcao > 0 && opcao < 5);

  return 0;
}

int menu() {
  int opcao;

  printf("\nDigite uma das opcoes");
  printf("\n\n(1) Inserir um caracter");
  printf("\n(2) Imprimir em Pre-Ordem");
  printf("\n(3) Imprimir em Ordem");
  printf("\n(4) Imprimir em Pos-Ordem");
  printf("\n(0) Sair\n");

  scanf("%d", &opcao);
  getchar();

  return opcao;
}