#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * criaVetor(int);
char ** criaMatriz(int);
void troca(char *, int , int);
void buildMaxHeap(char *, int );
void maxHeapify(char *, int , int );
void heapSort(char *, int );
//char extractHeapMax(char *, char *);
void comparador(char *, char **, int, int);
void imprime(char *, int);

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

void troca(char *A, int pai, int max) {
    char temp = A[pai];
    A[pai] = A[max];
    A[max] = temp;
}

void heapSort(char *Vet, int tamanho){
    buildMaxHeap(Vet, tamanho);

    int n = tamanho - 1;
    //int *auxVet;
    //auxVet = (int *)malloc(n * sizeof(int));

    for(; n >= 0; n--){
      //auxVet[n] = extractHeapMax(Vet, &tamanho);
      troca(Vet, 0, n);
      maxHeapify(Vet, 0, n);

    }

    return;
}

void buildMaxHeap(char *Vet, int tamanho){
  int i;

  for(i = (tamanho/2)-1; i >= 0; i--){
    maxHeapify(Vet, i, tamanho);
  }
  return;
}

void maxHeapify(char *Vet, int pai, int tamanho){
  int esq = (pai*2);    //folha do ramo esq
  int dir = (pai*2)+1 ;  //filho do ramo dir
  int max = pai;  

  if((esq < tamanho) && (Vet[esq] > Vet[max]))
    max = esq;
  if((dir < tamanho && Vet[dir] > Vet[max]))
    max = dir;

  if(max != pai){
    troca(Vet, pai, max);
    maxHeapify(Vet, max, tamanho);
  }
  return ;
}

/*
int extractHeapMax(char *Vet, int *tamanho){
    if(*tamanho < 1){
      printf("Erro de overflow!!!\n");
      return-1;
    }
    char max = Vet[1];
    int i = *tamanho;
    Vet[1] = Vet[i];
    (*tamanho)--;
    maxHeapify(Vet, 1, *tamanho);

    return max;
}
*/

void comparador(char *vetChave, char **matPalavra, int tamC, int tamP){
  int i, j;
  char *p, temp[32];
  char auxM[tamP][32];

  for (i = 0; i < tamP; i++) {
    for (j = 0; j < strlen(matPalavra[i]); j++) {
      p = strchr(vetChave, matPalavra[i][j]);
      if (p == NULL) {
        printf("quando da NULL %s\n", matPalavra[i]);
        //return;
      }
    }
  }
  printf("AYO\n");

  for (i = 0; i < tamP; i++) {
    for (j = i + 1; j < tamP; j++) {
      if (strcmp(matPalavra[i], matPalavra[j]) > 0) {
        strcpy(temp, matPalavra[i]);     //funcao troca para string
        strcpy(matPalavra[i], matPalavra[j]);
        strcpy(matPalavra[j], temp);
      }
    }
  }

  for (i = 0; i < tamP; i++) {
    printf("%s ", matPalavra[i]);
  }
  printf("\n");
  return;
}

void imprime(char *Vet, int tamanho){
  for(int i = 0; i < tamanho ;i++)
   printf("%c ", Vet[i]);

  return;
}


int main() {
  char **matPalavra;    //vetor pelo pivo no ultimo
  char *vetChave, *p;    //vetor pela mediana de tres
  int n, s, i;

  printf("\nDigite a quantidade de palavras e o tamanho da chave: ");
  scanf("%d", &n);      //qtd de palavras
  scanf("%d", &s);      //tamanho de chave
  getchar();

  matPalavra = criaMatriz(n);
  vetChave = criaVetor(s);

  printf("Digite a chave de %d caracteres: ", s);
    scanf("%s", vetChave);

  //printf("Digite %d palavras separadas por espaço: ", n);
    for (i = 0; i < n; i++) {
        scanf("%s", matPalavra[i]);
    }
  

  printf("comparador====\n");
  //comparador(vetChave, matPalavra, s, n);
  for (i = 0; i < n; i++) {
    for (int j = 0; j < strlen(matPalavra[i]); j++) {
      p = strchr(vetChave, matPalavra[i][j]);
      if (p == NULL) {
        printf("A palavra %s eh invalida\n", matPalavra[i]);
        return;
      }
    }
  }
  
  //heapSort(matPalavra, s);

  printf("entrou\n");
  for(i=0;i < s ;i++)
   printf("%c ", vetChave[i]);
   printf("\n\n");

  for(i=0;i < n ;i++)
    printf("%c ", matPalavra[i][0]);

  free(vetChave);

  for (i = 0; i < n; i++) {
    free(matPalavra[i]);
  }
  free(matPalavra);

  return 0;
}



