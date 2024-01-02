#include "Disciplina.hpp"
#include "Professor.hpp"
#include <iostream>
using namespace std;
 
     Disciplina::Disciplina(string nome,int Ch, Professor p){

        this->nome=nome;
        this->Ch=Ch;
        this->professor=p;

     }
     Disciplina::Disciplina(){}
 
    void  Disciplina::ImprimirDados(){
        cout << "Nome: "<<nome<<endl;
        cout << "Ch: "<<Ch<<endl;
        cout << "Professor: "<< endl;
        professor.ImprimirDados();
    }
