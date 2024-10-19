#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define N 4

void letraA(int **mat, int N) {

  // ##INICIA A LETRA A)

  int cont = 0;
  int i;
  int k;
  int j;
  char resposta[5];
  printf("\nA) Dado k, determinar quantas estradas saem e quantas chegam à "
         "cidade k");
  printf("\nDIGITE O VALOR DE K(REFERENTE A CIDADE DO EXERCICIO):\n");

  do {
    printf(" ENTRE O E %d\n\n", (N - 1));
    scanf("%d", &k);
  } while (k < 0 || k > (N - 1));

  // DEFINIR QUANTAS ESTRADAS CHEGAM NA CIDADE K

  for (i = 0; i < N; i++) {

    if (i != k && (mat[i][k]) == 1) {
      cont++;
      // CONT IGUAL A QUANTIDADE DE ESTRADAS QUE CHEGAM EM K
    }
  }
  printf("\n\nA QUANTIDADE DE ESTRADAS QUE CHEGAM NA CIDADE %d E:%d", k, cont);
  cont = 0;
  // DEFINIR QUANTAS ESTRADAS SAEM DE K
  for (j = 0; j < N; j++) {

    if (j != k && (mat[k][j]) == 1) {
      cont++;
      // CONT IGUAL A QUANTIDADE DE ESTRADAS QUE SAEM DE K
    }
  }
  printf("\n\nA QUANTIDADE DE ESTRADAS QUE SAEM DA CIDADE %d E:%d", k, cont);

  // VERIFICAR DE QUAL CIDADE SAI A MAIOR QUANTIDADE DE ESTRADAS

  // USAR UM VETOR PARA RECEBER OS VALORES SOMADOS DE TODOS OS 1'S EM UMA
  // COLUNA, E DEPOIS COMPARAR QUAL POSIÇAO DO VETOR TEM O MAIOR NUMERO, CADA
  // POSIÇAO DO VETOR É REFERENTE A UMA CIDADE, SENDO VETAUX[0]= (A QUANTIDADE
  // DE CIDADES QUE CHEGAM NA CIDADE 0)

  // ##TERMINA A LETRA A)
}

void letraB(int **mat, int N) {

  // ##INICIO DA LETRA B)

  printf("B) A qual das cidades chega o maior número de estradas?\n\n");

  int *vetaux;
  int aux = 0;  // recebera o maior valor de estradas que chegam
  int cont = 0; // auxiliara a definir quando chegam a mesma quantidade de
                // estradas em todas as cidades

  vetaux = (int *)malloc(N * sizeof(int));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      vetaux[i] += mat[j][i];
    }
    if (vetaux[i] > aux) {
      aux = vetaux[i];
    }
  }

  for (int i = 0; i < N - 1; i++) {
    if (vetaux[i] == vetaux[i + 1]) {
      cont++;
    }
  }

  if (cont == (N - 1)) {
    printf("CHEGAM A MESMA QUANTIDADE DE ESTRADAS EM TODAS AS CIDADES: %d",
           aux);
  }

  if (cont != (N - 1)) {
    printf("A CIDADE QUE CHEGA A MAIOR QUANTIDADE DE ESTRADAS E A CIDADE");
    for (int i = 0; i < N; i++) {
      if (vetaux[i] == aux) {
        printf(" [%d]", i);
      }
    }
  }
free(vetaux);
  // ##TERMINA A LETRA B)
}

void letraC(int **mat, int N) {

  // ##INICIO DA LETRA C)
  printf("Dado k, verificar se todas as ligações diretas entre a cidade k e "
         "outras são de mão dupla\n\n");

  int cont = 0;
  int i;
  int j;
  int k;
  int *vetaux;
  vetaux = (int *)malloc(N * sizeof(int));

  // DEFINIR SE AS LIGAÇOES ENTRE AS CIDADES SAO DE MAO DUPLA
  // CHECAR AS LINHAS E AS COLUNAS DAS CIDADES, PARA SEREM DE MAO DUPLA DEVE
  // HAVER O NUMERO 1 NA POSIÇAO [K][l] E NA POSIÇAO [i][k]

  printf("\n\nDEFINA UM NOVO VALOR PARA A CIDADE K: ");
  scanf("%d", &k);

  for (i = 0; i < N; i++) {

    if ((i != k) && (mat[k][i]) == 1 && (mat[i][k]) == 1) {
      vetaux[i] = 1;
    }
  }

  // para casos em que nao ha nenhuma ligaçoa de mao dupla
  for (i = 0; i < N; i++) {
    if (vetaux[i] == 1) {
      cont++;
    }
  }

  if (cont != 0) {
    printf("\n\nA CIDADE %d TEM LIGAÇAO DE MAO DUPLA COM A CIDADE\n", k);
    for (i = 0; i < N; i++) {
      if (vetaux[i] == 1) {
        printf("[%d]", i);
      }
    }
  }

  if (cont == 0) {
    printf("\n\nA CIDADE %d NAO POSSUI LIGAÇOES DE MAO DUPLA");
  }
  free(vetaux);
  // ## TERMINA LETRA C)
}

