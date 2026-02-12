--Criar tabelas que modelem a relação de (N,N) entre as tabelas Projeto e Recurso

CREATE TABLE IF NOT EXISTS Projeto(
    id INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(256) NOT NULL
);

CREATE TABLE IF NOT EXISTS Recurso(
    id INT PRIMARY KEY AUTO_INCREMENT,
    descricao VARCHAR(256) NOT NULL
);


CREATE TABLE IF NOT EXISTS Utilizacao(
    projeto_id INT,
    recurso_id INT,
    quantidade INT NOT NULL,
    PRIMARY KEY(projeto_id,recurso_id),
    CONSTRAINT fk_projeto FOREIGN KEY (projeto_id) REFERENCES Projeto(id) 
    CONSTRAINT fk_recurso FOREIGN KEY (recurso_id) REFERENCES Recurso(id) 
);

INSERT INTO Projeto (nome) VALUES 
('GTA VI'),
('Switch II'),
('SIGAA 2');


INSERT INTO Recurso (descricao) VALUES 
('dinheiro'),
('programador'),
('Nvidia'),
('engenheiro');

INSERT INTO Utilizacao (projeto_id,recurso_id,quantidade) VALUES 
(1,1,2500000),
(1,2,2),
(2,3,4);

SELECT p.nome,count(u.projeto_id) AS q_projetos
FROM Projeto AS p
JOIN Utilizacao AS u ON p.id=u.projeto_id
JOIN Recurso AS r ON r.id=u.recurso_id; 