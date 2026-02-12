CREATE TABLE IF NOT EXISTS Produto (
  id INT PRIMARY KEY AUTO_INCREMENT,
  nome VARCHAR(256) NOT NULL,
  preco_venda decimal(10,2) NOT NULL,
  preco_compra decimal(10,2) NOT NULL,
  qntd_estoque INT NOT NULL,
  descricao VARCHAR(256) NOT NULL
  );
  
 