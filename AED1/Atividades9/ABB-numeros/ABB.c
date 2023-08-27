#include "ABB.h"
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


int procuraElemento(TipoArvore arvore, int dado) {
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