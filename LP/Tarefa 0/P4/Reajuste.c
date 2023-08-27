#include <stdio.h>
 
int main()
 
{
    float salario,c;
    int reajuste;
 
    scanf("%f %d",&salario ,&reajuste );
 
    c=reajuste*0.01;        //transforma % de rajuste em decimal
    c=salario*c;            //valor de reajuste que irá somar ou diminuir
    salario=salario+c;      //salario  final
 
    printf("O reajuste salarial de %d%% é: R$%0.2f",reajuste,salario);
    return 0;
}
