#include "FilaDinamicaSenhas.h"

void imprimeMenu();
void leDadosItem(TipoItem *);
int menuRetira(char *);

int main(){
  TipoFila fila;
  TipoItem item;
  TipoNoh noh;
  
  int op, pos;  //pos = posiçao
  char info;

  inicializaFila(&fila);

  while (op != 4) {
    imprimeMenu();

    printf("\nOpção: ");
    scanf("%d", &op);
    getchar();
    
    
    switch (op) {
      case 1:
        leDadosItem(&item);
        if(gerarSenha(&fila, &item) == 1){
          printf("\nSenha gerada com sucesso");
          
          if(insereNaFila(&fila, item))
            printf("\nItem inserido com sucesso!\n");
          else
            printf("\nErro! Não foi possível inserir o item!\n");
          }
        else
          printf("\nNao foi possivel gerar a senha");
        break;
      case 2:
        if(!filaVazia(&fila)){
          if(menuRetira(&info)){
            if(info=='N'){
              if(retiraNormal(&fila, &item))
                printf("\nSucesso ao retirar senha normal");
              else
                printf("\nNão existe ou falhou ao retirar pessoa normal");
            }
            if(info=='P'){
              if(retiraPreferencial(&fila, &item))
                printf("\nSucesso ao retirar senha preferencial");
              else
              printf("\nNão existe ou falhou ao retirar pessoa normal");    
            }
          }
        }
        else
          printf("\nFila Vazia!\n");
        //printf("\n ---- %c", info);
        break;
      case 3:
        if (!filaVazia(&fila)) {
          printf("\nFila:\n");
          imprimeFila(&fila);
        } else {
          printf("\nFila Vazia!\n");
        }
        break;
      case 4:
        destroiFila(&fila);
        printf("\nAté logo!\n");
        break;
  
      default:
        break;
      }
  }
  return 0;
}

void imprimeMenu(){
  printf("\nMenu");
  printf("\n1 - Insere na fila");
  printf("\n2 - Retira da fila");
  printf("\n3 - Imprime fila");
  printf("\n4 - Sair");
  
  return;
}

void leDadosItem(TipoItem *item) {
  printf("esta entrando??????");
  while(item->tipoSenha != 5049128312){
    printf("\nTipo de senha:");
    printf("\n(N = senha normal e P = senha com prioridade)\n");
    
   scanf("%c", &item->tipoSenha);
    getchar();

    //printf("%c", item->tipoSenha);
    if(item->tipoSenha == 'P' || item->tipoSenha == 'N')
      return;
    else
      printf("\nLetra digitada invalida\n");
    }
}

int menuRetira(char *info){

  printf("\nQuem deseja retirar da fila?");
  printf("\n(N = senha normal e P = senha com prioridade)\n");
  scanf("%c", info);
    getchar();
  if(*info == 'N' || *info == 'P'){
    return 1;
  }
  else
    printf("\nLetra digitada invalida\n");

  //printf("\n---- %c", info);
  return 0;
}