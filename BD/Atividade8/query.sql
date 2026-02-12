CREATE TABLE IF NOT EXISTS Alunos(
    matricula INT  AUTO_INCREMENT PRIMARY KEY,
        nome VARCHAR(80) NOT NULL,
        cpf VARCHAR(11) NOT NULL UNIQUE,
        curso VARCHAR(80) NOT NULL
    );

    CREATE TABLE IF NOT EXISTS Professores(
        matricula INT  AUTO_INCREMENT PRIMARY KEY,
        nome VARCHAR(80) NOT NULL,
        cpf VARCHAR(11) NOT NULL UNIQUE,
        dept VARCHAR(80) NOT NULL
    );

    INSERT INTO Alunos( nome, cpf, curso) VALUES
    ('Ana', '123', 'Computação'),
    ( 'João', '456', 'Moda'),
    ( 'Maria', '789', 'Física'),
    ( 'Carlos', '987', 'Quimica'),
    ( 'Pedro', '654', 'Computação');


    INSERT INTO Professores( nome, cpf, dept) VALUES
    ('Maria', '789', 'Formação Geral'),
    ( 'Pedro', '999', 'Computação'),
    ( 'João', '456', 'Formação Geral'),
    ( 'Eduardo', '111', 'Moda');