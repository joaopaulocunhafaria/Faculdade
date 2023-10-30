#include <stdio.h>
#include <stdlib.h>
#include "Pessoa.h"

int main() {
    struct Pessoa pessoas[MAX_PESSOAS];
    int opcao;

    carregarDados(pessoas);

    do {
        printf("\nMenu de Opcoes:\n");
        printf("1. Cadastrar pessoa\n");
        printf("2. Exibir todas as pessoas cadastradas\n");
        printf("3. Excluir pessoa\n");
        printf("4. Alterar pessoa\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();  // Limpa o buffer do teclado

        switch (opcao) {
            case 1:
                cadastrarPessoa(pessoas);
                break;
            case 2:
                exibirPessoas(pessoas);
                break;
            case 3:
                excluirPessoa(pessoas);
                break;
            case 4:
                alterarPessoa(pessoas);
                break;
            case 5:
                salvarDados(pessoas);
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida. Digite novamente.\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}
