#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define TAM1 10
#define VET 4

float fatorial(float x) {
  float fat, rec = 1;
  for (fat = 1; fat <= x; fat++) {
    rec = fat * rec;
  }
  return rec;
}

float x_fat(float radX, float fat, float eq2, float i) {
  eq2 = 0;
  i = 0;
  int sig = 1;
  for (i = 1; i <= 11; i += 2) {
    eq2 += sig * (pow(radX, i) / fatorial(i));
    sig = sig * (-1);
  }
  return eq2;
}

int n_igualdade(int n) {
  int i = 0;
  for (i = 0; i < n; i++) {
    printf("n=%d", i + 1);
  }

  return i;
}

int **aloca_mat(int L1, int C1) {
  int i, j, **mat1;

  mat1 = (int **)malloc(sizeof(int *) * L1);

  for (i = 0; i < L1; i++) {
    mat1[i] = (int *)malloc(sizeof(int) * C1);
  }
  for (i = 0; i < L1; i++) {
    for (j = 0; j < C1; j++) {
      printf("\nDigite os elementos da matriz 1 na posiçao[%d][%d]:\n ", i, j);
      scanf("%d", &mat1[i][j]);
    }
  }
  printf("\n Imprimindo a matriz: \n\n");
  for (i = 0; i < L1; i++) {
    for (j = 0; j < C1; j++) {
      printf("%d\t", mat1[i][j]);
    }
    printf("\n");
  }

  return mat1;
}

int **aloca_mat2(int L2, int C2) {

  int i, j, **mat2;

  mat2 = (int **)malloc(sizeof(int *) * L2);

  for (i = 0; i < L2; i++) {
    mat2[i] = (int *)malloc(sizeof(int) * C2);
  }
  for (i = 0; i < L2; i++) {
    for (j = 0; j < C2; j++) {
      printf("\nDigite os elementos da matriz 2 na posiçao[%d][%d]:\n ", i + 1,
             j + 1);
      scanf("%d", &mat2[i][j]);
 }
  }
  return mat2;
}

void exercicio1() {
  int vet1[TAM1], vet2[TAM1], vetresult[TAM1], i;


  printf("Exercicio 1: Multiplicação dos elementos de mesmo índice!\n\n");
  // aqui multiplica-se o termo[i] do vetor ao termo[i] do vetor2 para obter
  // o valor do termo[i] do vetor3

  printf("digite os elementos do primeiro vetor:\t");
  for (i = 0; i < TAM1; i++) {
    scanf("%d", &vet1[i]);
  }

  printf("digite os elementos do segundo vetor:\t");
  for (i = 0; i < TAM1; i++) {
    scanf("%d", &vet2[i]);
  }
  for (i = 0; i < TAM1; i++) {
    vetresult[i] = vet1[i] * vet2[i];
  }
  printf("o vetor resultante é:\t");
  for (i = 0; i < TAM1; i++) {
    printf("%d  ", vetresult[i]);
  }
}

void exercicio2() {
  int vet1[VET];
  int inicio, fim;
  for (int i = 0; i < VET; i++) {
    printf("Digite o valor do indicie [%d] do vetor:  ", i + 1);
    scanf("%d", &vet1[i]);
  }
  int soma = 0;
  int somaM = vet1[3];
  printf("\nO vetor é:\n");
  for (int i = 0; i < VET; i++) {
    printf("[%d]", vet1[i]);
  }
  for (int k = VET; k > -1; k--) {
    for (int i = 0; i < VET; i++) {
      for (int j = i; j < k; j++) {
        int n = vet1[j];
        soma += n;
      }
      if (soma >= somaM) {
        somaM = soma;
        inicio = i + 1;
        fim = k;
      }
      soma = 0;
    }
  }
  printf("\n\nO subvetor de maior soma é [%d] de inicio [%d] até [%d]", somaM,
         inicio, fim);
}

void exercicio3() {
  int i, x, aux, soma = 0, vet1[VET], vet2[VET];

  // neste exerciçio ordena-se os vetores 1 e 2 em ordem crescente, logo apos
  // compara-se os termo [i] da funçao 1 com o termo[i] da fumçao 2, se todos
  // os elementos forem iguais amobos sao rearranjos um do outro, caso o
  // contrario nao sao rearranjos
  printf(
      "Exercício 3:vereficar se dois vetores são rearranjos um do outro!\n\n");

  printf("Digite os elementos do primeiro vetor:\n");
  for (i = 0; i < VET; i++) {
    scanf("%d", &vet1[i]);
  }

  for (i = 0; i < VET; i++) {
    for (x = i + 1; x < VET; x++)
      if (vet1[i] > vet1[x]) {
        aux = vet1[i];
        vet1[i] = vet1[x];
        vet1[x] = aux;
      }
  }

  printf("\nDigite os elementos do segundo vetor:\n");
  for (i = 0; i < VET; i++) {
    scanf("%d", &vet2[i]);
  }

  for (i = 0; i < VET; i++) {
    for (x = i + 1; x < VET; x++)
      if (vet2[i] > vet2[x]) {
        aux = vet2[i];
        vet2[i] = vet2[x];
        vet2[x] = aux;
      }
  }

  for (i = 0; i < VET; i++) {
    if (vet1[i] == vet2[i]) {
      soma += 1;
    }
  }
  if (soma == VET) {
    printf("\nOs vetores são rearranjos um do outro\n");
  } else {
    printf("\nOs vetores não são rearranjos um do outro\n");
  }
}

