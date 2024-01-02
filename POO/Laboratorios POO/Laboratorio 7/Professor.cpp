#include "Professor.hpp"
#include <iostream>
using namespace std;

Professor::Professor() {}

Professor::Professor(string titulacao, string curso, string nome, string endereco) : Pessoa(nome, endereco)
{

    this->titulacao = titulacao;
    this->curso = curso;
}

void Professor::ImprimirDados()
{
    cout << "Professor: " << nome << endl;
    cout << "Titulaçao: " << titulacao << endl;
    cout << "Curso: " << curso << endl;
    cout << "Endereço: " << endereco << endl;
}

string Professor::getNome()
{
    return nome;
}