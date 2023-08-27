#include <stdlib.h>
#include <stdio.h>

int* criarVetor(int);
int ordenaVetor(int *, int);
int encontrarElemento(int , int *, int, int, int *);

//
int* criarVetor(int tamanho){
  int *ptrVetor;

  ptrVetor = (int *)malloc(tamanho * sizeof(int));//criar um vetor com N casas vezes o tamanho de um float

  if (ptrVetor == NULL  ){      //se der erro em criar o vetor isso avisara e sair do programa
    //printf("\nErro de alocacao de memoria");
    free(ptrVetor);
    return NULL;
  }
  else
    //printf("\no vetor foi criado");

  return ptrVetor;
}


int ordenaVetor(int *vetor, int tamanho){    //metodo: insert sort
  int i, j, box;    //box = numero do vetor comparado com os outros para saber se é maior ou menor

   for(i = 0; i < tamanho; i++){

      for(j = i+1; j < tamanho; j++){
        if(vetor[i] > vetor[j]){
            box = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = vetor[i];
        }
      }
   }

  return 0;
}

int encontrarElemento(int num, int *vetor, int inicio, int fim, int *count){
  int meio;  

  if(inicio <= fim){

    meio = (inicio + fim)/2;
    
    if(vetor[meio] == num)   //achou o resultado e vai retornar a posiçao dele
        return meio;

    if(vetor[meio] > num){   //o num é antes(menor) da posiçao do meio
      (*count)++;
      return encontrarElemento(num, vetor, inicio, meio-1, count);
    }

    else{   //o num é depois(maior) da posiçao do meio
      (*count)++;
      return encontrarElemento(num, vetor, meio+1, fim, count);
    }
  }
  return -1;
}

int main(void) {
  int tamanho, num, i, box, count = 1;
  int* vetor = NULL;

  //printf("\ndigite a quantidade de elementos: ");
  scanf("%d", &tamanho);

  vetor = criarVetor(tamanho);
  
  //printf("\ndigite a sequencia de numeros: ");
  for(i = 0; i < tamanho; i++){
    scanf("%d", &vetor[i]);
  }

  ordenaVetor(vetor, tamanho);
  
  //printf("\ndigite o numero que deseja ser procurado: ");
  scanf("%d", &num);

  box = encontrarElemento(num, vetor, 0, tamanho-1, &count);

  if(box == -1){   //se for = -1 ele nao encontrou nada, se for > 0 ele achou
    printf("%d nao foi encontrado", num);
  }
  else
    printf("%d", count-1);

  free(vetor);       //limpa o espaço que criou o vetor

return 0;
}