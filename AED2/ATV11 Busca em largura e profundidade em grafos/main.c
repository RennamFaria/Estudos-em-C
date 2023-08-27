  #include <stdio.h>
  #include <stdlib.h>
  
  
  typedef struct No{
      int num;
      int qtd;  //quantade de arestas ligada à ele
      int cor;  //0 = branco, 1 = cinza, 2 = preto
      int dist;
      struct No *pred;    //antecessor desse vértice, no caminho
      struct No *prox;
  }TipoNo;
  
  typedef struct FilaAux{
   struct No *ptrNo;    //ponteiro para um nó/vertice
   struct FilaAux *prox;
  }TipoFilaAux;
  
  typedef struct Grafo{
      int vert;
      int arest;
      struct No **listaAdj;
  }TipoGrafo;
  
  ////////////////////////////////////////////////////////
  
  TipoGrafo* inicializaGrafo() {
    return NULL;
  }
  
  TipoNo* inicializaNo() {
    return NULL;
  }
  
  TipoFilaAux* inicializaFila() {
    return NULL;
  }
  
  TipoFilaAux* criaFila(TipoNo* No){
    TipoFilaAux* novaFila = malloc(sizeof(TipoFilaAux));
    novaFila->ptrNo = No;
    novaFila->prox = NULL;
    return novaFila;
  }
    
  
  TipoNo* criaNo(TipoGrafo* grafo, int num) {
    TipoNo* novoNo = malloc(sizeof(TipoNo));
    novoNo->num = num;
    novoNo->cor = 0;
    novoNo->dist = 0;
    novoNo->pred = NULL;
    novoNo->qtd = 0;
    novoNo->prox = NULL;
    return novoNo;
  }
  
  TipoGrafo* criaGrafo(int vert, int arest) {
    TipoGrafo* novoGrafo = malloc(sizeof(TipoGrafo));
    novoGrafo->vert = vert;
    novoGrafo->arest = arest;
  
    novoGrafo->listaAdj = malloc(100 * sizeof(TipoNo*));
  
    for (int i = 0; i < 100; i++)
      novoGrafo->listaAdj[i] = NULL;
  
    return novoGrafo;
  }
  
  void insereNo(TipoGrafo* grafo, int origem, int destino) {
    if(grafo->listaAdj[origem] == NULL){
      grafo->listaAdj[origem] = criaNo(grafo, origem);
    }
    if(grafo->listaAdj[destino] == NULL){
      grafo->listaAdj[destino] = criaNo(grafo, destino);
    }
    TipoNo* novoNo = criaNo(grafo, destino);
    TipoNo* aux = grafo->listaAdj[origem]->prox;
    if(aux == NULL){
      grafo->listaAdj[origem]->prox = novoNo;
      grafo->listaAdj[origem]->prox->dist++;
      return;
    }
    if(aux != NULL && aux->num > novoNo->num){
      novoNo->prox = grafo->listaAdj[origem]->prox;
      grafo->listaAdj[origem]->prox = novoNo;
      return;
    }
    while(aux->prox != NULL &&  aux->num > aux->prox->num){
      aux = aux->prox;
    }
    novoNo->prox = aux->prox;
    aux->prox = novoNo;
    aux->prox->dist++;
    //grafo->listaAdj[origem] = novoNo;
  
    return;
  }
  // void ordemCrescGrafo(TipoGrafo* grafo){
  //   int i;
  //   TipoNo* aux;

  //   for(i = 0; i < grafo->vert; i++){
  //     aux = grafo->listaAdj[i]->prox;

  //     while(aux != NULL){

        



  //       aux = aux->prox;
  //     }

  //   }



  //   return;
  // }

  // void selectionSortPtr(TipoNo* No, int tam){




  //   return;
  // }
  
  void insereNaFila(TipoFilaAux** fila, TipoNo* No) {
    TipoFilaAux* novaFila = criaFila(No);

    if (*fila == NULL) {
      *fila = novaFila;
    } 
    else {
      TipoFilaAux* aux = *fila;
      while (aux->prox != NULL) {
        aux = aux->prox;
      }
      aux->prox = novaFila;
    }
    return;
  }
  
  TipoNo* retiraDaFila(TipoFilaAux** fila){
    TipoFilaAux* aux = NULL;
   if(*fila == NULL){
    return NULL;    //a fila ja esta vazia, nao tem o que fazer
   }
   else{
    aux = *fila;
    *fila = aux->prox;
    //free(aux);
    //tam--;
     
    return aux->ptrNo;
   }
  }

