#include "Student.hpp"
#include <iostream>
using namespace std;


 Student::Student(){}


Student::Student(string nome, string cpf, int matricula, string curso) : Pessoa(nome, cpf)
{

    this->curso = curso;
    this->matricula = matricula;
}

void Student::imprimirAluno()
{

    cout << "Nome : " << getNome() << endl;
    cout << "Cpf : " << getCpf() << endl;
    cout << "Matricula : " << getMatricula() << endl;
    cout << "Curso : " << getCurso() << endl;
}



int Student::getMatricula(){
    return matricula;
}

string Student::getCurso(){
    return curso;
}