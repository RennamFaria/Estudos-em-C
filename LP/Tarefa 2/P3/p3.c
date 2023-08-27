#include <stdio.h>
 
int main(){
    int a;
    
    scanf("%d",&a);
 
    if(a<=1){
        printf("O número %d não é primo!",a);
        return 0;
    }
    if(a==2||a==3||a==5||a==7){
        printf("O número %d é primo!",a);
        return 0;
    }
    if(a%2){
        if(a%3){
            if(a%5){
                if(a%7){
                    printf("O número %d é primo!",a);
                    return 0;
                }
            }
        }
    }
    else;
    printf("O número %d não é primo!",a);
    return 0;
}