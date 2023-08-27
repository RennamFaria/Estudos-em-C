#include <stdio.h>
#include <math.h>
 
int main()
{
    float a,b,c,d,r1,r2;    //valor 1,2,3 e delta
    
    scanf("%f",&a);
    scanf("%f",&b);
    scanf("%f",&c);
    
    if(a>0){
     d=pow(b,2);   //b com expoente 2
     c=4*a*c;
     d=d-c;        //acha o delta da funçao
    
     if(d>=0){     //duas raízes
         d=sqrt(d);       //raiz de delta
         r1=(-b+d)/2*a;
            r2=(-b-d)/2*a;
    
         printf("Raiz 1: %0.2f\nRaiz 2: %0.2f",r1,r2);
         return 0;
        }
    else;           //nenhuma raíz
     printf("Não existem raízes reais");
     return 0;     
    }
    if(a<=0){       //uma raíz
         r1=-(c/b);
         printf("Raiz: %0.2f",r1);  //Ps: ele aredonta sosinho
         return 0;
    }                      
}