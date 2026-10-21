# aula 4 - 14 de agosto de 2026

import numpy as np
import matplotlib.pyplot as plt

def desenhar_linha_bresenham(img, x0, y0, x1, y1, cor):
    """Algoritmo de Bresenham para rasterizar linhas."""
    dx = abs(x1 - x0)
    dy = abs(y1 - y0)
    
    # direção do passo (1 ou -1)
    sx = 1 if x0 < x1 else -1
    sy = 1 if y0 < y1 else -1

    # Variável de decisão
    erro = dx - dy

    x, y = x0, y0

    # Laço infinito até chegar no ponto final
    while True:
        # Pinta o pixel na matrix NumPy
        img[y, x] = cor
        if x == x1 and y == y1:
            break

        # Cria variáveis para auxiliar o loop
        e2 = 2 * erro

        # Verifica se deve andar no eixo X
        if e2 > -dy:
            erro -= dy
            x += sx
        
        # Verifica se deve andar no eixo Y
        if e2 < dx:
            erro += dx
            y += sy

    return img

if __name__ == "__main__":
    
    tela = np.zeros((100, 100, 3), dtype=np.uint8) # Tela preta 100x100
    desenhar_linha_bresenham(tela, 10, 10, 90, 80, (255, 0, 0)) # Linha vermelha

    plt.imshow(tela)
    plt.title("Reta feita 'Do Zero' (Bresenham)")
    plt.show()