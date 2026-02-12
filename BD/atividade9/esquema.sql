DROP DATABASE IF EXISTS agenda;
CREATE DATABASE IF NOT EXISTS agenda;
USE agenda;

CREATE TABLE contato (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(64) NOT NULL,
    email VARCHAR(128)
);

CREATE TABLE contato_telefone (
    contato_id INT NOT NULL,
    telefone CHAR(11) NOT NULL,
    PRIMARY KEY (contato_id, telefone),
    CONSTRAINT FOREIGN KEY (contato_id) REFERENCES contato (id)
);
