#include <stdio.h>
#include <string.h>

void Zerar_vetores(char L1[], char L2[]){
//função que irá zerar todos os numeros dos vetores
    int i;
 
   for(i = 0; i < 100; i++){
    L1[i] = 0;
    L2[i] = 0;
    }
   return;
}
void Ler_entrada(char L1[], char L2[]){

    gets(L1);
    gets(L2);
    
    return;
}
void Calcular_ascii(char L1[], char L2[], int j[]){
    int i;
    for(i = 0; L1[i] != '\0' ; i++){   //repete dependendo do numero de caracteres digitados
        j[0] += L1[i];
    }

    for(i = 0; L2[i] != '\0' ; i++){   //repete dependendo do numero de caracteres digitados
        j[1] += L2[i];
    }

    return;
}
void Imprimir_valores(char L1[], char L2[], int j[]){
    printf("Str1: %s - Codificaçao Hash: %i\n", L1, j[0]);
    printf("Str2: %s - Codificaçao Hash: %i", L2, j[1]);

    return;
}


int main(){
    char string1 [100], string2 [100];
    int ascii[2] = {0,0};
    
    Zerar_vetores(string1, string2);
    Ler_entrada(string1, string2);
    Calcular_ascii(string1, string2, ascii);
    Imprimir_valores(string1, string2, ascii);

    return 0;
}
