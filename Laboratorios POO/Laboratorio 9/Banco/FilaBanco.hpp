#ifndef FILABANCO_HPP
#define FILABANCO_HPP
#include <iostream>
#include "ClienteBanco.hpp"

class FilaBanco
{

private:
    ClienteBanco *tail;

    ClienteBanco *head;

public:

    FilaBanco();
    ~FilaBanco();
    bool empty();


    

    void insert(bool prioridade, string NumeroDaConta, string agencia, string nome, string cpf);    

    void insertPriority(bool prioridade, string NumeroDaConta, string agencia, string nome, string cpf);

    void remove();

    void printAllFiles();


    void alterar(int ID);
};

#endif