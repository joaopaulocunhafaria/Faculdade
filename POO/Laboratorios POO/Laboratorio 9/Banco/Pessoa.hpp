#ifndef PESSOA_HPP
#define PESSOA_HPP
#include <iostream>
using namespace std;

class Pessoa
{
private:
    string nome;
    string cpf;

public:
    std::string getCpf();
    std::string getNome();
    Pessoa(string nome,string cpf);
    //~Pessoa();
};

#endif