void exercicio4() {

  int i, vet1[VET], vet2[VET], soma = 0, vetresult[VET];

  printf("Exercício 4:calcular o produto pontual de dois vetores!\n\n");
  // multiplica-se o primeiro elemento de vetor com o ultimo elemento do
  // segundo vetor, e assim sucessivamente, apos, soma-se todos os produtos
  // para obter o produto pontual de dois vetores

  // ler o primeiro vetor
  for (i = 0; i < VET; i++) {
    printf("\nDigite o valor do primeiro vetor na posiçao [%d]=\n", i + 1);
    scanf("%d", &vet1[i]);
  }

  // ler o segundo vetor
  for (i = 0; i < VET; i++) {

    printf("\nDigite o valor do segundo vetor na posiçao [%d]=\n", i + 1);
    scanf("%d", &vet2[i]);
  }

  for (i = 0; i < VET; i++) {
    vetresult[i] = vet1[i] * vet2[VET - 1 - i];
  }

  for (i = 0; i < VET; i++) {
    soma += vetresult[i];
  }
  printf("O produto pontual é:%d", soma);
}

void exercicio5() {
  int n, i, soma = 0, soma1 = 0;

  printf("Exercício 5: provar a igualdade entre duas equaçoes!\n\n");
  printf("escolha o valor de n:\n");

  scanf("%d", &n);

  for (i = 1; i <= n; i++) {

    soma += pow(i, 2);
  }

  soma1 = (n * (n + 1) * ((2 * n) + 1)) / 6;
  if (soma == soma1) {
    printf("\nO valor de 1^2+2^2+3^2+...+n^2= %d\n", soma);
    printf("O valor de (n*(n+1)*(2*n+1))/6= %d\n", soma1);
  }
}

void exercicio6() {
  int i;
  float radX, X, eq2 = 0;

  printf("Exercício 6: provar a igualdade entre duas equaçoes!\n\n");
  printf("digite o valor de X em graus(0 ate 360):\n");
  scanf("%f", &X);
  radX = X * 0.0174532;

  printf("O seno de X em radianos = %f\n\n", sin(radX));
  eq2 = 0;
  int sig = 1;
  for (i = 1; i <= 30 ; i += 2) {
    eq2 += sig * (pow(radX, i) / fatorial(i));
    sig = sig * (-1);
  }

  printf("A equaçao X - X^3/3! -X^5/5!...: %f\n", eq2);
  printf("o seno de %f é :%f\n", X, sin(radX));
}

void exercico7() {

  int execut, aux, i, j, k, L1, C1, L2, C2, **mat1, **mat2, **mat3;

  printf("Exercício 7: soma, subtrair e multiplicar matrizes ,(se "
         "possivel)!\n\n");

  printf("\ndigite a quantidade de linhas da matriz 1:\n");
  scanf("%d", &L1);
  printf("\ndigite a quantidade de colunas da matriz 1:\n");
  scanf("%d", &C1);

  printf("\ndigite a quantidade de linhas da matriz 2:\n");
  scanf("%d", &L2);
  printf("\ndigite a quantidade de colunas da matriz 2:\n");
  scanf("%d", &C2);

  mat1 = aloca_mat(L1, C1);

  mat2 = aloca_mat2(L2, C2);

  printf("\n Imprimindo a matriz 1: \n\n");
  for (i = 0; i < L1; i++) {
    for (j = 0; j < C1; j++) {
      printf("%d\t", mat1[i][j]);
    }
    printf("\n");
  }

  printf("\n Imprimindo a matriz 2: \n\n");
  for (i = 0; i < L2; i++) {
    for (j = 0; j < C2; j++) {
      printf("%d\t", mat2[i][j]);
    }
    printf("\n");
  }

  if (L1 == L2 && C1 == C2) {
    printf("\nA soma das matrizes é:\n");

    mat3 = (int **)malloc(sizeof(int *) * L1);

    for (i = 0; i < L1; i++) {
      mat3[i] = (int *)malloc(sizeof(int) * C1);
    }

    for (i = 0; i < L2; i++) {
      for (j = 0; j < C2; j++) {
        mat3[i][j] = mat1[i][j] + mat2[i][j];
        printf("%d\t", mat3[i][j]);
      }
      printf("\n");
    }
  }
  if (L1 == L2 && C1 == C2) {
    printf("A subtraçao das matrizes é: \n");

    for (i = 0; i < L2; i++) {
      for (j = 0; j < C2; j++) {
        mat3[i][j] = mat1[i][j] - mat2[i][j];
        printf("%d\t", mat3[i][j]);
      }
      printf("\n");
    }
  }

  if (L1 != L2) {
    printf("\nA soma e subtração das matrizes não é possível\n");
  }

  if (C2 != C1) {
    printf("\nA soma e subtração das matrizes não é possível\n");
  }

  if (C1 == L2) {
    mat3 = (int **)malloc(sizeof(int *) * L2);

    for (i = 0; i < L1; i++) {
      mat3[i] = (int *)malloc(sizeof(int) * C1);
    }
    printf("\nO produto das duas matrizes é:\n ");
    for (i = 0; i < L1; i++) {

      for (j = 0; j < C2; j++) {
        mat3[i][j] = 0;
        for (k = 0; k < L2; k++) {
          aux += mat1[i][k] * mat2[k][j];
        }
        mat3[i][j] = aux;
        aux = 0;
        printf("%d\t", mat3[i][j]);
      }
      printf("\n\n");
    }

    printf("\n\n");

  } else {
    printf("\nNao é possivel multiplicar as matrizes");
  }
  printf("\nDeseja executar o programa novamente utilizando matrizes "
         "diferentes, digite 1 para sim e 2 para nao:\n");
  scanf("%d", &execut);

  if (execut == 1) {
    exercico7();
  } else if (execut == 2) {
    printf("\nOk, obrigado");
  }
}

