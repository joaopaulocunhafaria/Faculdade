#include "Autor.hpp"
#include <iostream>

Autor::Autor(const std::string& nome, const std::string& dataNascimento)
    : nome(nome), dataNascimento(dataNascimento) {}

void Autor::mostrarAutor() const {
    std::cout << "Nome do Autor: " << nome << std::endl;
    std::cout << "Data de Nascimento: " << dataNascimento << std::endl;
}
