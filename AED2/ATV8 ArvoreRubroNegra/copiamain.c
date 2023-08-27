/////////////////////////ABB.h////////////////////////////////
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct nohArvore { // TipoNoh
  int dado;   //fator de balanceamento: -1, 0, 1 ou cor
  int fb_cor; //cor: 0, se for negro; 1, se for rubro;
  struct nohArvore *subArvorePai;
  struct nohArvore *subArvoreEsq;
  struct nohArvore *subArvoreDir;
};

typedef struct nohArvore TipoNohArvore;
typedef TipoNohArvore *TipoArvore;

int arvoreVazia(TipoArvore);
TipoArvore inicializaArvore(TipoArvore);
TipoArvore criarNoh(int);
TipoArvore destroiSubArvore(TipoArvore);
TipoArvore destroiArvore(TipoArvore);
int alturaArvore(TipoArvore);
int calculaFB(TipoArvore);
TipoArvore insereAVL(TipoArvore, int, int *);
TipoArvore insereAVPnaArvore(TipoArvore, int, TipoArvore);
TipoArvore rotacaoLL(TipoArvore);
TipoArvore rotacaoRR(TipoArvore);
TipoArvore rotacaoLR(TipoArvore);
TipoArvore rotacaoRL(TipoArvore);
TipoArvore balancearArvoreAVL(TipoArvore, int *);
// TipoArvore coloracao(TipoArvore);
void balancearEsq(TipoArvore, TipoArvore, TipoArvore);
void balancearDir(TipoArvore, TipoArvore, TipoArvore);
TipoArvore insereAVP(TipoArvore, int);
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

