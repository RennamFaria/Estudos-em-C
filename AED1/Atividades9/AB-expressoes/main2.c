#include <stdio.h>
#include <stdlib.h>
#include "AB.h"

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
}//{'A', 'B', 'C', '*', '+', 'D', '/'};

/*
char s[] = {'A', 'B', 'C', '*', '+', 'D', '/'};
  int l = sizeof(s) / sizeof(s[0]);
*/