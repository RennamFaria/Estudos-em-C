#include "ListaLinearE.h"

int main() {
  auxI Nmenu;
  contato cont[1000]; // max = 100 contatos

  Limpar_string_vetor(cont);

  for (Nmenu = 1; Nmenu > 0 && Nmenu <= 5;) {
    Nmenu = Menu();

    switch (Nmenu) {
    case 0:
      Encerrar_programa();
      break;

    case 1:
      Cadastro(cont);
      break;

    case 2:
      Listar_todos(cont);
      break;

    case 3:
      Mostrar_um_contato(cont);
      break;

    case 4:
      Apagar_contato_por_indice(cont);
      break;

    case 5:
      Apagar_contato_pelo_nome(cont);
      break;
    }
  }
  return 0;
}