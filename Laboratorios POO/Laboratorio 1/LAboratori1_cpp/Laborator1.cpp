#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void substitui()
{
    char ch, caracter1 = '_', caracter2 = '*';

    ifstream arquivoEntrada("entrada.txt");
    ofstream arquivoSaida("saida.txt");

    if (!arquivoEntrada || !arquivoSaida)
    {
        cout<< "\nNao foi possivel abrir o arquivo";
        return;
    }

    int aux = 0;

    cout << "Lendo do arquivo de entrada!\n";

    while (arquivoEntrada.get(ch))
    {
        cout << ch;
        if (ch == caracter1 && aux == 0)
        {
            arquivoSaida << "<i>";
            aux = 1;
        }
        else if (ch == caracter1 && aux == 1)
        {
            arquivoSaida << "</i>";
            aux = 0;
        }
        else if (ch == caracter2 && aux == 0)
        {

            arquivoSaida << "<b>";
            aux = 1;
        }
        else if (ch == caracter2 && aux == 1)
        {
            arquivoSaida << "</b>";
            aux = 0;
        }
        else if (ch != caracter1 && ch != caracter2)
        {
            arquivoSaida << ch;
        }
    }
    arquivoEntrada.close();
    arquivoSaida.close();

    ifstream outFile("saida.txt");
    cout << "\nLendo do arquivo de saida!\n";

    while (outFile.get(ch))
    {

        cout << ch;
    }
    outFile.close();
}

int main()
{

    substitui();
    return 0;
}