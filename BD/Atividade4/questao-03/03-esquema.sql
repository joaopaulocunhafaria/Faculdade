
 
CREATE TABLE IF NOT EXISTS Livro(
    id  INT PRIMARY KEY,
    nome  VARCHAR(60) NOT NULL,
    titulo  VARCHAR(60) NOT NULL
);


CREATE TABLE IF NOT EXISTS Mutuario(
    id  INT PRIMARY KEY,
    nome  VARCHAR(60) NOT NULL,
    telefone  VARCHAR(15) NOT NULL,
    email  VARCHAR(60) NOT NULL
);

CREATE TABLE IF NOT EXISTS Emprestimo (
  id  INT PRIMARY KEY,
  data_devolucao DATE NOT NULL,
  data_emprestimo DATE NOT NULL,
  livro INT,
  mutuo int,
  CONSTRAINT fk_livro 
  FOREIGN KEY (livro) REFERENCES Livro(id)
  ON DELETE CASCADE
  ON UPDATE CASCADE,
  CONSTRAINT fk_mutuo 
  FOREIGN KEY (mutuo) REFERENCES Mutuario(id)
  ON DELETE CASCADE
  ON UPDATE CASCADE
  );


  