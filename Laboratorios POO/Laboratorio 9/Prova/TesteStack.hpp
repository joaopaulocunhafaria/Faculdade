#ifndef TESTESTACK_HPP
#define TESTESTACK_HPP
#include "Teste.hpp"

class TesteStack
{
private:
    Teste *top;
    Teste *next;
    Teste *piso;

public:
    TesteStack();
    ~TesteStack();

    bool isEmpty();
    void pop();
    void push(string disciplina,string codigoDaProva,  float nota, Student *Aluno);
    void printTop();
    Teste* getTop();
};

#endif