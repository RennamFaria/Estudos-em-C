#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct nohArvore { // TipoArvore
  int *dado;    //vetor dinamico
  int qtd;    //marca a quantidade de numeros que existem, ps: o maximo=(M*2)
  struct nohArvore **prox;  //a quantidade de ponteiros será (M*2)+1
  struct nohArvore *subArvorePai;
  //ainda pensansao se uso isso
};

typedef struct nohArvore TipoNohArvore;
typedef TipoNohArvore *TipoArvore;

///////////////////////ABB.c////////////////////////////////

TipoArvore inicializaArvore(TipoArvore arvoreB) { 
  return NULL;
}

TipoArvore destroiSubArvore(TipoArvore arvoreB) {
  int i = 0;
  if (arvoreB == NULL) // se ArvoVaz volte uma recursao
    return NULL;
  while(arvoreB->prox[i] != NULL){
    destroiSubArvore(arvoreB->prox[i]);
    i++;
  }
  free(arvoreB);

  return NULL;
}

TipoArvore destroiArvore(TipoArvore arvoreB) {
  if (arvoreB == NULL) // se arvoreB vazia nao ha nada para destruir dinamicamente
    return NULL;
  arvoreB = destroiSubArvore(arvoreB);
  free(arvoreB);
  return NULL;
}

int* criaVetor(int tam){
  int *vetor;
  vetor = (int*)malloc(tam * sizeof(int));
  if(vetor)
    return vetor;
  else
    printf("Erro ao alocar memória!");

  return vetor;
}

void ordenaVetor(int *vetor, int tamV){    //metodo: insert sort
  int i, j, box;    //box = numero do vetor comparado com os outros
 
  for(i = 1; i < tamV; i++){
    box = vetor[i];
    for(j = i-1; vetor[j] > box; j--){
      vetor[j+1] = vetor[j];
      }
    vetor[j+1] = box;
   }
 
  return;
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
//arvoreB->prox = criarNoh(dado,MM);

TipoArvore criarNoh(int dado, int MM) {
    TipoArvore novoNoh = (TipoArvore)malloc(sizeof(TipoNohArvore));
    // int *vetAux; 
    // vetAux = criaVetor(MM);
    novoNoh->dado = criaVetor(MM);
    novoNoh->qtd = 0;
    novoNoh->subArvorePai = NULL;
    novoNoh->prox = (TipoArvore)malloc((MM+1) * sizeof(TipoNohArvore));
    for(int i = 0; i < MM; i++)
      novoNoh->prox[i] = NULL;
    return novoNoh;
}

TipoArvore dividirArvore(TipoArvore arvoreB, int dado, int MM){
  if(arvoreB == NULL){
    printf("dividirArvore, problem == NULL");
    return;
  }
  TipoArvore arvoreAux;

  arvoreAux = criarNoh(arvoreAux, MM);

  //if()
  


    


  arvoreAux = destroiArvore(arvoreAux);

  return arvoreB;
}

TipoArvore insere(TipoArvore arvoreB, int dado, int MM){
  int i = 0;
    if (arvoreB == NULL) {
      arvoreB = criarNoh(dado, MM);
      return insere(arvoreB, dado, MM);
    }else{
      if(arvoreB->qtd < MM){  //há espaço para adicionar na pagina
        if(arvoreB->prox != NULL){
          arvoreB->dado[arvoreB->qtd] = dado;
          arvoreB->qtd++;
          ordenaVetor(arvoreB->dado, arvoreB->qtd);
          printArray(arvoreB->dado, arvoreB->qtd);
        }
        else{
          if(dado < arvoreB->dado[0]){
            return insere(arvoreB->prox[0], dado, MM);  //quando há ponteiros e é menor que dado[0]
          }
          for(i = 0; i < arvoreB->qtd-1; i++){
            if(dado > arvoreB->dado[i] && dado < arvoreB->dado[i+1]){
              return insere(arvoreB->prox[i+1], dado, MM); //quando há ponteiro e está entro dois dados
            }
            if(dado > arvoreB->dado[arvoreB->qtd-1]){
              return insere(arvoreB->prox[arvoreB->qtd], dado, MM);//quando há ponteiro e é maior que o dado[MM]
            }
          } 
        }
      }
      else{
        dividirArvore(arvoreB, dado, MM);
      }
    }

  return arvoreB;
}

int procuraElemento(TipoArvore arvoreB, int num, int altura){
  if(arvoreB == NULL)
    printf("Valor nao encontrado");
    return altura;
  for(int i = 0; i < arvoreB->qtd; i++){
    if(num == arvoreB->dado[i])
      return printf("%d", altura);
    if(num < arvoreB->dado[i])
      return procuraElemento(arvoreB->prox[i], num, altura+1);    
    if(num > arvoreB->dado[i] && num < arvoreB->dado[i+1])
      return procuraElemento(arvoreB->prox[i+1], num, altura+1);
  }

  return printf("Valor nao encontrado");
}

void imprimeArvoreEmOrdem(TipoArvore arvoreB) { // remover dps essa funcao
  int i, j;
  if (arvoreBVazia(arvoreB))
    return;

  printf("qtd = %d ", arvoreB->qtd);
  
  for(i = 0; i < arvoreB->qtd; i++)
    printf("dado = %d", arvoreB->dado[i]);

  i = 0;
  if (arvoreB->prox[i] != NULL)
    for(i = 0; arvoreB->prox[i] != NULL; i++){
      printf("\n-ArvoreProx[%d]-\n", i);
      for(j = 0; j < arvoreB->qtd; j++){
        printf("\n");
        printf(" dado[%d] = %d", j, arvoreB->prox[i]->dado[j]);
      }
    }

  printf("\n");

  i = 0;
  while(arvoreB->prox[i] != NULL){
    imprimeArvoreEmOrdem(arvoreB->prox[i]);
    i++;
  }

  return;
}
////////////////////////////////main.c////////////////////////////////

int main() {
  TipoArvore raizB;
  int num, aux = 0, M;

  raizB = inicializaArvore(raizB);

  scanf("%d", &M);
  // printf("\nDigite um valor para inserir na arvoreB\n");
  while (1) {
    scanf("%d", &aux);
    if (aux < 0)
      break;
    raizB = insere(raizB, aux, M*2);
    //imprimeArvoreEmOrdem(raiz);
  }

  //imprimeArvoreEmOrdem(raiz);

  aux = 0;
  scanf("%d", &num);

  //procuraElemento(raizB, num, 0);

  raizB = destroiArvore(raizB);
  return 0;
}

//funcao para achar o pai

/*TipoArvore insereAVPnaArvore(TipoArvore arvoreB, int dado, TipoArvore *atual) {

    if (arvoreB == NULL) {
        arvoreB = criarNoh(dado);
        arvoreB->fb_cor = 1; // Rubro
        *atual = arvoreB;
        return arvoreB;
    }else{
      if (dado < arvoreB->dado) {
        arvoreB->subArvoreEsq = insereAVPnaArvore(arvoreB->subArvoreEsq, dado, atual);
        arvoreB->subArvoreEsq->subArvorePai = arvoreB;
      }
      if (dado > arvoreB->dado) {
        arvoreB->subArvoreDir = insereAVPnaArvore(arvoreB->subArvoreDir, dado, atual);
        arvoreB->subArvoreDir->subArvorePai = arvoreB;
      }
    }

    return arvoreB;
}*/