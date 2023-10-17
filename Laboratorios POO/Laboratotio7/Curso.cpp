#include "Curso.hpp"
#include "Professor.hpp"
#include "Aluno.hpp"
#include "Disciplina.hpp"
#include <iostream>
#include <vector>
using namespace std;

Curso::Curso(string nome)
{
    this->nome = nome;
}

Curso::~Curso() {}

void Curso::CadastrarProfessor(Professor p)
{

    professor.push_back(p);
}
void Curso::CadastrarAluno(Aluno a)
{
    aluno.push_back(a);
}

void Curso::CadastrarDisciplina(Disciplina d)
{
    disciplina.push_back(d);
}

void Curso::ImprimirListaDeAlunos()
{
    if (!aluno.empty())
    {

        for (int i = 0; i < aluno.size(); i++)
        {
            aluno.at(i).ImprimirDados();
        }
    }
    else
    {
        cout << "Não ha Alunos cadastrados!";
    }
}

void Curso::ImprimirListaDeProfessor()
{

    if (!professor.empty())
    {

        for (int i = 0; i < professor.size(); i++)
        {
            professor.at(i).ImprimirDados();
        }
    }
    else
    {
        cout << "Nao ha professores cadastrados!";
    }
}
void Curso::ImprimirListaDeDisciplina()
{

    if (!disciplina.empty())
    {
        for (int i = 0; i < disciplina.size(); i++)
        {

            disciplina.at(i).ImprimirDados();
        }
    }
}

bool Curso::vincularProfessor(string nome)
{

    if (!professor.empty())
    {

        for (int i = 0; i < professor.size(); i++)
        {

            if (professor.at(i).getNome() == nome)
            {
                return true;
            }
        }
    }
    else
    {
        cout << "Nao ha professores cadastrados!" << endl;
        return false;
    }
}

Professor Curso::getProfessores(string nome)
{

    for (int i = 0; i < professor.size(); i++)
    {

        if (professor.at(i).getNome() == nome)
        {
            Professor p = professor.at(i);
            return p;
        }
    }
}

Curso::~Curso()
{
    if (!professor.empty())
    {
        for (int i = 0; i < professor.size(); i++)
        {

            professor.erase(professor.begin() + i);
        }
    }


    if (!aluno.empty())
    {
        for (int i = 0; i < aluno.size(); i++)
        {

            aluno.erase(aluno.begin() + i);
        }
    }


    if (!disciplina.empty())
    {
        for (int i = 0; i < disciplina.size(); i++)
        {

            disciplina.erase(disciplina.begin() + i);
        }
    }



}
