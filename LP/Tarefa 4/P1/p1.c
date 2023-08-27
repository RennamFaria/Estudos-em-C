#include <stdio.h>

int main(){
    int matriz[50][50], tam, i, f, soma = 0;  //PS: tambem conta o linha diagonal que corta a matriz
    
     for (i = 0; i < 50 ; i++){         
        for (f = 0; f < 50 ; f++){       
        matriz[i][f] = 0;
        }
    }
    
    scanf("%d",&tam);
    
    for (i = 0; i < tam ; i++){         //ira preencher os [] apenas que serao usados
        for (f = 0; f < tam ; f++){         //que são apenas os tam * tam
        scanf("%d",&matriz[i][f]);      //ta tendo algum problema que ta loopando sem parar, preciso resolver
        }
    }

    for (i = 0; i < tam ; i++){                 //soma os nº superiores da linha
        for (f = i; f != tam ; f++){       //diagonal principal    
        soma += matriz[i][f];
        }
    }
    printf("%d",soma);
    
    return 0;
}