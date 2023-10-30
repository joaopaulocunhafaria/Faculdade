#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenar_numeros(int numeros[], int tamanho) {
   
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (numeros[j] > numeros[j + 1]) {
                int aux = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = aux;
            }
        }
    }
}

void gerar_numeros_aleatorios(char *nome_arquivo) {
    int quantidade;
    printf("Digite a quantidade de números a serem gerados: ");
    scanf("%d", &quantidade);

    // Abrid o arquivo para escrita
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return;
    }

    // Gerar números aleatórios e escrever no arquivo
    srand(time(NULL)); 
  //time(NULL), para gerar numeros diferentesa cada execuçao 

  for (int i = 0; i < quantidade; i++) {
        int numero = rand() % 100; 
    // Gera um número aleatório entre 0 e 99
        fprintf(arquivo, "%d ", numero);
    }

    fclose(arquivo);

    printf("Números gerados e escritos no arquivo com sucesso.\n");
}

void ordenar_arquivo(char *nome_arquivo_entrada, char *nome_arquivo_saida) {
    // Abrir o arquivo de entrada para leitura
    FILE *arquivo_entrada = fopen(nome_arquivo_entrada, "r");
    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return;
    }

    // Ler os números do arquivo e armazená-los em um vetor
    int tamanho = 0;
    int *numeros = NULL;
    int numero;
    while (fscanf(arquivo_entrada, "%d", &numero) == 1) {
        tamanho++;
        numeros = (int *)realloc(numeros, tamanho * sizeof(int));
        numeros[tamanho - 1] = numero;
    }

    // Fechar o arquivo de entrada
    fclose(arquivo_entrada);

    // Ordenar o vetor de números
    ordenar_numeros(numeros, tamanho);

    // Abrir o arquivo de saída para escrita
    FILE *arquivo_saida = fopen(nome_arquivo_saida, "w");
    if (arquivo_saida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        free(numeros);
        return;
    }

    // Escrever os números ordenados no arquivo de saída
    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo_saida, "%d ", numeros[i]);
    }

    // Fechar o arquivo de saída
    fclose(arquivo_saida);

    // Liberar a memória alocada para o vetor
    free(numeros);

    printf("Números ordenados e escritos no arquivo de saída com sucesso.\n");
}

int main() {
    char nome_arquivo_entrada[100];
    char nome_arquivo_saida[100];

    printf("Gerar números aleatórios e salvá-los em um arquivo.\n");
    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arquivo_entrada);

    gerar_numeros_aleatorios(nome_arquivo_entrada);

    printf("\nOrdenar números e salvar em um novo arquivo.\n");
    //printf("Digite o nome do arquivo de entrada: ");
    //scanf("%s", nome_arquivo_entrada);

    printf("Digite o nome do arquivo de saída: ");
    scanf("%s", nome_arquivo_saida);

    ordenar_arquivo(nome_arquivo_entrada, nome_arquivo_saida);

    return 0;
}
