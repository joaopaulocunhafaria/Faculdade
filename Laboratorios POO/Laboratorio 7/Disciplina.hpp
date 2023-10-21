#ifndef DISCIPLINA_HPP
#define DISCIPLINA_HPP
#include "Professor.hpp"
#include <iostream>

class Disciplina
{
private:
    string nome;
    int Ch;
    Professor professor;

public:
    Disciplina(string nome, int Ch, Professor p);
    Disciplina();
    void ImprimirDados();
};

#endif