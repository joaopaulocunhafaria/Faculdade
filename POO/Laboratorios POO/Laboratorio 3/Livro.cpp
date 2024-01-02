#include "Livro.hpp"
#include <iostream>

Livro::Livro(const std::string& titulo, const std::string& ISBN, const Autor& autor)
    : titulo(titulo), ISBN(ISBN), autor(autor) {}

void Livro::mostrarLivro() const {
    std::cout << "Título do Livro: " << titulo << std::endl;
    std::cout << "ISBN: " << ISBN << std::endl;
    autor.mostrarAutor();
}

const std::string& Livro::getTitulo() const {
    return titulo;
}
