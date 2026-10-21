"""Constantes de configuração do jogo: janela, cores, câmera pseudo-3D, física, pista e teclas."""

import math
import os

import pygame

# --- Janela ---
LARGURA_TELA = 960
ALTURA_TELA = 640
FPS = 60
TITULO_JANELA = "Trabalho Final - CG - Corrida Pseudo-3D estilo 80's Overdrive"

# --- Caminhos ---
DIRETORIO_BASE = os.path.dirname(os.path.abspath(__file__))
DIRETORIO_ASSETS = os.path.join(DIRETORIO_BASE, "assets")
CAMINHO_SPRITE_CARRO = os.path.join(DIRETORIO_ASSETS, "carro.png")
CAMINHO_SPRITE_CARRO_TRAFEGO = os.path.join(DIRETORIO_ASSETS, "carro_trafego.png")

# --- Cores (RGB) ---
COR_CEU = (64, 40, 90)
COR_GRAMA = (30, 130, 60)
COR_GRAMA_ESCURA = (24, 110, 50)
COR_ASFALTO = (80, 80, 90)
COR_ASFALTO_ESCURO = (70, 70, 80)
COR_ACOSTAMENTO_CLARO = (200, 60, 60)
COR_ACOSTAMENTO_ESCURO = (230, 230, 230)
COR_FAIXA_CENTRAL = (230, 230, 230)
COR_HUD_TEXTO = (255, 255, 255)
COR_HUD_AVISO = (255, 60, 60)

COR_CARRO_CHASSI = (200, 30, 30)
COR_CARRO_JANELA_TRASEIRA = (40, 40, 50)
COR_CARRO_LANTERNA = (255, 120, 40)

COR_TRAFEGO_CHASSI = (60, 90, 200)
COR_TRAFEGO_JANELA = (30, 30, 40)

# --- Câmera / projeção pseudo-3D (valores clássicos do técnica "segment-based OutRun clone") ---
COMPRIMENTO_SEGMENTO = 200          # unidades de mundo por segmento de pista
SEGMENTOS_POR_FAIXA_COR = 3         # segmentos por listra de cor (grama/asfalto/acostamento)
PERIODO_FAIXA_CENTRAL = 3           # a cada N segmentos, alterna o traço central (ligado/desligado)
DISTANCIA_DESENHO = 300             # segmentos desenhados à frente por frame
LARGURA_PISTA = 2000                # largura da pista em unidades de mundo
ALTURA_CAMERA = 1000                # altura fixa da câmera acima da pista
CAMPO_DE_VISAO_GRAUS = 100
PROFUNDIDADE_CAMERA = 1.0 / math.tan(math.radians(CAMPO_DE_VISAO_GRAUS / 2))
FATOR_ACOSTAMENTO = 1.15            # acostamento = largura da pista projetada * esse fator
FATOR_FAIXA_CENTRAL = 0.02          # largura da faixa central, fração da largura da pista

# --- Curvas e morros (presets para autorar a pista) ---
CURVA_LEVE = 2.0
CURVA_FECHADA = 5.0
MORRO_BAIXO = 4000
MORRO_ALTO = 9000

# --- Traçado da pista: (segmentos_entrada, segmentos_sustentacao, segmentos_saida, curvatura, delta_altura) ---
TRECHOS_PISTA = [
    (60, 100, 40, 0.0, 0),
    (40, 80, 40, CURVA_LEVE, 0),
    (50, 100, 50, 0.0, MORRO_BAIXO),
    (40, 60, 40, -CURVA_FECHADA, 0),
    (50, 100, 50, 0.0, -MORRO_BAIXO),
    (40, 60, 40, CURVA_FECHADA, MORRO_ALTO),
    (50, 100, 50, 0.0, -MORRO_ALTO),
    (40, 80, 40, -CURVA_LEVE, 0),
    (60, 120, 60, 0.0, 0),
]


