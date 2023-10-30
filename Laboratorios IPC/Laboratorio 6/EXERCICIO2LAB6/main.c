#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void substitui_string(char *nome_arquivo_entrada, char *string_procurada,
                      char *string_substituta, char *nome_arquivo_saida) {

  FILE *arquivo_entrada;
  FILE *arquivo_saida;
  char auxiliar[800];
  char matauxiliar[99][20];
  int size = 0;
  int tam=0;
  int cont=0;

  string_procurada[strlen(string_procurada)-1]='\0';
  string_substituta[strlen(string_substituta)-1]='\0';

  // passar o conteudo do arquivo para uma string auxiliar

  arquivo_entrada = fopen(nome_arquivo_entrada, "r");
  fgets(auxiliar, 80, arquivo_entrada);

  fclose(arquivo_entrada);

  int i = 0, j = 0, k = 0;
  while (auxiliar[i] != '\0') {
    if (auxiliar[i] != ' ') {
      matauxiliar[j][k] = auxiliar[i];
      k++;
    } else {
      matauxiliar[j][k] = '\0';
      j++;
      k = 0;
    }
    i++;
  }

  tam=strlen(matauxiliar[j]);
  
  matauxiliar[j][tam-1] = '\0';
  size = j + 1;

  for (i = 0; i < size; i++) {
    if (strstr(matauxiliar[i], string_procurada) != NULL) {
      cont++;
    }

    if (strcmp(matauxiliar[i], string_procurada) == 0) {
      strcpy(matauxiliar[i], string_substituta);
    }
  }
  arquivo_saida = fopen(nome_arquivo_saida, "w");
  for (i = 0; i < size; i++) {
    fprintf(arquivo_saida, "%s", matauxiliar[i]);
    fprintf(arquivo_saida, "%s", " ");
  }
  fclose(arquivo_saida);

   printf("\nHÁ %d OCORRENCIA DA PALAVRA NO TEXTO PROCURADO", cont);
  printf("\n\nARQUIVO ALTERADO COM SUCESSO!");
}

int main(void) {

  FILE *arquivo;
  char nome_arquivo_entrada[50];
  char nome_arquivo_saida[50];
  char palavrabusca[50];
  char palavratroca[50];
  char conteudo_arquivo[1000];

  printf("DIGITE A PALAVRA DE BUSCA:");
  fgets(palavrabusca, 50, stdin);

  printf("\nDIGITE A STRING PARA ALTERAR:");
  fgets(palavratroca, 50, stdin);

  printf("\nDIGITE O CONTEUDO DO ARQUIVO:");
  fgets(conteudo_arquivo, 500, stdin);

  printf("QUAL O NOME DO ARQUIVO DE ENTRADA:");
  fgets(nome_arquivo_entrada, 50, stdin);

  printf("\nQUAL O NOME DO ARQUIVO DE SAIDA:");
  fgets(nome_arquivo_saida, 50, stdin);

  arquivo = fopen(nome_arquivo_entrada, "w");

  fprintf(arquivo, "%s", conteudo_arquivo);

  fclose(arquivo);

  substitui_string(nome_arquivo_entrada, palavrabusca, palavratroca,
                   nome_arquivo_saida);
  return 0;
}