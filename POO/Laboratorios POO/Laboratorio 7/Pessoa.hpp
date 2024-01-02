#ifndef PESSOA_HPP
#define PESSOA_HPP
#include <iostream>
using namespace std;

class Pessoa
{
protected:
string nome;
string endereco;

public: 
    Pessoa();
    Pessoa(string nome,string endereco);
};


#endif