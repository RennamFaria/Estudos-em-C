/////////////////////////ABB.h////////////////////////////////
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
 
struct nohArvore { // TipoArvore
  int dado;
  int fb; // fator de balanceamento: -1, 0, 1
  struct nohArvore *subArvoreEsq;
  struct nohArvore *subArvoreDir;
};
 
typedef struct nohArvore TipoNohArvore;
typedef TipoNohArvore *TipoArvore;
 
int arvoreVazia(TipoArvore);
TipoArvore inicializaArvore(TipoArvore);
TipoArvore destroiSubArvore(TipoArvore);
TipoArvore destroiArvore(TipoArvore);
TipoArvore insere(TipoArvore, int);
int alturaArvore(TipoArvore);
int calculaFB(TipoArvore);
TipoArvore insereNaArvore(TipoArvore, int);
TipoArvore rotacaoLL(TipoArvore);
TipoArvore rotacaoRR(TipoArvore);
TipoArvore rotacaoLR(TipoArvore);
TipoArvore rotacaoRL(TipoArvore);
TipoArvore balancearArvore(TipoArvore);
TipoArvore procuraElemento(TipoArvore, int, int *);
// TipoArvore removeNos(TipoArvore, int, int*);
TipoArvore removeElemento(TipoArvore, int, int *);
int imprimeArvoreEmOrdem(TipoArvore, int);
 
///////////////////////ABB.c////////////////////////////////
// Funções da Árvore
int arvoreVazia(TipoArvore arvore) { 
  return arvore == NULL;
}
 
