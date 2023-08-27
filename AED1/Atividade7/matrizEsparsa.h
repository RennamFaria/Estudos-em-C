#include "listaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  TipoLista *matriz;
  int nLinhas;
  int nColunas;
} TipoMatriz;

void inicializaMatriz(TipoMatriz *);
int matrizVazia(TipoMatriz *);
int instanciaMatriz(TipoMatriz *, int, int);
void destroiMatriz(TipoMatriz *);
void insereNaMatriz(TipoMatriz *, int, int, int);
void retiraDaMatriz(TipoMatriz *, int, int);
void imprimeMatriz(TipoMatriz *);