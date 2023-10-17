#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP
#include <iostream>
#include "Pessoa.hpp"
using namespace std;

class Professor: public Pessoa
{
private:
    string titulacao;
    string curso;

public:
       Professor( string titulacao, string curso,string nome, string endereco);
 Professor();
    void ImprimirDados();
    string getNome();
};

#endif