#include <stdio.h>
#include <stdlib.h>

void LeVetor(int *, int);    //ou substituir * por []

int main(){
  int *vet, n, i;

  printf("Entre com o o n:  ");
  scanf("%d", &n);

  vet = (int*)malloc(n*sizeof(int));

  LeVetor(vet, n);    //precisa passar a quantidade de vetor por que a funçao nao sabe o quanto possui

  for(i = 0; i < n; i++){
    printf("%i\t", vet[i]);
  }
  
  free(vet);
  
  return 0;
}


void LeVetor(int *v, int N){      //ou substituir * por []
  int i;

  srand(time(NULL));
  for(i = 0;i < N; i++){
    v[i] = (rand()%199)-99;
  }
  return;
}
/* Faça um programa que leia um valor n e crie dinamicamente um vetor de n elementos
e passe esse vetor para uma função que vai ler os elementos desse vetor. Depois, no
programa principal, o vetor preenchido deve ser impresso. Além disso, antes de
finalizar o programa, deve-se liberar a área de memória alocada.*/