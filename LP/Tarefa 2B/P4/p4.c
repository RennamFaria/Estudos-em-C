#include <stdio.h>
 
int main(){
  int N,i,ano;        //N= saos os N anos bissextos
    
  scanf("%d",&N);
    
  for(i=1,ano=1;i<=N;){       //loopa N vezes
    if(ano%100 && !(ano%4) || !(ano%400)){  // divisor de 100 nao entra, 4 e 400 entra
      printf("\n");
      printf("%04d - ano:%4d",i,ano);
      i++;                           // adiciona +1 em i sempre que ano bissexto é printado
      }
     ano+=1;     //de 1 em 1
    }
  return 0;
}