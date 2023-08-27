#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Gerar_vetor(int *, int *);
void LeVetor(int *, int);    //ou substituir * por []
void Imprimir(int *, int);
void Liberar_alocacao(int *);

int main(){
  int *vet, n;

  vet = Gerar_vetor(vet, &n);       //vet recebe o ponteiro e o 'vet' vira um vetor novo
  LeVetor(vet, n);    //precisa passar a quantidade de vetor por que a funçao nao sabe o quanto possui
  Imprimir(vet, n);
  Liberar_alocacao(vet);        //libera a memoria alocada em vet
  
  return 0;
}

int Gerar_vetor(int *vet, int *n){
  
  printf("Entre com o o tamanho do vetor:  ");
  scanf("%d", n);

  vet = (int*)malloc((*n)*sizeof(int));

  return vet;
}

void LeVetor(int *v, int n){      //ou substituir * por []
  int i;

  srand(time(NULL));
  for(i = 0;i < n; i++){
    v[i] = (rand()%199)-99;
  }
  return;
}

void Imprimir(int *v, int n){
  int i;
  
  for(i = 0; i < n; i++){
    printf("%i\t", v[i]);
  }
  
  return;
}

void Liberar_alocacao(int *v){
  free(v);
  
  return;
}


/*Faça uma função que receba um valor n e crie dinamicamente um vetor de n
elementos e retorne um ponteiro. Crie uma função que receba um ponteiro para um
vetor e um valor n e imprima os n elementos desse vetor. Construa também uma
função que receba um ponteiro para um vetor e libere esta área de memória. Ao final,
crie uma função principal que leia um valor n e chame a função criada acima. Depois,
a função principal deve ler os n elementos desse vetor. Então, a função principal deve
chamar a função de impressão dos n elementos do vetor criado e, finalmente, liberar a
memória alocada através da função criada para liberação.*/