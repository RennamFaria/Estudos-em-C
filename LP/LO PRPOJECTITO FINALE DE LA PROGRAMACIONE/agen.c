#include <stdio.h>
#include <string.h>
    
//Bibliotecas
//---------------------------------------------------------------------------------
#define NUM "%d"
#define NAM "%s"
#define TEL "%llu"
/*ao inves de usar um float e divirs para outros 3 int que esta em uma struct
é melhor usar um tipo que armazena > 11 numeros*/

#define SCadastro "Contato[%d]- Nome:%s Tel:%llu\n"
#define SCadInfo i,cont[i-1].nome,cont[i-1].numero
#define IndVaz "Índice digitado está vazio!\n"
#define AV "Agenda vazia!\n"
#define IndNaoExst "Índice digitado não exite!\n"
#define CRemov "Contato removido com sucesso!\n"
    
typedef long long int longI;
typedef int auxI;
    
typedef struct contato{
    char nome[101];     //max= string de 100 char + \0
    longI numero;       //trocar para string
}contato;
    
//Defines, structs e enumerados
//-----------------------------------------------------------------------------
    
void Limpar_string_vetor(contato cont[]){
//função que irá zerar todos os numeros de N do main
    auxI i, j;
        
    for(i = 0; i < 100; i++){
        for(j = 0; j < 101 ; j++){
        cont[i].nome[j] = ' ';
        }
    }
    return;
}
    
int Menu(){
    auxI n;
    
    //lembrar de excluir quando mandar para o judge
    //
    //printf("Qual menu deseja entrar:\n");
    //printf("0 - Sair do programa\n");
    //printf("1 - Cadastrar nome e numero\n");
    //printf("2 - Listar todos os contatos salvos\n");
    //printf("3 - Mostrar um contato em expecifico\n");
    //printf("4 - Apagar um contato pelo numero/indice\n");
    //printf("5 - Apagar um contato pelo nome\n");
    //
    
    scanf("%d",&n);
    
    for( ; !(n >= 0)|| !(n <= 5) ; ){
        printf("Escolha valores entre 0 e 5!\n");
        scanf("%d",&n);
    }
    
    return n;
}
    
void Cadastro(contato cont[]){            //opcao 1
    auxI i, j = 0;
    longI box;
    
    //printf("Digite um idice de 1 a 100: ");
    scanf(NUM, &i);
    
    if(i > 0 && i <= 100){
        //printf("Digite um nome: ");
        scanf(NAM ,cont[i-1].nome);  //pega apenas o primeiro nome
    
        //printf("Digite o numero:");
        for(cont[i-1].numero = 0 ; j < 10 || j > 11 ;){    //salvar numero
    
            scanf (TEL, &cont[i-1].numero);      //12XXXXXXXXXXX 
    
            for(j = 0 , box = cont[i-1].numero ; box !=0; j++){
            //contar numeros digitados, condiçao nao importa por causa do break abaixo
                box = box / 10;
            }
    
            if(j < 10 || j > 12){
            //se diferente de 10 e 11 avise e repita novamente o codigo até estiver certo
                printf("Telefone não tem 10 ou 11 dígitos! Favor digite novamente.\n");
            }
        }
        //reorganizar o numero guardado em p para o struct numero int, para poupar espaço
    
        printf("Contato cadastrado com sucesso!\n");
    }
    else
        printf(IndNaoExst);
    
    return;
}

    int Checar_se_vazio(contato cont[]){  
    auxI i, j;

    for(i = 1, j = 0 ; i <= 100 ; i++){  //i=1 por causa que sera subtraido depois
        if(cont[i-1].nome[0] != ' '){
            j++;
        }
    }

        return j;
    }

    void Imprimir_todos(contato cont[]){
    auxI i, j;

    for(i = 1, j = 0 ; i <= 100 ; i++){  //i=1 por causa que sera subtraido depois
        if(cont[i-1].nome[0] != ' '){
         printf(SCadastro, SCadInfo);
         j++;
        }
    }

    return;
    }
void Listar_todos(contato cont[]){        //opcao 2
    auxI i, j;
    
    j = Checar_se_vazio(cont);

    if(j==0){
        printf(AV);
    }
    else
        Imprimir_todos(cont);
    
    return;
}   
    
void Mostrar_um_contato(contato cont[]){  //opcao 3
    auxI i;
    
    
    i = Checar_se_vazio(cont);

    if(i == 0)
        printf(AV);

    else{
    // printf("Digite o numero do contato que deseja ver:");
    scanf(NUM, &i);
    
    if(i > 0 && i <= 100){
        if(cont[i-1].nome[0] != ' '){
            printf(SCadastro, SCadInfo);
        }
        else
            printf(IndVaz);
        }
    }
    
    return;
}
    
void Apagar_contato_por_indice(contato cont[]){   //opcao 4
    auxI i, j;
    
    //printf("Digite um indice do contato que deseja apagar:");
    scanf(NUM, &i);  //pega o indice
    
    if(i > 0 && i <= 100){        //checa se indice existe
    
        if(cont[i-1].nome[0] != ' '){     //checa se o indice esta vazio  
            for(j = 0; j < 101 ; j++){
            cont[i-1].nome[j] = ' ';
            }
            
        cont[i-1].numero = 0;
        printf(CRemov);     //primeiro diga que foi removido
                            //depois mostre todos os contatos restantes
        Imprimir_todos(cont); //esta entrando com cont tudo zerado
        }
        else
            printf(IndVaz);
        }
    else
        printf(IndNaoExst);
    
    return;
}
    
void Apagar_contato_pelo_nome(contato cont[]){    //opcao 5
    char aux[101];
    auxI i, j = 0, retorno;
    
    //printf("Digite o nome do contato que deseja apagar:");
    scanf(NAM, aux);  //pega o nome
    
    
    for(i = 0 ; i < 100 ; i++){     //repete 100 vezes = numero de contatos max
        retorno = strcmp(aux, cont[i-1].nome);
        
        if(retorno == 0){        //checa se nome existe
            for(; j < 101 ; j++){
                cont[i-1].nome[j] = ' ';
            }
        cont[i-1].numero = 0;     //remove
            printf(CRemov);
    
        Imprimir_todos(cont);     //printa todos os contatos restantes
        }
    }
    //se possuir um contato ele irá repetir 100 vezes o for do j mas quando terminar
    //o valor do j não será excluido, entao caso possuir o nome, o j terá valor != 0 sempre
    
    if(j == 0)
        printf("Contato digitado não existe!\n");
    
    return;
}
    
void Encerrar_programa(){
    printf("Tchau!");
    
    return;
}
    
//Funções
//--------------------------------------------------------------------------------
    
int main(){
    auxI Nmenu;
    contato cont[100];      //max = 100 contatos
    /*as informaçoes serao depositadas entre 0 e 99 mas o que
    saira no console ou o que o usuario digitou será considerado
    como +1*/
    
    Limpar_string_vetor(cont);
    
    for(Nmenu = 1; Nmenu > 0 && Nmenu <= 5;){
    Nmenu = Menu();
    
    switch ( Nmenu ){
        case 0 :
            Encerrar_programa();
            break;
            
        case 1 :
            Cadastro(cont);
            break;
        
        case 2 :
            Listar_todos(cont);
            break;
            
        case 3 :
            Mostrar_um_contato(cont);
            break;
            
        case 4 :
            Apagar_contato_por_indice(cont);
            break;
            
        case 5 :
            Apagar_contato_pelo_nome(cont);
            break;
            
    }
    
    }
    return 0;
}
//Main
//--------------------------------------------------------------------------------