//criar uma função para comparar dois elementos, outro que compara string, outro que compara string de acordo com a chave

//começar com string e dps fazer com string













#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * criaVetor(int);
char ** criaMatriz(int);
void troca(char *, int , int);
void buildMaxHeap(char *, int );
void maxHeapify(char *, int , int );
void heapSort(char *, int );
//char extractHeapMax(char *, char *);
void comparador(char *, char **, int, int);
void imprime(char *, int);

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
    ptrMatriz[i] = (char *)malloc(30 * sizeof(char));
  if(ptrMatriz == NULL){
    //printf("\nErro de alocacao de memoria");
    return NULL;
  }
  else
    //printf("\no vetor foi criado");

  return ptrMatriz;
}

void troca(char *A, int pai, int max) {
    char temp = A[pai];
    A[pai] = A[max];
    A[max] = temp;
}

void heapSort(char *Vet, int tamanho){
    buildMaxHeap(Vet, tamanho);

    int n = tamanho - 1;
    //int *auxVet;
    //auxVet = (int *)malloc(n * sizeof(int));

    for(; n >= 0; n--){
      //auxVet[n] = extractHeapMax(Vet, &tamanho);
      troca(Vet, 0, n);
      maxHeapify(Vet, 0, n);

    }

    return;
}

void buildMaxHeap(char *Vet, int tamanho){
  int i;

  for(i = (tamanho/2)-1; i >= 0; i--){
    maxHeapify(Vet, i, tamanho);
  }
  return;
}

void maxHeapify(char *Vet, int pai, int tamanho){
  int esq = (pai*2);    //folha do ramo esq
  int dir = (pai*2)+1 ;  //filho do ramo dir
  int max = pai;  

  if((esq < tamanho) && (Vet[esq] > Vet[max]))
    max = esq;
  if((dir < tamanho && Vet[dir] > Vet[max]))
    max = dir;

  if(max != pai){
    troca(Vet, pai, max);
    maxHeapify(Vet, max, tamanho);
  }
  return ;
}

/*
int extractHeapMax(char *Vet, int *tamanho){
    if(*tamanho < 1){
      printf("Erro de overflow!!!\n");
      return-1;
    }
    char max = Vet[1];
    int i = *tamanho;
    Vet[1] = Vet[i];
    (*tamanho)--;
    maxHeapify(Vet, 1, *tamanho);

    return max;
}
*/

void comparador(char *vetChave, char **matPalavra, int tamC, int tamP){
  int i, n ,m, k;
  char auxM[tamP][30];

  for(i = 0, k = 0; i < tamC; i++){
    for(m = 0; m < tamP; m++){
      if(matPalavra[m][0] == vetChave[i]){
        strcpy(auxM[k], matPalavra[m]);
        if(auxM[k] == matPalavra[m])
        k++;
        m = tamP;   //para sair do for
      }
    }
  }

  printf("k = %d, tamP = %d\n", k ,tamP);
  //lembrar de printar a palavra que nao aparece na chave
  puts(auxM);
  //imprime(auxV, k);

  return;
}

void imprime(char *Vet, int tamanho){
  for(int i = 0; i < tamanho ;i++)
   printf("%c ", Vet[i]);

  return;
}


int main() {
  char **matPalavra;    //vetor pelo pivo no ultimo
  char *vetChave;    //vetor pela mediana de tres
  int n, s, i;

  printf("\nDigite a quantidade de palavras e o tamanho da chave: ");
  scanf("%d", &n);      //qtd de palavras
  scanf("%d", &s);      //tamanho de chave
  getchar();

  matPalavra = criaMatriz(n);
  vetChave = criaVetor(s);

  printf("Digite a chave de %d caracteres: ", s);
    gets(vetChave);

  //printf("Digite %d palavras separadas por espaço: ", n);
  for (i = 0; i < n; i++) {
    gets(matPalavra[i]);
  }
  
  heapSort(vetChave, s);

  printf("comparador====\n");
  comparador(vetChave, matPalavra, s, n);
  
  printf("entrou\n");
  for(i=0;i < s ;i++)
   printf("%c ", vetChave[i]);
   printf("\n\n");

  for(i=0;i < n ;i++)
    printf("%c ", matPalavra[i][0]);

  free(vetChave);

  for (i = 0; i < n; i++) {
    free(matPalavra[i]);
  }
  free(matPalavra);

  return 0;
}



//criar uma função para comparar dois elementos, outro que compara string, outro que compara string de acordo com a chave

//começar com string e dps fazer com string