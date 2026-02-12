USE agenda;

DROP TABLE IF EXISTS telefone;
DROP TABLE IF EXISTS Mensagem;
DROP TABLE IF EXISTS Relacao;
DROP TABLE IF EXISTS Usuario;

CREATE TABLE IF NOT EXISTS Usuario(
    id INT AUTO_INCREMENT PRIMARY KEY,
    email VARCHAR(255) NOT NULL,
    senha VARCHAR(255) NOT NULL,
    nome VARCHAR(255) NOT NULL,
    pais VARCHAR(50) NOT NULL,
    logradouro VARCHAR(255) NOT NULL,
    cidade VARCHAR(255) NOT NULL,
    complemento VARCHAR(255),
    número INT
);

CREATE TABLE IF NOT EXISTS telefone(
    usuario_id INT,
    telefone VARCHAR(15),
    PRIMARY KEY (usuario_id, telefone),
    CONSTRAINT fk_usuario_telefone FOREIGN KEY (usuario_id) REFERENCES Usuario(id)
);


CREATE TABLE IF NOT EXISTS Mensagem(
    usuario_id INT,
    corpo_mensagem VARCHAR(256) NOT NULL,
    titulo VARCHAR(50) NOT NULL,
    data_criacao DATETIME,
    PRIMARY KEY (usuario_id, data_criacao),
    CONSTRAINT fk_usuario_mensagem FOREIGN KEY (usuario_id) REFERENCES Usuario(id)
);



CREATE TABLE IF NOT EXISTS Relacao(
    Seguidor_Id INT,
    Seguido_Id INT,
    PRIMARY KEY (Seguido_Id, Seguidor_Id),
    CONSTRAINT fk_seguidor FOREIGN KEY (Seguidor_Id) REFERENCES Usuario(id),
    CONSTRAINT fk_seguido FOREIGN KEY (Seguido_Id) REFERENCES Usuario(id)
);