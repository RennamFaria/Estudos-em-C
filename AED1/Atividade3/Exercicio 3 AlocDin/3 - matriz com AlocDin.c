#include <stdio.h>
#include <stdlib.h>

int Gerar_matriz(int **, int *, int *);
void LeVetor(int **, int, int);    //ou substituir * por []
void Imprimir(int **, int, int);
void Liberar_alocacao(int **, int);

int main(){
  int **matriz;
  int n, m;    //n = coluna ,     m = linha

  matriz = Gerar_matriz(matriz, &n, &m);       //matriz recebe o ponteiro e o 'matriz' vira um matriz novo
  LeVetor(matriz, n, m);    //precisa passar a quantidade de vetor por que a funçao nao sabe o quanto possui
  Imprimir(matriz, n, m);
  Liberar_alocacao(matriz, m);        //libera a memoria alocada em matriz
  
  return 0;
}

int Gerar_matriz(int **mat, int *n, int *m){
  int i;
  
  printf("Entre com o o tamanho da linha da matriz: ");
  scanf("%d", m);   

  printf("\nAgora com o tamanho da coluna da matriz: ");
  scanf("%d", n);   


  mat = (int**)malloc((*n)*sizeof(int));    //criou um vetor

  for(i = 0; i < *n; i++){
    mat[i] = (int*)malloc((*m)*sizeof(int));    //transformo6u em uma matriz
  }

  return mat;
}

void LeVetor(int **mat, int n, int m){      //ou substituir * por []
  int i, j;

  for(i = 0; i < n; i++){
    for(j = 0; j < m; j++){
      scanf("%d", &mat[i][j]);
    }
  }

  return;
}

void Imprimir(int **mat, int n, int m){
  int i, j;
  
  for(i = 0; i < n; i++){
    printf("\n");
    for(j = 0; j < m; j++){
      printf("%d\t", mat[i][j]);
    }
  }
  
  return;
}

void Liberar_alocacao(int **mat, int m){
  int i;

  //o for tera que repetir por numero de colunas para limpar a matriz e 
  //meio que virar um vetor, logo depois deve limpar sua linha, que basta usar uma vez 'free'
  for(i = 0; i < m; i++)    
    free(mat[i]);

  free(mat);
  
  return;
}

/*Construa um programa (main) que aloque em tempo de execução (dinamicamente)
uma matriz de ordem m x n (linha por coluna)(uma matriz), usando 1+m chamadas a função
malloc. Agora, aproveite este programa para construir uma função que recebendo os
parametros m e n aloque uma matriz de ordem m x n e retorne um ponteiro para esta
matriz alocada. Crie ainda uma função para liberar a área de memória alocada pela
matriz. Finalmente, crie um novo programa (main) que teste/use as duas funções
criadas acima.*/