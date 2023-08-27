/////////////////////////arvoreBinaria.h///////////////////////////////

#include <stdio.h>
#include <stdlib.h>

struct nohArvore { // TipoArvore
  int dado;
  int nivel;
  struct nohArvore *subArvoreEsq;
  struct nohArvore *subArvoreDir;
};

typedef struct nohArvore TipoNohArvore;

typedef TipoNohArvore *TipoArvore;

int arvoreVazia(TipoArvore);
TipoArvore inicializaArvore(TipoArvore);
TipoArvore destroiSubArvore(TipoArvore);
TipoArvore destroiArvore(TipoArvore);
TipoArvore insereNaArvore(TipoArvore, int, int);
int procuraNivelMax(TipoArvore, int);
int imprimeArvorePreOrdem(TipoArvore, int, int);

////////////////////////arvoreBinaria.c//////////////////////////

// Funções da Árvore
int arvoreVazia(TipoArvore arvore) {
return arvore == NULL; 
}

TipoArvore inicializaArvore(TipoArvore arvore){ 
  return NULL; 
}

TipoArvore destroiSubArvore(TipoArvore arvore) {
  if (arvoreVazia(arvore)) // se ArvoVaz volte uma recursao
    return NULL;
  destroiSubArvore(arvore->subArvoreEsq);
  destroiSubArvore(arvore->subArvoreDir);
  free(arvore);

  return NULL;
}

TipoArvore destroiArvore(TipoArvore arvore) {
  if (arvoreVazia(arvore)) // se arvore vazia nao ha nada para destruir dinamicamente
    return NULL;
  arvore = destroiSubArvore(arvore);
  free(arvore);
  return NULL;
}

TipoArvore insereNaArvore(TipoArvore arvore, int dado, int nivel) {
  if (arvoreVazia(arvore)) { // se arvore vazia
    arvore = (TipoArvore)malloc(sizeof(TipoNohArvore));
    arvore->dado = dado;
    arvore->nivel = nivel;
    arvore->subArvoreDir = NULL;
    arvore->subArvoreEsq = NULL;
  } 
  else { // se arvore nao vazia, valorAscii > ou <
    if (dado < arvore->dado) {
      nivel++;
      arvore->subArvoreEsq = insereNaArvore(arvore->subArvoreEsq, dado, nivel);
    }
    if (dado > arvore->dado) {
      nivel++;
      arvore->subArvoreDir = insereNaArvore(arvore->subArvoreDir, dado, nivel);
    }
  }

  return arvore;
}

int procuraNivelMax(TipoArvore arvore, int max){
  if (arvoreVazia(arvore))
    return max;

  if(arvore->nivel > max){
    max = arvore->nivel;
  }

  max = procuraNivelMax(arvore->subArvoreEsq, max);
  max = procuraNivelMax(arvore->subArvoreDir, max);


  return max;
}

int imprimeArvorePreOrdem(TipoArvore arvore, int marcador, int nivel) {
  if (arvoreVazia(arvore))
    return marcador;
  
  if(arvore->nivel == nivel){
    if(marcador != 1)//Se não for o primeiro,imprime espaço antes
      printf(" ");
    printf("%d", arvore->dado);
    marcador = 0; // Atualiza o marcador
  }
  
  marcador = imprimeArvorePreOrdem(arvore->subArvoreEsq, marcador, nivel);
  marcador = imprimeArvorePreOrdem(arvore->subArvoreDir, marcador, nivel);

  return marcador;
}

////////////////////////////////main.c/////////////////////////////

int main(){
  TipoArvore raiz;
  int qtdTestes, qtdValores, dado, i, f, max, nivel, marcador;

  raiz = inicializaArvore(raiz);

  scanf("%d", &qtdTestes);

  for(i = 0; i<qtdTestes; i++){

    scanf("%d", &qtdValores);

    for(f = 0; f < qtdValores; f++){
      scanf("%d", &dado);

      raiz = insereNaArvore(raiz, dado, 0);
    }

    max = procuraNivelMax(raiz, 0);  //funcao que procura o nivel max da arvore binaria de busca
    printf("Case %d:\n", i+1);

    for(marcador = 1, nivel  = 0; nivel != (max+1); nivel++)    //repita enquanto max é maior ou igual a zero
      imprimeArvorePreOrdem(raiz, marcador, nivel);
    
    raiz = destroiArvore(raiz);
    
    printf("\n");
  }
  return 0;
}