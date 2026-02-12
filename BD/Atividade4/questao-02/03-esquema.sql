CREATE TABLE IF NOT EXISTS Aluno (
  matricula VARCHAR(10) PRIMARY KEY,
  nome_completo VARCHAR(256) NOT NULL,
  cpf VARCHAR(11) UNIQUE NOT NULL,
  data_nascimento DATE NOT NULL,
  curso VARCHAR(60) NOT NULL,
  logradouro VARCHAR(60) NOT NULL,
  cidade VARCHAR(60) NOT NULL,
  complemento VARCHAR(60) NOT NULL,
  numero VARCHAR(8) NOT NULL,
  email VARCHAR(60) NOT NULL,
);


  
 
CREATE TABLE IF NOT EXISTS telefone(
    aluno_id VARCHAR(10),
    telefone CHAR(11),
    PRIMARY KEY (aluno_id,telefone),
    CONSTRAINT fk_telefone
    FOREIGN KEY (aluno_id) REFERENCES Aluno(matricula)
    ON DELETE CASCADE
    ON UPDATE CASCADE
);
