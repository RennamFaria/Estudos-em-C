/////////////////////////ABB.h////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nohArvore { // TipoArvore
  int dado;
  struct nohArvore *subArvoreEsq;
  struct nohArvore *subArvoreDir;
};

typedef struct nohArvore TipoNohArvore;

typedef TipoNohArvore *TipoArvore;

int arvoreVazia(TipoArvore);
TipoArvore inicializaArvore(TipoArvore);
TipoArvore destroiSubArvore(TipoArvore);
TipoArvore destroiArvore(TipoArvore);
TipoArvore insereNaArvore(TipoArvore, int);
int procuraElemento(TipoArvore, int, int);
TipoArvore removeNos(TipoArvore, int);
TipoArvore removeElemento(TipoArvore, int);
int imprimeArvoreEmOrdem(TipoArvore, int);
void imprimeArvorePreOrdem(TipoArvore, int);
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

TipoArvore insereNaArvore(TipoArvore arvore, int dado) {
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

int procuraElemento(TipoArvore arvore, int dado, int aux){
  if (arvoreVazia(arvore))
    return aux;

  if(dado == arvore->dado){
    printf("%d existe\n", dado);
    aux++;
  }
  aux = procuraElemento(arvore->subArvoreEsq, dado, aux);
  aux = procuraElemento(arvore->subArvoreDir, dado, aux);


  return aux;
}



TipoArvore removeNos(TipoArvore arvore, int dado){
    // remove nós folhas (nós sem filhos)
    if(arvore->subArvoreEsq == NULL && arvore->subArvoreDir == NULL) {
        free(arvore);

        return NULL;
    }
    else{
        // remover nós que possuem 2 filhos
        if(arvore->subArvoreEsq != NULL && arvore->subArvoreDir != NULL){
            TipoArvore aux = arvore->subArvoreEsq;

            while(aux->subArvoreDir != NULL)
                aux = aux->subArvoreDir;
            arvore->dado = aux->dado;
            aux->dado = dado;
            arvore->subArvoreEsq = removeElemento(arvore->subArvoreEsq, dado);
            return arvore;
        }
        else{
            // remover nós que possuem apenas 1 filho
            TipoArvore aux;

            if(arvore->subArvoreEsq != NULL)
                aux = arvore->subArvoreEsq;
            else
                aux = arvore->subArvoreDir;
            free(arvore);
            return aux;
        }
    }
}

TipoArvore removeElemento(TipoArvore arvore, int dado){
    if(arvore == NULL){
        return NULL;
    } 
    else { // procura o nó a remover
        if(arvore->dado == dado) {
            arvore = removeNos(arvore, dado);
        } 
        else{
            if(dado < arvore->dado)
                arvore->subArvoreEsq = removeElemento(arvore->subArvoreEsq, dado);
            else
                arvore->subArvoreDir = removeElemento(arvore->subArvoreDir, dado);
            return arvore;
        }
    }
}

int imprimeArvoreEmOrdem(TipoArvore arvore, int marcador) {
  static int primeiro = 1; // Marca se é o primeiro elemento 
  if (arvoreVazia(arvore))
    return marcador;

  marcador = imprimeArvoreEmOrdem(arvore->subArvoreEsq, marcador);

  if(marcador != 1)//Se não for o primeiro,imprime espaço antes
    printf(" ");
  printf("%d", arvore->dado);
  marcador = 0; // Atualiza o marcador

  marcador = imprimeArvoreEmOrdem(arvore->subArvoreDir, marcador);

  return marcador;
}

void imprimeArvorePreOrdem(TipoArvore arvore, int marcador) {
  static int primeiro = 1;
  if (arvoreVazia(arvore))
    return;
  
  if(marcador != 1)//Se não for o primeiro,imprime espaço antes
    printf(" ");
  printf("%d", arvore->dado);
  marcador = 0; // Atualiza o marcador
  
  imprimeArvorePreOrdem(arvore->subArvoreEsq, marcador);
  imprimeArvorePreOrdem(arvore->subArvoreDir, marcador);

  return;
}

int imprimeArvorePosOrdem(TipoArvore arvore, int marcador) {
if (arvoreVazia(arvore))
    return marcador;

  marcador = imprimeArvorePosOrdem(arvore->subArvoreEsq, marcador);
  marcador = imprimeArvorePosOrdem(arvore->subArvoreDir, marcador);
  
  if(marcador != 1)//Se não for o primeiro,imprime espaço antes
    printf(" ");
  printf("%d", arvore->dado);
  marcador = 0;
  
  return marcador;
}
///////////////////main//////////////////////////////////
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
    }

    if (strncmp("PREFIXA", opcao, 7) == 0) { // imprimir em Pre-Ordem
      if (!arvoreVazia(raiz))
        imprimeArvorePreOrdem(raiz, 1);
    }

    if (strncmp("POSFIXA", opcao, 7) == 0) { // imprimir em Pós-Ordem
      if (!arvoreVazia(raiz)) // se arvore nao esta vazia
        imprimeArvorePosOrdem(raiz, 1);
    }

    if (strcmp("P", opcao) == 0) {
      if (!arvoreVazia(raiz)){ // se arvore nao esta vazia
        scanf("%d", &dado);    //que sera procurada
        aux = procuraElemento(raiz, dado, aux);
        if(aux == 0)
          printf("%d nao existe\n", dado);
      }
    }
    if (strcmp("R", opcao) == 0) {
      if (!arvoreVazia(raiz)){ // se arvore nao esta vazia
        scanf("%d", &dado);    //que sera procurada
        raiz  = removeElemento(raiz, dado);
      }
    }
  }

  printf("\n");
  raiz = destroiArvore(raiz);

  return 0;
}