#include "matrizEsparsa.h"
//TA DANDO ERRO

void imprimeMenu();

int main() {
  TipoMatriz mat;
  int op = 0;
  int linha, coluna, elemento;

  inicializaMatriz(&mat);

  printf("N. de linhas das Matriz: ");
  scanf("%d", &linha);
  printf("N. de colunas das Matriz: ");
  scanf("%d", &coluna);
  if(!instanciaMatriz(&mat, linha, coluna)){
    printf("\nErro ao instanciar a Matriz!");
  }

  while (op != 4) {
    imprimeMenu();
    scanf("%d", &op);
    switch (op) {
    case 1:
      printf("\nLinha: ");
      scanf("%d", &linha);
      printf("Coluna: ");
      scanf("%d", &coluna);
      printf("Elemento: ");
      scanf("%d", &elemento);
      insereNaMatriz(&mat, linha, coluna, elemento);
      printf("saiu");
      break;
    case 2:
      printf("\nLinha: ");
      scanf("%d", &linha);
      printf("Coluna: ");
      scanf("%d", &coluna);
      retiraDaMatriz(&mat, linha, coluna);
      break;
    case 3:
      printf("\nMatriz:\n");
      imprimeMatriz(&mat);
      break;
    case 4:
      destroiMatriz(&mat);
      break;
    default:
      printf("\nOpção incorreta!\n");
      break;
    }
  }
}

void imprimeMenu() {
  printf("\nMenu:");
  printf("\n1 - Insere na Matriz");
  printf("\n2 - Retira da Matriz");
  printf("\n3 - Imprime Matriz");
  printf("\n4 - Sair");
  printf("\nOpção: ");
}