#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define GRANDE 1000

void imprimiilhaint(int **ilha, int linha, int colunas) {

  // esta fun�ao imprimi matrizes de inteiros,
  //  usada somente para avaliacoes durante a contru�ao do programa

  int i, j;

  for (i = 0; i < linha; i++) {

    for (j = 0; j < colunas; j++) {

      printf("[%d]", ilha[i][j]);
    }
    printf("\n");
  }
}

void imprimiilha(char **ilha, int linhas, int colunas) {
  int i, j;

  // esta funcao imprimi matriz de char,
  // usada somente para avalia�oes durante a contrucao do programa

  printf("----------------------\n");
  for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++) {
      printf("%c", ilha[i][j]);
    }
    printf("\n");
  }
  printf("----------------------\n");
}

char **tratarmatriz(char **ilha, int linhas, int colunas) {

  int i, j;

  for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++) {

      if (ilha[i][j] == '*') {

        // tratamento para tirar lixos da matriz
        // colocar todas as posicoes nao posssiveis de acessar como #
        // nao colocar # na posicoes onde tem canbais, por isso ilha[][]!='*'

        // canibais
        if (i + 1 >= 0 && i + 1 < linhas && ilha[i + 1][j] != '*') {
          ilha[i + 1][j] = '#';
        } // baixo

        if (i - 1 >= 0 && i - 1 < linhas && ilha[i - 1][j] != '*') {
          ilha[i - 1][j] = '#';
        } // cima

        if (j + 1 >= 0 && j + 1 < colunas && ilha[i][j + 1] != '*') {
          ilha[i][j + 1] = '#';
        } // direita

        if (j - 1 > 0 && j - 1 < colunas && ilha[i][j - 1] != '*') {
          ilha[i][j - 1] = '#';
        } // esquerda

        if (i - 1 >= 0 && i - 1 < linhas && j - 1 > 0 && j - 1 < colunas &&
            ilha[i - 1][j - 1] != '*') {
          ilha[i - 1][j - 1] = '#';
        } // diagonal cima a esquerda

        if (i - 1 >= 0 && i - 1 < linhas && j + 1 > 0 && j + 1 < colunas &&
            ilha[i - 1][j + 1] != '*') {
          ilha[i - 1][j + 1] = '#';
        } // diagonla cima a direita

        if (i + 1 >= 0 && i + 1 < linhas && j - 1 > 0 && j - 1 < colunas &&
            ilha[i + 1][j - 1] != '*') {
          ilha[i + 1][j - 1] = '#';
        } // daigonal baixo a esquerda

        if (i + 1 >= 0 && i + 1 < linhas && j + 1 > 0 && j + 1 < colunas &&
            ilha[i + 1][j + 1] != '*') {
          ilha[i + 1][j + 1] = '#';
        }
      }

      if (ilha[i][j] == '~') {
        ilha[i][j] = '#';
      }
    }
  }
  return ilha;
}

int quantidadetes(char **ilha, int linhas, int colunas) {

  int i, j;
  int qntdtes = 0;

  // esta fun�ao retorna a qunatidade de tesouros presente na matriz

  // usada antes e depois do tratamento da matriz, se acasso o valor da
  // quantidade de tesouros se alterar isso quer dizer que algum tesouro �
  // inacessivel, logo o programa deve imprimir -1

  for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++) {
      if (ilha[i][j] == '!') {
        qntdtes++;
      }
    }
  }
  return qntdtes;
}

int **achartesouros(char **ilha, int linhas, int colunas, int qntdtes) {

  // esta fun�ao retorna uma matriz de tamanho 2 X qunatidade de tesouros
  // onde a linha 0 guarda o valor do indice i de todos os tesouros
  // e a linha 1 guarda o valor do indice j de todos os tesouros

  int i = 0, j = 0;
  int cont = 0;
  int **cordenadas;
  cordenadas = (int **)malloc(sizeof(int *) * 2);
  for (i = 0; i < 2; i++) {
    cordenadas[i] = (int *)malloc(sizeof(int) * qntdtes);
  }

  for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++) {

      if (ilha[i][j] == '!') {
        cordenadas[0][cont] = i;
        cordenadas[1][cont] = j;

        cont++;
      }
    }
  }
  return cordenadas;
}