void letraD(int **mat, int N) {
  //##COMEÇA A LETRA D
  printf(
      " Relacionar as cidades que possuem saídas diretas para a cidade k\n\n");

  int k;
  int *vetaux;
  vetaux = (int *)malloc(N * sizeof(int));

  printf("DEFINA UM VALOR PARA A CIDADE K: ");
  scanf("%d", &k);

  for (int j = 0; j < N; j++) {

    if (j != k && mat[k][j] == 1) {
      // j!=k, para nao ler o numero 1 na posiçao Lii
      vetaux[j] = 1;
    } else {
      vetaux[j] = 0;
    }
  }

  printf("\n\nAS CIDADES");
  for (int j = 0; j < N; j++) {
    if (vetaux[j] == 1) {
      printf(" [%d] ", j);
    }
  }
  printf("POSSUEM SAIDA DIRETA PARA A CIDADE %d", k);
free(vetaux);
  //##TERMINA A LETRA D
}

void letraE(int **mat, int N) {
  //##COMEÇA A LETRA E

  printf("Relacionar, se existirem:\n");
  printf("i. As cidades isoladas, isto é, as que não têm ligação com nenhuma "
         "outra\n");
  printf("ii. As cidades das quais não há saída, apesar de haver entrada\n");
  printf("iii. As cidades das quais há saída sem haver entrada.\n");

  int i;
  int j;
  int cont = 0;
  int cont2 = 0;
  int *vetaux;
  int *vetaux2;
  vetaux = (int *)malloc(N * sizeof(int));
  vetaux2 = (int *)malloc(N * sizeof(int));

  // i
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (i != j) {
        vetaux[i] += mat[i][j] + mat[j][i];
      }
    }
    if (vetaux[i] == 0) {
      cont++;
    }
  }

  // O CONTADOR TEM A FUNÇAO DE APONTAR QUANDO NA HÁ NENHUMA CIDADE ISOLADA
  if (cont != 0) {
    printf("\ni)A CIDADE");
    for (i = 0; i < N; i++) {
      if (vetaux[i] == 0) {
        vetaux[i] = 10;
        printf(" [%d] ", i);
      }
    }
    printf("NÃO POSSUE LIGAÇAO COM NENHUMA OUTRA");
  }
  if (cont == 0) {
    printf("\ni)NAO HÁ NENHUMA CIDADE ISOLADA");
  }

  for (i = 0; i < N; i++) {
    vetaux[i] = 0;
  }

  // ii

  // concertar para quando nao ha cidades sem saida
  cont = 0;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (i != j) {
        vetaux[i] += mat[i][j];
        vetaux2[i] += mat[j][i];
      }
    }
    if (vetaux[i] == 0) {
      cont++;
    }

    if (vetaux2[i] == 0) {
      cont2++;
    }
  }

  if (cont >= 1) {
    printf("\n\nii)A CIDADE ");
    for (i = 0; i < N; i++) {
      if (vetaux[i] == 0 && vetaux2[i] != 0) {
        printf("[%d]", i);
      }
    }
    printf(" NAO POSSUI SAIDAS");
  }
  if (cont == 0) {
    printf("\n\nii)NAO HA CIDADES SEM SAIDAS");
  }

  // iii
  if (cont2 >= 1) {
    printf("\n\niii)A CIDADE ");
    for (i = 0; i < N; i++) {
      if (vetaux2[i] == 0 && vetaux[i] != 0) {
        printf("[%d]", i);
      }
    }
    printf(" NAO POSSUI ENTRADAS");
  }

  if (cont2 == 0) {
    printf("\n\niii) NAO HA CIDADES SEM CHEGADA");
  }
  free(vetaux);
  free(vetaux2);
}

void letraF(int **mat, int N) {
  //##COMEÇO LETRA F

  printf("Verificar se é possível realizar o roteiro correspondente.\n\n");

  int tam;
  int *roteiro;
  int cont = 0;
  char resposta[5];

  printf("\nQUANTIDADE DE INTERAÇOES DO SEU ROTEIRO:");
  scanf("%d", &tam);
  roteiro = (int *)malloc(tam * sizeof(int));

  printf("\nDIGITE O SEU ROTEIRO");
  for (int i = 0; i < tam; i++) {

    do {
      printf("\n[%d]:", i);
      scanf("%d", &roteiro[i]);
      if ((roteiro[i]) >= N) {
        printf("\nDIGITE UM NUMERO ENTRE 0 E %d\n\n", N - 1);
      }
    } while ((roteiro[i]) >= N);
  }

  for (int i = 0; i < tam - 1; i++) {

    if (mat[roteiro[i + 1]][roteiro[i]] == 1) {
      cont++;
    }
  }

  if (cont == tam - 1) {
    printf("\nO ROTEIRO É POSSIVEL");
  } else {
    printf("\nO ROTEIRO É IMPOSSIVEL");
  }

  printf("\nDESEJA TESTAR OUTRO ROTEIRO?");
  scanf("%s", resposta);

  if (strcmp(resposta, "sim") == 0) {
    letraF(mat, N);
  }
  free(roteiro);

  //##TERMINA LETRA F
}

