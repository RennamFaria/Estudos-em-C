#include <stdio.h>

int main(void){
    int decimal,resultado,resto[32],i;
    scanf("%d",&decimal);
    
    resto[0]=decimal%2;     
    resultado=decimal/2;

    for(i=1;resultado>0;i++){
         resto[i]=resultado%2;
         resultado=resultado/2;
    }
    printf("Decimal:%d Binário:",decimal);
    for(;i>0;i--){
        printf("%d",resto[i-1]);        //i-1 é por  causa que ele começa com 4
    }

	return 0;
}