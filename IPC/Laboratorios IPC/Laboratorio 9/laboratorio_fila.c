#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo
{

    char nome[80];
    char cpf[20];
    int pref;
    struct nodo *prox;
};

struct fila
{

    struct nodo *inicio;
    struct nodo *fim;
};

void liberarfila(struct fila *fila)
{

    struct nodo *aux;

    while (fila->inicio != NULL)
    {

        aux = fila->inicio;

        fila->inicio = fila->inicio->prox;

        free(aux);
    }
    free(fila);
}
struct fila *criar_fila()
{

    struct fila *f = (struct fila *)malloc(sizeof(struct fila));

    f->inicio = NULL;
    f->fim = NULL;

    return f;
}

int fila_vazia(struct fila *f)
{
    if (f != NULL)
    { // Verifica se a fila existe
        return f->inicio ==
               NULL; // Retorna 1 se o início da fila for NULL, 0 caso contrário
    }
    else
    { // Se a fila não existe, retorna-1
        return -1;
    }
}

void imprimifila(struct fila *fila)
{

    struct nodo *p;
    int cont = 0;
    p = fila->fim;

    if (fila_vazia(fila))
    {
        printf("\na fila esta vazia!!\n");
        return;
    }
    else
    {

        while (p->prox != NULL)
        {

            cont++;
            printf("\npessoa %d\nnome:%s\ncpf:%s", cont, p->nome, p->cpf);
            if (p->pref == 0)
            {
                printf("\npessoa nao preferencial!!\n");
            }
            if (p->pref == 1)
            {
                printf("\npessoa preferencial!!\n\n");
            }
            p = p->prox;
        }
    }
}

void inserir(struct fila *fila, char *cpf, char *nome)
{

    if (fila != NULL)
    {

        struct nodo *no = (struct nodo *)malloc(sizeof(struct nodo));
        if (no == NULL)
        { // Verifica se a alocação foi bem sucedida
            printf("Erro na alocação de memória.\n");
            exit(1);
        }
        strcpy(no->nome, nome);
        strcpy(no->cpf, cpf);
        no->pref = 0;
        no->prox = NULL;

        if (fila_vazia(fila))
        {

            fila->fim = no;
            fila->inicio = no;
            
        }

        else
        {

            fila->fim->prox = no;
            fila->fim = no;
            fila->fim->prox = NULL;
        }
    }
    printf("\ncadastro feito com sucesso!!\n\n");
}

void inserir_preferencial(struct fila *fila, char *nome, char *cpf)
{

    struct nodo *aux, *no;
    //   printf("\ncadastro preferencia feito!!\n");

    if (fila != NULL)
    {
        no = (struct nodo *)malloc(sizeof(struct nodo));

        strcpy(no->nome, nome);
        strcpy(no->cpf, cpf);
        no->pref = 1;

        if (fila_vazia(fila))
        {

            fila->fim = no;
            fila->inicio = no;
            no->prox = NULL;
            printf("\ncadastro preferenciaL feito!!\n");

            printf("\npreferencial %d!!\n", fila->inicio->pref);

            return;
        }
        else
        {

            if (fila->inicio->pref == 1)
            { // se ja tiver algum preferencial

                aux = fila->inicio;

                while (aux->prox->pref != 0)
                {

                    aux = aux->prox;
                }

                // o erro esta aqui, concertar amanha

                no->prox = aux->prox;
                aux->prox = no;

                printf("\npreferencial %d!!\n", fila->inicio->pref);

                printf("\ncadastro preferenciaL feito!!\n");
                return;
            }
            if (fila->inicio->pref == 0)
            { // se ainda nao tiver nenhum preferencial

                no->prox = fila->inicio;
                fila->inicio = no;

                printf("\ncadastro preferenciaL feito!!\n");
            }
        }
    }
}

void excluir(struct fila *fila)
{

    struct nodo *aux;
    if (fila_vazia(fila))
    {

        printf("\nA fila esta vazia, nao ha como excluir!\n");
        return;
    }
    aux = fila->inicio;
    fila->inicio = fila->inicio->prox;

    free(aux);
    printf("\nelemento excluido com sucesso!!\n");
    if (fila_vazia(fila))
    {
        printf("\nagora a fila esta vazia!!\n");
        fila->fim = NULL;
    }
}

int main()
{

    int opcao;
    char cpf[15];
    char nome[80];
    struct fila *f = criar_fila();

    do
    {

        printf("\nEscolha uma opção:\n");
        printf("1 - Inserir na fila\n");
        printf("2 - Remover da fila\n");
        printf("3 - Imprimir a fila\n4- inserir preferencial\n5- conferir se esta "
               "vazia\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:

            liberarfila(f);
            printf("\n\nsaindo...\n");
            return 0;
            break;

        case 1:

            getchar();
            printf("\n\ndigite o nome:");
            fgets(nome, 80, stdin);
            nome[strlen(nome) - 1] = '\0';
            printf("\ndigite o cpf:");
            fgets(cpf, 15, stdin);
            cpf[strlen(cpf) - 1] = '\0';

            inserir(f, cpf, nome);

            break;

        case 2:

            excluir(f);
            break;
        case 3:
            imprimifila(f);

            break;

        case 4:

            getchar();
            printf("\n\ndigite o nome:");
            fgets(nome, 80, stdin);
            nome[strlen(nome) - 1] = '\0';
            printf("\ndigite o cpf:");
            fgets(cpf, 15, stdin);
            cpf[strlen(cpf) - 1] = '\0';

            inserir_preferencial(f, nome, cpf);
            break;
        case 5:
            if (fila_vazia(f))
            {
                printf("\n\n A fila esta vazia!!\n\n");
            }
            else
            {
                printf("\nA fila nao esta vazia!!\n");
            }
            break;
        default:
            break;
        }
    } while (opcao != 0);
    liberarfila(f);
    return 0;
}
