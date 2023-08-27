/////////////////////////ABB.h////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nohArvore { // TipoArvore
  char dado;
  struct nohArvore *subArvoreEsq;
  struct nohArvore *subArvoreDir;
};

typedef struct nohArvore TipoNohArvore;

typedef TipoNohArvore *TipoArvore;

int arvoreVazia(TipoArvore);
TipoArvore inicializaArvore(TipoArvore);
TipoArvore destroiSubArvore(TipoArvore);
TipoArvore destroiArvore(TipoArvore);
TipoArvore insereNaArvore(TipoArvore, char);
int procuraElemento(TipoArvore, char);
int imprimeArvoreEmOrdem(TipoArvore, int);
int imprimeArvorePreOrdem(TipoArvore, int);
int imprimeArvorePosOrdem(TipoArvore, int);

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

TipoArvore insereNaArvore(TipoArvore arvore, char dado) {
  if(arvoreVazia(arvore)){ // se arvore vazia
    arvore = (TipoArvore)malloc(sizeof(TipoNohArvore));
    arvore->dado = dado;
    arvore->subArvoreDir = NULL;
    arvore->subArvoreEsq = NULL;
  } 
  else { // se arvore nao vazia, valorAscii > ou <
    if (dado < arvore->dado) {
      arvore->subArvoreEsq = insereNaArvore(arvore->subArvoreEsq, dado);
    }
    if (dado > arvore->dado) {
      arvore->subArvoreDir = insereNaArvore(arvore->subArvoreDir, dado);
    }
  }
  return arvore;
}


int procuraElemento(TipoArvore arvore, char dado) {
    if(arvore == NULL)
        return 0;
    TipoArvore ArvoreAux = arvore;
    while(ArvoreAux != NULL) {
        if(dado == ArvoreAux->dado)
            return 1;
        if(dado > ArvoreAux->dado)
            ArvoreAux = ArvoreAux->subArvoreDir;
        else
            ArvoreAux = ArvoreAux->subArvoreEsq;
    }
    return 0;
}

int imprimeArvoreEmOrdem(TipoArvore arvore, int marcador) {
  if (arvoreVazia(arvore))
    return marcador;

  marcador = imprimeArvoreEmOrdem(arvore->subArvoreEsq, marcador);

  if(marcador != 1)//Se não for o primeiro,imprime espaço antes
    printf(" ");
  printf("%c", arvore->dado);
  marcador = 0; // Atualiza o marcador

  marcador = imprimeArvoreEmOrdem(arvore->subArvoreDir, marcador);

  return marcador;
}

int imprimeArvorePreOrdem(TipoArvore arvore, int marcador) {
  if (arvoreVazia(arvore))
    return marcador;
  
  if(marcador != 1)//Se não for o primeiro,imprime espaço antes
    printf(" ");
  printf("%c", arvore->dado);
  marcador = 0; // Atualiza o marcador
  
  marcador = imprimeArvorePreOrdem(arvore->subArvoreEsq, marcador);
  marcador = imprimeArvorePreOrdem(arvore->subArvoreDir, marcador);

  return marcador;
}

int imprimeArvorePosOrdem(TipoArvore arvore, int marcador) {
if (arvoreVazia(arvore))
    return marcador;

  marcador = imprimeArvorePosOrdem(arvore->subArvoreEsq, marcador);
  marcador = imprimeArvorePosOrdem(arvore->subArvoreDir, marcador);
  
  if(marcador != 1)//Se não for o primeiro,imprime espaço antes
    printf(" ");
  printf("%c", arvore->dado);
  marcador = 0;
  
  return marcador;
}
///////////////////main//////////////////////////////////
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