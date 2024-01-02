#include "TesteStack.hpp"

TesteStack::TesteStack()
{
    top = NULL;
   
    piso = NULL;
}
TesteStack::~TesteStack()
{

    Teste *aux = top;

    while (aux != NULL)
    {
        aux = aux->getNext();
        delete top;
        top = aux;
    }
}

Teste *TesteStack::getTop()
{
    return top;
}

bool TesteStack::isEmpty()
{
    return (top == NULL);
}

void TesteStack::pop()
{
    if (isEmpty())
    {
        cout << "A pilha esta vazia!" << endl;
        return;
    }
    else if (top->getNext() == NULL)
    {
        Teste *aux = top;
        top = NULL;
        piso = NULL;
       
        delete aux;

        return;
    }
    else
    {
        Teste *aux = top;
        top = top->getNext();
        delete aux;
        return;
    }
}
void TesteStack::push(string disciplina, string codigoDaProva, float nota, Student *Aluno)
{

    Teste *teste = new Teste(disciplina, codigoDaProva, nota, Aluno);

    if (isEmpty())
    {

        top = teste;
        piso = teste;
        teste->setNext(NULL);
    }
    else
    {
        teste->setNext(top);
        top = teste;
    }
    cout << endl
         << endl
         << endl;
    teste->imprimirTeste();
    cout << endl
         << endl
         << endl;

    cout << "Prova adicionada a pilha!" << endl;
}
void TesteStack::printTop()
{
    if (isEmpty())
    {

        cout << "A pilha esta vazia!" << endl;
    }
    else
    {
        cout << endl
             << endl
             << "Prova do topo:" << endl;

        getTop()->imprimirTeste();
    }
}
