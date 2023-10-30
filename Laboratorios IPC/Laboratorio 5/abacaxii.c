#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  char frase[80];
  int cont;
  int tam;
  char i;

  printf("DIGITE A FRASE:\n");
  fgets(frase, 80, stdin);

  tam = strlen(frase) - 1;


  for (i = 0; i < tam; i++) {
    frase[i] = tolower(frase[i]);
  }

  

  for (i = 'a'; i <= 'z'; i++) {
    cont = 0;
    for (int j = 0; j < tam; j++) {
      if (frase[j] == i) {
        cont++;
      }
    }
    if (frase[i] != i && cont > 0) {
      printf("[%c]=%d\n", i, cont);
    }
  }
  return 0;
}