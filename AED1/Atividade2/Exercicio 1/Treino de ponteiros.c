#include <stdio.h>

#define Variaveis "\nInteiro = %d\nReal = %0.1f\nChar = %c"
#define VarComeco inteiro ,real ,caracter
#define VarFinal *ptrInt, *ptrReal, *ptrChar

void main(){
    int inteiro = 10, *ptrInt;
    float real = 20.9, *ptrReal;
    char caracter = 'R', *ptrChar;

    printf("\nValor das variaveis no comeco:");
    printf(Variaveis, VarComeco);

    ptrInt = &inteiro;
    ptrReal = &real;
    ptrChar = &caracter;

    *ptrInt = 52;
    *ptrReal = 1.9;
    *ptrChar = 'J' ;

    printf("\n\nValor das variaveis modificado pelo ponteiro:");
    printf(Variaveis, VarFinal);

    return;
}

/******************************************************************************

Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro,
real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores de 
cada variavel usando os ponteiros. Imprima os valores das variaveis antes e apos a 
modificacao.

*******************************************************************************/