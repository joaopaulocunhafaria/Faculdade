#ifndef AUTOR_HPP
#define AUTOR_HPP

#include <string>

class Autor {
private:
    std::string nome;
    std::string dataNascimento;

public:
    Autor(const std::string& nome, const std::string& dataNascimento);
    void mostrarAutor() const;
};

#endif
