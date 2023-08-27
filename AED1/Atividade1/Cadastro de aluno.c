#include <stdio.h>
#include <stdlib.h>

//------------------------------------------
#define IndNaoExst "Indice digitado nao exite!\n\n"
#define ContCad "Contato cadastrado com sucesso!\n\n"


typedef struct informacoes{
    char nome[101];
    int RA;
    float nota;
    int freq;
}informacoes;

//-------------------------------------------

void Limpar_registro(informacoes cadastro[]){
//função que irá zerar todos os numeros de N do main
    int i, j;
        
    for(i = 0; i < 100; i++){
        cadastro[i].RA = 0;
        cadastro[i].nota = 0.0;
        cadastro[i].freq = 0;

        for(j = 0; j < 101 ; j++){
        cadastro[i].nome[j] = ' ';
        }
    }
    return;
}

//

int Menu(){
    int a;

    printf("Qual menu deseja acessar?\n\n");
    printf("0 - Sair do programa\n");
    printf("1 - Inserir novo cadastro\n");
    printf("2 - Remover cadastrado\n"); 
    printf("3 - Visualizar todos os cadastrados\n");
    printf("4 - Visualizar cadastro pelo RA\n");

    scanf("%d", &a);

    for( ; (a < 0)|| (a > 4) ; ){
        printf("Escolha valores entre 0 e 4!\n");
        scanf("%d", &a);
    }
    
    return a;
}

//

//

void Encerrar_programa(){   //opção 0
    printf("Encerrando!");
    
    return;
}

//

void Inserir_cadastro(informacoes cadastro[]){    //opção 1
    int i, box, j = 0;     //auxiliares
    
    printf("Digite um idice de 1 a 100: ");
    scanf("%d",&i);

    if(i > 0 && i <= 100){

        getchar();      //limpa o buffer e desbuga o gets futuro

        printf("Digite o nome (Sem espacos): ");
        gets(cadastro[i-1].nome);  //pega o nome, nao consegui usar o "gets" por causaa que estava pulando essaa etapa
        //preciso saber o porque nao esta funcionando
    
        printf("Digite o RA (apenas numeros): ");
        for(cadastro[i-1].RA = 0 ;  j != 6 ;){    //sai do for apenas se RA = 6 digitos
    
            scanf("%d", &cadastro[i-1].RA);      //salvar RA
    
            for(j = 0 , box = cadastro[i-1].RA ; box !=0; j++){
            //contar numeros digitados, condiçao nao importa por causa do break abaixo
                box = box / 10;
            }
    
            if(j != 6){
            //se diferente de 6 avise e repita novamente o codigo até estiver certo
                printf("O RA nao possui 6 digitos! Favor digite novamente.\n");
            }
        }

        printf("Digite a nota: ");
        scanf("%f", &cadastro[i-1].nota);   //pode ser digitado como Ex: 8.5

        for(cadastro[i-1].freq = -1 ; cadastro[i-1].freq < 0 || cadastro[i-1].freq > 100 ;){    
            //sai do for apenas se freq >=0 && <=100

            printf("Digite a frequencia em porcentagem(apenas numeros): ");
            scanf("%d",&cadastro[i-1].freq);       //lembrar de usar % no prinf

            if (cadastro[i-1].freq < 0 && cadastro[i-1].freq > 100)
                printf("A frequencia nao está entre 0 e 100! Digite novamente");
        }

        printf(ContCad);
    }
    else
        printf(IndNaoExst);
    
    return;
}

//

int Checar_se_vazio(informacoes cadastro[]){  
    int i, j;

    for(i = 1, j = 0 ; i <= 100 ; i++){  //i=1 por causa que sera subtraido depois
        if(cadastro[i-1].nome[0] != ' '){
            j++;
        }
    }
        return j;
}

//

void Remover_cadastrado_pelo_RA(informacoes cadastro[]){
    int i, f;       //auxiliares
    int box;         //guarda informaçao do RA
    
    i = Checar_se_vazio(cadastro);

    if(i == 0)
        printf("Nao possui nenhum cadastro\n");

    else{
    printf("Digite o RA que deseja remover(apenas numeros): ");
    scanf("%d", &box);
    
    for(i = 0; i < 100 ; i++){       //repete o loop pela quantidade de structs criados (100)
        if(cadastro[i].RA == box){
            cadastro[i].RA = 0;
            cadastro[i].nota = 0.0;
            cadastro[i].freq = 0;

            for(f = 0 ; f < 101 ; f++){
                cadastro[i].nome[f] = ' ';
            }

            printf("Cadastro removido");
            f == 1;        //indicador para avisar que entrou
        }  
            
    }
    if(f == 0){
            printf("Nao existe cadastro com este RA!");
        }
    }
    return;


    return;
}

//

void Imprimir_todos(informacoes cadastro[]){
    int i;

    for(i = 0 ; i < 100 ; i++){  //i=1 por causa que sera subtraido depois
        if(cadastro[i].nome[0] != ' '){
            printf("Nome: %s ", cadastro[i].nome);
            printf("RA: %d ", cadastro[i].RA);
            printf("Nota: %0.1f ", cadastro[i].nota);
            printf("Frequencia: %d%%\n", cadastro[i].freq);
        }
    }
    return;
}

void Visualizar_todos(informacoes cadastro[]){        //opcao 3
    int i, j;       //auxiliares
    
    j = Checar_se_vazio(cadastro);

    if(j==0){
        printf("Nao possui nenhum cadastro\n");
    }
    else
        Imprimir_todos(cadastro);
    
    return;
}

void Visualizar_por_RA(informacoes cadastro[]){
    int i, f;       //auxiliares
    int box;         //guarda informaçao do RA
    
    i = Checar_se_vazio(cadastro);

    if(i == 0)
        printf("Nao possui nenhum cadastro\n");

    else{
    printf("Digite o RA que deseja ver(apenas numeros): ");
    scanf("%d", &box);
    
    for(i = 0, f = 0 ; i < 100 ; i++){       //repete o loop pela quantidade de structs criados (100)
        if(cadastro[i].RA == box){
            printf("Nome: %s ", cadastro[i].nome);
            printf("RA: %d ", cadastro[i].RA);
            printf("Nota: %0.1f ", cadastro[i].nota);
            printf("Frequencia: %d%%\n", cadastro[i].freq);
            f++;        //indicador para avisar que entrou
        }  
            
    }
    if(f == 0){
            printf("Nao existe cadastro com este RA!");
        }
    }
    return;
}

//--------------------------------------------

int main(){
    informacoes cadastro[100];
    int save;

    Limpar_registro(cadastro);  //limpar todos os registros

    for(save = 1; save > 0 && save <= 4;){
    save = Menu();          //acessar o menu

        switch ( save ){
            case 0 :
                Encerrar_programa();
                break;
                
            case 1 :
                Inserir_cadastro(cadastro);
                break;
            
            case 2 :
                Remover_cadastrado_pelo_RA(cadastro);
                break;
                
            case 3 :
                Visualizar_todos(cadastro);
                break;
               
            case 4 :
                Visualizar_por_RA(cadastro);
                break;
            
        }
    }

    return 0;
}