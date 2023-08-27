/////////////////////////ABB.h////////////////////////////////
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct nohArvore { // TipoNoh
  int dado;   //fator de balanceamento: -1, 0, 1 ou cor
  int fb_cor; //cor: 0, se for negro; 1, se for rubro;
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
TipoArvore insereAVP(TipoArvore, int, int *);
TipoArvore rotacaoLL(TipoArvore);
TipoArvore rotacaoRR(TipoArvore);
TipoArvore rotacaoLR(TipoArvore);
TipoArvore rotacaoRL(TipoArvore);
TipoArvore balancearArvoreAVL(TipoArvore, int *);
TipoArvore coloracao(TipoArvore);
TipoArvore balancearArvoreAVP(TipoArvore, TipoArvore, int *);
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
    novoNoh->fb_cor = 1; // Rubro
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
    arvore = (TipoArvore)malloc(sizeof(TipoNohArvore));
    arvore->dado = dado;
    arvore->fb_cor = 0;    //fator de balanceamento
    arvore->subArvoreDir = NULL;
    arvore->subArvoreEsq = NULL;
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

TipoArvore insereAVP(TipoArvore arvore, int dado, int *countTurn) {
TipoArvore novoNoh = criarNoh(dado);

    if (arvore == NULL) {
        novoNoh->fb_cor = 0; // Define como negro
        return novoNoh;
    }

    TipoArvore atual = arvore;
    TipoArvore pai = NULL;

    while (atual != NULL) {
        pai = atual;

        if (dado < atual->dado) {
            atual = atual->subArvoreEsq;
        } else if (dado > atual->dado) {
            atual = atual->subArvoreDir;
        } else {
            free(novoNoh); // Dado já existe na árvore
            return arvore;
        }
    }

    if (dado < pai->dado) {
        pai->subArvoreEsq = novoNoh;
    } else {
        pai->subArvoreDir = novoNoh;
    }

    novoNoh->subArvorePai = pai;

   printf("\nEntrando para balancear a arvore");
    arvore = balancearInsercao(arvore, novoNoh);

  printf("saiu\n");

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

TipoArvore coloracao(TipoArvore arvore){
    arvore->fb_cor = 1 - arvore->fb_cor;
    if (arvore->subArvoreEsq != NULL) {
      arvore->subArvoreEsq->fb_cor = 1 - arvore->subArvoreEsq->fb_cor;
    }
    if (arvore->subArvoreDir != NULL) {
      arvore->subArvoreDir->fb_cor = 1 - arvore->subArvoreDir->fb_cor;
    }
  
  return arvore;
}

TipoArvore balancearArvoreAVP(TipoArvore raiz, TipoArvore noh, int *countTurn) {
    // Caso 1: Nó é a raiz
    if (noh->subArvorePai == NULL) {
        noh->fb_cor = 0; // Define como negro
        return noh;
    }

    TipoArvore pai = noh->subArvorePai;
    TipoArvore avo = NULL;
    TipoArvore tio = NULL;

    // Caso 2: Pai é negro
    if (pai->fb_cor == 0) {
        return raiz; // Árvore já está balanceada
    }

    avo = pai->subArvorePai;

    // Caso 3: Pai e tio são rubros
    if (avo != NULL) {
        if (pai == avo->subArvoreEsq) {
            tio = avo->subArvoreDir;
        } else {
            tio = avo->subArvoreEsq;
        }
    }

    if (tio != NULL && tio->fb_cor == 1) {
        pai->fb_cor = 0;
        tio->fb_cor = 0;
        avo->fb_cor = 1;
        return balancearInsercao(raiz, avo);
    }

    // Caso 4: Rotações e inversão de cores
    if (pai == avo->subArvoreEsq) {
        if (noh == pai->subArvoreDir) {
            raiz = rotacaoEsquerda(pai);
            noh = noh->subArvoreEsq;
        }
        raiz = rotacaoDireita(avo);
    } else {
        if (noh == pai->subArvoreEsq) {
            raiz = rotacaoDireita(pai);
            noh = noh->subArvoreDir;
        }
        raiz = rotacaoEsquerda(avo);
    }

    pai->fb_cor = 0;
    avo->fb_cor = 1;
    inverterCor(raiz);

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
    raizAVL = insereAVL(raizAVL, aux, &countTurnAVL);
    raizAVP = insereAVP(raizAVP, aux, &countTurnAVP);
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