int funcao_confere(int **mat, int k, int p, int N) {

  int i;
  int *vet;
  vet = (int *)malloc(N * sizeof(int));
  for (i = 0; i < N; i++) {
    vet[i] = 77;
  }

  if(mat[p][k]==1){
    return 1;
  }

  
  for (i = 0; i < N; i++) {

    if(i!=k){
      if (mat[i][k] == 1) {
        vet[i] = i;
      }
    }
  }

  
  for (i = 0; i < N; i++) {
    if (vet[i] != 77) {
      if(funcao_confere(mat, vet[i], p, N)){
        return 1;
      }
    }
  }
  free(vet);
  
}

void letraG(int **mat, int N) {
  printf("G) Dados k e p, determinar se é possível ir da cidade k para a "
         "cidade p pelas estradas existentes\n\n");

  int result = 2;
int cont=0;
  int k = 0, p = 0;
  int i, j;
  int *vet;
  vet = (int *)malloc(N * sizeof(int));
  for (i = 0; i < N; i++) {
    vet[i] = 77;
  }
  printf("DE QUAL CIDADE VOCE QUER SAIR:");
  scanf("%d", &k);
  printf("\nPARA QUAL CIDADE VOCE QUER IR:");
  scanf("%d", &p);

for(i=0;i<N;i++){
  if(mat[p][i]==1){
    cont++;
    //se cont nao assumir nenhum valor diferente de zero, significa que nao ha estradas que chegam em p
  }
}

  if(cont==0){
    printf("\nNAO É POSSIVEL IR DE UMA CIDADE PARA OUTRA PELAS ESTRADAS EXISTENTES");
  return;
  }
  
  if (mat[p][k] == 1) {
    printf("\nE POSSIVEL IR DE UMA CIDADE PARA A OUTTRA PELAS ESTRADAS "
           "EXISTENTES");
    return;
  }

  
  for (i = 0; i < N; i++) {

    if (mat[i][k] == 1) {
      vet[i] = i;
    }
  }
  
    for(i = 0; i < N; i++) {
      if (vet[i] != 77) {
        result = funcao_confere(mat, vet[i], p, N);
        if (result == 1) {
          printf("\nE POSSIVEL IR DE UMA CIDADE PARA A OUTRA PELAS ESTRADAS "
                 "EXISTENTES");
          return;
        }
      }
    }
  
  free(vet);
}

int main() {

  char letra;
  int i, j;
  int **mat;
  int N;

  printf("DIGITE A DIMENSAO DA MATRIZ:\n");
  scanf("%d", &N);

  mat = (int **)malloc(sizeof(int *) * N);
  for (i = 0; i < N; i++) {
    mat[i] = (int *)malloc(sizeof(int) * N);
  }

  // AQUI A MATRIZ SO PODERA ASSSUMIR VALORES DE 1 OU 0
  printf("\n\nCAPTANDO VALORES DA MATRIZ(SOMENTE 1 OU 0):\n");
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (i == j) // PARA QUE TODO L(ii),  SEJA IGUAL A 1
      {
        mat[i][j] = 1;
      }
      if (i != j) // PARA POSIÇOES DIFERENTES DE L(ii)
      {
        do // PARA GARANTIR QUE TODO NUMERO DIGITADO SEJA 0 OU 1
        {
          printf("[%d][%d]:", i, j);
          scanf("%d", &mat[i][j]);
          if ((mat[i][j]) != 1 && (mat[i][j]) != 0) {
            printf("\nDIGITE APENAS (1) OU (0)\n\n");
          }
        } while ((mat[i][j] < 0) || (mat[i][j] > 1));
      }
    }
    printf("\n\n");
  }

  printf("IMPRIMINDO A MATRIZ A MATRIZ\n\n");
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("[%d]\t", mat[i][j]);
    }
    printf("\n\n");
  }

  do {
    printf("QUAL LETRA VOCE DESEJA?");
    scanf(" %c", &letra);
    letra = toupper(letra);
  } while (letra < 'A' || letra > 'G');

  getchar();
  switch (letra) {
  case 'A':
    letraA(mat, N);
    break;

  case 'B':
    letraB(mat, N);
    break;
  case 'C':
    letraC(mat, N);
    break;

  case 'D':
    letraD(mat, N);
    break;
  case 'E':
    letraE(mat, N);
    break;
  case 'F':
    letraF(mat, N);
    break;
  case 'G':
    letraG(mat, N);
    break;
  default:
    printf("Opção inválida.\n");
    break;
  }
free(mat);
  return 0;
}