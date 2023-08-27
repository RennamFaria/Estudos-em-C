    #include <stdio.h>
     
    void Calcular_derivadas();       //definição declarada
     
    void Zerar_N(float N[]){
    //função que irá zerar todos os numeros de N do main
        int i;
     
        for(i = 0; i < 100; i++){
            N[i] = 0;
        }
        return;
    }
     
     
    void Ler_valores(int *Valor, float vetor[]){
    /*scaneia o valor do usuário, que será usado como
    tamanho da equação e os valores dele*/
        int i;
     
        scanf("%d", Valor);
     
        for(i = 0; i < (*Valor + 1) ; i++){
          scanf("%f", &vetor[i]);
        }
        
        return;
    }
     
    void Imprimir(int Valor, float vetor[]){
    //nucleo que imprime os resultados e depois manda
    //o Calcular_derivadas calcular o resto delas 
     
        int i, f, j, aux;
     
        for(i = 0; 0 < (Valor + 1) ; i++, Valor--){
            aux = Valor;
            
            if(i > 0){      //irá entrar no if apenas na segunda passada pelo for
            printf("Dev %d: ", (i));
            }
            if(Valor != 0){
            printf("Equação: ");    //não imprimira na ultima linha do printf
            }
     
            for(f = 0; 0 < (aux + 1); f++, aux--){
            
             printf("%0.1fx^%d" ,vetor[f] ,aux);
     
             if (aux > 0){
             printf(" + ");
             }
            }
            printf("\n");
     
            Calcular_derivadas(vetor, Valor);
        }
        return;
    }
     
    void Calcular_derivadas(float vetor[], int valor){
    /*ira calcula as derivadas, multiplicado pelo valor do lado da derivada
    e depois -1 toda vez que voltar para ca*/ 
     
       int i, f, aux = valor;
     
        for(i = 0; 0 < aux ; i++, aux--){
            vetor[i] *= aux;
        }
     
        return;
    } 
     
    /*-------------------------------------------------------------*/
     
    int main(){
        float N[100];
        int valor;
     
        Zerar_N(N);
        Ler_valores(&valor,N);
        if(valor > 0){
        Imprimir(valor, N);
        }
        else{
            printf("Grau inválido");
        }
     
        return 0;
    }
