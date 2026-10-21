import numpy as np
import matplotlib.pyplot as plt


def matriz_translacao(tx, ty):
    # Matriz de Translação em Coordenadas Homogêneas
    return np.array([
        [1, 0, tx],
        [0, 1, ty],
        [0, 0,  1]
    ], dtype=np.float32)


def matriz_escala(sx, sy):
    # Matriz de Escala em Coordenadas Homogêneas
    return np.array([
        [sx,  0, 0],
        [0,  sy, 0],
        [0,   0, 1]
    ], dtype=np.float32)


def matriz_rotacao(angulo_graus):
    # Matriz de Rotação em torno da origem (plano XY)
    theta = np.radians(angulo_graus)
    cos_t, sin_t = np.cos(theta), np.sin(theta)

    return np.array([
        [cos_t, -sin_t, 0],
        [sin_t,  cos_t, 0],
        [0,          0, 1]
    ], dtype=np.float32)


def desenhar_peca(ax, matriz, cor, rotulo):
    # Cada coluna da matriz é um vértice [X, Y, W]^T
    x = matriz[0, :]
    y = matriz[1, :]

    ax.plot(x, y, color=cor, linestyle='-', linewidth=2, label=rotulo)
    ax.fill(x, y, color=cor, alpha=0.25)


def configurar_plano(ax, titulo):
    # Plano Cartesiano (Grade, Eixos, Limites)
    ax.set_title(titulo, fontsize=13, fontweight='bold')
    ax.set_xlabel("Eixo X", fontsize=11)
    ax.set_ylabel("Eixo Y", fontsize=11)

    # limites da janela de visualização (Viewport)
    ax.set_xlim(-8, 8)
    ax.set_ylim(-6, 6)
    ax.set_aspect('equal')

    # Desenhando os eixos X=0 e Y=0 em negrito
    ax.axhline(0, color='black', linewidth=1.5)
    ax.axvline(0, color='black', linewidth=1.5)

    # Configurando a grade
    ax.set_xticks(np.arange(-8, 9, 2))
    ax.set_yticks(np.arange(-6, 7, 2))
    ax.grid(True, linestyle=':', color='gray', alpha=0.7)
    ax.legend(loc='upper right', fontsize=9)


def desafio_satelite():
    print("=== Desafio do Engenheiro de Satélites Espaciais ===\n")

    # Definição da Geometria Original (SRO - Sistema de Referência do Objeto)
    # Todas as peças foram modeladas na origem (0,0).
    # Cada coluna é um vértice: [X, Y, W]^T e o último vértice fecha o polígono.

    # Corpo e Painéis: p1(-1,-1), p2(1,-1), p3(1,1), p4(-1,1)
    quadrado_unitario = np.array([
        [-1,  1, 1, -1, -1],  # Linha do Eixo X
        [-1, -1, 1,  1, -1],  # Linha do Eixo Y
        [1,   1, 1,  1,  1]   # Linha do Eixo W (Coordenada Homogênea)
    ], dtype=np.float32)

    # Antena: p1(-1,0), p2(1,0), p3(0,2)
    triangulo_antena = np.array([
        [-1, 1, 0, -1],  # Linha do Eixo X
        [0,  0, 2,  0],  # Linha do Eixo Y
        [1,  1, 1,  1]   # Linha do Eixo W (Coordenada Homogênea)
    ], dtype=np.float32)

    print("Quadrado Unitário no SRO (corpo e painéis):")
    print(quadrado_unitario, "\n")

    print("Triângulo da Antena no SRO:")
    print(triangulo_antena, "\n")

    # Composição das Matrizes TRS (Translação * Rotação * Escala)
    # Dica: Ordem da Direita para a Esquerda! (M_T * M_R * M_S)
    # Primeiro a peça é dimensionada, depois girada e só então posicionada.

    # 1) Corpo: quadrado 2x2 -> 4x4, centrado na origem
    M_corpo = (matriz_translacao(0, 0)
               @ matriz_rotacao(0)
               @ matriz_escala(2, 2))

    # 2) Painel Esquerdo: vira uma barra 6x1, inclinada +30º e levada para (-4, 0)
    M_painel_esq = (matriz_translacao(-4, 0)
                    @ matriz_rotacao(30)
                    @ matriz_escala(3, 0.5))

    # 3) Painel Direito: mesma barra, inclinada -30º e levada para (4, 0)
    M_painel_dir = (matriz_translacao(4, 0)
                    @ matriz_rotacao(-30)
                    @ matriz_escala(3, 0.5))

    # 4) Antena: reduzida à metade e encaixada no topo do corpo (0, 2)
    M_antena = (matriz_translacao(0, 2)
                @ matriz_rotacao(0)
                @ matriz_escala(0.5, 0.5))

    matrizes = [
        ("Corpo Principal", M_corpo, quadrado_unitario, 'gray'),
        ("Painel Esquerdo", M_painel_esq, quadrado_unitario, 'blue'),
        ("Painel Direito", M_painel_dir, quadrado_unitario, 'blue'),
        ("Antena", M_antena, triangulo_antena, 'red')
    ]

    # Renderização 2D com o Matplotlib
    fig, (ax_sro, ax_sru) = plt.subplots(1, 2, figsize=(16, 7))

    for rotulo, matriz_composta, vertices_sro, cor in matrizes:
        print(f"Matriz Composta (T * R * S) - {rotulo}:")
        print(np.round(matriz_composta, 4), "\n")

        # Multiplicação Matricial: leva a peça do SRO para o SRU
        vertices_sru = matriz_composta @ vertices_sro

        print(f"Vértices de {rotulo} no SRU:")
        print(np.round(vertices_sru, 4), "\n")

        desenhar_peca(ax_sro, vertices_sro, cor, rotulo)
        desenhar_peca(ax_sru, vertices_sru, cor, rotulo)

    configurar_plano(ax_sro, "1. Peças Modeladas na Origem (SRO)")
    configurar_plano(ax_sru, "2. Cena Montada: Satélite no SRU")

    print("[*] Renderizando o plano cartesiano...")
    plt.tight_layout()
    plt.show()


if __name__ == "__main__":
    desafio_satelite()