void exercicio8() {
  {
    int execut, aux, i, j, k, L1, C1, L2, C2, **mat1, **mat2, **mat3;

    printf("\ndigite a quantidade de linhas da matriz 1:\n");
    scanf("%d", &L1);
    printf("\ndigite a quantidade de colunas da matriz 1:\n");
    scanf("%d", &C1);

    printf("\ndigite a quantidade de linhas da matriz 2:\n");
    scanf("%d", &L2);
    printf("\ndigite a quantidade de colunas da matriz 2:\n");
    scanf("%d", &C2);
    if (C1 != L2) {
      printf("\nNao é possivel multiplicar as matrizes\n");
      printf("\nDeseja executar o programa novamente utilizando matrizes "
             "diferentes, digite 1 para sim e 2 para nao:\n");
      scanf("%d", &execut);

      if (execut == 1) {
        exercico7();
      }
    }
    mat1 = aloca_mat(L1, C1);

    mat2 = aloca_mat2(L2, C2);

    printf("\n Imprimindo a matriz 1: \n\n");
    for (i = 0; i < L1; i++) {
      for (j = 0; j < C1; j++) {
        printf("%d\t", mat1[i][j]);
      }
      printf("\n");
    }

    printf("\n Imprimindo a matriz 2: \n\n");
    for (i = 0; i < L2; i++) {
      for (j = 0; j < C2; j++) {
        printf("%d\t", mat2[i][j]);
      }
      printf("\n");
    }

    if (C1 == L2) {
      mat3 = (int **)malloc(sizeof(int *) * L2);

      for (i = 0; i < L1; i++) {
        mat3[i] = (int *)malloc(sizeof(int) * C1);
      }
      printf("\nO produto das duas matrizes é:\n ");
      for (i = 0; i < L1; i++) {

        for (j = 0; j < C2; j++) {
          mat3[i][j] = 0;
          for (k = 0; k < L2; k++) {
            aux += mat1[i][k] * mat2[k][j];
          }
          mat3[i][j] = aux;
          aux = 0;
          printf("%d\t", mat3[i][j]);
        }
        printf("\n\n");
      }
      printf("\n\n");
    }
    printf("\nDeseja executar o programa novamente utilizando matrizes "
           "diferentes, digite 1 para sim e 2 para nao:\n");
    scanf("%d", &execut);

    if (execut == 1) {
      exercicio8();
    } else if (execut == 2) {
      printf("\nOk, obrigado");
    }
  }
}

int main(void) {

  int exercicio;
  

  printf("\nDigite o exercicio que voce deseja executar(1 até 8):\n ");
  scanf("%d", &exercicio);

  if (exercicio>8 || exercicio<1)
  {printf("\nEscolha um exercicio entre 1 e 8\n");
   main();
  }
  
  switch (exercicio) {
  case 1:
    exercicio1();
    break;

  case 2:

    exercicio2();
    break;

  case 3:
    exercicio3();
    break;

  case 4:

    exercicio4();
    break;

  case 5:
    exercicio5();
    break;

  case 6:

    exercicio6();

    break;

  case 7:
    exercico7();
    break;

  case 8:
    exercicio8();
    break;
  }

  return 0;
}