
 
CREATE TABLE IF NOT EXISTS Registro(
    id  INT PRIMARY KEY,
    horario_entrada DATETIME NOT NULL,
    horario_saida DATETIME NOT NULL,
    tipo_pagamento VARCHAR(8) NOT NULL,
    tarifa INT NOT NULL,
    veiculo VARCHAR(8),
    CONSTRAINT fk_veiculo
    FOREIGN KEY (veiculo) REFERENCES Veiculo(id)
    ON DELETE CASCADE
    ON UPDATE CASCADE
);


CREATE TABLE IF NOT EXISTS Veiculo(
    placa VARCHAR(8) PRIMARY KEY,
    categoria  VARCHAR(5) NOT NULL,
    telefone  VARCHAR(15) NOT NULL
);

