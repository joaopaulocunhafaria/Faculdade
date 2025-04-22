-- Criação do banco de dados.
-- Caso já exista, o banco de dados será apagado.
--DROP DATABASE IF EXISTS lista_tarefas;
--CREATE DATABASE IF NOT EXISTS lista_tarefas;


-- Seleção do banco de dados.
--USE lista_tarefas;


-- Criação da tabela `tarefas`.
CREATE TABLE tarefas (
  id INT PRIMARY KEY AUTO_INCREMENT,
  descricao VARCHAR(256) NOT NULL,
  data_criacao TIMESTAMP NOT NULL,
  data_limite TIMESTAMP,
  finalizado BOOLEAN NOT NULL DEFAULT FALSE 
);
