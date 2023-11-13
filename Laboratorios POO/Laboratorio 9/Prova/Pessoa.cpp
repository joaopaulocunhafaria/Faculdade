#include "Pessoa.hpp"
using namespace std;

Pessoa::Pessoa(){}

Pessoa::Pessoa(string nome, string cpf)
{
    this->nome = nome;
    this->cpf = cpf;
}

string Pessoa::getCpf()
{
    return cpf;
}

string Pessoa::getNome()
{
    return nome;
}