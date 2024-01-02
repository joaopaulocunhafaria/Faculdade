#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  // mesma logica do exercicio 2
  // coletar uma string, transformar cada palavra em uma linha de uma matriz,
  // conferir se existe a palvra desejada, substituir caso exista, reoarganixar uma em frase

  char frase[1000];
  char matfrase[30][100];
  char frase2[1000] = "";

  int i = 0;
  int j = 0;
  int k = 0;
  int tamanho;
  int size = 0;

  printf("DIGITE A FRASE:");
  fgets(frase, 1000, stdin);

  while (frase[i] != '\0') {
    frase[i] = toupper(frase[i]);
    i++;
  }


  tamanho = strlen(frase);

  frase[tamanho - 1] = '\0';

  i = 0;
  // i=0, pois apos usar a funçao tolower i assume valores diferente de 0

  // transformar a string em uma matriz
  while (frase[i] != '\0') {
    if (frase[i] != ' ') {
      matfrase[j][k] = frase[i];
      k++;
    } else {
      matfrase[j][k] = '\0';
      j++;
      k = 0;
    }
    i++;
  }

  matfrase[j][k] = '\0';
  size = j + 1;

  // size= a quantidade de palavras na matriz

  for (i = 0; i < size; i++) {
    if (strcmp(matfrase[i], "ALUNO") == 0) {
      // conferir se tem a palavra aluno na string

      strcpy(matfrase[i], "ESTUDANTE");
      // substituir pela palavra desejada
    }
    if (strcmp(matfrase[i], "ESCOLA") == 0) {
      // conferir se tem a palavra escola na string

      strcpy(matfrase[i], "UNIVERSIDADE");
      // substituir pela palavra desejada
    }
  }

  // reconstruir a frase
  for (i = 0; i < size; i++) {

    strcat(frase2, matfrase[i]);
    if (i < size - 1) {
      strcat(frase2, " ");
    }
  }

  printf("\n\nFRASE COM AS PALAVRAS ALUNO E ESCOLA SUBSTITUIDAS:\n\n %s", frase2);

  return 0;
}