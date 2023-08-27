#include <stdio.h>
#include <stdlib.h>
 
int * criaVetor(int);
void troca(int *, int , int);
void quickSortUlt(int *, int, int, int *, int *, int);
int particaoUlt(int *, int, int);
void quickSortMed(int *, int, int, int *, int *, int);
int particaoMed(int *, int, int);
 
 
int* criaVetor(int tamanho){
  int *ptrVetor;
  
  ptrVetor = (int *)malloc(tamanho * sizeof(int));
  if(ptrVetor == NULL){
    //printf("\nErro de alocacao de memoria");
    return NULL;
  }
  else
    //printf("\no vetor foi criado");
 
  return ptrVetor;
}
 
void troca(int *A, int b, int c) {
    int temp = A[b];
    A[b] = A[c];
    A[c] = temp;
}
 
void quickSortUlt(int *vetUlt, int inicio, int final, int *max, int *min, int count){
  int pivo;
 
  if(inicio < final){
    count++;
    pivo = particaoUlt(vetUlt, inicio, final);
    quickSortUlt(vetUlt, inicio, pivo-1, max, min, count);
    quickSortUlt(vetUlt, pivo+1, final, max, min, count);
    }
  else{ 
    if (count > *max) 
      *max = count;
    if (count < *min)
      *min = count;
  }
  return;
}
 
int particaoUlt(int *vetor, int inicio, int final){
  int pivo = vetor[final];
  int i, j, aux;
 
  j = inicio-1;
  for(i = inicio; i < final; i++){
    if(vetor[i] <= pivo){
        j++;
        aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
    }
  }
  aux = vetor[j+1];
  vetor[j+1] = vetor[final];
  vetor[final] = aux;
 
  return j+1;
}
 
void quickSortMed(int *vetMed, int inicio, int final, int *max, int *min, int count){
  int pivo;
 
  if(inicio < final){
    count++;
    pivo = particaoMed(vetMed, inicio, final);
    quickSortMed(vetMed, inicio, pivo-1, max, min, count);
    quickSortMed(vetMed, pivo+1, final, max, min, count);
  }
  else{ 
    if(count > *max)
      *max = count;
    if(count < *min)
      *min = count;
  }
  return;
}
 
int particaoMed(int *vetor, int inicio, int final){
  int meio = (inicio + final)/2;
  int a = vetor[inicio];
  int b = vetor[meio];
  int c = vetor[final];
  int medianaIndice; 
  
  if(a < b){
    if(b < c){
    medianaIndice = meio;
  }else{                
    if(a < c){
    medianaIndice = final;
    }else{
    medianaIndice = inicio;
      }
    }
  }else{
    if(c < b){
      medianaIndice = meio;
    }else{
      if(c < a){
        medianaIndice = final;
      }else{
        medianaIndice = inicio;
      }
    }
  }
    troca(vetor, medianaIndice, final);
   
    int pivo =vetor[final];
    int i = inicio - 1;
    int j;
  
    for (j = inicio; j <= final - 1; j++) {
        if (vetor[j] <= pivo) {
            i = i + 1;
            troca(vetor, i, j);
        }
    }
    troca(vetor, i + 1, final);
 
  return i+1;
}
 
int main() {
  int *vetUlt;    //vetor pelo pivo no ultimo
  int *vetMed;    //vetor pela mediana de tres
  int n, i, max, min, dif;
 
//  printf("\nDigite a quantidade de numeros: ");
  scanf("%d", &n);
 
  vetUlt = criaVetor(n);
  vetMed = criaVetor(n);
 
 // printf("Digite a sequencia de %d numeros: ", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &vetUlt[i]);
    vetMed[i] = vetUlt[i];
  }
  
  //printf("entrou\n");
  max = 0;
  min = n;
  quickSortUlt(vetUlt, 0, n-1, &max, &min, 0);
  //printf("\nmax %d\n", max);
 // printf("min %d\n", min);
  dif = max-min;
  printf("%d\n", dif);
 // for(i=0;i < n ;i++)
  //  printf("%d ", vetUlt[i]);
 
  max = 0;
  min = n;
  quickSortMed(vetMed, 0, n-1, &max, &min, 0);
 // printf("\nmax %d\n", max);
 // printf("min %d\n", min);
  dif = max-min;
  printf("%d\n", dif);
  //for(i=0;i < n ;i++)
 //   printf("%d ", vetMed[i]);
 
  free(vetUlt);
  free(vetMed);
 
  return 0;
}