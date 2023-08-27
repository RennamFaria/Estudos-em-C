#include <stdio.h>
#include <stdlib.h>
 
struct nohArvore {
    char dado;
    struct nohArvore *subArvoreEsq;
    struct nohArvore *subArvoreDir;
    struct nohArvore *prox;
};

typedef struct nohArvore TipoNohArvore;
typedef TipoNohArvore *TipoArvore;

TipoArvore pilha = NULL;        //ajuda a criar as arvores com simbolos e  os caracters
 
int arvoreVazia(TipoArvore);
TipoArvore inicializaArvore(TipoArvore);
TipoArvore destroiSubArvore(TipoArvore);
TipoArvore destroiArvore(TipoArvore);
TipoArvore criaArvore(TipoArvore, char);
void empilha(TipoArvore);
TipoArvore removeNoh();
int qtdNiveis(TipoArvore, int, int, int);
int imprimeArvoreEmOrdem(TipoArvore, int, int, int);

// Funções da Árvore
int arvoreVazia(TipoArvore arvore) {
return arvore == NULL; 
}

TipoArvore inicializaArvore(TipoArvore arvore){ 
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

TipoArvore criaArvore(TipoArvore arvore, char dado){
    arvore = (TipoArvore)malloc(sizeof(TipoNohArvore));
    arvore->dado = dado;
    arvore->subArvoreEsq = NULL;
    arvore->subArvoreDir = NULL;
    arvore->prox = NULL;      
     
    return arvore;
}

int qtdNiveis(TipoArvore arvore, int nivel, int parametro, int n){
    if (arvore == NULL)
        return n;
    n = qtdNiveis(arvore->subArvoreEsq, nivel+1, parametro, n);
    if(nivel == parametro){
        n++;
    }
    n = qtdNiveis(arvore->subArvoreDir, nivel+1, parametro, n);
    return n;
}

int imprimeArvoreEmOrdem(TipoArvore arvore, int nivel, int parametro, int n){
    if (arvore == NULL)
        return n;
    n = imprimeArvoreEmOrdem(arvore->subArvoreEsq, nivel+1, parametro, n);
    if(nivel == parametro){
        n++;
        printf("%c ", arvore->dado, n);
    }
    n = imprimeArvoreEmOrdem(arvore->subArvoreDir, nivel+1, parametro, n);
    return n;
}

 
void empilha(TipoArvore arvore){
    if(pilha == NULL){
        pilha = arvore;
    }
    arvore->prox = pilha;
    pilha = arvore;

    return;
}

TipoArvore removeNoh(){
    TipoArvore aux;
    
    aux = pilha;
    pilha = pilha->prox;

    return aux;
}

int main(){
    char dado[50];
    int i, qtdValores;
    TipoArvore raiz, esq, dir;

    raiz = inicializaArvore(raiz);
    esq = inicializaArvore(esq);
    dir = inicializaArvore(dir);

    printf("Digite a quantidade de dados que ira digitar (simbolos tambem contam!)\n");
    scanf("%d", &qtdValores);
    printf("\nPs: escreva os caracteres SEM espacos entre eles em forma de notacao posfixa\n");
    printf("Ex: 9A7+-D*\n");

    for(i = 0; i <= qtdValores; i++)
        scanf("%c", &dado[i-1]);
    //printf("%c, %c, %c, %c, %c, %c, %c", dado[0], dado[1], dado[2], dado[3], dado[4], dado[5], dado[6]);

    for (int i = 0; i < qtdValores; i++) {
        if (dado[i] == '+' || dado[i] == '-' || dado[i] == '*'|| dado[i] == '/') {
            raiz = criaArvore(raiz , dado[i]);
            esq = removeNoh();
            dir = removeNoh();
            raiz->subArvoreEsq = esq;
            raiz->subArvoreDir = dir;
            empilha(raiz);
        }
        else {
            raiz = criaArvore(raiz, dado[i]);
            empilha(raiz);
        }
    }

    for(i = 0; i < 10; i++){
        if(qtdNiveis(raiz, 0,  i, 0) != 0){
            printf("\nNivel %d: ", i);
            imprimeArvoreEmOrdem(raiz, 0,  i, 0);
        }
    }
    return 0;
}