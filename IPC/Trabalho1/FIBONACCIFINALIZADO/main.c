
#include "bibliotecaEX2.h"
#include <stdio.h>

int main() {
  int n, i, j;
  //n é o valor informado pelo usuario, i e j sao os valores para laços
  int **mat1;
  int **mat;

  printf("DIGITE O VALOR DE N:\n");
  scanf("%d", &n);

mat=fibonacci_matriz(n);
  
   printf("\n\nPRINTANDO A MATRIZ DA FUNÇAO\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("[%d]\t", mat[i][j]);
    }
    printf("\n\n");
  }


  
  return 0;
}
