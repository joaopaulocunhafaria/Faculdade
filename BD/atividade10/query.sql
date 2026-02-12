--Questão 1
SELECT e.nome
FROM equipes AS e
LEFT JOIN partidas AS p 
    ON e.id = p.equipe_mandante_id 
    AND p.gols_mandante > p.gols_visitante
WHERE p.id IS NULL
ORDER BY e.nome ASC;

--Questão 2
SELECT e.nome, e.estado, e.cidade, COUNT(p.id) AS total_partidas
FROM estadios AS e
JOIN partidas AS p ON p.estadio_id = e.id
WHERE p.gols_mandante IS NOT NULL AND p.gols_visitante IS NOT NULL
GROUP BY e.id
HAVING COUNT(p.id) > 5
ORDER BY e.nome ASC;

--Questão 3
WITH vitorias_mandante AS (
    SELECT 
        e.id,
        COUNT(*) AS vitorias_mandante
    FROM equipes AS e
    JOIN partidas AS p ON p.equipe_mandante_id = e.id
    WHERE p.gols_mandante > p.gols_visitante
    GROUP BY e.id
),
vitorias_visitante AS (
    SELECT 
        e.id,
        COUNT(*) AS vitorias_visitante
    FROM equipes AS e
    JOIN partidas AS p ON p.equipe_visitante_id = e.id
    WHERE p.gols_visitante > p.gols_mandante
    GROUP BY e.id
)
SELECT
    e.nome,
    COALESCE(vv.vitorias_visitante, 0) AS vitorias_visitante,
    COALESCE(vm.vitorias_mandante, 0) AS vitorias_mandante,
    (COALESCE(vv.vitorias_visitante, 0) - COALESCE(vm.vitorias_mandante, 0)) AS saldo_vitorias
FROM equipes AS e
LEFT JOIN vitorias_mandante vm ON e.id = vm.id
LEFT JOIN vitorias_visitante vv ON e.id = vv.id
WHERE COALESCE(vv.vitorias_visitante, 0) > COALESCE(vm.vitorias_mandante, 0)
ORDER BY saldo_vitorias DESC;



--Questão 4
SELECT e.nome AS equipe_mandante,
       e_v.nome AS equipe_visitante,
       p.gols_mandante,
       p.gols_visitante,
       p.data_partida,
       p.horario
FROM partidas AS p
LEFT JOIN equipes AS e ON p.equipe_mandante_id = e.id
LEFT JOIN equipes AS e_v ON p.equipe_visitante_id = e_v.id
WHERE p.gols_mandante = p.gols_visitante
ORDER BY p.data_partida DESC, p.horario DESC;



--Questão 5
SELECT 
    e.nome,
    SUM(CASE WHEN p.equipe_mandante_id = e.id THEN p.gols_mandante ELSE 0 END) +
    SUM(CASE WHEN p.equipe_visitante_id = e.id THEN p.gols_visitante ELSE 0 END) AS total_gols
FROM equipes AS e
LEFT JOIN partidas AS p 
    ON e.id = p.equipe_mandante_id OR e.id = p.equipe_visitante_id
WHERE p.gols_mandante IS NOT NULL AND p.gols_visitante IS NOT NULL
GROUP BY e.nome
ORDER BY total_gols DESC;



--Questão 6
SELECT  p.rodada,
        e.nome AS estadio,
        e.cidade,
        e.estado,
        COUNT(p.id) AS total_partidas
FROM partidas AS p
LEFT JOIN estadios AS e on p.estadio_id = e.id
WHERE p.rodada = 3
GROUP BY e.nome
ORDER BY total_partidas DESC;

--Questão 7 
SELECT 
    p.rodada,
    e.nome AS estadio,
    ROUND(AVG(p.gols_mandante + p.gols_visitante), 2) AS media_gols
FROM partidas AS p
JOIN estadios AS e ON p.estadio_id = e.id
WHERE p.gols_mandante IS NOT NULL AND p.gols_visitante IS NOT NULL
GROUP BY p.rodada, e.nome
ORDER BY p.rodada ASC, e.nome ASC;
















--Questão 8
SELECT 
    e.nome,
    -- Pontuação
    (COALESCE(SUM(CASE WHEN (p.equipe_mandante_id = e.id AND p.gols_mandante > p.gols_visitante) THEN 3
                       WHEN (p.equipe_visitante_id = e.id AND p.gols_visitante > p.gols_mandante) THEN 3
                       WHEN ((p.equipe_mandante_id = e.id OR p.equipe_visitante_id = e.id) AND p.gols_mandante = p.gols_visitante) THEN 1
                       ELSE 0 END), 0)
    AS pontos,

    -- Número de jogos
    COUNT(CASE WHEN (p.equipe_mandante_id = e.id OR p.equipe_visitante_id = e.id) THEN 1 END) AS jogos,

    -- Vitórias
    COUNT(CASE WHEN (p.equipe_mandante_id = e.id AND p.gols_mandante > p.gols_visitante)
                    OR (p.equipe_visitante_id = e.id AND p.gols_visitante > p.gols_mandante)
               THEN 1 END) AS vitorias,

    -- Derrotas
    COUNT(CASE WHEN (p.equipe_mandante_id = e.id AND p.gols_mandante < p.gols_visitante)
                    OR (p.equipe_visitante_id = e.id AND p.gols_visitante < p.gols_mandante)
               THEN 1 END) AS derrotas,

    -- Empates
    COUNT(CASE WHEN (p.equipe_mandante_id = e.id OR p.equipe_visitante_id = e.id) 
                    AND p.gols_mandante = p.gols_visitante
               THEN 1 END) AS empates,

    -- Gols pró
    SUM(CASE WHEN p.equipe_mandante_id = e.id THEN p.gols_mandante
             WHEN p.equipe_visitante_id = e.id THEN p.gols_visitante
             ELSE 0 END) AS gols_pro,

    -- Gols contra
    SUM(CASE WHEN p.equipe_mandante_id = e.id THEN p.gols_visitante
             WHEN p.equipe_visitante_id = e.id THEN p.gols_mandante
             ELSE 0 END) AS gols_contra,

    -- Saldo de gols
    SUM(CASE WHEN p.equipe_mandante_id = e.id THEN p.gols_mandante - p.gols_visitante
             WHEN p.equipe_visitante_id = e.id THEN p.gols_visitante - p.gols_mandante
             ELSE 0 END) AS saldo_gols

FROM equipes AS e
LEFT JOIN partidas AS p ON e.id = p.equipe_mandante_id OR e.id = p.equipe_visitante_id
WHERE p.gols_mandante IS NOT NULL AND p.gols_visitante IS NOT NULL
GROUP BY e.nome
ORDER BY pontos DESC, vitorias DESC, saldo_gols DESC, gols_pro DESC;


