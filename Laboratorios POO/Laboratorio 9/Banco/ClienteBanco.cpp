
#include "ClienteBanco.hpp"
using namespace std;

ClienteBanco::ClienteBanco(bool prioridade, string NumeroDaConta, string agencia, string nome, string cpf):Pessoa(nome, cpf){
this->NumeroDaConta=NumeroDaConta;
this->agencia=agencia;
this->prioridade=prioridade;
}

bool ClienteBanco::getPrioridade(){
    return prioridade;
}
    

string ClienteBanco::getNumeroConta()
{
    return NumeroDaConta;
}

string ClienteBanco::getAgencia()
{
    return agencia;
}

ClienteBanco *ClienteBanco::getNext()
{
    return next;
}

void ClienteBanco::setNext(ClienteBanco *p)
{
    this->next = p;
}


void ClienteBanco::imprimirCliente(){
    cout << "Nome: "<< getNome()<<endl;

    cout << "cpf: "<< getCpf()<<endl;
    cout << "Numero da conta: "<< getNumeroConta()<<endl;
    cout << "Agencia: "<< getAgencia()<<endl<<endl;
;


}



/*string NumeroDaConta, string agencia, string nome, string cpf*/