#include <cstddef>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

#include <mariadb/mysql.h>


// Dados para conexão
const std::string HOST     = "200.128.142.185";
const int PORT             = 3306;
const std::string DATABASE = "agenda";
const std::string USER     = "root";
const std::string PASSWORD = "123456";

// Estrutura para armazenar os dados de contato
struct Contato {
    int id;
    std::string nome;
    std::string email;
    std::vector<std::string> telefones;
};

void inserir_contato(MYSQL* connection, Contato contato);

std::vector<Contato> buscar_todos_contatos(MYSQL* connection);

Contato buscar_contato(MYSQL* connection, int id);


int main (int argc, char** argv) {

    // Cria a estrutura que mantém a conexão com o banco de dados.
    MYSQL* connection = mysql_init(NULL);    
    if (connection == NULL) {
        std::cerr << "Ocorreu um erro ao inicializar a estrutura para conexão ao banco de dados." << std::endl;
        std::cerr << "Erro: " << mysql_error(connection) << std::endl;
        return EXIT_FAILURE;
    }

    // Estabele a conexão com o banco de dados.
    if (!mysql_real_connect(connection, HOST.c_str(), USER.c_str(), PASSWORD.c_str(), DATABASE.c_str(), PORT, NULL, 0)) {
        std::cerr << "Ocorreu um erro ao tentar estabelecer uma conexão com o banco de dados." << std::endl;
        std::cerr << "Erro: " << mysql_error(connection) << std::endl;
        mysql_close(connection);
        return EXIT_FAILURE;
    } else {
        std::cout << "Conexão ao banco de dados estabelecida com sucesso!" << std::endl;
    }

    // Inserção de dados
    Contato novo_contato = {
        -1, 
        "Gilber k Chesterton", 
        "chesterton@gemail.com",
        {  }
    };

    inserir_contato(connection, novo_contato);

    // Busca de um contato pelo ID
    std::vector<Contato> contatos = buscar_todos_contatos(connection);

    std::cout << std::endl;
    std::cout << "Todos os contatos encontrados:" << std::endl;
    for (const auto& contato : contatos) {
        std::cout << "ID: " << contato.id << std::endl;
        std::cout << "Nome: " << contato.nome << std::endl;
        std::cout << "E-mail: " << contato.email << std::endl;
        std::cout << "Telefones: " << std::endl;
        for (const auto& telefone : contato.telefones) {
            std::cout << telefone << std::endl;
        }
        std::cout << std::endl;
    }

    // Encerra a conexão com o banco de dados e libera recursos alocados
    mysql_close(connection);

    return EXIT_SUCCESS;
}


void inserir_contato(MYSQL* connection, Contato contato) {

    std::string query_contato = "INSERT INTO contato (nome, email) VALUES ('" + contato.nome + "', '" + contato.email + "')";

    if (mysql_query(connection, query_contato.c_str())) {
        std::cerr << "Ocorreu um erro ao tentar cadastrar o contato." << std::endl;
        std::cerr << "Erro: " << mysql_error(connection) << std::endl;
        return;
    }

    // Se inserido, obtém o valor do ID para inserir os telefones
    int id = mysql_insert_id(connection);

    // Insere os telefones do contato
    for (const auto& telefone : contato.telefones) {
        std::string query_telefone = "INSERT INTO contato_telefone (contato_id, telefone) VALUES (" + std::to_string(id) + ", '" + telefone + "')";
        if (mysql_query(connection, query_telefone.c_str())) {
            std::cerr << "Ocorreu um erro ao tentar cadastrar o telefone do contato." << std::endl;
            std::cerr << "Erro: " << mysql_error(connection) << std::endl;
        }
    }

}

Contato buscar_contato(MYSQL* connection, int id) {
    std::string query_contato = "SELECT id, nome, email FROM contato WHERE id = " + std::to_string(id);
    if (mysql_query(connection, query_contato.c_str())) {
        std::cerr << "Ocorreu um erro ao buscar o contato." << std::endl;
        std::cerr << "Erro: " << mysql_error(connection) << std::endl;
    }

    // Obtém os dados da consulta
    MYSQL_RES* result = mysql_use_result(connection);
    MYSQL_ROW linha = mysql_fetch_row(result);

    Contato contato;
    if (linha != NULL) {
        contato.id = std::atoi(linha[0]);
        contato.nome = linha[1];
        contato.email = linha[2];
    }

    // Libera os recursos alocados
    mysql_free_result(result);
    result = NULL;

    // Com o contato encontrado, busca os seus telefones
    std::string query_telefones = "SELECT telefone FROM contato_telefone WHERE contato_id = " + std::to_string(id);
    if (mysql_query(connection, query_telefones.c_str())) {
        std::cerr << "Ocorreu um erro ao buscar os telefones do contato." << std::endl;
        std::cerr << "Erro: " << mysql_error(connection) << std::endl;
    }

    result = mysql_use_result(connection);
    MYSQL_ROW linha_telefone;
    while ((linha_telefone = mysql_fetch_row(result)) != NULL) {
        contato.telefones.push_back(std::string(linha_telefone[0]));
    }

    // Libera os recursos alocados
    mysql_free_result(result);

    return contato;
}


std::vector<Contato> buscar_todos_contatos(MYSQL* connection) {
    std::vector<Contato> contatos;

    // Consulta para buscar todos os contatos
    std::string query_contato = "SELECT id, nome, email FROM contato";
    if (mysql_query(connection, query_contato.c_str())) {
        std::cerr << "Ocorreu um erro ao buscar os contatos." << std::endl;
        std::cerr << "Erro: " << mysql_error(connection) << std::endl;
        return contatos;
    }

    // Obtém os dados da consulta
    MYSQL_RES* result = mysql_use_result(connection);
    MYSQL_ROW linha;

    while ((linha = mysql_fetch_row(result)) != NULL) {
        Contato contato;
        contato.id = std::atoi(linha[0]);
        contato.nome = linha[1];
        contato.email = linha[2];

        // Busca os telefones do contato
        std::string query_telefones = "SELECT telefone FROM contato_telefone WHERE contato_id = " + std::to_string(contato.id);
        if (mysql_query(connection, query_telefones.c_str())) {
            std::cerr << "Ocorreu um erro ao buscar os telefones do contato com ID " << contato.id << "." << std::endl;
            std::cerr << "Erro: " << mysql_error(connection) << std::endl;
        } else {
            MYSQL_RES* telefones_result = mysql_use_result(connection);
            MYSQL_ROW linha_telefone;
            while ((linha_telefone = mysql_fetch_row(telefones_result)) != NULL) {
                contato.telefones.push_back(std::string(linha_telefone[0]));
            }
            mysql_free_result(telefones_result);
        }

        contatos.push_back(contato);
    }

    // Libera os recursos alocados
    mysql_free_result(result);

    return contatos;
}