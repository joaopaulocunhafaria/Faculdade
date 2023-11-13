#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "Pessoa.hpp"

class Student : public Pessoa
{
private:
    int matricula;
    string curso;

public:
    Student();
    Student(string nome, string cpf, int matricula, string curso);
    void imprimirAluno();

    int getMatricula();

    string getCurso();
};

#endif