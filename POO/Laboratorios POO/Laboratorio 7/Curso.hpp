
#ifndef CURSO_HPP
#define CURSO_HPP
#include "Professor.hpp"
#include "Aluno.hpp"
#include "Disciplina.hpp"
#include <vector>
#include <iostream>

class Curso
{
private:
    string nome;

    vector<Professor> professor;
    vector<Aluno> aluno;
    vector<Disciplina> disciplina;

public:
    Curso(string nome);
    ~Curso();
    void CadastrarProfessor(Professor p);
    void CadastrarAluno(Aluno a);
    void CadastrarDisciplina(Disciplina d);
    void ImprimirListaDeAlunos();
    void ImprimirListaDeProfessor();
    void ImprimirListaDeDisciplina();
    bool vincularProfessor(string nome);
    Professor getProfessores(string nome);
};

#endif