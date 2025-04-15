
--Questão 1
SELECT * 
FROM contato
ORDER BY nome ASC;

--Questão 2
SELECT nome,email,telefone 
FROM contato
ORDER BY nome ASC;


--Questão 3
SELECT nome
FROM contato
ORDER BY nome DESC;

--Questão 4
SELECT nome
FROM contato
WHERE telefone IS NULL
ORDER BY nome DESC;

--Questão 5
SELECT nome,telefone
FROM contato
WHERE telefone LIKE "__9%"
ORDER BY nome ASC;


--Questão 6
SELECT nome,telefone
FROM contato
WHERE telefone NOT LIKE "__9%"
ORDER BY nome ASC;


--Questão 7
SELECT nome,telefone,endereco
FROM contato
WHERE endereco LIKE "%Belo Horizonte"
ORDER BY nome ASC;

--Questão 8
SELECT nome,email
FROM contato
WHERE email LIKE "%@protonmail.com"
ORDER BY nome ASC;

--Questão 9
SELECT *
FROM contato
WHERE nome IS NOT NULL AND telefone IS NOT NULL AND email IS NOT NULL AND endereco IS NOT NULL 
ORDER BY nome ASC;


--Questão 9
SELECT *
FROM contato
WHERE nome LIKE "Bruna%"
ORDER BY nome ASC;

