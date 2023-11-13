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


int Metodos::pedirMatricula()
{
    int matricula;
    cout << "Matrícula:" << endl;
    cin >> matricula;
    cin.ignore(); // Limpa o caractere de nova linha deixado no buffer de entrada
    return matricula;
}

string Metodos::pedirCurso()
{
    string curso;
    cout << "Curso:" << endl;
    getline(cin, curso);
    return curso;
}

string Metodos::pedirDisciplina()
{
    string disciplina;
    cout << "Disciplina:" << endl;
    getline(cin, disciplina);
    return disciplina;
}

string Metodos::pedirCodigoDaProva()
{
    string codigoDaProva;
    cout << "Código da Prova:" << endl;
    getline(cin, codigoDaProva);
    return codigoDaProva;
}

float Metodos::pedirNota()
{
    float nota;
    cout << "Nota:" << endl;
    cin >> nota;
    cin.ignore(); // Limpa o caractere de nova linha deixado no buffer de entrada
    return nota;
}
