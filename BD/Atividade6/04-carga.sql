INSERT INTO Usuario (email, senha, nome, pais, logradouro, cidade, complemento, número) VALUES
('ana@email.com', 'senha123', 'Ana Souza', 'Brasil', 'Rua A', 'São Paulo', 'Apto 101', 10),
('bruno@email.com', 'senha123', 'Bruno Lima', 'Brasil', 'Rua B', 'Rio de Janeiro', NULL, 25),
('carla@email.com', 'senha123', 'Carla Dias', 'Portugal', 'Av. Central', 'Lisboa', 'Bloco 2', 200),
('daniel@email.com', 'senha123', 'Daniel Costa', 'Brasil', 'Rua D', 'Curitiba', NULL, 45),
('elisa@email.com', 'senha123', 'Elisa Martins', 'Brasil', 'Av. Paulista', 'São Paulo', 'Sala 5', 1000),
('felipe@email.com', 'senha123', 'Felipe Braga', 'Brasil', 'Rua F', 'Recife', NULL, 12),
('giovana@email.com', 'senha123', 'Giovana Rios', 'Portugal', 'Rua das Laranjeiras', 'Porto', 'Casa 3', 88),
('heitor@email.com', 'senha123', 'Heitor Lopes', 'Brasil', 'Av. Brasil', 'Belo Horizonte', NULL, 321),
('isabela@email.com', 'senha123', 'Isabela Cunha', 'Brasil', 'Rua I', 'Florianópolis', 'Apto 302', 90),
('joao@email.com', 'senha123', 'João Pedro', 'Brasil', 'Av. JK', 'Brasília', NULL, 555);

INSERT INTO telefone (usuario_id, telefone) VALUES
(1, '11912345678'),
(2, '21923456789'),
(3, '351912345678'),
(4, '41987654321'),
(5, '11987654321'),
(6, '81912345678'),
(7, '351934567890'),
(8, '31923456789'),
(9, '48998765432'),
(10, '61987654321');


INSERT INTO Mensagem (usuario_id, corpo_mensagem, titulo, data_criacao) VALUES
(1, 'Olá! Tudo bem?', 'Saudações', '2025-06-01 10:00:00'),
(2, 'Lembrete da reunião.', 'Reunião', '2025-06-01 10:05:00'),
(3, 'Você recebeu um presente.', 'Notificação', '2025-06-01 10:10:00'),
(4, 'Nova atualização disponível.', 'Atualização', '2025-06-01 10:15:00'),
(5, 'Feliz aniversário!', 'Parabéns', '2025-06-01 10:20:00'),
(6, 'Sua entrega chegou.', 'Entrega', '2025-06-01 10:25:00'),
(7, 'Agende sua consulta.', 'Consulta', '2025-06-01 10:30:00'),
(8, 'Pagamento confirmado.', 'Pagamento', '2025-06-01 10:35:00'),
(9, 'Evento cancelado.', 'Aviso', '2025-06-01 10:40:00'),
(10, 'Obrigado por participar.', 'Agradecimento', '2025-06-01 10:45:00');


INSERT INTO Relacao (Seguidor_Id, Seguido_Id) VALUES
(1, 2),
(2, 3),
(3, 1),
(4, 5),
(5, 4),
(6, 1),
(7, 8),
(8, 9),
(9, 10),
(10, 7);
