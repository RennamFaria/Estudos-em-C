#include "AB.h"

int main(){
  TipoArvore raiz, pai, filho;
  int qtdTestes, qtdValores, i, f, nada = 0;
  char dado[100];

  raiz = inicializaArvore(raiz);
  limparVetor(dado);

  scanf("%d", &qtdTestes);

  for(i = 0; i<qtdTestes; i++){

    scanf("%d", &qtdValores);

    printf("\nPs: sempre de um espaço entre caracteres\n\n");

    for(f = 0; f < qtdValores; f++){
        scanf("%c", &dado[f]);

        if(f = 0)
            raiz = instanciaArvore(dado[f]);
        if(f = 2){
            filho = instanciaArvore(dado[f-1]);       //esq
            raiz = insereSubArvoreEsq(raiz, filho);
            filho = instanciaArvore(dado[f]);            //dir
            raiz = insereSubArvoreDir(raiz, filho);
        }
//dai vai indo com um monte de ifs

    }

    printf("\nCase %d:", i+1);
    printf("\nPre.:");
      imprimeArvorePreOrdem(raiz, nada);
    printf("\nIn..:");
      imprimeArvoreEmOrdem(raiz, nada);
    printf("\nPost:");
      imprimeArvorePosOrdem(raiz, nada);
    
    raiz = destroiArvore(raiz);
    
  }
  printf("\n");
  return 0;
}