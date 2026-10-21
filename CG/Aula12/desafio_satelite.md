# Desafio do Engenheiro de Satélites Espaciais

Resolução do exercício proposto ao final do slide `12 - Transformações Gráficas.pdf`.

**Script:** `desafio_satelite.py`

```bash
cd Aula12
../venv/bin/python desafio_satelite.py
```

---

## 1. O problema

Somos engenheiros de software de uma agência espacial e precisamos modelar as peças de um
satélite:

- um **corpo**
- dois **painéis solares**
- uma **antena**

Porém, **todas as peças foram modeladas na origem (0,0)**, no Sistema de Referência do Objeto
(SRO). A missão é compor matrizes de **Translação, Rotação e Escala (TRS)** para montar o
satélite no espaço, ou seja, no Sistema de Referência do Universo (SRU).

Geometria fornecida pelo slide:

| Peça | Vértices no SRO |
|---|---|
| Corpo | p1(-1,-1), p2(1,-1), p3(1,1), p4(-1,1) |
| Painéis solares | p1(-1,-1), p2(1,-1), p3(1,1), p4(-1,1) |
| Antena | p1(-1,0), p2(1,0), p3(0,2) |

Repare que o corpo e os painéis usam **a mesma geometria**: um quadrado unitário centrado na
origem. É a matriz de transformação de cada um que os diferencia — essa é justamente a ideia
central do exercício.

---

## 2. Representação: coordenadas homogêneas

Seguindo a convenção usada nos scripts das aulas 8 a 12, cada polígono é uma matriz onde
**cada coluna é um vértice** no formato `[X, Y, W]ᵀ`:

```python
quadrado_unitario = np.array([
    [-1,  1, 1, -1, -1],  # Linha do Eixo X
    [-1, -1, 1,  1, -1],  # Linha do Eixo Y
    [1,   1, 1,  1,  1]   # Linha do Eixo W (Coordenada Homogênea)
], dtype=np.float32)
```

O último vértice repete o primeiro apenas para **fechar o polígono** no desenho.

A coordenada homogênea `W = 1` é o que permite escrever a translação — que é uma *soma* — como
uma *multiplicação* de matrizes. Sem ela as três transformações não poderiam ser combinadas em
uma única matriz 3x3.

---

## 3. As três matrizes básicas

O script tem uma função para cada transformação vista nas aulas 9, 10 e 11:

### Translação (Aula 9)

```python
def matriz_translacao(tx, ty):
    return np.array([
        [1, 0, tx],
        [0, 1, ty],
        [0, 0,  1]
    ], dtype=np.float32)
```

Move o objeto `tx` unidades em X e `ty` em Y (`P' = P + T`).

### Escala (Aula 10)

```python
def matriz_escala(sx, sy):
    return np.array([
        [sx,  0, 0],
        [0,  sy, 0],
        [0,   0, 1]
    ], dtype=np.float32)
```

Multiplica as coordenadas pelos fatores de escala (`P' = P * S`). Como as peças estão
**centradas na origem**, a escala expande/contrai igualmente para os dois lados, sem deformar a
posição — exatamente a situação favorável descrita na Aula 10.

### Rotação (Aulas 11 e 12)

```python
def matriz_rotacao(angulo_graus):
    theta = np.radians(angulo_graus)
    cos_t, sin_t = np.cos(theta), np.sin(theta)
    return np.array([
        [cos_t, -sin_t, 0],
        [sin_t,  cos_t, 0],
        [0,          0, 1]
    ], dtype=np.float32)
```

É a matriz `x' = x·cos(θ) − y·sen(θ)` / `y' = y·cos(θ) + x·sen(θ)` da Aula 12, em torno da
origem.

---

## 4. A ordem da composição: T · R · S

Este é o ponto mais importante do exercício. O slide `tranformacao_rotacao_origem.py` já dava a
dica:

> `# Dica: Ordem da Direita para a Esquerda! (M_T2 * M_R * M_T1)`

Como os vértices são **vetores-coluna** e a conta é `M @ vertices`, a matriz mais à **direita**
é a primeira a agir sobre o ponto. Logo:

```python
M_Composta = T @ R @ S
```

significa **primeiro escalar, depois rotacionar, por último transladar**.

