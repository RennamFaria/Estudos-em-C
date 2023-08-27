#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
char * criaVetor(int);
char ** criaMatriz(int);
void troca(char *, char *);
int comparaChave(char*, char*, char*);
void buildMaxHeap(char **, int , char *);
void maxHeapify(char **, int , int , char *);
void heapSort(char **, int , char *);
 
 char* criaVetor(int tamanho){
  char *ptrVetor;
  
  ptrVetor = (char *)malloc(tamanho * sizeof(char));
  if(ptrVetor == NULL){
    //printf("\nErro de alocacao de memoria");
    return NULL;
  }
  else
    //printf("\no vetor foi criado");
 
  return ptrVetor;
}
char** criaMatriz(int tamanho){
  char **ptrMatriz;
  
  ptrMatriz = (char **)malloc(tamanho * sizeof(char *));
  for(int i = 0; i < tamanho; i++)
    ptrMatriz[i] = (char *)malloc(32 * sizeof(char));
  if(ptrMatriz == NULL){
    //printf("\nErro de alocacao de memoria");
    return NULL;
  }
  else
    //printf("\no vetor foi criado");
 
  return ptrMatriz;
}
 
void troca(char* a, char* b) {
    char temp[strlen(a) + 1];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}
 
int comparaChave(char* str1, char* str2, char* chave) {
  int j;
 
  if(strlen(str1) >= strlen(str2))
    j = strlen(str2);
  else
    j = strlen(str1);
    for (int i = 0; i<j; i++) {
        int idx1 = strchr(chave, str1[i]) - chave;
        int idx2 = strchr(chave, str2[i]) - chave;
        if(idx1 != idx2) {
          //if(strlen(str1) < i)
            //return 1;
          //else
            return idx1 - idx2;
        }
    }
    return strcmp(str1, str2);
}
 
void heapSort(char **arr, int tamanho, char *chave){
    buildMaxHeap(arr, tamanho, chave);
 
    for(int n = tamanho-1; n >= 0; n--){
      troca(arr[0], arr[n]);
      maxHeapify(arr, 0, n, chave);
 
    }
 
    return;
}
 
void buildMaxHeap(char **arr, int tamanho, char *chave){
  int i;
 
  for(i = (tamanho/2)-1; i >= 0; i--){
    maxHeapify(arr, i, tamanho, chave);
  }
  return;
}
 
void maxHeapify(char **arr, int pai, int tamanho, char *chave){
    int l = 2 * pai + 1;
    int r = 2 * pai + 2;
    int max = pai;
 
    if (l < tamanho && (comparaChave(arr[l], arr[max], chave)) > 0) {
        max = l;
    }
 
    if (r < tamanho && (comparaChave(arr[r], arr[max], chave)) > 0) {
        max = r;
    }
 
    if (max != pai) {
        troca(arr[pai], arr[max]);
        maxHeapify(arr, max, tamanho, chave);
    }
  return ;
}
 
int main() {
  char **matPalavra;    //vetor pelo pivo no ultimo
  char *vetChave, *p;    //vetor pela mediana de tres
  int n, s, i;
 
  //printf("\nDigite a quantidade de palavras e o tamanho da chave: ");
  scanf("%d", &n);      //qtd de palavras
  scanf("%d", &s);      //tamanho de chave
  getchar();
 
  matPalavra = criaMatriz(n);
  vetChave = criaVetor(s);
 
  //printf("Digite a chave de %d caracteres: ", s);
    scanf("%s", vetChave);
 
  //printf("Digite %d palavras separadas por espaço: ", n);
    for (i = 0; i < n; i++) {
        scanf("%s", matPalavra[i]);
    }
  
  for (i = 0; i < n; i++) {
    for (int j = 0; j < strlen(matPalavra[i]); j++) {
      p = strchr(vetChave, matPalavra[i][j]);
      if (p == NULL) {
        printf("A palavra %s eh invalida\n", matPalavra[i]);
        return 0;
      }
    }
  }
  
  heapSort(matPalavra, n, vetChave);
  for(i = 0; i< n; i++){
    printf("%s", matPalavra[i]);
    if(i < n-1)
      printf(" ");
}
 
  free(vetChave);
 
  for (i = 0; i < n; i++) {
    free(matPalavra[i]);
  }
  free(matPalavra);
 
  return 0;
}