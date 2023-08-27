#include <stdio.h>
int main(){
    int a,i=-1;
    float v=0;

    do{
        scanf("%d",&a);
        v+=a;
        i++;

    }while(a);
    v=v/i;
    printf("A medida aritmética dos %d valores é: %0.1f",i,v);
    return 0;
}