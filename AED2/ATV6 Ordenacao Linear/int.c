#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int * criaVetor(int);
int ** criaMatriz(int);
void troca(int *, int *);
int maxInArray(int*, int);
int comparaChave(int*, int*, int*);
void countingSort(int *, int *, int, int);
void radixSort(int *, int* , int);

 
 int* criaVetor(int tamanho){
  int *ptrVetor;
  
  ptrVetor = (int *)malloc(tamanho * sizeof(int));
  if(ptrVetor == NULL){
    printf("\nErro de alocacao de memoria");
    return NULL;
  }
  else
    //printf("\no vetor foi criado");
 
  return ptrVetor;
}
int** criaMatriz(int tamanho){
  int **ptrMatriz;
  
  ptrMatriz = (int **)malloc(tamanho * sizeof(int *));
  for(int i = 0; i < tamanho; i++)
    ptrMatriz[i] = (int *)malloc(32 * sizeof(int));
  if(ptrMatriz == NULL){
    //printf("\nErro de alocacao de memoria");
    return NULL;
  }
  else
    //printf("\no vetor foi criado");
 
  return ptrMatriz;
}
 
void troca(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int maxInArray(int vet[], int n) {
  int max = vet[0];
  for (int i = 1; i < n; i++)
    if (vet[i] > max)
      max = vet[i];
  return max;
}

void countingSort(int *vetA, int *vetB, int decimal, int n){
  int i, j, max = ((vetA[0] / decimal) % 10);       //arrayA arranjo original e arrayB de saida
  int *C;

  //achar o elemento maximo do decimal que está
  for (int i = 1; i < n; i++) {
    printf("%d", ((vetA[i] / decimal) % 10));
    if (((vetA[i] / decimal) % 10) > max)
      max = ((vetA[i] / decimal) % 10);
  }
  printf("n = %d, max = %d\n", n, max);
  C = criaVetor(max + 1);

    //limpa vetor C
  for(i = 0; i <= max; i++) 
    C[i] = 0;
      printf("b ");

    //contar quantos elementos tem para cada chave
  for(j = 0 ; j < n; j++)   
    C[(vetA[j] / decimal) % 10] = C[(vetA[j] / decimal) % 10]+1;
  printf("c ");

    //percorre arrayC e faz uma soma prefixa, soma o valor existente i + soma anterior
  for(i = 1; i <= max; i++)
    C[i] = C[i] + C[i-1];
    printf("d ");

    //percorre ao contrario o arrayA
    //ordena o vetor resultante, escreve no vetorB no indice vetorC
    //escreve a ultima posicao de vetA na   posicao correta de vetB
    // e dps decrementa em -1 no vetorC
  for(j = n-1; j >= 0; j--){
    //printf("??\n"); 
    vetB[C[(vetA[j] / decimal) % 10]-1] = vetA[j];
    //printf("??\n");
    C[(vetA[j] / decimal) % 10] = C[(vetA[j] / decimal) % 10] -1;
  }
   printf("e ");

  for (int i = 0; i < n; i++) {
    vetA[i] = vetB[i];
  }
  printf("SAIU!\n");
  return;
}

//ordenar e depois combinar os vetores de acordo com a ordem desejada
//ordena-se através de cada casa, começando pela unidade(0>1>2>...) e dps dezena, ...
//ordenar o valor do vetor pelo coutingSort depois ordenar os vetores pelo radixSort
//de acordo com o numero menos significativo para o mais significativo do vetor
void radixSort(int *vetA, int *vetB, int n){
  int decimal;    //sistema decimal: 1=unidade, 2=dezena, 3=centena
  int max = maxInArray(vetA, n);

  for (decimal = 1; (max/decimal) > 0; decimal *= 10){
    countingSort(vetA, vetB, decimal, n);
    for(int j = 0; j < n; j++)
      printf("  %d\n", vetA[j]);
  }

  return;
}
 
int main() {
  int *vetNum;
  int *vetOut;
  //int vetChave[26] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};  
  int n, max, i, k;
 
  printf("\nDigite a quantidade de numeros: ");
  scanf("%d", &n);     
  //scanf("%d", &s);
 
  //matPalavra = criaMatriz(n);
  vetNum = criaVetor(n);
  vetOut = criaVetor(n);

//    for(i=0;i < 26 ;i++)
//     printf("%d ", vetChave[i]);
//     printf("\n\n");

 
  //printf("Digite a chave de %d caracteres: ", s);
  //  scanf("%d", vetChave);
 
  printf("Digite %d numeros separadas por espaço: ", n);
    for (i = 0; i < n; i++) {
      scanf("%d", &vetNum[i]);
    }

  //printf("Qual eh a maior casa dos numeros digitados(unidade, dezena, ...)?\n");

  radixSort(vetNum, vetOut, n);
  
  printf("entrou\n");
  for(i=0;i < n ;i++)
   printf("%d ", vetNum[i]);
   printf("\n\n");

  for(i=0;i < n ;i++)
    printf("%d ", vetOut[i]);

  free(vetNum);
  free(vetOut);

  return 0;
}

//fazer em etapas, primeiro comece com iteiros, depois carateres e depois strings
//tente ordear primeiramente em ordem alfabeicao, depois ordne alafabetica

//explicacao das saidas

//palavras ordenadas pela chave separadas por \n
//tamaho do maior string
//cada linha de numeros mostra os prcessos do countSor de cada palavra, que tera tamanho 30 e o tamanho de lnhas é a tamanho da maior string
//lista ordeada alfabeicamente

//radixSort + countSort





// int comparaChave(int* str1, int* str2, int* chave) {
//   int j;
 
//   if(strlen(str1) >= strlen(str2))
//     j = strlen(str2);
//   else
//     j = strlen(str1);
//     for (int i = 0; i<j; i++) {
//         int idx1 = strchr(chave, str1[i]) - chave;
//         int idx2 = strchr(chave, str2[i]) - chave;
//         if(idx1 != idx2) {
//           //if(strlen(str1) < i)
//             //return 1;
//           //else
//             return idx1 - idx2;
//         }
//     }
//     return strcmp(str1, str2);
// }