#include <stdio.h>
 
int main(){
    int a,i=1,v=1;
    
    scanf("%d",&a);
 
    if(a<=0){       //Analise se é primo antes para o código não perder tempo
        printf("Não tem primos");
        return 0;
    }
    else;
    while(i<=a){    //faz ação X vezes dependendo do valor digitado
        if(v==2||v==3||v==5||v==7){     //exceção para os primos 2,3,5 e 7
            printf("%d\n",v);
        }
        if(!(v==1)){            //apenas para arrumar o bug que sempre impimia o 1 como primo
         if(v%2){              
             if(v%3){           //analisa se o v se é primo e se for primo
                if(v%5){        //ele vai imprimir no terminal
                    if(v%7){
                    printf("%d\n",v);
                    }
                }
            }
         }
        }
        v++;
        i++;
    }
    return 0;
}