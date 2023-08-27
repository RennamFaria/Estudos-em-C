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

void imprimeArvoreEmOrdem(TipoArvore arvoreB) { // remover dps essa funcao
  int i, j;
  if (arvoreB == NULL)
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

int* criaVetor(int tam){
  int *vetor;
  vetor = (int*)malloc(tam * sizeof(int));
  if(vetor)
    return vetor;
  else
    printf("Erro ao alocar Vetor memória!");

  return vetor;
}

// TipoArvore criarVetorArv(int tam){
//   TipoArvore vetorArv;
//     vetorArv = (TipoArvore)malloc(sizeof(TipoNohArvore));
//   if(vetorArv)
//     return vetorArv;
//   else
//     printf("Erro ao alocar VetorArvore memória!");

//   return vetorArv;
// }

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

TipoArvore ordenaPonteiros(TipoArvore arvoreB, int tamanho){
  TipoArvore arvoreAux = (TipoArvore)malloc(sizeof(TipoNohArvore));
  int i, j, dadoA;
  
  for(i = 0; i < tamanho+1; i++){
    if(arvoreB->prox[i] != NULL){
      dadoA = arvoreB->prox[i]->dado[arvoreB->prox[i]->qtd-1];
       if(dadoA < arvoreB->dado[0]){
         arvoreAux = arvoreB->prox[0];
         arvoreB->prox[0] = arvoreB->prox[i];
         arvoreB->prox[i] = arvoreAux;
       }
     for(j = 0; j < tamanho; j++){
       if(dadoA > arvoreB->dado[j] && dadoA < arvoreB->dado[j+1]){
         arvoreAux = arvoreB->prox[j];
         arvoreB->prox[j] = arvoreB->prox[i];
         arvoreB->prox[i] = arvoreAux;
       }
     }
      if(dadoA < arvoreB->dado[tamanho]){
         arvoreAux = arvoreB->prox[tamanho];
         arvoreB->prox[tamanho] = arvoreB->prox[i];
         arvoreB->prox[i] = arvoreAux;
       }
    }
    else
      return arvoreB;
  }
  return arvoreB;
}

void printArray(int arr[], int n){
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
//arvoreB->prox = criarNoh(dado,MM);

TipoArvore criarNoh(int MM) {
    TipoArvore novoNoh = (TipoArvore)malloc(sizeof(TipoNohArvore));
    // int *vetAux; 
    // vetAux = criaVetor(MM);
    novoNoh->dado = criaVetor(MM);
    novoNoh->qtd = 0; 
    novoNoh->subArvorePai = NULL;
    for(int i = 0; i < MM+1; i++)
      novoNoh->prox[i] = (TipoArvore)malloc(sizeof(TipoNohArvore));
    for(int i = 0; i < MM+1; i++)
      novoNoh->prox[i] = NULL;
  
    return novoNoh;
}

TipoArvore dividirArvore(TipoArvore arvoreB, int dado, int MM){
  if(arvoreB == NULL){
    printf("dividirArvore, problem == NULL");
    return arvoreB;
  }
  TipoArvore arvoreAux;
  int i;

  arvoreAux = criarNoh(MM);
  arvoreAux->subArvorePai = arvoreB->subArvorePai;

  for(i = 0; i < (MM/2); i++){
    arvoreAux->dado[i] = arvoreB->dado[i+(MM/2)];
    arvoreAux->qtd++;
    arvoreB->dado[i+(MM/2)] = 0;
    arvoreB->qtd--;
  }

  if(dado < arvoreAux->dado[0]){
    arvoreB->dado[arvoreB->qtd] = dado;
    arvoreB->qtd++;
    ordenaVetor(arvoreB->dado, arvoreB->qtd);
  }
  else{
    arvoreAux->dado[arvoreAux->qtd] = dado;
    arvoreAux->qtd++;
    ordenaVetor(arvoreAux->dado, arvoreAux->qtd);
  }

  if(arvoreB->subArvorePai == NULL){
    arvoreB->subArvorePai = criarNoh(MM);
    arvoreB->subArvorePai->prox[0] = arvoreB;
    arvoreB->subArvorePai->prox[1] = arvoreAux;
    
    if(arvoreB->qtd > arvoreAux->qtd){
      arvoreB->subArvorePai->dado[0] = arvoreB->dado[arvoreB->qtd-1];
      arvoreB->subArvorePai->qtd++;
      arvoreB->dado[arvoreB->qtd-1] = 0;
      arvoreB->qtd--;
    } 
    else{
      arvoreB->subArvorePai->dado[0] = arvoreAux->dado[0];
      arvoreB->subArvorePai->qtd++;
      arvoreAux->dado[0] = 0;
      arvoreAux->qtd--;
      ordenaVetor(arvoreAux->dado, arvoreAux->qtd);
    }
  }
  //se pai ja existe preciso inserir um novo valor nele e remodular os ponteiros dos proximos
  if(arvoreB->subArvorePai != NULL && arvoreB->subArvorePai->qtd < MM+1){
    arvoreB->subArvorePai->dado[arvoreB->subArvorePai->qtd] = dado;
    arvoreB->subArvorePai->qtd++;
    ordenaVetor(arvoreB->subArvorePai->dado, arvoreB->subArvorePai->qtd);//talvez o ordenaVetor deva vim antes da adcionar +1 na quantidade
    arvoreB->subArvorePai = ordenaPonteiros(arvoreB->subArvorePai, MM);
  }
  if(arvoreB->subArvorePai != NULL && arvoreB->subArvorePai->qtd > MM+1){
    arvoreB->subArvorePai = dividirArvore(arvoreB, dado, MM);
  }

  return arvoreB;
}

TipoArvore insere(TipoArvore arvoreB, int dado, int MM){
  int i = 0;
    if (arvoreB == NULL) {
      arvoreB = criarNoh(MM);
      return insere(arvoreB, dado, MM);
    }
      else{
        if(arvoreB->prox[0] != NULL){
          if(dado < arvoreB->dado[0] && arvoreB->prox[0] != NULL){
            return insere(arvoreB->prox[0], dado, MM);
          }
          for(i = 0; i < MM; i++){
            if(dado > arvoreB->dado[i] && dado < arvoreB->dado[i+1]){
            return insere(arvoreB->prox[i+1], dado, MM);
          }
          if(dado < arvoreB->dado[MM] && arvoreB->prox[MM] != NULL){
            return insere(arvoreB->prox[MM], dado, MM);
          }
        }
        if(dado < arvoreB->dado[0]){
          return insere(arvoreB->prox[0], dado, MM);  //quando há ponteiros e é menor que dado[0]
        }
        }
        else{
          for(i = arvoreB->qtd; dado < arvoreB->dado[i] && i > 1; i--){
          } 
          if (dado == arvoreB->dado[i]){  //quer dizer que ja existe
            return arvoreB;
          }
        }
        if(arvoreB->prox[i] == NULL){
          if(arvoreB->qtd < MM){
            arvoreB->dado[arvoreB->qtd] = dado;
            arvoreB->qtd++;
            ordenaVetor(arvoreB->dado, arvoreB->qtd);
          }
          else{
            arvoreB = dividirArvore(arvoreB, dado, MM);
            return arvoreB;
          }
        }
        }
  return arvoreB;
}

int procuraElemento(TipoArvore arvoreB, int num, int altura, int aux){
  int i;
  if(arvoreB == NULL)
    return aux;
  for(i = 0; i < arvoreB->qtd && num > arvoreB->dado[i]; i++){
  }

  if(num == arvoreB->dado[i]){
    printf("%d\n", altura);
    imprimeArvoreEmOrdem(arvoreB);
    return 1;
  }
  if(arvoreB->prox[0] == NULL)  //quer dizer que nao teem mais paginas para frente
    return printf("Valor nao encontrado");
  else
    return procuraElemento(arvoreB->prox[i], num, altura+1, aux);

  return aux;
}

////////////////////////////////main.c////////////////////////////////

int main() {
  TipoArvore raizB;
  int num, aux = 0, M;

  raizB = inicializaArvore(raizB);

  printf("\nDigite a ordem da Arvore");
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
  printf("\nDigite o numero a ser pesquisado");
  scanf("%d", &num);

  if(procuraElemento(raizB, num, 0, 0) == 0)
    printf("Valor nao encontrado");


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