-- Questão 1

SELECT nome 
FROM Produto
WHERE nome IS NOT NULL;

-- Questão 2

SELECT 
  nome, 
  CONCAT(
    endereco_logradouro, ', ',
    endereco_numero, ', ',
    endereco_complemento, ' - ',
    endereco_cep, ' - ',
    endereco_cidade
  ) AS endereco_formatado
FROM contato
WHERE 
  endereco_logradouro IS NOT NULL AND
  endereco_numero IS NOT NULL AND
  endereco_complemento IS NOT NULL AND
  endereco_cep IS NOT NULL AND
  endereco_cidade IS NOT NULL;

-- Questão 3

SELECT c.nome, COUNT(t.id) AS n_tel
FROM contatos AS c 
LEFT JOIN telefones AS t
ON c.id = t.contato_id
GROUP BY c.id;

-- Questão 4

SELECT 
  c.nome, 
  GROUP_CONCAT(t.telefone SEPARATOR ', ') AS telefones
FROM contato AS c
LEFT JOIN contato_telefone AS t
  ON c.id = t.contato_id
GROUP BY c.id, c.nome;

-- Questão 5

SELECT 
  nome, 
  CONCAT(
    endereco_logradouro, ', ',
    endereco_numero, ', ',
    endereco_complemento, ' - ',
    endereco_cep, ' - ',
    endereco_cidade
  ) AS endereco_formatado
FROM contato
WHERE endereco_cidade LIKE "%São Paulo%";

-- Questão 6

SELECT 
  endereco_cidade, 
  COUNT(*) AS quantidade_contatos
FROM contato
WHERE endereco_cidade IS NOT NULL
GROUP BY endereco_cidade
ORDER BY endereco_cidade ASC;

-- Questão 7

  SELECT 
    c.nome, 
    CONCAT(
        endereco_logradouro, ', ',
        endereco_numero, ', ',
        endereco_complemento, ' - ',
        endereco_cep, ' - ',
        endereco_cidade
    ) AS endereco_formatado,
    GROUP_CONCAT(t.telefone SEPARATOR ', ') AS telefones
    FROM contato AS c
    LEFT JOIN contato_telefone AS t
    ON c.id = t.contato_id
    GROUP BY c.id, c.nome
	ORDER BY nome ASC
    LIMIT 10 OFFSET 20 ;