int percorrer_ilha(char **ilha, int atualinnha, int atualcoluna, int linhas,
                   int colunas) {

  // nesta fun�ao implementei o metodo de recursao do trabalho 1 para saber se
  // cada tesouro pode chegar ate o jack sparrow, se acasso algum tesouro nao
  // ser possivel de ser acessado a fun�ao retorna 0

  if (atualinnha < 0 || atualinnha >= linhas || atualcoluna < 0 ||
      atualcoluna >= colunas) {
    return 0;
  }
  // Verificar se a posição atual é uma parede ou já foi visitada
  if (ilha[atualinnha][atualcoluna] == '#' ||
      ilha[atualinnha][atualcoluna] == '.') {
    return 0;
  }
  // Verificar se a posição atual é o ponto final
  if (ilha[atualinnha][atualcoluna] == 'T') {
    return 1;
  }

  // Marcar a posição atual como visitada
  ilha[atualinnha][atualcoluna] = '.';

  // Tentar percorrer as posições vizinhas (cima, baixo, esquerda, direita)

  if (percorrer_ilha(ilha, atualinnha - 1, atualcoluna, linhas, colunas) ||
      percorrer_ilha(ilha, atualinnha + 1, atualcoluna, linhas, colunas) ||
      percorrer_ilha(ilha, atualinnha, atualcoluna - 1, linhas, colunas) ||
      percorrer_ilha(ilha, atualinnha, atualcoluna + 1, linhas, colunas)) {
    return 1;
  }

  // Se não foi possível encontrar um caminho válido, desfazer a marcação
  ilha[atualinnha][atualcoluna] = ' ';
  return 0;
}

char **limparilha(char **ilha, int linhas, int colunas) {

  int i = 0, j = 0;

  for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++) {
      if (ilha[i][j] == '.') {
        ilha[i][j] = ' ';
      }
    }
  }
  return ilha;
}

int *confererota(char **ilha, int linhas, int colunas, int qntdtes,
                 int **cordenadas, int inilinha, int inicoluna) {

  int i = 0, j = 0;
  int *aux;
  int aux1, aux2;

  // nesta fun�ao usei um vetor auxilar inicializado todo com numeros 0,
  // cada posi�ao do vetor vai ser referente a um tesouro do mapa, se acasso
  // um tesouro nao poder ser ser acessado o vetor continuara com o valor 0,
  // caso seja possivel recebera o 1 assim � possivel saber quais tesouros
  // podem ser acessados

  aux = (int *)malloc(sizeof(int) * qntdtes);
  for (i = 0; i < qntdtes; i++) {
    aux[i] = 0;
  }

  for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++) {
      if (ilha[i][j] == '!') {
        ilha[i][j] = ' ';
      }
    }
  }

  for (i = 0; i < qntdtes; i++) {
    aux1 = cordenadas[0][i];
    aux2 = cordenadas[1][i];

    ilha[aux1][aux2] = 'T';

    if (percorrer_ilha(ilha, inilinha, inicoluna, linhas, colunas)) {
      aux[i] = 1;
    }

    ilha = limparilha(ilha, linhas, colunas);
    ilha[aux1][aux2] = ' ';
  }

  return aux;
}

char **tiratesourosinacessiveis(char **ilha, int **postes,
                                int *tesourosacessiveis, int qntdtes) {

  int i = 0;
  int aux1, aux2;

  // nesta fun�ao retiro os tesouros que nao podem ser acessados, utilizand o
  // vetor da fun�ao confere rota

  for (i = 0; i < qntdtes; i++) {
    if (tesourosacessiveis[i] == 0) {
      aux1 = postes[0][i];
      aux2 = postes[1][i];
      ilha[aux1][aux2] = '#';
    }
    if (tesourosacessiveis[i] == 1) {
      aux1 = postes[0][i];
      aux2 = postes[1][i];
      ilha[aux1][aux2] = '!';
    }
  }

  return ilha;
}

int **conferteilha(char **ilha, int linhas, int colunas) {

  int i, j;
  int **ilhaaux;

  // fun�ao auxiliar que conferte a ilha de char para uma ilha de inteiros,
  // onde cada possi�ao da ilha recebe um valor diferente
  //@=1;!=2;.=0;#=*=~=-1;
  // esta fun�ao tem a utilidade para que possa ser implementado o metodo de
  // enxame como foi passado na aula

  ilhaaux = (int **)malloc(sizeof(int *) * linhas);
  for (i = 0; i < linhas; i++) {
    ilhaaux[i] = (int *)malloc(sizeof(int) * colunas);
  }

  for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++) {

      if (ilha[i][j] == '#' || ilha[i][j] == '*' || ilha[i][j] == '~') {
        ilhaaux[i][j] = -1;
      }
      if (ilha[i][j] == '.') {
        ilhaaux[i][j] = 0;
      }
      if (ilha[i][j] == '@') {
        ilhaaux[i][j] = 1;
      }
      if (ilha[i][j] == '!') {
        ilhaaux[i][j] = 2;
      }
    }
  }

  return ilhaaux;
}

