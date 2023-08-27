#include <stdlib.h>
#include <stdio.h>
 
int* criarVetor(int);
int ordenaVetor(int *, int);
int comparador(int *, int *, int);
 
//
int* criarVetor(int doses){
  int *ptrVetor;
 
  ptrVetor = (int *)malloc(doses * sizeof(int));//criar um vetor com N casas vezes o doses de um int
 
  if (ptrVetor == NULL  ){      //se der erro em criar o vetor isso avisara e sair do programa
    //printf("\nErro de alocacao de memoria");
    free(ptrVetor);
    return NULL;
  }
  else
    //printf("\no vetor foi criado");
 
  return ptrVetor;
}
 
 
int ordenaVetor(int *vetor, int doses){    //metodo: insert sort
  int i, j, box;    //box = numero do vetor comparado com os outros
 
  for(i = 1; i < doses; i++){
    box = vetor[i];
    for(j = i-1; vetor[j] > box; j--){
      vetor[j+1] = vetor[j];
      }
    vetor[j+1] = box;
   }
 
  return 0;
}

int comparador(int *qtdOrganismo, int *potencia, int doses){
  int i, box = 0;

  for(i = 0; i < doses; i++){
    if(qtdOrganismo[i] < potencia[i])
      box++;
  }

  if(box == doses)
    return 1;
  else
    return 0;
}

 
int main(void) {
  int doses, i, box;
  int *qtdOrganismo = NULL, *potencia = NULL;
 
  //printf("\ndigite a quantidade de doses: ");
  scanf("%d", &doses);
 
  qtdOrganismo = criarVetor(doses);
  potencia = criarVetor(doses);
  
  //printf("\ndigite a quantidade de organismo em cada pessoa: ");
  for(i = 0; i < doses; i++){
    scanf("%d", &qtdOrganismo[i]);
  }
  
  //printf("\ndigite as potencia das doses: ");
  for(i = 0; i < doses; i++){
    scanf("%d", &potencia[i]);
  }
 
  ordenaVetor(qtdOrganismo, doses);
  ordenaVetor(potencia, doses);

  box = comparador(qtdOrganismo, potencia, doses);
  
  if(box){ 
    printf("sim");
  }
  else
    printf("nao");
 
  free(qtdOrganismo);       //libera a alocação que criou o vetor
  free(potencia);
 
return 0;
}