def _indice_inicial_trecho(indice_trecho):
    inicio = 0
    for entrada, sustentacao, saida, _curva, _altura in TRECHOS_PISTA[:indice_trecho]:
        inicio += entrada + sustentacao + saida
    return inicio


def _segmento_no_trecho(indice_trecho, posicao_dentro_do_trecho):
    return _indice_inicial_trecho(indice_trecho) + posicao_dentro_do_trecho


# --- Tráfego: (indice_segmento, offset_x) — carros parados/lentos para desviar ---
POSICOES_TRAFEGO = [
    (_segmento_no_trecho(0, 30), -0.5),
    (_segmento_no_trecho(0, 45), 0.4),
    (_segmento_no_trecho(1, 40), 0.5),
    (_segmento_no_trecho(2, 50), -0.3),
    (_segmento_no_trecho(2, 90), 0.2),
    (_segmento_no_trecho(3, 30), -0.6),
    (_segmento_no_trecho(4, 60), 0.0),
    (_segmento_no_trecho(5, 20), 0.4),
    (_segmento_no_trecho(6, 60), -0.4),
    (_segmento_no_trecho(7, 40), 0.5),
    (_segmento_no_trecho(8, 50), -0.2),
    (_segmento_no_trecho(8, 90), 0.3),
]

# --- Sprites de carro ---
CARRO_SPRITE_LARGURA = 140
CARRO_SPRITE_ALTURA = 100
CARRO_TRAFEGO_LARGURA = 120
CARRO_TRAFEGO_ALTURA = 88
LARGURA_MUNDO_CARRO_TRAFEGO = 300   # largura "física" do carro de tráfego, em unidades de mundo
MARGEM_INFERIOR_CARRO = 60
FATOR_DESLOCAMENTO_TELA_CARRO = 300  # deslocamento horizontal máx. (px) do carro do jogador na tela
INCLINACAO_MAXIMA = 8               # graus, puramente cosmético
FATOR_INCLINACAO = 400              # converte variação de offset_x/frame em graus de inclinação

# --- Física do carro (unidades de mundo por segundo) ---
# Calibrada como no clássico "segment-based OutRun clone": velocidade máxima percorre
# exatamente um segmento por frame a 60 FPS.
VELOCIDADE_MAXIMA = float(COMPRIMENTO_SEGMENTO * FPS)   # 12000
ACELERACAO = VELOCIDADE_MAXIMA / 5.0                      # atinge o máximo em ~5s
FRENAGEM = VELOCIDADE_MAXIMA                              # freia do máximo a 0 em ~1s
ATRITO = VELOCIDADE_MAXIMA / 5.0                          # mesma taxa ao soltar o acelerador
VELOCIDADE_MAXIMA_RE = VELOCIDADE_MAXIMA / 4.0

VELOCIDADE_LATERAL = 2.0            # variação de offset_x/s ao esterçar em velocidade máxima
FATOR_CENTRIFUGO = 0.3              # quanto a curvatura da pista empurra offset_x para fora

# --- Limites de pista ---
LIMITE_OFFSET_ACOSTAMENTO = 1.0
LIMITE_OFFSET_CLAMP = 3.0

# --- Colisão com tráfego ---
LIMIAR_Z_COLISAO = COMPRIMENTO_SEGMENTO * 1.2
LIMIAR_LATERAL_COLISAO = 0.5
FATOR_PENALIDADE_COLISAO = 0.4
DURACAO_FLASH_COLISAO = 0.3

# --- HUD ---
TAMANHO_FONTE_HUD = 28
FATOR_EXIBICAO_VELOCIDADE = 0.022   # converte velocidade (unidades/s) em um número estilo "km/h"

# --- Teclas ---
TECLAS_ACELERAR = (pygame.K_w, pygame.K_UP)
TECLAS_FRENAR = (pygame.K_s, pygame.K_DOWN)
TECLAS_VIRAR_ESQUERDA = (pygame.K_a, pygame.K_LEFT)
TECLAS_VIRAR_DIREITA = (pygame.K_d, pygame.K_RIGHT)
