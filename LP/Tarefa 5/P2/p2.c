#include <stdio.h>

int Ler_valor(){
//scaneia o valor do usuário, que será usado como omega
    int Valor;

    scanf("%d", &Valor);

    return Valor;
}

void Zerar_omega(int *omega){
//função que irá zerar todos os numeros de omega do main
    int i;

    for(i = 0; i < 100; i++){
        omega[i] = 0;
    }
    return;
}

void Primos_do_valor(int valor, int *vetor){        
//ele irá dividir pelo menor numero divisivel primo, depois irá marcar no
//vetor quais números ele dividiu e quantas vezes
    int i;

    for (i = 2; valor > 1; ) {
        if ((valor % i) == 0) {
        valor = valor / i;
        vetor [i-1] = vetor[i-1] + 1;
        } 
        else
        i++;
    }
    return;     //return endereço de omega
}

int Soma_dos_n_divisores_primos(int omega[100]){
//soma todos os valores do vetor salvo
    int  final, i;
    
    for(final = 0, i = 0; i < 100 ; i++){
        final = final + omega[i];
    }
    return final;
}
/*----------------------------------------------------------------------------*/

int main(){
    int valor, omega[100], somatorio, lembrete;

    valor = Ler_valor();
    Zerar_omega(&omega);
    Primos_do_valor(valor, &omega);
    somatorio = Soma_dos_n_divisores_primos(omega);
    printf("Omega(%d)=%d", valor, somatorio);

    return 0;
}


/*Escreva um programa, que calcule a quantidade de
fatores primos (Omega) de um número desejado positivo.
Formalmente, se a decomposição de n em fatores P 
primos resulta em p1^α1 p2^α2...pk^αk , queremos 
Omega(n) = SOMATORIO(αi). Por exemplo, n = 20 = 2^2 5^1,
assim Omega(20) = 2 + 1 = 3. Informalmente, queremos
saber quantas vezes um valor pode ser dividido por
números primos. Este programa deve ter no mínimo 4
funções contando com a função "main".

Entrada 1:
1
Saída 1:
Omega(1)=0

Entrada 2:
2
Saída 2:
Omega(2)=1

Entrada 3:
15
Saída 3:
Omega(15)=2

Entrada4:
10
Saída4:
Omega(10)=2
*/