#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {

  char frase[500];
  char matfrase[30][100];
  char frase2[500]="";

  int i = 0;
  int j = 0;
  int k = 0;
  int tamanho;
  int size = 0;

  printf("DIGITE A FRASE:");
  fgets(frase, 1000, stdin);

while(frase[i]!='\0'){
  frase[i]=toupper(frase[i]);
  i++;
}
  
  tamanho = strlen(frase);

  frase[tamanho - 1] = '\0';

  i=0;

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
  
  
  for (i = 0; i < 30; i++) {
    if (strcmp(matfrase[i], "TECLADO") == 0) {
      // conferir se tem a palavra teclado na string
      
      strcat(matfrase[i], " OU MOUSE");
      //concatenr o complemento "ou mouse" ao final da matriz caso tenha a palavra teclado
    }
  }

 
  // reconstruir a frase
  for (i = 0; i < size; i++) {

    strcat(frase2, matfrase[i]);
    if (i < size-1) {
      strcat(frase2, " ");
    }
  }
   
  printf("\n\nFRASE RECONSTRUIDA: %s\n", frase2);
  
  return 0;
}