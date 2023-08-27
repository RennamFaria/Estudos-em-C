#include <stdlib.h>
#include <stdio.h>

int* criarVetor(int *, int);
int ordenaVetor(int *, int);
int encontrarElemento(int , int *, int, int, int *);

//
int* criarVetor(int *ptrVetor, int tamanho){

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

   for(i = 1; i < tamanho; i++){
      box = vetor[i];

      for(j = i-1; (j >= 0) && (box < vetor[j]); j--)
        vetor[j+1] = vetor[j];

      vetor[j+1] = box;
   }

  return 0;
}

int encontrarElemento(int num, int *vetor, int inicio, int fim, int *cont){
  int meio;  
  (*cont)++;

  if(inicio > fim) 
    return -1;

  meio = (inicio + fim)/2;
  
  if(vetor[meio] == num)   //achou o resultado e vai retornar a posiçao dele
    return meio;

  if(vetor[meio] > num)   //o num é antes(menor) da posiçao do meio
    return encontrarElemento(num, vetor, inicio, meio-1, cont);

  if(vetor[meio] < num)   //o num é depois(maior) da posiçao do meio
    return encontrarElemento(num, vetor, meio+1, fim, cont);

  //return i;    //se nao encontrar o valor, -1 por causa que nao existe essa posicao no vetor
}

int main(void) {
  int tamanho, num, i, cont=0, box;
  int* vetor;

  //printf("\ndigite a quantidade de elementos: ");
  scanf("%d", &tamanho);

  vetor = criarVetor(vetor, tamanho);
  
  //printf("\ndigite a sequencia de numeros: ");

  for(i = 0; i < tamanho; i++){
    scanf("%d", &vetor[i]);
  }

  ordenaVetor(vetor, tamanho);
  
  //printf("\ndigite o numero que deseja ser procurado: ");
  scanf("%d", &num);

  box = encontrarElemento(num, vetor, 0, tamanho, &cont);

  if(box == -1){   //se for = -1 ele nao encontrou nada, se for > 0 ele achou
    printf("%d nao foi encontrado", num);
  }
  else
    printf("%d", box+1);

  free(vetor);       //limpa o espaço que criou o vetor

return 0;
}