//busca em largura
  void BFS(TipoGrafo* grafo, TipoNo* Adj[], int fonte, TipoFilaAux* fila){
    int i, box;   
    TipoNo* u;
    TipoNo* aux;
    for(i = 0; i < 100; i++){
      if(grafo->listaAdj[i] != NULL){
      grafo->listaAdj[i]->cor = 0;  // = branco
      grafo->listaAdj[i]->dist = 9999999;  // = infinito
      grafo->listaAdj[i]->pred = NULL;
      }
    }
  
    grafo->listaAdj[fonte]->cor = 1;  // = cinza
    grafo->listaAdj[fonte]->dist = 0;
    grafo->listaAdj[fonte]->pred = NULL;
    insereNaFila(&fila, grafo->listaAdj[fonte]);
    printf("%d", grafo->listaAdj[fonte]->num);

     while(fila != NULL){
       u = retiraDaFila(&fila);
       aux = u;
       while (aux != NULL) {
            if(grafo->listaAdj[aux->num]->cor == 0){  // == branco
              grafo->listaAdj[aux->num]->cor = 1;    // = cinza
              grafo->listaAdj[aux->num]->dist = u->dist + 1;
              grafo->listaAdj[aux->num]->pred = u;
              insereNaFila(&fila, grafo->listaAdj[aux->num]);
              printf(" %d", grafo->listaAdj[aux->num]->num);
           }
           aux = aux->prox;
       }
       grafo->listaAdj[u->num]->cor = 2;    // = preto
    }
    return;
  }

void DFSvisita(TipoGrafo* grafo, TipoNo* No, int *tempo){
  TipoNo* aux;
  if(*tempo != 0)
    printf(" ");
  *tempo = *tempo+1;
  printf("%d", No->num);
  
  No->cor = 1;    // = cinza

  aux = No;
   while(aux != NULL){
     if(grafo->listaAdj[aux->num]->cor == 0){    //se adjacente de No == branco
       grafo->listaAdj[aux->num]->pred = No;
       DFSvisita(grafo, grafo->listaAdj[aux->num], tempo);
     }
     aux = aux->prox;
   }
  No->cor = 2;    // = preto
  return;
}

//busca em profundidade
void DFS(TipoGrafo* grafo, int fonte){ 
  int i, tempo;
  TipoNo* aux;
  for(i = 0; i < 100; i++){
    if(grafo->listaAdj[i] != NULL){
    grafo->listaAdj[i]->cor = 0;    // = branco
    grafo->listaAdj[i]->pred = NULL;
    }
  }
  
  tempo = 0;
  aux = grafo->listaAdj[fonte];
  while(aux != NULL){
    if(grafo->listaAdj[aux->num]->cor == 0){
      DFSvisita(grafo, grafo->listaAdj[aux->num], &tempo);
    }
    aux = aux->prox;
  }
  return;
}
  void printaGrafo(TipoGrafo* grafo) {
    int i;
    for (i = 0; i < 10; i++) {
      TipoNo* aux = grafo->listaAdj[i];
      printf("\n Vertex %d\n: ", i);
      while (aux != NULL) {
        printf("%d -> ", aux->num);
        aux = aux->prox;
      }
      printf("\n");
    }
  }
  
  int main() {
    TipoGrafo* grafo;
    TipoNo* no;
    TipoFilaAux* fila;
    int inicio, vert, arest, num, adj;
  
    grafo = inicializaGrafo();
    no = inicializaNo();
    fila = inicializaFila();
    
    scanf("%d", &inicio);
    scanf("%d", &vert);
    scanf("%d", &arest);
    
    grafo = criaGrafo(vert, arest);
    
    for(int i = 0; i < arest; i++){
      scanf("%d", &num);
      scanf("%d", &adj);
      insereNo(grafo, num, adj);
      //printaGrafo(grafo);
    }
   // ordemCrescGrafo(grafo);
    BFS(grafo, grafo->listaAdj, inicio, fila);
    printf("\n");
    DFS(grafo, inicio);
    
    return 0;
  }

  /*
  
7
8 9
1 0
2 0
3 0
4 1
6 3
5 2
7 4
7 6
7 5
  
  */