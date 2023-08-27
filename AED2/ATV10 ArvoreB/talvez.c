#include <stdio.h>
#include <stdlib.h>

  struct nohArvore{
  int *value;
  int count;
    struct nohArvore **link;
};

typedef struct nohArvore TipoNohArvore;
typedef TipoNohArvore *TipoArvore;

TipoArvore createNode(int value, int MM, TipoArvore folha, TipoArvore raiz) {
  TipoArvore novoNoh = (TipoArvore)malloc(sizeof(TipoNohArvore));
  novoNoh->value = (int*)malloc(MM * sizeof(int));
  novoNoh->value[0] = value;
  novoNoh->count = 1;
  for(int i = 0; i < MM+1; i++){
    novoNoh->link[i] = (TipoArvore)malloc(sizeof(TipoNohArvore));
    novoNoh->link[i] = NULL;
}
  novoNoh->link[0] = raiz;
  novoNoh->link[1] = folha;
  return novoNoh;
}

void insertNode(int value, int pos, TipoArvore node, TipoArvore child) {
  int j = node->count;
  while (j > pos) {
    node->value[j + 1] = node->value[j];
    node->link[j + 1] = node->link[j];
    j--;
  }
  node->value[j + 1] = value;
  node->link[j + 1] = child;
  node->count++;
}

void splitNode(int value, int *pvalue, int pos, TipoArvore node, TipoArvore child, TipoArvore *newNode, int MM) {
  int median, j;

  if (pos > (MM-1))
    median = MM;  //pegar uma mediana aritimetica boa para subir, Muda MUITO, resolver
  else
    median = MM-1;  //seria o MIN, nao sei exatamente se MIN = MAX-1
  
  //cria noh
  *newNode = (TipoArvore)malloc(sizeof(TipoNohArvore));
  (*newNode)->value = (int*)malloc(MM * sizeof(int));
  for(int i = 0; i < MM+1; i++)
    (*newNode)->link[i] = (TipoArvore)malloc(sizeof(TipoNohArvore));
  //
  
  j = median + 1;
  while (j <= MM) {  //eu acho que é algum algoritmo de ordenar
    (*newNode)->value[j - median] = node->value[j];
    (*newNode)->link[j - median] = node->link[j];
    j++;
  }
  node->count = median;  //quando eu mudar a mediana tomar cuidado com isso pois provavel que o tamanho correto nao seja o da mediana
  (*newNode)->count = MM - median;

  if (pos <= MM-1) {
    insertNode(value, pos, node, child);
  } else {
    insertNode(value, pos - median, *newNode, child);
  }
  *pvalue = node->value[node->count];
  (*newNode)->link[0] = node->link[node->count];
  node->count--;
}//fazer teste com o caderno ajuda muito
//dica, fazer do 0, passo a passo do primeiro exemplo e ver o que esta dando de errado, vai demorar mais vai ser muito util para o futuro

int setValue(int value, int *pvalue, TipoArvore node, TipoArvore *child, int MM) {
  int pos;
  if (node == NULL) {
    *pvalue = value;
    *child = NULL;
    return 1;
  }

  if (value < node->value[1]) {
    pos = 0;
  } 
  else {
    for (pos = node->count; (value < node->value[pos] && pos > 1); pos--)
    if (value == node->value[pos]) {
      printf("The duplicates are not allowed\n");
      return 0;
    }
  }
  if (setValue(value, pvalue, node->link[pos], child, MM)) {//nao ter crianca  ou se tiver cheio
    if (node->count < MM) {
      insertNode(*pvalue, pos, node, *child);
    } else {
      splitNode(*pvalue, pvalue, pos, node, *child, child, MM);
      return 1;
    }
  }
  return 0;
}

TipoArvore insert(TipoArvore root, int value, int MM) {
  TipoArvore child = NULL;
  int aux, i;
  //printf("entrou");

  aux = setValue(value, &i, root, &child, MM);
  if (aux)
    root = createNode(i, MM, root, child);

  return root;
}

void imprimePagina(TipoArvore myNode, int nivel) {
  int i;
  if (myNode) {
    for (i = 0; i < myNode->count; i++) {
      imprimePagina(myNode->link[i], nivel+1);
      printf("N(%d) %d ",nivel, myNode->value[i + 1]);
    }
    imprimePagina(myNode->link[i], nivel+1);
  }
}

int search(int value, int *pos, TipoArvore myNode) {
  int flag = 0;
  if (!myNode) {
    return flag;
  }

  if (value < myNode->value[0]) {
    *pos = 0;
  } else {
    for (*pos = myNode->count;
       (value < myNode->value[*pos] && *pos > 1); (*pos)--)
    if (value == myNode->value[*pos]) {
      imprimePagina(myNode, 0);
      return 1;
    }
  }
  flag  = search(value, pos, myNode->link[*pos]);

  return flag;
}


int main(int argc, char **argv) {
  TipoArvore root;
  int i, num, M, ch = 0;

  root = NULL;

 scanf("%d", &M);
  while (1) {
   // printf("comecou\n");
    scanf("%d", &num);
   // printf("peguei");
    if (num < 0){
      //printf("brekou");
      break;
    }
    //printf("\n entrou");
    //printf("entrando");
    root  = insert(root, num, (M*2));    //algum problema de alocar que esta dando core dumped
    printf("\n saiu\n");
  }

  
  imprimePagina(root, 0);

  scanf("%d", &num);
  printf("\n");
  if(search(num, &ch, root) == 0)
    printf("\nValor nao encontrado");

  return 0;
}

  //https://www.shiksha.com/online-courses/articles/b-tree-in-data-structure/