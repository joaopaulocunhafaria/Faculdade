#ifndef TESTE_HPP
#define TESTE_hpp
#include "Student.hpp"

class Teste
{
private:
    string disciplina;
    string codigoDaProva;
    float nota;
    Student *Aluno;
    Teste *next;

public:
    Teste(string disciplina,
          string codigoDaProva,
          float nota,
          Student *Aluno);
    Teste *getNext();
    void setNext(Teste *t);
    void imprimirTeste();
    string getDisciplina();

    string getCodigoDaProva();

    float getNota();

    Student *getAluno();
};

#endif