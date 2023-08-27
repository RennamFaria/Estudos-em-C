#include <stdio.h>
#include <string.h>

// Bibliotecas
//---------------------------------------------------------------------------------
#define NUM "%d"
#define NAM "%s"
#define TEL "%llu"

#define SCadastro "Contato[%d]- Nome:%s Tel:%llu\n"
#define SCadInfo i, cont[i - 1].nome, cont[i - 1].numero
#define IndVaz "Índice digitado está vazio!\n"
#define AV "Agenda vazia!\n"
#define IndNaoExst "Índice digitado não exite!\n"
#define CRemov "Contato removido com sucesso!\n"

typedef long long int longI;
typedef int auxI;

typedef struct contato {
  char nome[101]; // max= string de 100 char + \0
  longI numero;   // trocar para string
} contato;

// Defines, structs e enumerados
//-----------------------------------------------------------------------------

void Limpar_string_vetor(contato *);
int Menu();
void Cadastro(contato *);
int Checar_se_vazio(contato *);
void Imprimir_todos(contato *);
void Listar_todos(contato *);
void Mostrar_um_contato(contato *);
void Apagar_contato_por_indice(contato *);
void Apagar_contato_pelo_nome(contato *);
void Encerrar_programa();