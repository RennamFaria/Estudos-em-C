#include <stdio.h>

int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    
    if(a+b>c && a+c>b && b+c>a){
     if(a==b){
        if(b==c){   //(a==b==c)
         printf("O triângulo é equilátero");
         return 0;
        }
        else;       //(a==b!=c)
         printf("O triângulo é isóceles");
         return 0;
     }
     if(b==c){
        if(b!=a){   //(b==c!=a)
        printf("O triângulo é isóceles");
        return 0;
        }
     }
     else;   //(a!=b)
        if(c==a){   //(c==a!=b)
         printf("O triângulo é isóceles");
         return 0;
        }
        else;       //(a!=b!=c)
         printf("O triângulo é escaleno");
         return 0;
    }
    else;
     printf("Não é possível formar um triângulo");
     return 0;
}