INSERT INTO contato (nome, email, logradouro, numero, cidade) VALUES
('João da Silva', 'joao.silva@example.com', 'Rua das Flores', '123', 'Divinópolis');
INSERT INTO contato (nome, email, logradouro, numero, cidade) VALUES
('Maria Oliveira', 'maria.oliveira@example.com', 'Avenida Principal', '456', 'Divinópolis');
INSERT INTO contato (nome, email, logradouro, numero, cidade) VALUES
('Pedro Santos', 'pedro.santos@example.com', 'Praça Central', '789', 'Divinópolis');


SELECT * FROM contato;

#Inserir na tabela contato_telefone (que não possue delete cascade)
INSERT INTO contato_telefone (contato_id, telefone) VALUES
(1, '37999999999');
INSERT INTO contato_telefone (contato_id, telefone) VALUES
(2, '37988888888');
INSERT INTO contato_telefone (contato_id, telefone) VALUES
(2, '37911111111');
INSERT INTO contato_telefone (contato_id, telefone) VALUES
(3, '37922222222');

#Inserir registros na tabela telefone (que possue delete CASCADE)
INSERT INTO telefone (contato_id, telefone) VALUES
(4, '37999999999');
INSERT INTO telefone (contato_id, telefone) VALUES
(2, '37988888888');
INSERT INTO telefone (contato_id, telefone) VALUES
(2, '37911111111');
INSERT INTO telefone (contato_id, telefone) VALUES
(3, '37922222222');

DELETE FROM contato WHERE id = 5;

CREATE TABLE contato(
	id int primary key auto_increment,
    nome varchar(32) not null,
    email varchar(128),
    logradouro varchar(100),
    numero char(5),
    cidade varchar(100)
);

CREATE TABLE telefone(
    contato_id int,
    telefone CHAR(11),
    PRIMARY KEY (contato_id,telefone),
    CONSTRAINT fk_telefone
    FOREIGN KEY (contato_id) REFERENCES contato(id)
    ON DELETE CASCADE
    ON UPDATE CASCADE
);

CREATE TABLE contato_telefone(
	contato_id int,
    telefone char(11),
    constraint primary key (contato_id,telefone),
    constraint foreign key (contato_id) references contato(id)
    );
        