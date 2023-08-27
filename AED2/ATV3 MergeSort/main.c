#include <stdio.h>
#include <stdlib.h>
//

typedef struct noh {
  int chave;
  struct noh *prox;
} TipoNoh;

typedef struct {
  TipoNoh *inicioLista;
  // int ultimo;    acho que eu nao preciso disso pois o proprio user vai me
  // passar a quantidade de valores que precisa
} ListaEncadeada;
//

int listaVazia(ListaEncadeada *);
void inicializaLista(ListaEncadeada *);
int insereFinalLista(ListaEncadeada *, int);
void meioLista(TipoNoh *, TipoNoh *, int);
void mergeSort(TipoNoh *, int, int);
void merge(TipoNoh *, TipoNoh *);
void imprimeLista(TipoNoh *);
void destroiLista(ListaEncadeada *);

//
int listaVazia(ListaEncadeada *lista) { // checar se esta vazia
  if (lista->inicioLista == NULL)
    return 1;
  else
    return 0;
}

void inicializaLista(ListaEncadeada *lista) {
  lista->inicioLista = NULL;
  // lista->ultimo = 0;
  return;
}

int insereFinalLista(ListaEncadeada *lista, int item){
  TipoNoh *novoNoh, *ptrAux;

  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  if(novoNoh != NULL){
    ptrAux = lista->inicioLista;
    if(!listaVazia(lista)){
      while(ptrAux->prox != NULL)
        ptrAux = ptrAux->prox;
      ptrAux->prox = novoNoh;
    }
    else
      lista->inicioLista = novoNoh;
    novoNoh->chave = item;
    novoNoh->prox = NULL;
    return 0;
  }
  return 1;
}

void meioLista(TipoNoh *esq, TipoNoh *dir, int meio){
  TipoNoh *ptrAux;
  int i;

  ptrAux = esq;
  for(i = 1; i < meio; i++)
    esq = esq->prox;

  dir = esq->prox;
  esq->prox = NULL;
  esq = ptrAux;

  ptrAux = dir;   
  for(i = 1; i < meio; i++)
    dir = dir->prox;
  dir->prox = NULL;
  dir = ptrAux;

  //printf("chave: %d\n", esq->chave);
  return; 
}

void mergeSort(TipoNoh *lista, int inicio, int final) {
  if (inicio < final){
    TipoNoh *esq = lista;
    TipoNoh *dir;
    int meio = (final - inicio) /2;

    //printf("chave: %d\n", esq->chave);
    
    meioLista(esq, dir, meio);
    mergeSort(esq, inicio, meio);  //preciso que tbm a
//lista dir aponte para o NULL tbm se nao vai dar problema 
//na parte da esq quando o dir tiver apontando para a outra 
//lista cortada
    mergeSort(dir, meio+1, final);
    merge(esq, dir);

    imprimeLista(esq);

    //printf("meio: %d\n", meio);
    //printf("chave: %d\n", esq->chave);
  }
  return;
}

void merge(TipoNoh *esq, TipoNoh *dir){
  // Base cases
  if (esq == NULL)
    return;
  else if (dir == NULL)
    return;

  if (esq->chave <= dir->chave){
    esq->prox = dir;
  }
  else{
    dir->prox = esq;
  }
  return;
}

void imprimeLista(TipoNoh *lista){
    while (lista != NULL){
      printf("%d ", lista->chave);
      lista = lista->prox;
    }
  return;
}

void destroiLista(ListaEncadeada *lista) {
  TipoNoh *ptrAux1, *ptrAux2;
  if (!listaVazia(lista)) {
    ptrAux1 = lista->inicioLista;
    ptrAux2 = ptrAux1->prox;
    while (ptrAux1->prox != NULL) {
      free(ptrAux1);
      ptrAux1 = ptrAux2;
      ptrAux2 = ptrAux1->prox;
    }
    free(ptrAux1);
  }
  lista->inicioLista = NULL;
  // lista->ultimo = 0;

  return;
}

//
int main(void) {
  ListaEncadeada lista;
  int tamanho, valor, i, count = 1;

  inicializaLista(&lista);

  printf("\ndigite a quantidade de chaves: ");
  scanf("%d", &tamanho);

  printf("\ndigite a sequencia de chaves: ");
  for (i = 0; i < tamanho; i++) {
    scanf("%d", &valor);
    if (insereFinalLista(&lista, valor))
      printf("\nErro! Não foi possível inserir!\n");
  }

  mergeSort(lista.inicioLista, 0, tamanho); 

  imprimeLista(lista.inicioLista);

  destroiLista(&lista);

  return 0;
}

// nao vai ser um vetor, sera uma lista ligada

// quando for enviar trocar o int do insereInicioLista por "void", eu estou
// usando int apenas para ter um aviso caso nao de para alocar