TipoArvore inicializaArvore(TipoArvore arvore) { 
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
 
int alturaArvore(TipoArvore arvore) {  //provavelmente esta dando algum erro quando esta tendando calcular a altura e está dando erro de segment fault
  if (arvoreVazia(arvore))
    return -1;
  else {
    int esq = alturaArvore(arvore->subArvoreEsq); //-1
    int dir = alturaArvore(arvore->subArvoreDir); //-1
    if (esq > dir) {
      return esq + 1;
    } else
      return dir + 1;
  }
}
 
int calculaFB(TipoArvore arvore) {
  if (arvoreVazia(arvore))
    return 0;
  int esq = alturaArvore(arvore->subArvoreEsq);
  int dir = alturaArvore(arvore->subArvoreDir);
 
  return esq - dir;
}
 
TipoArvore insere(TipoArvore arvore, int dado) {
  int esq, dir;
 
  arvore = insereNaArvore(arvore, dado);
 
  return arvore;
}
 
TipoArvore insereNaArvore(TipoArvore arvore, int dado) {
  if (arvoreVazia(arvore)) { // se arvore vazia
    arvore = (TipoArvore)malloc(sizeof(TipoNohArvore));
    arvore->dado = dado;
    arvore->fb = 0;
    arvore->subArvoreDir = NULL;
    arvore->subArvoreEsq = NULL;
  } else { // se arvore nao vazia, valorAscii > ou <
    if (dado < arvore->dado) {
      arvore->subArvoreEsq = insereNaArvore(arvore->subArvoreEsq, dado);
    }
    if (dado > arvore->dado) {
      arvore->subArvoreDir = insereNaArvore(arvore->subArvoreDir, dado);
    }
  }
  // printf("\nEntrando para calcular o fb\n");
  arvore->fb = calculaFB(arvore);
 
  // printf("\nEntrando para balancear a arvore");
  arvore = balancearArvore(arvore);
 
  return arvore;
}
 
TipoArvore rotacaoLL(TipoArvore arvore) {
  TipoArvore pA, pB;
  pA = arvore;
 
  pB = pA->subArvoreEsq;
  pA->subArvoreEsq = pB->subArvoreDir;
  pB->subArvoreDir = pA;
  pA = pB;
 
  return pA;
}
 
TipoArvore rotacaoRR(TipoArvore arvore) {
  TipoArvore pA, pB;
  pA = arvore;
 
  pB = pA->subArvoreDir;
  pA->subArvoreDir = pB->subArvoreEsq;
  pB->subArvoreEsq = pA;
  pA = pB;
 
  return pA;
}
 
TipoArvore rotacaoLR(TipoArvore arvore) {
  TipoArvore pA, pB, pC;
  pA = arvore;
 
  pB = pA->subArvoreEsq;
  pC = pB->subArvoreDir;
  pB->subArvoreDir = pC->subArvoreEsq;
  pC->subArvoreEsq = pB;
  pA->subArvoreEsq = pC->subArvoreDir;
  pC->subArvoreDir = pA;
  pA = pC;
 
  return pA;
}
 
TipoArvore rotacaoRL(TipoArvore arvore) {
  TipoArvore pA, pB, pC;
  pA = arvore;
 
  pB = pA->subArvoreDir;
  pC = pB->subArvoreEsq;
  pB->subArvoreEsq = pC->subArvoreDir;
  pC->subArvoreDir = pB;
  pA->subArvoreDir = pC->subArvoreEsq;
  pC->subArvoreEsq = pA;
  pA = pC;
 
  return pA;
}
 
TipoArvore balancearArvore(TipoArvore arvore) {
  if (arvoreVazia(arvore))
    return NULL;
 
  int fatorBalanceamento = calculaFB(arvore);
 
  if (fatorBalanceamento > 1) {
    if (arvore->subArvoreEsq->fb >= 0) { // rotacao simples direita
      arvore = rotacaoLL(arvore);
    }
    if (arvore->subArvoreEsq->fb < 0) { // rotacao dupla à esquerda
      arvore = rotacaoLR(arvore);
    }
  } else if (fatorBalanceamento < -1) {
    if (arvore->subArvoreDir->fb <= 0) { // rotacao simples esquerda
      arvore = rotacaoRR(arvore);
    }
    if (arvore->subArvoreDir->fb > 0) { // rotacao dupla à esquerda
      arvore = rotacaoRL(arvore);
    }
  }
  arvore->fb = calculaFB(arvore);
 
  arvore->subArvoreEsq = balancearArvore(arvore->subArvoreEsq);
  arvore->subArvoreDir = balancearArvore(arvore->subArvoreDir);
 
  return arvore;
}
 
TipoArvore procuraElemento(TipoArvore arvore, int dado, int *aux) {
  if (arvore == NULL) {
    return arvore;
  }
  if (arvore->dado > dado){
    arvore = procuraElemento(arvore->subArvoreEsq, dado, aux);
    return arvore;
  }
  if (arvore->dado < dado){
    arvore = procuraElemento(arvore->subArvoreDir, dado, aux);
    return arvore;
  }
 
   if (arvore->dado == dado) {
    //printf("Valor %d encontrado", dado);
    (*aux) = alturaArvore(arvore);
    printf("%d", (*aux));
    (*aux) = alturaArvore(arvore->subArvoreEsq);//eu acho que aqui está o erro, esta mandando a arvore que é NULL
    printf(", %d", (*aux) + 1);
    (*aux) = alturaArvore(arvore->subArvoreDir);
    printf(", %d", (*aux) + 1);
     (*aux) = 1;
   }
  return arvore;
}
 
TipoArvore removeElemento(TipoArvore arvore, int dado, int *flag) {
  if (arvoreVazia(arvore)) {
    return arvore;
  }
 
  if (arvore->dado > dado)
    arvore->subArvoreEsq = removeElemento(arvore->subArvoreEsq, dado, flag);
 
  if (arvore->dado < dado)
    arvore->subArvoreDir = removeElemento(arvore->subArvoreDir, dado, flag);
 
  if (arvore->dado == dado) { // quando a arvore->dado = dado
    TipoArvore aux;
    (*flag)++;
 
    if (arvore->subArvoreEsq == NULL) {
      aux = arvore->subArvoreDir;
      free(arvore);
      return aux;
    }
    if (arvore->subArvoreDir == NULL) {
      aux = arvore->subArvoreEsq;
      free(arvore);
      return aux;
    }
    // remover nós que possuem 2 filhos
    else {
      aux = arvore->subArvoreDir;
      while (aux && aux->subArvoreEsq != NULL) // achando o sucessor
        aux = aux->subArvoreEsq;
      arvore->dado = aux->dado;
      arvore->subArvoreDir =
          removeElemento(arvore->subArvoreDir, aux->dado, flag);
    }
    // se nao achou o elemento, coloque na arvore
    // arvore = insereNaArvore(arvore, dado);
    arvore->fb = calculaFB(arvore);
    arvore = balancearArvore(arvore);
  }
  return arvore;
}
 
int imprimeArvoreEmOrdem(TipoArvore arvore, int marcador) { // remover dps essa funcao
  static int primeiro = 1;               // Marca se é o primeiro elemento
  if (arvoreVazia(arvore))
    return marcador;
 
  marcador = imprimeArvoreEmOrdem(arvore->subArvoreEsq, marcador);
 
  if (marcador != 1) // Se não for o primeiro,imprime espaço antes
    printf(" ");
  printf("dado = %d, fb = %d", arvore->dado, arvore->fb);
  if (arvore->subArvoreDir != NULL)
    printf(" subArvoreDir = %d", arvore->subArvoreDir->dado);
  if (arvore->subArvoreEsq != NULL)
    printf(" subArvoreEsq = %d", arvore->subArvoreEsq->dado);
  printf("\n");
  marcador = 0; // Atualiza o marcador
 
  marcador = imprimeArvoreEmOrdem(arvore->subArvoreDir, marcador);
 
  return marcador;
}
 
///////////////////main//////////////////////////////////
int main() {
  TipoArvore raiz;
  int dado, num, flag, i = 0, aux = 0;
 
  raiz = inicializaArvore(raiz);
 
  // printf("\nDigite um valor para inserir na arvore\n");
  while (1) {
    scanf("%d", &aux);
    if (aux < 0)
      break;
    raiz = insere(raiz, aux);
    //imprimeArvoreEmOrdem(raiz, 1);
  }
  aux = alturaArvore(raiz);
  printf("%d", aux);
  aux = alturaArvore(raiz->subArvoreEsq);
  printf(", %d", aux + 1);
  aux = alturaArvore(raiz->subArvoreDir);
  printf(", %d\n", aux + 1);
 
  //imprimeArvoreEmOrdem(raiz, 1);
 
  // printf("Digite os valores para ser removido ou inserido\n");
  while (1) {
    scanf("%d", &aux);
    if (aux < 0)
      break;
    flag = 0;
    raiz = removeElemento(raiz, aux, &flag);
    if (flag == 0) {
      // printf("o valor %d não está na arvore\n", aux);
      raiz = insere(raiz, aux);
    }
    //imprimeArvoreEmOrdem(raiz, 1);
  }
 
  aux = 0;
  scanf("%d", &num);
 
  raiz = procuraElemento(raiz, num, &aux);
  if (aux == 0) {
    printf("Valor nao encontrado");
  }
 
  raiz = destroiArvore(raiz);
  return 0;
}