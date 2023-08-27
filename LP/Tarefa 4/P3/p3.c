#include <stdio.h>

int main(){
    int matriz[50][50], ponto[50], N, k, distancia, i, f;

    for (i = 0; i < 50 ; i++){         //zera toda a matriz[][]
        for (f = 0; f < 50 ; f++){       
        matriz[i][f] = 0;
        }
        ponto[i]=0;
    }

//----------------------coleta de dados do user-----------------------------------//
    scanf("%d",&N);         //tamanho da matriz

    for (i = 0; i < N ; i++){         //grava os nº da matriz do user
        for (f = 0; f < N ; f++){        
        scanf("%d",&matriz[i][f]);
        }
    }

    scanf("%d",&k);          //numeros de pontos do trajeto

    for(i = 0; i < k ; i++){
        scanf("%d",&ponto[i]);
    }
//------------------------------------------------------------------------//

    for(distancia = 0, i = 0; i < (k-1) ; i++){
        distancia += matriz [ponto[i]] [ponto[i+1]];
    }
    
    printf("%d",distancia);

    return 0;
}
/* Problema 3: Os elementos a,i,j de uma matriz representam a distância entre os pontos i e j de uma 
cidade. Dado um trajeto com k pontos, calcular a distância percorrida.

Entrada: Uma linha contendo o tamanho da matriz. N linhas com os valores da matriz. Uma linha com o 
número de pontos do trajeto e uma linha com o pontos do trajeto.
Saída: Distância percorrida no trajeto.

Exemplo
Entrada
3           = tamanho da matriz N
4 6 2       = N linhas da matriz
1 2 8
2 5 9
5           = numero de pontos do trajeto = K
0 2 1 2 1   = pontos do trajeto ????    02 deposi 21    12      21

Saída
20  */