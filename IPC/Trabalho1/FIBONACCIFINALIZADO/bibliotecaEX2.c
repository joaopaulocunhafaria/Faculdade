#include "bibliotecaEX2.h"


//##funçao do exercicio 2
int **fibonacci_matriz(int n) {
  int i, j;
  // i e j sao os valores para laços
  int aux = (n * n), o = 0, m = 1, p = 0;
  //aux é para definir o tamanho do vetor, que no caso é n*n,  o e m, sao para a dinamica do vetor de fibonacci, p é para passar os valores do vetor ´para a matriz
  int **mat;
 int *vet;

  vet = (int *)malloc(aux * sizeof(int));

  mat = (int **)malloc(sizeof(int *) * n);
  for (i = 0; i < n; i++) {
    mat[i] = (int *)malloc(sizeof(int) * n);
  }

  vet[0] = 0;
  vet[1] = 1;

for (i = 2; i < (n * n); i++) {
    vet[i] = vet[o] + vet[m];
    o++;
    m++;
  }

   for (i = 0; i < n; i++) {
    p=i;
    for (j = 0; j < n; j++) {
      mat[i][j] = vet[p];
      p++;
    }
  }

  return mat;
}
//##termina funçao do exercicio 2

