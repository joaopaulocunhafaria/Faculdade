#include "Teste.hpp"
#include <iostream>
using namespace std;

Teste::Teste(string disciplina,
             string codigoDaProva,
             float nota,
             Student *Aluno)
{
    this->disciplina = disciplina;
    this->codigoDaProva = codigoDaProva;
    this->nota = nota;
    this->Aluno = Aluno;
}

Teste *Teste::getNext()
{
    return next;
}

void Teste::setNext(Teste *t)
{

    this->next = t;
}

void Teste::imprimirTeste()
{
    cout << "Disciplina: " << getDisciplina() << endl;

    cout << "Codigo da prova: " << getCodigoDaProva() << endl;
    cout << "Nota : " << getNota() << endl;
    cout << "Aluno : " << endl; 
    this->Aluno->imprimirAluno(); 
}
 string Teste::getDisciplina() {
        return disciplina;
    }

    std::string Teste::getCodigoDaProva() {
        return codigoDaProva;
    }

    float Teste::getNota() {
        return nota;
    }

    Student* Teste::getAluno() {
        return Aluno;
    }