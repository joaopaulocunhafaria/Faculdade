--Questão 1 
SELECT * FROM comites 
ORDER BY pais ASC;

--Questão 2
SELECT modalidade FROM esportes
GROUP BY modalidade
ORDER BY modalidade ASC;

--Questão 3
SELECT modalidade, count(categoria) AS qtd_categorias FROM esportes
GROUP BY modalidade
ORDER BY modalidade ASC;

--Questão 4
SELECT * FROM edicoes AS e 
JOIN participacoes AS p ON p.comite_id="BRA" AND e.inverno =false
GROUP BY e.nome
ORDER BY e.ano;


--Questão 5
SELECT * FROM esportes AS e 
JOIN participacoes AS p ON p.comite_id="BRA"
GROUP BY e.modalidade
ORDER BY e.modalidade ASC, e.categoria ASC;

--Questão 6
SELECT ano, nome, SUM(ouro + prata+ bronze) AS total_medalhas FROM edicoes AS e 
JOIN participacoes AS p ON p.edicao_id=e.id
WHERE e.inverno=0 AND p.comite_id = "BRA"
GROUP BY e.nome
ORDER BY total_medalhas DESC;


--Questão 7
SELECT id, pais, SUM(ouro) AS ouro,SUM(prata) AS prata,SUM(bronze) AS bronze, SUM(ouro + prata+ bronze) AS total_medalhas FROM comites AS c 
JOIN participacoes AS p ON p.comite_id=c.id
GROUP BY c.pais 
ORDER BY total_medalhas DESC;




