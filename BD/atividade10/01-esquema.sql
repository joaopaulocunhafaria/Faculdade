Criação do banco de dados
DROP DATABASE IF EXISTS brasileirao_2025;
CREATE DATABASE IF NOT EXISTS brasileirao_2025;
USE brasileirao_2025;

-- Tabela de Equipes
CREATE TABLE IF NOT EXISTS equipes (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(50) NOT NULL,
    estado CHAR(2) NOT NULL
);

-- Tabela de Estádios
CREATE TABLE IF NOT EXISTS estadios (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    cidade VARCHAR(50) NOT NULL,
    estado CHAR(2) NOT NULL
);

-- Tabela de Partidas
CREATE TABLE IF NOT EXISTS partidas (
    id INT AUTO_INCREMENT PRIMARY KEY,
    equipe_mandante_id INT NOT NULL,
    equipe_visitante_id INT NOT NULL,
    gols_mandante INT,
    gols_visitante INT,
    rodada INT NOT NULL,
    estadio_id INT,
    data_partida DATE,
    horario TIME,
    FOREIGN KEY (equipe_mandante_id) REFERENCES equipes(id),
    FOREIGN KEY (equipe_visitante_id) REFERENCES equipes(id),
    FOREIGN KEY (estadio_id) REFERENCES estadios(id)
);
