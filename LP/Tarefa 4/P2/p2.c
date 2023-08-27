#include <stdio.h>

int main(){
    int matriz[50][50], elemento[2] = {0,0}, N, i, f, soma = 0;      
    //elemento será um para guardar o 0 e outro para o 1
    
     for (i = 0; i < 50 ; i++){         //zera toda a matriz[][]
        for (f = 0; f < 50 ; f++){       
        matriz[i][f] = 0;
        }
    }
    
    scanf("%d",&N);

    for (i = 0; i < N ; i++){         //grava os nº da matriz do user
        for (f = 0; f < N ; f++){        
        scanf("%d",&matriz[i][f]);
        }
    }
    
    for (i = 0; i < N ; i++){         //checa se as verticais sao N-1 zeros e apenas um elemento=1
        for (f = 0; f < N ; f++){     //ira checar de cima para baixo a matriz
            if (matriz[f][i] == 0){
             elemento[0]++;
            }
            if (matriz[f][i] == 1){
             elemento[1]++;
             }
        }
        if (elemento[0] == (N-1) && elemento[1] == 1){   //se verdade, confirme a coluna vertical.tam = N da questao
         soma++;
        }
        
        elemento[0] = 0;            //reseta os valores de 0 e 1
        elemento[1] = 0;
    }
    if(soma == N & N > 0){
        printf("verdadeiro");
    }
    else{
        printf("falso");
    }
    return 0;
}
/* Problema 2:Na matemática, uma matriz quadrada binária é uma matriz de permutação se em cada linha
 e em cada coluna houver N-1 elementos iguais a 0 e um único elemento igual a 1. Assim, dada uma matriz, 
 verificar se ela é ou não uma matriz de permutação.

Entrada: Um número inteiro N indicando o tamanho da matriz. N linhas contendo os valores da matriz.
Saída: Escrever "verdadeiro" se for uma matriz permutação ou "falso" caso contrário.

Exemplo
Entrada1
3
0 1 0
0 0 1
1 0 0

Saída1
verdadeiro

Entrada2

2
0 0
1 0

Saída
falso

*/