#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int valor;
} Dado;

Dado Hash;
typedef Dado *TipoDado;
////////////////////////////////////////////////

Dado inicializaHash(int size) {
  Dado Hash;
  int i;
    Hash.valor = -1;

  return Hash;
}

void insereTabelaHash(Dado Hash[], int num, int size){
  int i = -1, box, h1, h2, FP = 0;
  
    do{
      i++;
      h1 = num%size;
      h2 = 1 + (num%(size-1));
      box = (h1 + i*h2)%size;


      if(Hash[box].valor == -1){  //quer dizer que está vazio/nulo
        Hash[box].valor = num;
        FP = 1;
      }
      
    }while(FP == 0);

//k é o valor a ser inserido
  //m sempre tem que ser o primo, nesse caso vamos usar o tamanho da tabela
  //pois todos os tamanho possiveis dado pelo usuario serao primos

//h(k, i) = (h1(k) + ih2(k)) mod m
  //h1(k) = k mod m
//h2(k) = 1 + (k mod (m − 1))
  return;
}

//pesquisa e remoção de numero na tabela hash
int remocaoHash(Dado Hash[], int num, int size){
  int i = -1, box, h1, h2, FP = 0;
  
    do{
      i++;
      h1 = num%size;
      h2 = 1 + (num%(size-1));
      box = (h1 + i*h2)%size;


      if(Hash[box].valor == num){  //quer dizer que está vazio/nulo
        Hash[box].valor = -2;
        FP = 1;
      }
      
    }while(i < size+5);
  return FP; 
}

void imprimeTabelaHash(Dado Hash[], int size){
  int i;

  for(i = 0; i < size; i++){
    if(Hash[i].valor == -2)
      printf("D");
    if(Hash[i].valor == -1)
      printf("\\");
    if(Hash[i].valor > 0)
      printf("%d", Hash[i].valor);
    if(i < size-1)
      printf(" ");
  }
  return;
}

//////////////////////////////////////////////
int main() {
  Dado *Hash;
  int size, num, aux, i;

  scanf("%d", &size);

  Hash = (TipoDado)malloc(size * sizeof(Dado));

  for (i = 0; i < size; i++)
    Hash[i] = inicializaHash(size);
  
  while (1) {
    scanf("%d", &num);
    if (num < 0)
      break;
    insereTabelaHash(Hash, num, size);
  }

  scanf("%d", &num);
  aux = remocaoHash(Hash, num, size);
  if (aux == 0)
    printf("Valor nao encontrado\n");

    imprimeTabelaHash(Hash, size);

  return 0;
  }

// tabelaHash baseada no endereçamento aberto