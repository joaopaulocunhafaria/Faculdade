#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct livro
{
    char titulo[80];
    int isbn;

    struct livro *prox;
} livro;

typedef struct pilha
{
    struct livro *topo;
} pilha;

pilha *criarpilha()
{

    pilha *p = (struct pilha *)malloc(sizeof(struct pilha));

    p->topo = NULL;
    return p;
}

int pilha_vazia(pilha *pilha)
{
    if (pilha->topo == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};

void adicionar(pilha *pilha, char *titulo, int isbn)
{

    int cont = 0;
    livro *aux, *no = (struct livro *)malloc(sizeof(struct livro));

    strcpy(no->titulo, titulo);
    no->isbn = isbn;

    if (pilha_vazia(pilha))
    {

        no->prox = NULL;
        pilha->topo = no;

        printf("\nLivro adicionado cm sucesso!!\n");
        printf("\nTitulo: %s\nISBN: %d\n", no->titulo, no->isbn);
    }
    else
    {

        no->prox = pilha->topo;
        pilha->topo = no;

        printf("\nTitulo: %s\nISBN: %d\n", no->titulo, no->isbn);
        printf("\nLivro adicionado cm sucesso!!\n");
    }

    aux = pilha->topo;
    while (aux->prox != NULL)
    {
        cont++;
        aux = aux->prox;
    }
    printf("Tem  %d livros na pilha\n", cont + 1);
}

void excluir(pilha *pilha)
{

    livro *aux;

    if (pilha_vazia(pilha))
    {

        printf("\nA pilha esta vazia!!\n");

        return;
    }
    else
    {
        aux = pilha->topo;

        pilha->topo = pilha->topo->prox;
        printf("\nLivro excluido com sucesso!!\n");
        printf("\nO livro excluido foi\n%s\nSeu ISBN:%d ", aux->titulo, aux->isbn);

        free(aux);
        if (pilha_vazia(pilha))
        {

            printf("\nAgora a pilha esta vazia\n");
            return;
        }
    }

    aux = pilha->topo;
    int cont = 0;
    while (aux->prox != NULL)
    {
        cont++;
        aux = aux->prox;
    }
    printf("\n Restam %d livros na pilha\n", cont + 1);
}

void imprimitopo(pilha *pilha)
{

    if (!pilha_vazia(pilha))
    {

        printf("\nO livro do topo eh %s\nISBN: %d\n", pilha->topo->titulo, pilha->topo->isbn);
        return;
    }
    else
    {

        printf("\nA pilha esta vazia!!\n");
        return;
    }
}

void esfaziar_pilha(pilha *pilha)
{

    livro *aux;

    while (aux->prox != NULL)
    {
        aux = pilha->topo;
        pilha->topo = aux->prox;
        free(aux);
        aux = pilha->topo;
    }
    free(pilha);
}

int main()
{

    int opcao;
    char titulo[80];
    int isbn;

    pilha *pilha = criarpilha();

    while (1)
    {
        printf("\nSELECIONE A OPCAO");
        printf("\n1- Adicionar livros na pilha");
        printf("\n2- Excluir livros da pilha");
        printf("\n3- Imprimir o livro do topo da pilha");
        printf("\n4- Conferir se a pilha esta vazia");
        printf("\n0- Sair\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            printf("\nSaindo...\n");

            esfaziar_pilha(pilha);
            return 0;

            break;
        case 1:
            getchar();
            printf("\n Digite o titulo do livro: \n");
            fgets(titulo, 80, stdin);
            printf("\nDigite o ISBN:");
            scanf("%d", &isbn);
            getchar();

            adicionar(pilha, titulo, isbn);
            break;

        case 2:

            excluir(pilha);
            break;
        case 3:
            imprimitopo(pilha);
            break;

        case 4:

            if (pilha_vazia(pilha))
            {

                printf("\nA pilha esta vazia!!\n");
            }
            else
            {

                printf("\nA pilha NAO esta vazia!!\n");
            }
            break;

        default:
            printf("\nOpcao invalida!!\n");
            break;
        }
    }

    return 0;
}