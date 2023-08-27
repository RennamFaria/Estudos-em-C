#include <stdio.h>


int main()
{
    int a,b;        //LEMBRAR:apenas usar duas variáveis

    scanf("%d%d",&a,&b);
    printf("Os valores digitados foram a: %d e b: %d.\n",a,b);

    b=b+a;
    a=b-a;
    b=b-a;

    printf("Os valores atuais são a: %d e b: %d.",a,b);
    return 0;
}