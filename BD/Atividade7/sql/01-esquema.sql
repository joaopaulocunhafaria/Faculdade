-- DROP DATABASE IF EXISTS olimpiadas;
-- CREATE DATABASE IF NOT EXISTS olimpiadas;
-- USE olimpiadas;

CREATE TABLE comites (
    id CHAR(3) PRIMARY KEY,
    pais VARCHAR(128) NOT NULL, 
    observacoes VARCHAR(256)
);

CREATE TABLE edicoes (
    id INT PRIMARY KEY,
    nome VARCHAR(256) NOT NULL,
    ano INT NOT NULL,
    cidade VARCHAR(128) NOT NULL,
    inverno BOOLEAN NOT NULL
);

CREATE TABLE esportes (
    id INT PRIMARY KEY,
    modalidade VARCHAR(128) NOT NULL,
    categoria VARCHAR(128)
);

CREATE TABLE participacoes (
    edicao_id INT NOT NULL,
    esporte_id INT NOT NULL,
    comite_id CHAR(3) NOT NULL,
    ouro BOOLEAN NOT NULL,
    prata BOOLEAN NOT NULL,
    bronze BOOLEAN NOT NULL,
    CONSTRAINT PRIMARY KEY (edicao_id, esporte_id, comite_id),
    CONSTRAINT fk_participacoes_edicoes FOREIGN KEY (edicao_id) REFERENCES edicoes (id),
    CONSTRAINT fk_participacoes_esportes FOREIGN KEY (esporte_id) REFERENCES esportes (id),
    CONSTRAINT fk_participacoes_comite FOREIGN KEY (comite_id) REFERENCES comites (id)
);
