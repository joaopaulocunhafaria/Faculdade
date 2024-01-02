#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct numeros {
  int qntd;
  float soma;
  float media;
  char nome_arquivo[15];
};

void somamedia(char nome_arquivo[], struct numeros num[], float *vet,
               float qntd) {

  int i = 0;
  float soma;
  float media;

  printf("\nestes sao os numeros gerados\n");
  for (i = 0; i < qntd; i++) {

    printf("%.f,", vet[i]);
    soma += vet[i];
  }

  media = soma / qntd;

  for (i = 0; i < 10; i++) {
    if (num[i].soma == 0 || num[i].nome_arquivo[0] == '\0') {
      num[i].soma = soma;
      num[i].media = qntd;
      num[i].qntd = qntd;
      strcpy(num[i].nome_arquivo, nome_arquivo);

      printf(
          ".\n\n-------------- RESULTADOS DO ARQUIVO ATUAL --------------\n");

      printf("\nNome do arquivo: %s", num[i].nome_arquivo);
      printf("\nA media e %.2f", num[i].media);
      printf("\nA soma e %.2f", num[i].soma);
      printf("\nA quantidade de numeros: %d", num[i].qntd);
      printf("\n----------------------------------------\n\n");
      return;
    }
  }
}

int main() {

  struct numeros num[10];
  float *vet;
  int i;
  float qntd = 0;
  char nome_arquivo[15];

  srand(time(NULL));

  printf("Digite o nome do arquivo:");
  fgets(nome_arquivo, 15, stdin);
  nome_arquivo[strlen(nome_arquivo) - 1] = '\0';

  printf("Quantos numeros voce deseja gerar??\n");
  scanf("%f", &qntd);

  vet = (float *)malloc(qntd * sizeof(float));

  for (i = 0; i < qntd; i++) {

    vet[i] = (rand() % 20) + 1;
  }

  FILE *fp = fopen("resultadoTotal.bin", "rb");
  if (fp == NULL) {
    fp = fopen("resultadoTotal.bin", "wb");
  }
  if (fp != NULL) {
    fread(&num, sizeof(struct numeros), 10, fp);
  }
  fclose(fp);

  somamedia(nome_arquivo, num, vet, qntd);

  fp = fopen("resultadoTotal.bin", "w+b");
  fwrite(num, sizeof(struct numeros), 10, fp);
  fclose(fp);

  printf("-------------- RESULTADOS TOTAIS---------------");
  for (i = 0; i < 10; i++) {
    if (num[i].soma != 0 && num[i].media != 0 && num[i].qntd != 0 &&
        num[i].nome_arquivo[0] != '\0') {
      printf("\nNome do arquivo %d: %s", i + 1, num[i].nome_arquivo);
      printf("\nMedia:  %.f", num[i].media);
      printf("\nSoma:  %.f", num[i].soma);
      printf("\nA quantidade de numeros: %d\n\n", num[i].qntd);
    }
  }
  printf("\n----------------------------------------\n\n");

  printf("saindo...");
  return 0;
}