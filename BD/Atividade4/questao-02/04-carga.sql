
INSERT INTO Aluno (matricula, nome_completo, cpf, data_nascimento, curso, logradouro, cidade, complemento, numero, email) VALUES
('A001', 'João Pedro Lima', '12345678901', '2000-05-20', 'Engenharia Civil', 'Rua das Flores', 'São Paulo', 'Apto 12B', '150', 'joao.lima@email.com'),
('A002', 'Maria Clara Souza', '23456789012', '1999-08-15', 'Direito', 'Av. Brasil', 'Rio de Janeiro', 'Casa', '101', 'maria.clara@email.com'),
('A003', 'Lucas Fernandes Rocha', '34567890123', '2001-02-10', 'Medicina', 'Rua Central', 'Belo Horizonte', 'Bloco A', '345', 'lucas.rocha@email.com'),
('A004', 'Ana Beatriz Silva', '45678901234', '1998-12-25', 'Arquitetura', 'Rua Nova', 'Curitiba', 'Apto 101', '200', 'ana.silva@email.com'),
('A005', 'Carlos Eduardo Almeida', '56789012345', '2002-03-30', 'Administração', 'Rua das Palmeiras', 'Porto Alegre', 'Casa', '89', 'carlos.almeida@email.com'),
('A006', 'Fernanda Oliveira Costa', '67890123456', '2000-07-12', 'Psicologia', 'Av. Paulista', 'São Paulo', 'Apto 903', '800', 'fernanda.costa@email.com'),
('A007', 'Rafael Gomes Martins', '78901234567', '2001-11-03', 'Engenharia da Computação', 'Rua do Sol', 'Florianópolis', 'Casa', '400', 'rafael.martins@email.com'),
('A008', 'Juliana Andrade Lopes', '89012345678', '1999-04-17', 'Enfermagem', 'Rua Verde', 'Salvador', 'Bloco B', '512', 'juliana.lopes@email.com'),
('A009', 'Bruno Henrique Dias', '90123456789', '2000-09-08', 'Educação Física', 'Av. das Nações', 'Brasília', 'Casa', '321', 'bruno.dias@email.com'),
('A010', 'Larissa Monteiro Ramos', '01234567890', '1998-06-22', 'Jornalismo', 'Rua Azul', 'Recife', 'Apto 305', '127', 'larissa.ramos@email.com');

INSERT INTO telefone (aluno_id, telefone) VALUES
('A001', '11987654321'),
('A002', '21996543210'),
('A003', '31999887766'),
('A004', '41988776655'),
('A005', '51977665544'),
('A006', '11966554433'),
('A007', '48955443322'),
('A008', '71944332211'),
('A009', '61933221100'),
('A010', '81922110099');