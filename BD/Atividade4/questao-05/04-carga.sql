
INSERT INTO Cliente (nome, descricao, logradouro, cidade, complemento, numero) VALUES
('Loja Aquarela', 'Cliente de produtos infantis', 'Rua das Flores', 'São Paulo', 'Sala 2', '101'),
('Comercial Lima', 'Cliente do ramo alimentício', 'Av. Brasil', 'Rio de Janeiro', 'Bloco B', '202'),
('Mercado Verde', 'Supermercado local', 'Rua Central', 'Belo Horizonte', 'Fundos', '303'),
('Distribuidora Norte', 'Distribui materiais de limpeza', 'Av. Norte', 'Manaus', 'Galpão 1', '404'),
('Farmácia Boa Saúde', 'Farmácia de bairro', 'Rua das Árvores', 'Salvador', 'Loja 5', '505'),
('Empório Sabor Natural', 'Venda de produtos naturais', 'Rua Harmonia', 'Curitiba', 'Box 3', '606'),
('Padaria Doce Trigo', 'Padaria e confeitaria', 'Av. Trigo', 'Porto Alegre', 'Frente', '707'),
('Laticínios Bela Vista', 'Fornecedor de laticínios', 'Rua Leite', 'Brasília', 'Galpão 2', '808'),
('Casa da Carne', 'Açougue de bairro', 'Rua Boiadeiro', 'Fortaleza', 'Box 4', '909'),
('Pet Shop Amigo Fiel', 'Loja de artigos para pets', 'Rua dos Animais', 'Recife', 'Loja 1', '100');

INSERT INTO Pedido (data_criacao, situacao_entrega, cliente) VALUES
('2025-05-01 09:00:00', 'Entregue', 1),
('2025-05-02 10:30:00', 'Em trânsito', 2),
('2025-05-03 08:45:00', 'Pendente', 3),
('2025-05-04 11:00:00', 'Entregue', 4),
('2025-05-05 14:20:00', 'Cancelado', 5),
('2025-05-06 13:15:00', 'Entregue', 6),
('2025-05-07 15:00:00', 'Pendente', 7),
('2025-05-08 12:40:00', 'Em trânsito', 8),
('2025-05-09 16:10:00', 'Entregue', 9),
('2025-05-10 10:05:00', 'Entregue', 10);

INSERT INTO Item (nome, descricao, preco) VALUES
('Pacote de Arroz 5kg', 'Arroz branco tipo 1', 26.50),
('Feijão Carioca 1kg', 'Feijão tipo 1 embalado a vácuo', 8.90),
('Shampoo 400ml', 'Shampoo anticaspa com extrato natural', 14.20),
('Sabão em Pó 1kg', 'Sabão para roupas brancas', 10.75),
('Biscoito Recheado 120g', 'Biscoito sabor chocolate', 3.50),
('Leite Integral 1L', 'Leite longa vida', 5.20),
('Iogurte Natural 170g', 'Iogurte sem açúcar', 2.90),
('Pão de Forma 500g', 'Pão integral sem casca', 7.80),
('Carne Moída 1kg', 'Carne bovina moída de primeira', 35.00),
('Ração para Cães 10kg', 'Ração seca para cães adultos', 89.90);

INSERT INTO ListaItem (item, pedido) VALUES
(1, 1),
(2, 2),
(3, 3),
(4, 4),
(5, 5),
(6, 6),
(7, 7),
(8, 8),
(9, 9),
(10, 10);
