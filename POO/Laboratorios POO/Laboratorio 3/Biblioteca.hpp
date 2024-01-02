#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include "Livro.hpp"
#include <vector>

class Biblioteca {
private:
    std::vector<Livro> livros;

public:
    Biblioteca();
    void adicionarLivro(const Livro& livro);
    void buscarLivro(const std::string& titulo) const;
    void mostrarLivros() const;
};

#endif
