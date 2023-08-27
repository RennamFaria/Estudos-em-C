#include <stdio.h>
#include <stdlib.h>

int * criaVetor(int);
void quickSortUlt(int *, int, int, int *, int *, int);
void quickSortMed(int *, int, int);
int particaoUlt(int *, int, int);
int particaoMed(int *, int, int);

int* criaVetor(int tamanho){
  int *ptrVetor;
  
  ptrVetor = (int *)malloc(tamanho * sizeof(int));
  if(ptrVetor == NULL){
    printf("\nErro de alocacao de memoria");
    free(ptrVetor);
    return NULL;
  }
  else
    printf("\no vetor foi criado");

  return ptrVetor;
}

void quickSortUlt(int *vetUlt, int inicio, int final, int *max, int *min, int count){
  int pivo;
  if(count > *max)
    *max = count;

  if(inicio >= final)
    return;
  pivo = particaoUlt(vetUlt, inicio, final);
  quickSortUlt(vetUlt, inicio, pivo-1, max, min, count++);
  quickSortUlt(vetUlt, pivo+1, final, max, min, count++);
  
  return;
}

int particaoUlt(int *vetor, int inicio, int final){
  int pivo = vetor[final];
  int i, j, aux;

  j = inicio-1;
  for(i = inicio; i < final-1; i++){
    if(vetor[i] <= pivo){
        i++;
        aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
    }
  }
  aux = vetor[i+1];
  vetor[i+1] = vetor[final];
  vetor[final] = aux;
//entender antes de fazer abobrinha
  return pivo+1;
}

void quickSortMed(int *vetUlt, int inicio, int final){
  if(inicio >= final)
    return;

  int pivo = particaoMed(vetUlt, inicio, final);
  quickSortMed(vetUlt, inicio, pivo-1);
  quickSortMed(vetUlt, pivo, final-1);
  
  return;
}

int particaoMed(int *vetor, int inicio, int final){
  int pivo;


  return pivo;
}

int main() {
  int *vetUlt;    //vetor pelo pivo no ultimo
  int *vetMed;    //vetor pela mediana de tres
  int n, dif, max, min;

  printf("\nDigite a quantidade de numeros: ");
  scanf("%d", &n);

  vetUlt = criaVetor(n);
  vetMed = criaVetor(n);

  printf("Digitie a sequência de %d numeros: ", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &vetUlt[i]);
    vetMed[i] = vetUlt[i];
  }
  
  max = 0;
  min = 0;
  printf("entro");
  quickSortUlt(vetUlt, 1, n, &max, &min, 0);
  printf("Diferença entre altura max e min com pivo pelo ultimo: %d\n", dif);
  printf("%d\n%d\n", max+1, min);
  

  //quickSortMed(vetMEd, 0 , n);
  printf("Diferença entre altura max e min com pivo mediana de tres: %d\n", dif);

  free(vetUlt);
  free(vetMed);

  return 0;
}



void quickSortMed(int *vetUlt, int inicio, int final){
  if(inicio >= final)
    return;

  int pivo = particaoMed(vetUlt, inicio, final);
  quickSortMed(vetUlt, inicio, pivo-1);
  quickSortMed(vetUlt, pivo, final-1);
  
  return;
}

int particaoMed(int *vetor, int inicio, int final){
  int pivo;


  return pivo;
}