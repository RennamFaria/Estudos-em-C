#include <stdio.h>

int main()
{
    float a,b,c;

    scanf("%f",&a);
    scanf("%f",&b);

    c = b + a;

    printf("%0.2f + %0.2f = %0.2f",a,b,c);
    return 0;
}