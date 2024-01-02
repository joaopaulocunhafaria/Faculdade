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

string Metodos::PedirEndereco()
{
    string endereco;
    cout << "Endereço:" << endl;
    getline(cin, endereco);
    return endereco;
}

string Metodos::PedirCurso()
{
    string curso;
    cout << "Curso:" << endl;
    getline(cin, curso);
    return curso;
}

string Metodos::PedirTitulacao()
{
    string titulacao;
    cout << "Titulação:" << endl;
    getline(cin, titulacao);
    return titulacao;
}

int Metodos::PedirMatricula()
{
    int matricula;
    cout << "Matricula:" << endl;
    cin >> matricula;
    getchar();
    return matricula;
}

int Metodos::PedirCh()
{
    int ch;
    cout   << "Ch:" << endl;
    cin >> ch;
    getchar();
    return ch;
}