int valordistancia(int **ilhaaux, int inilinha, int inicol, int fimlinha,
                   int fimcol, int linhas, int colunas) {

  int i, j;
  int **dist;

  // fun�ao de implementa�ao do metodo de enxame,
  // retorna o valor de um ponto ate o outro da matriz
  // utiliza uma matriz espelho da original completamente preenchida por
  //-1, e tem os valores emplementados a cada espa�o que seja possivel a
  // locomo�ao, ate chegar no ponto destino

  dist = (int **)malloc(sizeof(int *) * linhas);
  for (i = 0; i < linhas; i++) {
    dist[i] = (int *)malloc(sizeof(int) * colunas);
  }

  for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++) {
      dist[i][j] = -1;
    }
  }

  // Definir a dist�ncia do ponto inicial como 0
  dist[inilinha][inicol] = 0;

  int houve_mudanca = 1;

  // Repetir at� que n�o haja mais mudan�as nas dist�ncias
  while (houve_mudanca) {
    houve_mudanca = 0;

    // Percorrer toda a matriz do labirinto
    for (i = 0; i < linhas; i++) {
      for (j = 0; j < colunas; j++) {
        // Verificar se � um caminho acess�vel (valor >= 0) na matriz do
        // labirinto
        if (ilhaaux[i][j] >= 0) {
          // Verificar se a dist�ncia atualizada � menor do que a
          // dist�ncia anterior
          if (i > 0 && dist[i - 1][j] == -1 && dist[i][j] != -1) {
            dist[i - 1][j] = dist[i][j] + 1;
            houve_mudanca = 1;
          }
          if (i < linhas - 1 && dist[i + 1][j] == -1 && dist[i][j] != -1) {
            dist[i + 1][j] = dist[i][j] + 1;
            houve_mudanca = 1;
          }
          if (j > 0 && dist[i][j - 1] == -1 && dist[i][j] != -1) {
            dist[i][j - 1] = dist[i][j] + 1;
            houve_mudanca = 1;
          }
          if (j < colunas - 1 && dist[i][j + 1] == -1 && dist[i][j] != -1) {
            dist[i][j + 1] = dist[i][j] + 1;
            houve_mudanca = 1;
          }
        }
      }
    }
  }

  // Retornar a dist�ncia do ponto inicial at� o ponto final
  return dist[fimlinha][fimcol];
}

int **distancias(int **ilhaaux, int linhas, int colunas, int qntdtes,
                 int **postesouros, int linhaini, int colunaini) {

  // provavelmente a fun�ao que me deu mais trabalho
  // utilizando o metodo de enxame obtive o valor da distancia de cada tesouro
  // ate o jack sparrow, e o valor da distancia de cada tesouro entre si,
  // formando assim uma matriz de adjascencia, onde a primeira linha tem os
  // valores da distncia de jack sparrow ate cada tesouro e assim sucessivamente
  // para cada tesouro,como no exemplo abaixo
  /*
     [0][5][6]
    [5][0][9]
    [6][9][0]
  */

  int i = 0, j = 0;
  int **matdistancias;
  int **cordenadasaux;

  cordenadasaux = (int **)malloc(sizeof(int *) * 2);
  for (i = 0; i < 2; i++) {
    cordenadasaux[i] = (int *)malloc(sizeof(int) * (qntdtes + 1));
  }

  cordenadasaux[0][0] = linhaini;
  cordenadasaux[1][0] = colunaini;

  for (j = 1; j < (qntdtes) + 1; j++) {
    cordenadasaux[0][j] = postesouros[0][j - 1];
    cordenadasaux[1][j] = postesouros[1][j - 1];
  }

  matdistancias = (int **)malloc(sizeof(int *) * (qntdtes + 1));
  for (i = 0; i < (qntdtes + 1); i++) {
    matdistancias[i] = (int *)malloc(sizeof(int) * (qntdtes + 1));
  }

  for (i = 0; i < (qntdtes + 1); i++) {
    for (j = 0; j < (qntdtes + 1); j++) {

      matdistancias[i][j] = valordistancia(
          ilhaaux, cordenadasaux[0][i], cordenadasaux[1][i],
          cordenadasaux[0][j], cordenadasaux[1][j], linhas, colunas);
    }
  }

  free(cordenadasaux);
  return matdistancias;
}

