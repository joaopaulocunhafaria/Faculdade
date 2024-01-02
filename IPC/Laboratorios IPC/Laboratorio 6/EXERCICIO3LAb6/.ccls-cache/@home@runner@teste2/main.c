#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void filtra_nomes(char *nome_arquivo_entrada,char *nome_arquivo_saida ,
                  char letra_inicial) {

  FILE *arquivo_saida;
  FILE *arquivo_entrada;
  char conteudo_lista[200];
  char auxiliar[200];
  int i, qntd;
  char nome_completo[50];
  char sobrenome[50];
  int idade;

  arquivo_entrada = fopen(nome_arquivo_entrada, "r");
  arquivo_saida = fopen(nome_arquivo_saida, "w");

  if (arquivo_entrada == NULL) {
    printf("Erro ao abrir o arquivo de entrada.\n");
    return;
  }

  while (fgets(auxiliar, 200, arquivo_entrada) != NULL) {
    sscanf(auxiliar, "%s %s %d", nome_completo, sobrenome, &idade);

    if (nome_completo[0] == letra_inicial) {
      fprintf(arquivo_saida, "%s %s %d\n", nome_completo, sobrenome, idade);
    }
  }

  fclose(arquivo_saida);
  fclose(arquivo_entrada);

  printf("\nOS NOMES DO ARQUIVO DE ENTRADA INICIADOS COM A LETRA %c FORAM "
         "ARMAZENADOS NO ARQUIVO DE SAIDA COM SUCESSO!",
         letra_inicial);
}

int main(void) {

  char arquivo_entrada[20];
  char arquivo_saida[20];
  char letra_inicial;

  printf("QUAL O NOME DO ARQUIVO DE ENTRADA?");
  scanf("%s", arquivo_entrada);

  printf("QUAL O NOME DO ARQUIVO DE SAIDA?");
  scanf("%s", arquivo_saida);

  printf("ESCOLHA A LETRA:");
  getchar();
  scanf("%c", &letra_inicial);

  filtra_nomes(arquivo_entrada,arquivo_saida, letra_inicial);

  return 0;
}