SELECT * FROM contato 
ORDER BY nome 
LIMIT 1 OFFSET 2;


SELECT *
FROM contato
WHERE nome LIKE "%Joao%" AND email LIKE "%@%"
ORDER BY nome 
LIMIT 5 OFFSET 0;


SELECT count(*)/5
FROM contato
WHERE nome LIKE "%Joao%";


SELECT count(*)/4
FROM contato;