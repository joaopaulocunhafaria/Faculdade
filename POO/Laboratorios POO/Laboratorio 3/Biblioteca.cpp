#include "Biblioteca.hpp"
#include <iostream>

Biblioteca::Biblioteca() {}

void Biblioteca::adicionarLivro(const Livro& livro) {
    livros.push_back(livro);
    std::cout << "Livro adicionado à biblioteca." << std::endl;
}

void Biblioteca::buscarLivro(const std::string& titulo) const {
    bool encontrado = false;
    for (const Livro& livro : livros) {
        if (livro.getTitulo() == titulo) {
            livro.mostrarLivro();
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        std::cout << "Livro não encontrado na biblioteca." << std::endl;
    }
}

void Biblioteca::mostrarLivros() const {
    if (livros.empty()) {
        std::cout << "A biblioteca está vazia." << std::endl;
    } else {
        std::cout << "Livros na biblioteca:" << std::endl;
        for (const Livro& livro : livros) {
            livro.mostrarLivro();
            std::cout << "-------------------------" << std::endl;
        }
    }
}
