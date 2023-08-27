#include <stdio.h>
#include <stdlib.h>

typedef struct noh {
  int chave;
  struct noh *prox;
} TipoNoh;

typedef struct {
  TipoNoh *inicioLista;
} ListaEncadeada;

int listaVazia(ListaEncadeada *);
void inicializaLista(ListaEncadeada *);
int insereFinalLista(ListaEncadeada *, int);
void meioLista(TipoNoh *, TipoNoh **, TipoNoh **);
void mergeSort(TipoNoh **, int *, int);
TipoNoh *merge(TipoNoh *, TipoNoh *);
void imprimeLista(TipoNoh *);
void destroiLista(ListaEncadeada *);

int listaVazia(ListaEncadeada *lista) { return lista->inicioLista == NULL; }

void inicializaLista(ListaEncadeada *lista) { lista->inicioLista = NULL; }

int insereFinalLista(ListaEncadeada *lista, int item) {
  TipoNoh *novoNoh, *ptrAux;

  novoNoh = (TipoNoh *)malloc(sizeof(TipoNoh));
  if (novoNoh != NULL) {
    ptrAux = lista->inicioLista;
    if (!listaVazia(lista)) {
      while (ptrAux->prox != NULL) {
        ptrAux = ptrAux->prox;
      }
      ptrAux->prox = novoNoh;
    } else {
      lista->inicioLista = novoNoh;
    }
    novoNoh->chave = item;
    novoNoh->prox = NULL;
    return 0;
  }
  return 1;
}

void meioLista(TipoNoh *lista, TipoNoh **esq, TipoNoh **dir) {
  TipoNoh *ptrAux;
  TipoNoh *ptrAux2;
  int i;
  // dois ponteiro percorrem ao mesmo tempo até achar o meio
  if (lista == NULL || lista->prox == NULL) {
    *esq = lista;
    *dir = NULL;
    return;
  } else {
    ptrAux = lista->prox;
    ptrAux2 = lista;
    while (ptrAux != NULL) {
      ptrAux = ptrAux->prox;
      if (ptrAux != NULL) {
        ptrAux = ptrAux->prox;
        ptrAux2 = ptrAux2->prox;
      }
    }
    *dir = ptrAux2->prox;
    *esq = lista;
    ptrAux2->prox = NULL;
    // esq->prox = NULL;
  }
  return;
}

void mergeSort(TipoNoh **lista, int *max, int count) {
  TipoNoh *ptrLista = *lista;
  TipoNoh *esq;
  TipoNoh *dir;

  if(count > *max)
    *max = count;

  if ((ptrLista == NULL) || (ptrLista->prox == NULL)) {
    return;
  }
  meioLista(ptrLista, &esq, &dir);
  mergeSort(&esq, max, count++);
  mergeSort(&dir, max, count++);
  *lista = merge(esq, dir);
  return;
}

TipoNoh *merge(TipoNoh *esq, TipoNoh *dir) {
  TipoNoh *result = NULL;

  if (esq == NULL)
    return (dir);
  else if (dir == NULL)
    return (esq);
  if (esq->chave <= dir->chave) {
    result = esq;
    result->prox = merge(esq->prox, dir);
  } else {
    result = dir;
    result->prox = merge(esq, dir->prox);
  }
  return (result);
}

void imprimeLista(TipoNoh *lista) {
  if (lista == NULL) {
    printf("Lista vazia\n");
    return;
  }
  while (lista != NULL) {
    printf("%d ", lista->chave);
    lista = lista->prox;
  }
  printf("\n");

  return;
}

void destroiLista(ListaEncadeada *lista) {
  TipoNoh *ptrAux;

  while (lista->inicioLista != NULL) {
    ptrAux = lista->inicioLista;
    lista->inicioLista = lista->inicioLista->prox;
    free(ptrAux);
  }
  return;
}

int main() {
  ListaEncadeada lista;
  int n, item, max = 0;

  inicializaLista(&lista);
  // printf("\nDigite a quantidade de chaves: ");
  scanf("%d", &n);

  // printf("Digitie a sequência de %d chaves: ", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &item);
    insereFinalLista(&lista, item);
  }
  mergeSort(&lista.inicioLista, &max, 0);
  imprimeLista(lista.inicioLista);
  printf("%d", max+1);

  destroiLista(&lista);

  return 0;
}
