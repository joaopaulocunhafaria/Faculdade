#ifndef LIVRO_HPP
#define LIVRO_HPP

#include "Autor.hpp"
#include <string>

class Livro {
private:
    std::string titulo;
    std::string ISBN;
    Autor autor;

public:
    Livro(const std::string& titulo, const std::string& ISBN, const Autor& autor);
    void mostrarLivro() const;
    const std::string& getTitulo() const;
};

#endif
