#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct{
  char tipoSenha;    //prioridade ou nao
  int numeroSenha;
} TipoItem;

struct noh{
  TipoItem item;
  struct noh *prox;
};

typedef struct noh TipoNoh;

typedef struct{
  int n;
  int senhas;
  TipoNoh *inicio;
  TipoNoh *fim;
} TipoFila;

void inicializaFila(TipoFila*);
void destroiFila(TipoFila*);
void retiraDaFila(TipoFila*, TipoItem*);
int filaVazia(TipoFila*);
int gerarSenha(TipoFila*, TipoItem*);
int insereNaFila(TipoFila*,TipoItem);
int retiraNormal(TipoFila*,TipoItem*);
int retiraPreferencial(TipoFila*,TipoItem*);
int imprimeFila(TipoFila*);
void imprimeItem(TipoItem);