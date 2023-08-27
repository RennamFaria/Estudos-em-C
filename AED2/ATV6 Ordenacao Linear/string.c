#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
char * criaVetor(int);
char ** criaMatriz(int);
void troca(char *, char *);
void convertMin(char **, int);
void maxInArray(char**, int*, int);
int comparaChave(char**, char**, char**);
void countingSort(char **, char **, int, int);
void radixSort(char **, char **, int);

 
 char* criaVetor(int tamanho){
  char *ptrVetor;
  
  ptrVetor = (char *)malloc(tamanho * sizeof(char));
  if(ptrVetor == NULL){
    printf("\nErro de alocacao de memoria");
    return NULL;
  }
  return ptrVetor;
}
char** criaMatriz(int tamanho){
  char **ptrMatriz;
  
  ptrMatriz = (char **)malloc(tamanho * sizeof(char *));
  for(int i = 0; i < tamanho; i++)
    ptrMatriz[i] = (char *)malloc(20 * sizeof(char));
  if(ptrMatriz == NULL){
    printf("\nErro de alocacao de memoria");
    return NULL;
  }
  return ptrMatriz;
}
 
void troca(char* a, char* b) {
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void convertMin(char **mat, int n){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 20; j++)
      mat[i][j] = tolower(mat[i][j]);
  printf("%s.\n", mat[i]);
  }
  return;
}

void maxInArray(char **mat, int *max, int n) {
  *max = 0;
  for (int i = 1; i < n; i++) {
    if (strlen(mat[i]) > strlen(mat[*max])) {
      *max = i;
    }
  }
  return;
}

void fillString(char **matA, int max, int n){
  int maxChar = 20;
  int aux;    //conta quantos espaços vazios na string para dar tamanho 20

  for(int i = 0; i < n; i++){
    aux = (20 - strlen(matA[i]));
    for(int j = 0; j < aux; j++)
      strcat(matA[i], " ");
    //printf("%s.\n", matA[i]);
  }
  return;
}

void countingSort(char **matA, char **matB, int posicao, int n){
    int i, j;
  char max = matA[0][posicao];

  // Encontrar o caractere máximo
  for (i = 1; i < n; i++) {
    if (matA[i][posicao] > max) {
      max = matA[i][posicao];
    }
  }

  // Alocar vetor C dinamicamente
  int tamanhoC = max - 'a' + 2; // Tamanho do vetor C, incluindo espaço e 'a'
  int *C = (int *) calloc(27, sizeof(int));
  if (C == NULL) {
    printf("\nErro de alocacao de memoria");
    return;
  }

  // Contagem dos caracteres
  for (j = 0; j < n; j++) {
    int index = (matA[j][posicao] == ' ') ? 0 : matA[j][posicao] - 'a' + 1;
    C[index]++;
  }

  // Acumular as contagens
  for (i = 1; i < 27; i++) {
    C[i] += C[i - 1];
  }
  for (i = 0; i < 27; i++) {
    printf("%d", C[i]);
  }
  printf("\n");
  

  // Ordenar os elementos
  for (j = n - 1; j >= 0; j--) {
    int index = (matA[j][posicao] == ' ') ? 0 : matA[j][posicao] - 'a' + 1;
    matB[C[index] - 1] = matA[j];
    C[index]--;
  }

  // Copiar os elementos de B para A
  for (i = 0; i < n; i++) {
    matA[i] = matB[i];
  }

  free(C);
  // Liberar o vetor C
 

  return;
}

void radixSort(char **matA, char **matB, int n){
  int posicao, max;    //sistema decimal: 1=unidade, 2=dezena, 3=centena
  convertMin(matA, n);   //kfuncao que verifica letra maiuscula nas palavras e trasnforma
  maxInArray(matA, &max, n); //acho a string maxima
  printf("max = %d\n", max);    //max  = posicao da maior string
  posicao = strlen(matA[max]) -1;
  printf("%d\n", strlen(matA[max]));
  fillString(matA, max, n);  //depois de descobrir o tam da maior palavra, completar outras com esapaço
  //max 20 caracteres

  for(int i = n-1; posicao >= 0; i--, posicao--){
    countingSort(matA, matB, posicao, n);
    //for(int j = 0; j < n; j++)
    //  printf("  %s.\n", matA[j]);
  }
  return;
}
 
int main() {
  char **matChar;
  char **matOut;
  char chave[27];
  int n, max, i, j;
 
  printf("\nDigite a quantidade de strings: ");
  scanf("%d", &n);     

  matChar = criaMatriz(n);
  matOut = criaMatriz(n);
  getchar();

  printf("Digite a chave que sera baseada na ordenacao: ");
  scanf("%s", &chave);
  getchar();
  puts(chave);
 
  printf("Digite %d caracteres separadas por espaço: ", n);
  for(i = 0; i < n; i++)
    scanf("%s", matChar[i]);

  radixSort(matChar, matOut, n);

  printf("entrou\n");
  for(i=0;i < n ;i++)
   printf("%s\n", matChar[i]);
   printf("\n\n");

  printf("coisa que nuca diria");

  for (int i = 0; i < n; i++) {
    matChar[i] = NULL;
    free(matChar[i]);
  }
  free(matChar);
  
  for (int i = 0; i < n; i++) {
    matOut[i] = NULL;
    free(matOut[i]);
  }
  free(matOut);

  return 0;
}