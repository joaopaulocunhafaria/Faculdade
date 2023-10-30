#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pessoa.h"

void cadastrarPessoa(struct Pessoa pessoas[]) {
    for (int i = 0; i < MAX_PESSOAS; i++) {
        if (pessoas[i].cpf[0] == '\0') {
            printf("Cadastro de Pessoa:\n");
            printf("Nome: ");
            fgets(pessoas[i].nome, sizeof(pessoas[i].nome), stdin);
            printf("Endereco: ");
            fgets(pessoas[i].endereco, sizeof(pessoas[i].endereco), stdin);
            printf("Telefone: ");
            fgets(pessoas[i].telefone, sizeof(pessoas[i].telefone), stdin);
            printf("Idade: ");
            scanf("%d", &pessoas[i].idade);
            getchar();  // Limpa o buffer do teclado
            printf("CPF: ");
            fgets(pessoas[i].cpf, sizeof(pessoas[i].cpf), stdin);
            printf("Pessoa cadastrada com sucesso!\n");
            return;
        }
    }
    printf("O limite de pessoas foi atingido. Impossivel cadastrar mais pessoas.\n");
}

void exibirPessoas(struct Pessoa pessoas[]) {
    printf("Lista de Pessoas:\n");
    for (int i = 0; i < MAX_PESSOAS; i++) {
        if (pessoas[i].cpf[0] != '\0') {
            printf("Pessoa %d:\n", i + 1);
            printf("Nome: %s", pessoas[i].nome);
            printf("Endereco: %s", pessoas[i].endereco);
            printf("Telefone: %s", pessoas[i].telefone);
            printf("Idade: %d\n", pessoas[i].idade);
            printf("CPF: %s", pessoas[i].cpf);
            printf("\n");
        }
    }
}

void excluirPessoa(struct Pessoa pessoas[]) {
    char cpf[12];
    printf("Digite o CPF da pessoa que deseja excluir: ");
    fgets(cpf, sizeof(cpf), stdin);

    for (int i = 0; i < MAX_PESSOAS; i++) {
        if (strcmp(pessoas[i].cpf, cpf) == 0) {
            pessoas[i].cpf[0] = '\0';  // Marca como vazio
            printf("Pessoa excluida com sucesso!\n");
            return;
        }
    }

    printf("Pessoa nao encontrada.\n");
}

void alterarPessoa(struct Pessoa pessoas[]) {
    char cpf[12];
    printf("Digite o CPF da pessoa que deseja alterar: ");
    fgets(cpf, sizeof(cpf), stdin);

    for (int i = 0; i < MAX_PESSOAS; i++) {
        if (strcmp(pessoas[i].cpf, cpf) == 0) {
            printf("Alteracao de Pessoa:\n");
            printf("Nome: ");
            fgets(pessoas[i].nome, sizeof(pessoas[i].nome), stdin);
            printf("Endereco: ");
            fgets(pessoas[i].endereco, sizeof(pessoas[i].endereco), stdin);
            printf("Telefone: ");
            fgets(pessoas[i].telefone, sizeof(pessoas[i].telefone), stdin);
            printf("Idade: ");
            scanf("%d", &pessoas[i].idade);
            getchar();  // Limpa o buffer do teclado
            printf("CPF: ");
            fgets(pessoas[i].cpf, sizeof(pessoas[i].cpf), stdin);
            printf("Pessoa alterada com sucesso!\n");
            return;
        }
    }

    printf("Pessoa nao encontrada.\n");
}

void salvarDados(struct Pessoa pessoas[]) {
    FILE *arquivo = fopen("pessoa.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar os dados.\n");
        return;
    }

    fwrite(pessoas, sizeof(struct Pessoa), MAX_PESSOAS, arquivo);
    fclose(arquivo);
}

void carregarDados(struct Pessoa pessoas[]) {
    FILE *arquivo = fopen("pessoa.dat", "rb");
    if (arquivo == NULL) {
        printf("Nenhum dado encontrado. O arquivo pessoa.dat nao existe.\n");
        return;
    }

    fread(pessoas, sizeof(struct Pessoa), MAX_PESSOAS, arquivo);
    fclose(arquivo);
}
