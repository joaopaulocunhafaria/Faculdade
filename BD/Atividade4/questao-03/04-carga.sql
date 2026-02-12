
INSERT INTO Livro (id, nome, titulo) VALUES
(1, 'George Orwell', '1984'),
(2, 'J.K. Rowling', 'Harry Potter e a Pedra Filosofal'),
(3, 'Machado de Assis', 'Dom Casmurro'),
(4, 'J.R.R. Tolkien', 'O Senhor dos Anéis'),
(5, 'Clarice Lispector', 'A Hora da Estrela'),
(6, 'Gabriel García Márquez', 'Cem Anos de Solidão'),
(7, 'Stephen King', 'O Iluminado'),
(8, 'Sun Tzu', 'A Arte da Guerra'),
(9, 'Yuval Noah Harari', 'Sapiens'),
(10, 'Mary Shelley', 'Frankenstein');



INSERT INTO Mutuario (id, nome, telefone, email) VALUES
(1, 'Ana Paula Souza', '11987654321', 'ana.souza@email.com'),
(2, 'Bruno Martins', '21976543210', 'bruno.martins@email.com'),
(3, 'Carlos Eduardo Silva', '31999887766', 'carlos.silva@email.com'),
(4, 'Daniela Oliveira', '41988776655', 'daniela.oliveira@email.com'),
(5, 'Eduardo Lima', '51977665544', 'eduardo.lima@email.com'),
(6, 'Fernanda Costa', '11966554433', 'fernanda.costa@email.com'),
(7, 'Gustavo Rocha', '48955443322', 'gustavo.rocha@email.com'),
(8, 'Helena Andrade', '71944332211', 'helena.andrade@email.com'),
(9, 'Igor Dias', '61933221100', 'igor.dias@email.com'),
(10, 'Juliana Ramos', '81922110099', 'juliana.ramos@email.com');

INSERT INTO Emprestimo (id, data_devolucao, data_emprestimo, livro, mutuo) VALUES
(1, '2025-05-20', '2025-05-10', 1, 1),
(2, '2025-05-21', '2025-05-11', 2, 2),
(3, '2025-05-22', '2025-05-12', 3, 3),
(4, '2025-05-23', '2025-05-13', 4, 4),
(5, '2025-05-24', '2025-05-14', 5, 5),
(6, '2025-05-25', '2025-05-15', 6, 6),
(7, '2025-05-26', '2025-05-16', 7, 7),
(8, '2025-05-27', '2025-05-17', 8, 8),
(9, '2025-05-28', '2025-05-18', 9, 9),
(10, '2025-05-29', '2025-05-19', 10, 10);

