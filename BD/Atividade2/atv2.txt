CREATE DATABASE IF NOT EXISTS joao_paulo_cunha_lista_tarefas;

USE joao_paulo_cunha_lista_tarefas;

SOURCE /01-esquema.sql
SOURCE /02-carga.sql


--Questão 1
SELECT * FROM tarefas ORDER BY data_criacao DESC;


--Questão 2
SELECT data_limite, descricao FROM tarefas WHERE data_limite < now() AND finalizado = FALSE ORDER BY data_limite ASC;

--Questão 3
SELECT * FROM tarefas WHERE data_limite < data_criacao ORDER BY id ASC;

--Questão 4
SELECT data_criacao, data_limite, descricao FROM tarefas WHERE finalizado = FALSE 
AND (data_limite > now() OR data_limite IS NULL)     
ORDER BY data_criacao ASC;


--Questão 5
SELECT * FROM tarefas 
WHERE data_criacao >  SUBDATE(NOW(), INTERVAL 7 DAY)     
ORDER BY data_criacao DESC;


--Questão 6

SELECT * FROM tarefas 
WHERE descricao LIKE "%limpar%" AND finalizado = FALSE     
ORDER BY id ASC;


--Questão 7
SELECT * FROM tarefas 
WHERE finalizado = TRUE AND data_criacao <  SUBDATE(NOW(), INTERVAL 20 DAY)     
ORDER BY data_criacao ASC;

--Questão 8
SELECT descricao, data_criacao, DATEDIFF(now(),data_criacao) as dias_passados
FROM tarefas 
WHERE data_limite IS NULL AND finalizado = FALSE     
ORDER BY dias_passados  DESC;


--Questão 9
SELECT descricao, data_limite, DATEDIFF(data_limite,now()) as dias_limite
FROM tarefas 
WHERE data_limite IS NOT NULL AND finalizado = FALSE     
ORDER BY dias_limite  ASC;

--Questão 10
SELECT descricao, data_criacao, data_limite, DATEDIFF(now(),data_criacao) as dias_passados, DATEDIFF(data_limite,now()) as dias_limite 
FROM tarefas 
WHERE finalizado = FALSE 
AND data_criacao <= SUBDATE(now(), INTERVAL 10 DAY)
AND data_limite IS NOT NULL AND   DATEDIFF(data_limite,now()) <= 3  
ORDER BY dias_limite  ASC,  dias_passados DESC;