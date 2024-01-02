#ifndef ALUNO_HPP
#define ALUNO_HPP
#include "Pessoa.hpp"

class Aluno : public Pessoa
{
protected:
int matricula;

public:

 Aluno(int matricula, string nome , string endereco);
void ImprimirDados();

};



#endif