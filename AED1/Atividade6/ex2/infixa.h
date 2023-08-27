#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct noh{
    float valor;
    struct no *proximo;
}TipoNoh;

TipoNoh* empilhar(TipoNoh *, float);
TipoNoh* desempilhar(TipoNoh **);
float operacao(float, float, char);
float resolver_expressao(char *);
void emprimePilha();
void emprimeItem();