Essa ordem não é opcional. Se transladássemos antes de rotacionar, a peça já estaria longe da
origem e a rotação — que gira **em torno da origem** — a arremessaria para outro lugar do plano,
como alerta a Aula 11 ("se o objeto não estiver definido na origem, a multiplicação por uma
matriz de rotação também resulta em uma translação"). Escalar depois de transladar traria o mesmo
problema, agora com a deformação descrita na Aula 10.

Como todas as peças nascem na origem, aplicar S e R primeiro é gratuito: elas ainda estão no
lugar certo para isso.

---

## 5. Transformação de cada peça

### Corpo Principal — `T(0,0) · R(0°) · S(2,2)`

O quadrado unitário vai de 2x2 para **4x4** (de -2 a +2 nos dois eixos). Não precisa girar nem
transladar: o corpo é a referência da cena e fica no centro.

```python
M_corpo = matriz_translacao(0, 0) @ matriz_rotacao(0) @ matriz_escala(2, 2)
```

### Painel Esquerdo — `T(-4,0) · R(+30°) · S(3, 0.5)`

Três passos encadeados:

1. **Escala (3, 0.5)** — deforma o quadrado numa barra comprida e fina de **6 x 1** unidades
   (`Sx ≠ Sy`, o caso de deformação da Aula 10). É isso que transforma um quadrado em painel
   solar.
2. **Rotação (+30°)** — inclina a barra para cima, no sentido anti-horário.
3. **Translação (-4, 0)** — leva o painel para a esquerda do corpo, encostando nele.

```python
M_painel_esq = matriz_translacao(-4, 0) @ matriz_rotacao(30) @ matriz_escala(3, 0.5)
```

### Painel Direito — `T(4,0) · R(-30°) · S(3, 0.5)`

Idêntico ao esquerdo, com o sinal invertido no ângulo e na translação, o que produz a simetria
em relação ao eixo Y vista na figura do slide.

```python
M_painel_dir = matriz_translacao(4, 0) @ matriz_rotacao(-30) @ matriz_escala(3, 0.5)
```

### Antena — `T(0,2) · R(0°) · S(0.5, 0.5)`

1. **Escala (0.5, 0.5)** — encolhe o triângulo pela metade: base de -0,5 a +0,5 e altura 1.
2. **Translação (0, 2)** — encaixa a base da antena exatamente na borda superior do corpo
   (y = 2), deixando a ponta em (0, 3).

```python
M_antena = matriz_translacao(0, 2) @ matriz_rotacao(0) @ matriz_escala(0.5, 0.5)
```

---

## 6. Aplicando a transformação

Com a matriz mestre de cada peça pronta, **uma única multiplicação** leva todos os vértices do
SRO para o SRU de uma vez:

```python
vertices_sru = matriz_composta @ vertices_sro
```

Não é preciso percorrer ponto a ponto: a multiplicação de matrizes já faz isso para todas as
colunas simultaneamente.

Conferindo o painel esquerdo, a matriz composta resultante é:

```
[[ 2.5981 -0.25   -4.    ]
 [ 1.5     0.433   0.    ]
 [ 0.      0.      1.    ]]
```

E o vértice p3(1,1) do quadrado unitário vai parar em:

```
x' = 2.5981·1 + (-0.25)·1 + (-4)·1 = -1.6519
y' = 1.5·1    +   0.433·1 +   0·1  =  1.933
```

que é a quina superior direita do painel esquerdo, tocando o canto do corpo — como no resultado
esperado pelo slide.

---

## 7. Renderização

O script desenha dois planos cartesianos lado a lado:

1. **Peças Modeladas na Origem (SRO)** — todas as peças empilhadas no centro, antes das
   transformações. Deixa claro o problema inicial: sem TRS não há satélite, só um amontoado na
   origem.
2. **Cena Montada: Satélite no SRU** — o resultado final pedido pelo exercício.

Ambos usam os mesmos limites (X de -8 a 8, Y de -6 a 6), `set_aspect('equal')` para que os
ângulos de 30° não apareçam distorcidos, eixos X=0 e Y=0 em negrito e grade pontilhada, seguindo
o padrão de `Aula8/transformacao_translacao.py`.

O terminal imprime, para cada peça, a matriz composta e a matriz de vértices já transformada,
permitindo conferir a conta à mão como feito nos slides.
