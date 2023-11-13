#include "Metodos.hpp"

Metodos::Metodos() {}

Metodos::~Metodos() {}

string Metodos::PedirNome()
{
    string nome;
    cout << "Nome:" << endl;
    getline(cin, nome);
    return nome;
}

string Metodos::pedirCpf()
{
    string cpf;
    cout << "CPF:" << endl;
    getline(cin, cpf);
    return cpf;
}

string Metodos::pedirNumeroConta()
{
    string numeroConta;
    cout << "Número da Conta:" << endl;
    getline(cin, numeroConta);
    return numeroConta;
}

string Metodos::pedirAgencia()
{
    string agencia;
    cout << "Agência:" << endl;
    getline(cin, agencia);
    return agencia;
}
