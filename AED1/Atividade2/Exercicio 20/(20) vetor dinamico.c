#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Receber_valores(int *);
void Criar_vetor_dinam(int, float *);
int negativos(float *, int );
void Imprimir_variaveis(int, float[]);

int main(){
    int N = 0, i;
    float *ptrVet;

    Receber_valores(&N);

    ptrVet = (float *) malloc(N*sizeof(float));      //criar um vetor com N casas vezes o tamanho de um float
    
    if (ptrVet == NULL  ){      //se der erro em criar o vetor isso avisara e sair do programa
        printf("\nErro de alocacao de memoria");
        free(ptrVet);
        system("pause");
        exit(1);
    }

    srand(time(NULL));      //aleatoriza numeros do programa

    for(i = 0 ; i < N ; i++){
        ptrVet[i] = (rand() % 199) -99;     //coloca numeros aleatorios de 100 a -100 no vetor
    }

    printf("Numeros negativos gerados do vetor dinamico:\n");    

    for(i = 0 ; i < N ; i++){       
        if(ptrVet[i] < 0){     //printa apenas numeros negativos
            printf("%0.2f\t", ptrVet[i]);
        }
    }

    free(ptrVet);       //limpa o espaço que criou o vetor

    return 0;
}

//----------------------------------------------------------

void Receber_valores(int *ptrN){
    printf("Qual o tamanho sera do vetor? ");
    scanf("%d", ptrN);

    return;
}

/******************************************************************************

Implemente uma funçao que receba como parametro um array de numeros reais de
tamanho N e retorne quantos numeros negativos ha nesse array. Essa funçao deve
obdecer ao prototipo:

int negativos(float *vet, int N)

*******************************************************************************/