#include "FilaBanco.hpp"
#include "ClienteBanco.hpp"
#include "Metodos.hpp"
using namespace std;
Metodos m;

int main()
{

    FilaBanco fila;

    while (true)
    {

        string op;
        cout << "1-Adicionar" << endl;
        cout << "2-Remover" << endl;
        cout << "3-Listar todos" << endl;
        cout << "4-Checar" << endl;
        cout << "5-Adicionar com prioridade" << endl;
        cout << "6-Sair" << endl;
        getline(cin, op);

        char opçao = op[0];
        switch (opçao)
        {
        case '1':
        {
            cout << "1-Adicionar" << endl;

            string nome = m.PedirNome();
            string cpf = m.pedirCpf();
            string agencia = m.pedirAgencia();
            string numeroConta = m.pedirNumeroConta();

            fila.insert(false, numeroConta, agencia, nome, cpf);
        }
        break;

        case '2':
        {

            fila.remove();
        }
        break;

        case '3':
        {

            fila.printAllFiles();
        }
        break;

        case '4':
        {
            if (fila.empty())
            {
                cout << "A fila esta vazia!" << endl;
            }
            else
            {
                cout << "A fila nao esta vazia!" << endl;
            }
        }
        break;

        case '5':
        {

            cout << "1-Adicionar" << endl;

            string nome = m.PedirNome();
            string cpf = m.pedirCpf();
            string agencia = m.pedirAgencia();
            string numeroConta = m.pedirNumeroConta();

            fila.insertPriority(true, numeroConta, agencia, nome, cpf);
        }
        break;

        case '6':
        {

            fila.~FilaBanco();
            cout << "Saindo..." << endl;
            return 0;
            
        }
        break;
        default:
            break;
        }
    }

    return 0;
}
