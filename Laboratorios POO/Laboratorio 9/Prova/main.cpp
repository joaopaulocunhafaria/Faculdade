#include "TesteStack.hpp"
#include "Metodos.hpp"
#include <iostream>

// g++ main.cpp  Metodos.hpp Pessoa.hpp Metodos.cpp Pessoa.cpp Student.cpp Student.hpp Teste.cpp Teste.hpp TesteStack.cpp TesteStack.hpp -o meu_programa

using namespace std;
Metodos m;

int main()
{

    TesteStack* pilha  = new TesteStack();

    while (true)
    {

        string op;
        cout << "1-Empilhar" << endl;
        cout << "2-Remover" << endl;
        cout << "3-Imprimir topo" << endl;
        cout << "4-Verificar se a pilha esta vazia" << endl;
        cout << "5-Sair" << endl;
        getline(cin, op);
   
        char opçao = op[0];
        switch (opçao)
        {
        case '1':
        { 
             cout << "Dados do aluno->" << endl;
            string nome = m.PedirNome();
            string cpf = m.pedirCpf();

            int matricula = m.pedirMatricula();
            string curso = m.pedirCurso();

            cout << "Dados da prova->" << endl;

            string disciplina = m.pedirDisciplina();
            string codigoDaProva = m.pedirCodigoDaProva();
            float nota = m.pedirNota();

            Student *student = new Student(nome, cpf, matricula, curso);
            pilha->push(disciplina, codigoDaProva, nota, student);
        }
        break;

        case '2':
        {

            pilha->pop();
        }
        break;

        case '3':
        {
         
            pilha->printTop();
        
        }
        break;

        case '4':
        {
            if (pilha->isEmpty())
            {
                cout << "A pilha esta vazia!" << endl;
            }
            else
            {
                cout << "A pilha nao esta vazia!" << endl;
            }
        }

        break;

        case '5':
        {

            pilha->~TesteStack();
            cout << "Saindo..." << endl;
            return 0;
        }
        break;

            break;
        default:
            break;
        }
    }

    return 0;
}
