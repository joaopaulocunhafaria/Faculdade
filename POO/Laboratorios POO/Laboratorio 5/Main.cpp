#include <iostream>
#include "Document.hpp"
#include "DocumentsLine.hpp"

using namespace std;

int main()
{

    DocumentsLine l;

    while (true)
    {
        int opcao = 0;

        cout << "\n1-inserir novo documento na fila";
        cout << "\n2-Excluir documento da fila";
        cout << "\n3-Checar se a fila esta vazia";
        cout << "\n4- Conferir documento(usando ID)";
        cout << "\n5-Mostrar todos documentos";
        cout << "\n6-Alterar documento";
        cout << "\n7-Sair do programa\n\n";
        cin >> opcao;

        switch (opcao)
        {
        case 1:

        {

            string Nome;
            int qntPag;
            int prioridade;
            char a = cin.get();
            cout << "Digite o nome do arquivo:\n";
            getline(cin, Nome);

            cout << "\nQuantidade de paginas:\n";
            cin >> qntPag;
            do
            {
                cout << "\nPrioridade na fila(1-Maior prioridade, 3-Menor prioridade):\n";

                cin >> prioridade;
            } while (prioridade < 0 || prioridade > 3);

            l.insert(prioridade, qntPag, Nome);

            break;
        }

        case 2:
        {
            int id;
            cout << "Digite o ID do documento a ser excluido:\n";
            cin >> id;

            l.remove(id);
        }

        break;

        case 3:
            if (l.empty())
            {

                cout << "\n\nA fila esta vazia!\n\n";
            }
            else
            {
                cout << "\nA fila nao esta vazia!!\n";
            }

            break;

        case 4:

        {

            int id;

            cout << "\n\nDigite o ID do documento:\n";
            cin >> id;

            l.check(id);
        }

        break;
        case 5:

            l.printAllFiles();

            break;
        case 6:
        {
            int id;
            cout << "\nDigite o ID do documento a ser alterado!\n";
            cin >> id;

            l.alterar(id);
        }

        break;
        case 7:

            cout << "\nSaindo...\n";
             //l.~DocumentsLine();
            //  chamar destrutor
            return 0;
            break;

        default:

            cout << "\nOpçao invalida!";

            break;
        }
    }
}
