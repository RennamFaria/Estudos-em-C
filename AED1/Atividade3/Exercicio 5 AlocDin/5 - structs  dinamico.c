#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-------------------------------structs------------------------------------

typedef struct data_de_nascimento{
    int dia;
    int mes;
    int ano;
}nascimento;

struct  dados{
    char nome[50];
    nascimento data;
    long long int CPF;
};

//---------------------------indice de funcoes-----------------------------

void Receber_dados(struct dados *);
void Imprimir(struct dados *);

//-----------------------------main-----------------------------------------

int main(){
    struct dados cadastro;
    struct dados *ptrCadastro;    //ponteiro
    
    ptrCadastro = &cadastro;

    Receber_dados(ptrCadastro);
    Imprimir(ptrCadastro);


    return 0;
}

//-----------------------------funçoes-----------------------------------

void Receber_dados(struct dados *cad){
  int  i, j;

    printf("\nNome: ");
    gets(cad->nome);
    //printf("Nome = %s", cad[i].nome);

    printf("\nData de nascimento");
    printf("\nDia:");
    scanf("%d", &cad -> data.dia);

    printf("Mes:");
    scanf("%d", &cad -> data.mes);

    printf("Ano:");
    scanf("%d", &cad -> data.ano);

    //printf("Data de nascimento = %d/%d/%d", cad -> data.dia, cad -> data.mes, cad -> data.ano);

    printf("CPF: ");
    scanf("%llu", &cad -> CPF);

  return;
}

void Imprimir(struct dados *cad){
  int i;
  
    printf("\nNome: %s", cad -> nome);
    printf("\nData de nascimento: %d/%d/%d", cad -> data.dia, cad -> data.mes, cad -> data.ano);
    printf("\nCPF: %llu",  cad -> CPF);
  
  return;
}


/*Criar um tipo abstrato de dados que represente uma pessoa, contendo nome, data de
nascimento e CPF. Crie uma variável que é um ponteiro para este TAD (no programa
principal). Depois crie uma função que receba este ponteiro e preencha os dados da
estrutura e também uma uma função que receba este ponteiro e imprima os dados da
estrutura. Finalmente, faça a chamada a esta função na função principal.*/