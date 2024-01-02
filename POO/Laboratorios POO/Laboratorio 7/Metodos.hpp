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
    string PedirEndereco();
    string PedirCurso();
    string PedirTitulacao();
    int PedirMatricula();
    int PedirCh();

};

#endif