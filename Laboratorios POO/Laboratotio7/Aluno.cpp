#include "Aluno.hpp"
#include "Pessoa.hpp"
#include <iostream>
using namespace std;



 Aluno:: Aluno(int matricula, string nome , string endereco)
:Pessoa(nome, endereco){
    this->matricula=matricula;
   
 }


void Aluno::ImprimirDados(){
    cout << "Aluno: "<<nome<<endl;
    cout << "Endereço: "<<endereco<<endl;
    cout << "Matricula: "<<matricula<<endl;
}