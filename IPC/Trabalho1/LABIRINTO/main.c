
#include <stdio.h>

#define MAX_LINHAS 9
#define MAX_COLUNAS 9

int percorrer_labirinto(char labirinto[MAX_LINHAS][MAX_COLUNAS], int atualinnha,int atualcoluna) {

  // Verificar se a posição atual está dentro dos limites do labirinto
  if (atualinnha < 0 || atualinnha >= MAX_LINHAS || atualcoluna < 0 ||
      atualcoluna >= MAX_COLUNAS) {
    return 0;
  }
  // Verificar se a posição atual é uma parede ou já foi visitada
  if (labirinto[atualinnha][atualcoluna] == '#' ||labirinto[atualinnha][atualcoluna] == '.') {
    return 0;
  }
  // Verificar se a posição atual é o ponto final
  if (labirinto[atualinnha][atualcoluna] == 'F') {
    return 1;
  }

  // Marcar a posição atual como visitada
  labirinto[atualinnha][atualcoluna] = '.';

  // Tentar percorrer as posições vizinhas (cima, baixo, esquerda, direita)

  if (percorrer_labirinto(labirinto, atualinnha - 1, atualcoluna) ||
      percorrer_labirinto(labirinto, atualinnha + 1, atualcoluna) ||
      percorrer_labirinto(labirinto, atualinnha, atualcoluna - 1) ||
      percorrer_labirinto(labirinto, atualinnha, atualcoluna + 1)) {
     return 1;
  }
 

  // Se não foi possível encontrar um caminho válido, desfazer a marcação
  labirinto[atualinnha][atualcoluna] = ' ';
  return 0;
}

int encontrar_caminho(char labirinto[MAX_LINHAS][MAX_COLUNAS]) {
  int linha_inicial = -1;
  int coluna_inicial = -1;
  int linha_final = -1;
  int coluna_final = -1;
  

  // Encontrar a posição inicial e final
  for (int i = 0; i < MAX_LINHAS; i++) {
    for (int j = 0; j < MAX_COLUNAS; j++) {
      if (labirinto[i][j] == 'S') {
        linha_inicial = i;
        coluna_inicial = j;
      } else if (labirinto[i][j] == 'F') {
        linha_final = i;
        coluna_final = j;
      }
    }
  }

  // Verificar se a posição inicial e final foram encontradas
  if (linha_inicial == -1 || coluna_inicial == -1 || linha_final == -1 ||
      coluna_final == -1) {
    return 0;
  }

 

  // Chamar a função auxiliar para encontrar o caminho
  if (percorrer_labirinto(labirinto, linha_inicial, coluna_inicial)) {
    return 1;
  } else {
    return 0;
  }
}


int main() {
  char labirinto1[MAX_LINHAS][MAX_COLUNAS] = {
      {'#', '#', '#', '#', '#', '#', '#', '#', '#'},
      {'#', ' ', '#', ' ', '#', ' ', ' ', ' ', '#'},
      {'#', ' ', '#', '#', '#', ' ', '#', ' ', '#'},     
      {'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#'},
      {'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#'},
      {'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#'},
      {'#', 'S', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
      {'#', '#', '#', '#', '#', '#', '#', 'F', '#'}};

  int resultado = encontrar_caminho(labirinto1);

  if(resultado==1){
    printf("Caminho encontrado\n\n");
  }
  if(resultado!=1){
     printf("Caminho nao encontrado\n\n");
  }
  

  for (int i = 0; i < MAX_LINHAS; i++) {
    for (int j = 0; j < MAX_COLUNAS; j++) {
      printf("%c ", labirinto1[i][j]);
    }
    printf("\n");
  }

  return 0;
}
