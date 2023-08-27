#include <stdio.h>  
#include <math.h>  
  
int main()  
{   
    int  decimal,x=0,binario,i;  
    scanf("%i",&binario);  
  
    printf("Binário:%i Decimal:", binario);  
    for(decimal=0,i=0;binario;i++){
        x=binario % 10;  
        if(x){
            decimal=decimal+(pow(2,i));              
        }  
        binario=binario/10;    
    }  
    printf("%d",decimal);  
  
    return 0;  
}  