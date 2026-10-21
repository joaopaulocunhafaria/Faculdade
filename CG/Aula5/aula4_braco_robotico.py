import math

import cv2
import numpy as np
import matplotlib.pyplot as plt

def calcular_junta(x_origem, y_origem, comprimento, angulo_rad):
    """
    Calcula onde a ponta de um elo cai na tela a partir da sua origem.

    O cosseno anda no eixo X normalmente, mas o seno é SUBTRAÍDO do Y.
    Isso acontece porque na matriz de pixels o Y cresce para baixo:
    se somasse, o braço seria desenhado de ponta cabeça.
    """
    x_final = x_origem + comprimento * math.cos(angulo_rad)
    y_final = y_origem - comprimento * math.sin(angulo_rad)

    # A tela só entende índices inteiros de pixel
    return int(round(x_final)), int(round(y_final))

def main():
    print("Iniciando a projeção do braço robótico...")

    # Cria a tela (matriz NumPy)
    tela = np.zeros((400, 400, 3), dtype=np.uint8)

    # Propriedades do braço (o "mundo" matemático)
    base_x, base_y = 120, 340
    comprimento_braco = 130   # elo do ombro até o cotovelo
    comprimento_antebraco = 100  # elo do cotovelo até a mão
    ang_ombro = 65
    ang_cotovelo = -40  # negativo = o cotovelo dobra para baixo

    ang_ombro_rad = math.radians(ang_ombro)
    ang_cotovelo_rad = math.radians(ang_cotovelo)

    # O cotovelo depende só do ângulo do ombro
    cotovelo_x, cotovelo_y = calcular_junta(
        base_x, base_y, comprimento_braco, ang_ombro_rad)

    # Já a mão depende do ângulo ACUMULADO (ombro + cotovelo).
    # Usar só o ângulo do cotovelo aqui é o erro clássico:
    # o segundo elo ignoraria a inclinação que o primeiro já deu.
    mao_x, mao_y = calcular_junta(
        cotovelo_x, cotovelo_y, comprimento_antebraco,
        ang_ombro_rad + ang_cotovelo_rad)

    print(f"Ombro   --> Coordenadas: ({base_x}, {base_y})")
    print(f"Cotovelo --> Coordenadas: ({cotovelo_x}, {cotovelo_y})")
    print(f"Mão      --> Coordenadas: ({mao_x}, {mao_y})")

    # Primitiva: Retângulo (a base fixa do robô)
    # cv2.rectangle(image, canto_superior_esquerdo, canto_inferior_direito, cor_rgb, espessura)
    cv2.rectangle(tela, (base_x - 35, base_y), (base_x + 35, 400), (128, 128, 128), -1)

    # Primitiva: Linha (os elos rígidos)
    cv2.line(tela, (base_x, base_y), (cotovelo_x, cotovelo_y), (200, 200, 200), 8)
    cv2.line(tela, (cotovelo_x, cotovelo_y), (mao_x, mao_y), (200, 200, 200), 8)

    # Primitiva: Círculo (as juntas que giram e a garra)
    cv2.circle(tela, (base_x, base_y), 12, (255, 0, 0), -1)  # ombro vermelho
    cv2.circle(tela, (cotovelo_x, cotovelo_y), 12, (255, 0, 0), -1)  # cotovelo vermelho
    cv2.circle(tela, (mao_x, mao_y), 10, (255, 255, 0), -1)  # garra amarela

    # Exibe a imagem
    plt.imshow(tela)
    plt.title("Braço Robótico Articulado (OpenCV + Trigonometria)")
    plt.show()

if __name__ == "__main__":
    main()
