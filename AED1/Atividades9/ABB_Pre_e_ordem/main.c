/////////////////////////////arvoreBinaria.h///////////////////////////
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
void limparVetor(char[], char[]);
TipoArvore inicializaArvore(TipoArvore);
TipoArvore destroiSubArvore(TipoArvore);
TipoArvore destroiArvore(TipoArvore);
TipoArvore criaArvore(TipoArvore, char);
int acharTamanho(char[], char, int);
TipoArvore construirArvore(TipoArvore,char[], char[], int);
void imprimeArvorePreOrdem(TipoArvore);
void imprimeArvoreEmOrdem(TipoArvore);
void imprimeArvorePosOrdem(TipoArvore);

/////////////////////////arvoreBinaria.c//////////////////////////

// Funções da Árvore
void limparVetor(char p[], char o[]){
//função que irá zerar todos os numeros de N do main
    int i;
        
    for(i = 0; i < 100; i++){
        p[i] = '\0';
        o[i] = '\0';
        }
    return;
}

int arvoreVazia(TipoArvore arvore) { 
  return arvore == NULL; 
  }

TipoArvore inicializaArvore(TipoArvore arvore) { 
  return NULL; 
  }

TipoArvore destroiSubArvore(TipoArvore arvore) {
  if(arvoreVazia(arvore)) // se ArvoVaz volte uma recursao
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

TipoArvore criaArvore(TipoArvore arvore, char dado) {
  arvore = (TipoArvore) malloc(sizeof(TipoNohArvore));
  arvore->dado = dado;
  arvore->subArvoreDir = NULL;
  arvore->subArvoreEsq = NULL;
  return arvore;
}

int acharTamanho(char valores[], char dado, int tamanho) {
int i;
for(i = 0; i < tamanho; i++){
if (valores[i] == dado) {
return i;
}
}
return -1;
}

TipoArvore construirArvore(TipoArvore arvore, char prefix[], char infix[], int tamanho) {
  int pos;

  // Cria uma nova árvore e atribui o primeiro caractere a ela
  arvore = criaArvore(arvore, prefix[0]);

  // Verifica se o tamanho da árvore é igual a 1
  if (tamanho == 1) {
    return arvore;
  }

  // Encontra a posição do primeiro caractere no vetor de infixo
  pos = acharTamanho(infix, prefix[0], tamanho);

  // Verifica se o caractere foi encontrado
  if (pos == -1) {
    //printf("Erro: Caractere não encontrado no vetor de infixo\n");
    return NULL;
  }

  // Adiciona as subárvores esquerda e direita recursivamente
  arvore->subArvoreEsq = construirArvore(arvore->subArvoreEsq, prefix + 1, infix, pos);
  arvore->subArvoreDir = construirArvore(arvore->subArvoreDir, prefix + pos + 1, infix + pos + 1, tamanho - pos - 1);

  return arvore;
}

void imprimeArvorePreOrdem(TipoArvore arvore) {
  if (arvoreVazia(arvore)) {
    return;
  }
  printf("%c", arvore->dado);
  imprimeArvorePreOrdem(arvore->subArvoreEsq);
  imprimeArvorePreOrdem(arvore->subArvoreDir);
}

void imprimeArvoreEmOrdem(TipoArvore arvore) {
  if (arvoreVazia(arvore)) {
    return;
  }
  imprimeArvoreEmOrdem(arvore->subArvoreEsq);
  printf("%c", arvore->dado);
  imprimeArvoreEmOrdem(arvore->subArvoreDir);
}

void imprimeArvorePosOrdem(TipoArvore arvore) {
  if (arvoreVazia(arvore)) {
    return;
  }
  imprimeArvorePosOrdem(arvore->subArvoreEsq);
  imprimeArvorePosOrdem(arvore->subArvoreDir);
  printf("%c", arvore->dado);
}

//////////////////////////////////main.c//////////////////////////////////

//arvore binaria mas com o sistema de organização de busca baseada no valor ASCII de cada caracter e não da ordem que é digitado
//Ex: C < T < W     pois    67 < 84 < 87
int main() {
  TipoArvore raiz;
  int qtdTestes, nValores, i;
  char prefix[100], infix[100];

  inicializaArvore(raiz);
  limparVetor(prefix, infix);

  //printf("Digite a quantidade de testes ");
  scanf("%d", &qtdTestes);

  for(i = 0; i<qtdTestes; i++){
    //printf("digite a quantida de valores ");
    scanf("%d", &nValores);

    scanf("%s", &prefix);

    scanf("%s", &infix);

    //puts(prefix);
    //puts(infix);

    //printf("%d\n", nValores); 

    raiz = construirArvore(raiz, prefix, infix, nValores);
    //printf("saiu\n");
    imprimeArvorePosOrdem(raiz);
    printf("\n");

    raiz = destroiArvore(raiz);
  }
  return 0;
}