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