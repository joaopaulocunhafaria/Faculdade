#ifndef CLIENTEBANCO_HPP
#define CLIENTEBANCO_HPP
#include "Pessoa.hpp"
#include <iostream>


class ClienteBanco: public Pessoa
{
private:
    bool prioridade;
    ClienteBanco* next;
    string NumeroDaConta;
    string agencia;

public:

    bool getPrioridade();
    void imprimirCliente();
    ClienteBanco * getNext();
    void setNext(ClienteBanco * p);
    string getNumeroConta();
    string getAgencia();
    ClienteBanco(bool prioridade, string NumeroDaConta, string agencia, string nome, string cpf);
    //~ClienteBanco();

};

#endif