#ifndef PESSOA_H
#define PESSOA_H

#define MAX_PESSOAS 100

struct Pessoa {
    char nome[50];
    char endereco[100];
    char telefone[15];
    int idade;
    char cpf[12];
};

void cadastrarPessoa(struct Pessoa pessoas[]);
void exibirPessoas(struct Pessoa pessoas[]);
void excluirPessoa(struct Pessoa pessoas[]);
void alterarPessoa(struct Pessoa pessoas[]);
void salvarDados(struct Pessoa pessoas[]);
void carregarDados(struct Pessoa pessoas[]);

#endif