void hora_gastas(int **matriz, int tam) {
  int *inseridos = (int *)malloc(sizeof(int) * tam);
  int *caminho = (int *)malloc(sizeof(int) * (tam + 1));
  int i, j;
  int min, proxcaminho;
  int horas = 0;

  for (i = 0; i < tam; i++) {
    inseridos[i] = FALSE;
  }
  inseridos[0] = TRUE;

  caminho[0] = 0;

  for (i = 1; i < tam; i++) {
    min = GRANDE;
    proxcaminho = 0;

    for (j = 0; j < tam; j++) {
      if (inseridos[j] == FALSE && min > matriz[caminho[i - 1]][j] &&
          caminho[i - 1] != j) {
        min = matriz[caminho[i - 1]][j];
        proxcaminho = j;
      }
    }

    inseridos[proxcaminho] = TRUE;
    caminho[i] = proxcaminho;
  }

  caminho[tam] = 0;

  for (i = 0; i < tam + 1; i++) {
    //  printf("%d->", caminho[i]);
    horas += matriz[caminho[i]][caminho[i + 1]];
  }

  printf("\nhoras: %d", horas);

  free(inseridos);
  free(caminho);
}

int main() {

  char **ilha;
  int linhaini, colunaini;
  int qntdtesini = 0;
  int qntdtesreal = 0;
  int linhas, colunas;
  int j = 0, i = 0;
  char c;
  int **postesouros;
  int *tesourosacessiveis;
  int cont = 0;
  char nomearq[20];
  int **ilhaaux;
  int **matadjascencia;

  printf("qual o nome do arquivo de entrada, meu nobre?");
  fgets(nomearq, 20, stdin);
  nomearq[strlen(nomearq) - 1] = '\0';

  FILE *arq = fopen(nomearq, "r");
  if (arq == NULL) {
    printf("\nnao foi possivel ler o arquivo");
  }

  while (linhas != 0 || colunas != 0) {
    cont++;
    fscanf(arq, "%d %d\n", &linhas, &colunas);
    if (linhas == 0 && colunas == 0) {
      // se o programa ler 0 0 no fim do arquivo, ja retorna 0

      fclose(arq);
       printf("\nacabou, meu nobre ;)...");
      return 13;
    }
    ilha = (char **)malloc(sizeof(char *) * linhas);
    for (i = 0; i < linhas; i++) {
      ilha[i] = (char *)malloc(sizeof(char) * colunas);
    }

    for (i = 0; i < linhas; i++) {
      for (j = 0; j < colunas; j++) {
        c = fgetc(arq);
        if (c == '.') {
          c = ' ';
          ilha[i][j] = c;
        }
        ilha[i][j] = c;
        if (c == '@') {
          linhaini = i;
          colunaini = j;
        }
      }
      fscanf(arq, "\n");
    }

    /*
     printf("\nilha antes do tratamento\n");
         imprimiilha(ilha, linhas, colunas);
    */

    qntdtesini = quantidadetes(ilha, linhas, colunas);

    ilha = tratarmatriz(ilha, linhas, colunas);

    qntdtesreal = quantidadetes(ilha, linhas, colunas);

    postesouros = achartesouros(ilha, linhas, colunas, qntdtesreal);

    tesourosacessiveis = confererota(ilha, linhas, colunas, qntdtesreal,
                                     postesouros, linhaini, colunaini);

    ilha = tiratesourosinacessiveis(ilha, postesouros, tesourosacessiveis,
                                    qntdtesreal);

    /*
         printf("\nilha depois do tratamento\n");
             imprimiilha(ilha, linhas, colunas);
   */

    qntdtesreal = quantidadetes(ilha, linhas, colunas);

    postesouros = achartesouros(ilha, linhas, colunas, qntdtesreal);

    if (qntdtesini != qntdtesreal) {

      printf("\nilha %d \n-1", cont);

      ilhaaux = conferteilha(ilha, linhas, colunas);

      matadjascencia = distancias(ilhaaux, linhas, colunas, qntdtesreal,
                                  postesouros, linhaini, colunaini);

      //	imprimiilhaint(matadjascencia,qntdtesreal+1,qntdtesreal+1);

      hora_gastas(matadjascencia, qntdtesreal + 1);
    }

    if (qntdtesini == qntdtesreal) {

      printf("\nilha %d \n1", cont);

      ilhaaux = conferteilha(ilha, linhas, colunas);

      matadjascencia = distancias(ilhaaux, linhas, colunas, qntdtesini,
                                  postesouros, linhaini, colunaini);

      //  imprimiilhaint(matadjascencia,qntdtesini+1,qntdtesini+1);

      hora_gastas(matadjascencia, qntdtesini + 1);
    }
      free(ilha);
      free(ilhaaux);
      free(matadjascencia);
      free(tesourosacessiveis);
      free(postesouros);
  
  }
}