TipoArvore criarNoh(int dado) {
    TipoArvore novoNoh = (TipoArvore)malloc(sizeof(TipoNohArvore));
    novoNoh->dado = dado;
    novoNoh->fb_cor = 0;
    novoNoh->subArvorePai = NULL;
    novoNoh->subArvoreEsq = NULL;
    novoNoh->subArvoreDir = NULL;
    return novoNoh;
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
//no slide 30 ensinando rubro negro diz que quando a arvore é vazia inserir como negro, mas eu nao sei se devo criar um if para quando a arvore seja vazia ou deixo o proprio programa resolver isso quando for passar na hora do balanceamento, caso eu use um if diminuiria 1 na contagem do balanceamento Rubro negro.
TipoArvore insereAVL(TipoArvore arvore, int dado, int *countTurn) {
  if (arvoreVazia(arvore)) { // se arvore vazia
    arvore = criarNoh(dado);
    arvore->fb_cor = 0;
  } else { // se arvore nao vazia, valorAscii > ou <
    if (dado < arvore->dado) {
      arvore->subArvoreEsq = insereAVL(arvore->subArvoreEsq, dado, countTurn);
    }
    if (dado > arvore->dado) {
      arvore->subArvoreDir = insereAVL(arvore->subArvoreDir, dado, countTurn);
    }
  }
  arvore->fb_cor = calculaFB(arvore);

  // printf("\nEntrando para balancear a arvore");
  arvore = balancearArvoreAVL(arvore, countTurn);

  return arvore;
}

TipoArvore insereAVPnaArvore(TipoArvore arvore, int dado, TipoArvore atual) {

    if (arvore == NULL) {
        arvore = criarNoh(dado);
        arvore->fb_cor = 1; // Rubro
        atual = arvore;
        return arvore;
    }else{
      if (dado < arvore->dado) {
        TipoArvore criancaEsq = insereAVPnaArvore(arvore->subArvoreEsq, dado, atual);
        arvore->subArvoreEsq = criancaEsq;
        criancaEsq->subArvorePai = arvore;
      }
      if (dado > arvore->dado) {
        TipoArvore criancaDir = insereAVPnaArvore(arvore->subArvoreDir, dado, atual);
        arvore->subArvoreDir = criancaDir;
        criancaDir->subArvorePai = arvore;
      }
    }

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

TipoArvore balancearArvoreAVL(TipoArvore arvore, int *countTurn) {
  if (arvoreVazia(arvore))
    return NULL;

  int fatorBalanceamento = calculaFB(arvore);

  if (fatorBalanceamento > 1) {
    if (arvore->subArvoreEsq->fb_cor >= 0) { // rotacao simples direita
      (*countTurn)++;
      arvore = rotacaoLL(arvore);
    }
    if (arvore->subArvoreEsq->fb_cor < 0) { // rotacao dupla à esquerda
      (*countTurn)++;
      arvore = rotacaoLR(arvore);
    }
  } else if (fatorBalanceamento < -1) {
    if (arvore->subArvoreDir->fb_cor <= 0) { // rotacao simples esquerda
      (*countTurn)++;
      arvore = rotacaoRR(arvore);
    }
    if (arvore->subArvoreDir->fb_cor > 0) { // rotacao dupla à esquerda
      (*countTurn)++;
      arvore = rotacaoRL(arvore);
    }
  }
  arvore->fb_cor = calculaFB(arvore);

  arvore->subArvoreEsq = balancearArvoreAVL(arvore->subArvoreEsq, countTurn);
  arvore->subArvoreDir = balancearArvoreAVL(arvore->subArvoreDir, countTurn);

  return arvore;
}

TipoArvore rotacaoEsquerda(TipoArvore noh) {
    TipoArvore novoNoh = noh->subArvoreDir;
    noh->subArvoreDir = novoNoh->subArvoreEsq;
    if (novoNoh->subArvoreEsq != NULL) {
        novoNoh->subArvoreEsq->subArvorePai = noh;
    }
    novoNoh->subArvorePai = noh->subArvorePai;
    if (noh->subArvorePai == NULL) {
        return novoNoh;
    } else if (noh == noh->subArvorePai->subArvoreEsq) {
        noh->subArvorePai->subArvoreEsq = novoNoh;
    } else {
        noh->subArvorePai->subArvoreDir = novoNoh;
    }
    novoNoh->subArvoreEsq = noh;
    noh->subArvorePai = novoNoh;
    return noh;
}

// Função auxiliar para realizar a rotação à direita
TipoArvore rotacaoDireita(TipoArvore noh) {
    TipoArvore novoNoh = noh->subArvoreEsq;
    noh->subArvoreEsq = novoNoh->subArvoreDir;
    if (novoNoh->subArvoreDir != NULL) {
        novoNoh->subArvoreDir->subArvorePai = noh;
    }
    novoNoh->subArvorePai = noh->subArvorePai;
    if (noh->subArvorePai == NULL) {
        return novoNoh;
    } else if (noh == noh->subArvorePai->subArvoreEsq) {
        noh->subArvorePai->subArvoreEsq = novoNoh;
    } else {
        noh->subArvorePai->subArvoreDir = novoNoh;
    }
    novoNoh->subArvoreDir = noh;
    noh->subArvorePai = novoNoh;
  
    return noh;
}
void balancearEsq(TipoArvore atual, TipoArvore pai, TipoArvore avo){
  TipoArvore tio;
  tio = avo->subArvoreDir;

  if(tio->fb_cor == 1){
    pai->fb_cor = 0;
    avo->fb_cor = 1;
    tio->fb_cor = 0;
    atual = avo;
  }else{
    if(pai->subArvoreDir == atual){
      pai = rotacaoLL(pai);
      atual = atual->subArvoreEsq;
    }
    pai->fb_cor = 0;
    avo->fb_cor = 1;
    avo = rotacaoRR(avo);
  }
  return;
}

void balancearDir(TipoArvore atual, TipoArvore pai, TipoArvore avo){
  TipoArvore tio;
  tio = avo->subArvoreEsq;

  if(tio->fb_cor == 1){
    pai->fb_cor = 0;
    avo->fb_cor = 1;
    tio->fb_cor = 0;
    atual = avo;
  }else{
    if(pai->subArvoreDir == atual){
      pai = rotacaoLL(pai);
      atual = atual->subArvoreEsq;
    }
    pai->fb_cor = 0;
    avo->fb_cor = 1;
    avo = rotacaoRR(avo);
  }
  return;
}


// TipoArvore coloracao(TipoArvore arvore){
//     arvore->fb_cor = 1 - arvore->fb_cor;
//     if (arvore->subArvoreEsq != NULL) {
//       arvore->subArvoreEsq->fb_cor = 1 - arvore->subArvoreEsq->fb_cor;
//     }
//     if (arvore->subArvoreDir != NULL) {
//       arvore->subArvoreDir->fb_cor = 1 - arvore->subArvoreDir->fb_cor;
//     }
  
//   return arvore;
// }

TipoArvore insereAVP(TipoArvore raiz, int dado) {
  TipoArvore atual, pai, avo;
printf("teste1");
  raiz = insereAVPnaArvore(raiz, dado, atual);
  printf("teste2");
imprimeArvoreEmOrdem(raiz, 0);
  atual = raiz; 
  while(atual != raiz && atual->subArvorePai->fb_cor == 1){
    printf("teste3");
    pai = atual->subArvorePai;
    avo = pai->subArvorePai;
    if(avo->subArvoreEsq == pai){
      printf("teste4");
      balancearEsq(atual, pai, avo);
      printf("teste5");
    }
    else{
      printf("teste6");
      balancearDir(atual, pai, avo);
      printf("teste7");
    }
  }
  raiz->fb_cor = 0;    
  
  return raiz;
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

int imprimeArvoreEmOrdem(TipoArvore arvore, int marcador) { // remover dps essa funcao
  static int primeiro = 1;               // Marca se é o primeiro elemento
  if (arvoreVazia(arvore))
    return marcador;

  marcador = imprimeArvoreEmOrdem(arvore->subArvoreEsq, marcador);

  if (marcador != 1) // Se não for o primeiro,imprime espaço antes
    printf(" ");
  printf("dado = %d, fb_cor = %d", arvore->dado, arvore->fb_cor);
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
  TipoArvore raizAVL;
  TipoArvore raizAVP;
  int dado, num, flag, i = 0, aux = 0;
  int countCor = 0, countTurnAVP = 0, countTurnAVL = 0;

  raizAVL = inicializaArvore(raizAVL);
  raizAVP = inicializaArvore(raizAVP);

  // printf("\nDigite um valor para inserir na arvore\n");
  while (1) {
    scanf("%d", &aux);
    if (aux < 0)
      break;
    printf("teste-1");
    raizAVL = insereAVL(raizAVL, aux, &countTurnAVL);
    printf("teste0");
    raizAVP = insereAVP(raizAVP, aux);
    printf("\narvoreAVL\n");
  imprimeArvoreEmOrdem(raizAVL, 1);
  printf("\narvoreAVP\n");
  imprimeArvoreEmOrdem(raizAVP, 1);
  }
  
  aux = alturaArvore(raizAVL);
  printf("%d", aux);
  aux = alturaArvore(raizAVL->subArvoreEsq);
  printf(", %d", aux + 1);
  aux = alturaArvore(raizAVL->subArvoreDir);
  printf(", %d\n", aux + 1);

  aux = alturaArvore(raizAVP);
  printf("%d", aux);
  aux = alturaArvore(raizAVP->subArvoreEsq);
  printf(", %d", aux + 1);
  aux = alturaArvore(raizAVP->subArvoreDir);
  printf(", %d\n", aux + 1);

  //imprimeArvoreEmOrdem(raizAVL, 1);
  //imprimeArvoreEmOrdem(raizAVP, 1);
  
  // aux = alturaNegra(raizAVP);
  // printf("%d\n", aux);

  // printf("%d", countCor);
  // aux = alturaArvore(raizAVP->subArvoreEsq);
  // printf(", %d", countTurnAVP);
  // aux = alturaArvore(raizAVP->subArvoreDir);
  printf(", %d", countTurnAVL);

  raizAVL = destroiArvore(raizAVL);
  raizAVP = destroiArvore(raizAVP);
  return 0;
}