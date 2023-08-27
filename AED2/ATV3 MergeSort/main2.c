#include <stdlib.h>
#include <stdio.h>

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
void meioLista(TipoNoh *, TipoNoh **, TipoNoh **, int);
void mergeSort(TipoNoh **, int, int);
TipoNoh *merge(TipoNoh *, TipoNoh *);
void imprimeLista(TipoNoh *);
void destroiLista(ListaEncadeada *);

int listaVazia(ListaEncadeada *lista) {
    return lista->inicioLista == NULL;
}

void inicializaLista(ListaEncadeada *lista) {
    lista->inicioLista = NULL;
}

int insereFinalLista(ListaEncadeada *lista, int item) {
    TipoNoh *novoNoh, *ptrAux;

    novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
    if(novoNoh != NULL) {
        ptrAux = lista->inicioLista;
        if(!listaVazia(lista)) {
            while(ptrAux->prox != NULL) {
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

void meioLista(TipoNoh *lista, TipoNoh **esq, TipoNoh **dir, int meio) {
    if (lista==NULL || lista->prox==NULL){
        *esq = lista;
        *dir = NULL;
    }
    for(int i = 1; i < meio; i++) {
        lista = lista->prox;
    }
    *esq = lista;
    *dir = lista->prox;
    //esq->prox = NULL;
}

void mergeSort(TipoNoh **lista, int inicio, int final) {
    if (inicio < final) {
        TipoNoh *ptrLista = *lista;
        TipoNoh *esq;
        TipoNoh *dir;

        int meio = (final + inicio) / 2;
        meioLista(ptrLista, &esq, &dir, meio);
        mergeSort(&esq, inicio, meio);
        mergeSort(&dir, meio+1, final);
        *lista = merge(esq, dir);
    }
}

TipoNoh *merge(TipoNoh *esq, TipoNoh *dir) {
    TipoNoh *result;

    result = NULL;
 
    if (esq == NULL)
        return(dir);
    else if (dir == NULL)
        return(dir);
    if (esq->chave <= dir->chave)
    {
        result = esq;
        result->prox = merge(esq->prox, dir);
    }
    else
    {
        result=dir;
        result->prox = merge(esq, dir->prox);
    }
    return(result);
}

void imprimeLista(TipoNoh *lista) {
    if(lista == NULL) {
        printf("Lista vazia\n");
        return;
    }
    while(lista != NULL) {
        printf("%d ", lista->chave);
        lista = lista->prox;
    }
    printf("\n");

    return;
}

void destroiLista(ListaEncadeada *lista) {
    TipoNoh *ptrAux;

    while(lista->inicioLista != NULL) {
        ptrAux = lista->inicioLista;
        lista->inicioLista = lista->inicioLista->prox;
        free(ptrAux);
    }
    return;
}

int main() {
ListaEncadeada lista;
int n, item;

inicializaLista(&lista);
printf("Quantos elementos deseja inserir na lista? ");
scanf("%d", &n);

for(int i = 0; i < n; i++) {
    printf("Insira o elemento %d: ", i+1);
    scanf("%d", &item);
    insereFinalLista(&lista, item);
}

printf("Lista antes da ordenacao: ");
imprimeLista(lista.inicioLista);

mergeSort(&lista.inicioLista, 0, n-1);

printf("Lista apos a ordenacao: ");
imprimeLista(lista.inicioLista);

destroiLista(&lista);

return 0;
}