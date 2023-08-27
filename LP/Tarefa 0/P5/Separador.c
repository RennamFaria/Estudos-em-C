#include <stdio.h>

int main()
{
    float a,c;  //entrada de (a) e saida de(a) apenas decimal
    int b;      //saida de (a) apenas inteiro
    
    scanf("%f",&a);

    b=(int)a;
    c=b-a;
    c=c*(-1);
    c=c*100;

    printf("A parte inteira: %d\n",b);
    printf("A parte decimal: %0.f",c);

    return 0;
}