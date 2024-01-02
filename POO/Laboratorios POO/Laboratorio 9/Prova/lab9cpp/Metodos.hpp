#ifndef METODOS_HPP
#define METODOS_HPP
#include <iostream>
using namespace std;

class Metodos
{
public:
    Metodos();
    ~Metodos();
    string PedirNome();
    string pedirCpf();
    string pedirNumeroConta();
    string pedirAgencia();
    static int pedirMatricula();
    static std::string pedirCurso();
    static std::string pedirDisciplina();
    static std::string pedirCodigoDaProva();
    static float pedirNota();
};

#endif