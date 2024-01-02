#include <iostream>
#include "Autor.hpp"
#include "Livro.hpp"
#include "Biblioteca.hpp"

int main() {
    Biblioteca biblioteca;

    Autor autor1("Autor 1", "01/01/1980");
    Autor autor2("Autor 2", "15/03/1975");

    Livro livro1("Livro 1", "ISBN001", autor1);
    Livro livro2("Livro 2", "ISBN002", autor2);

    int escolha;
    std::string titulo;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1) Adicionar livro à biblioteca\n";
        std::cout << "2) Procurar um livro\n";
        std::cout << "3) Mostrar todos os livros da biblioteca\n";
        std::cout << "4) Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> escolha;

        switch (escolha) {
            case 1: {
                std::string nomeAutor, dataNascimento;
                std::string tituloLivro, ISBN;
                std::cin.ignore(); // Limpar o buffer de entrada
                std::cout << "Nome do Autor: ";
                getline(std::cin, nomeAutor);
                std::cout << "Data de Nascimento do Autor: ";
                getline(std::cin, dataNascimento);
                std::cout << "Título do Livro: ";
                getline(std::cin, tituloLivro);
                std::cout << "ISBN do Livro: ";
                getline(std::cin, ISBN);

                Autor autor(nomeAutor, dataNascimento);
                Livro livro(tituloLivro, ISBN, autor);

                biblioteca.adicionarLivro(livro);
                break;
            }
            case 2: {
                std::cout << "Digite o título do livro que deseja procurar: ";
                std::cin.ignore(); // Limpar o buffer de entrada
                getline(std::cin, titulo);
                biblioteca.buscarLivro(titulo);
                break;
            }
            case 3:
                biblioteca.mostrarLivros();
                break;
            case 4:
                return 0;
            default:
                std::cout << "Opção inválida. Tente novamente." << std::endl;
        }
    }

    return 0;
}
