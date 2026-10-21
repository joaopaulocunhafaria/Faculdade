"""Trabalho Final de CG - versão prévia de um jogo de corrida pseudo-3D, estilo
"80's Overdrive" (câmera atrás do carro, na linha de OutRun/Chase HQ).

Núcleo da experiência de direção: pista com curvas e morros, tráfego simples
para desviar, velocidade e cronômetro/voltas na HUD. Sem modo carreira, loja,
polícia ou editor de pistas - extensões futuras possíveis, não implementadas.

Antes de rodar pela primeira vez, gere os assets:
    ./venv/bin/python gerar_assets.py

Depois rode o jogo:
    ./venv/bin/python jogo.py
"""

import os
import sys

import pygame

import configuracoes as cfg
from carro import Carro
from pista import Pista
from trafego import carregar_trafego, desenhar_trafego, verificar_colisoes


def assets_existem():
    return os.path.isfile(cfg.CAMINHO_SPRITE_CARRO) and os.path.isfile(cfg.CAMINHO_SPRITE_CARRO_TRAFEGO)


def desenhar_hud(tela, fonte, carro, tempo_decorrido, voltas, flash_colisao):
    velocidade_exibida = int(abs(carro.velocidade) * cfg.FATOR_EXIBICAO_VELOCIDADE)
    minutos = int(tempo_decorrido) // 60
    segundos = int(tempo_decorrido) % 60

    texto_tempo = fonte.render(f"{minutos:02d}:{segundos:02d}", True, cfg.COR_HUD_TEXTO)
    texto_velocidade = fonte.render(f"{velocidade_exibida} km/h", True, cfg.COR_HUD_TEXTO)
    texto_voltas = fonte.render(f"Volta {voltas}", True, cfg.COR_HUD_TEXTO)

    tela.blit(texto_tempo, (16, 16))
    tela.blit(texto_velocidade, (cfg.LARGURA_TELA - texto_velocidade.get_width() - 16, 16))
    tela.blit(texto_voltas, (16, cfg.ALTURA_TELA - texto_voltas.get_height() - 16))

    if not carro.esta_na_pista():
        texto_aviso = fonte.render("FORA DA PISTA", True, cfg.COR_HUD_AVISO)
        tela.blit(texto_aviso, (cfg.LARGURA_TELA / 2 - texto_aviso.get_width() / 2, 16))

    if flash_colisao > 0:
        overlay = pygame.Surface((cfg.LARGURA_TELA, cfg.ALTURA_TELA), pygame.SRCALPHA)
        alfa = int(120 * (flash_colisao / cfg.DURACAO_FLASH_COLISAO))
        overlay.fill((255, 0, 0, max(0, alfa)))
        tela.blit(overlay, (0, 0))


def main():
    if not assets_existem():
        print("Assets não encontrados. Rode primeiro: ./venv/bin/python gerar_assets.py")
        sys.exit(1)

    pygame.init()
    tela = pygame.display.set_mode((cfg.LARGURA_TELA, cfg.ALTURA_TELA))
    pygame.display.set_caption(cfg.TITULO_JANELA)
    relogio = pygame.time.Clock()
    fonte = pygame.font.Font(None, cfg.TAMANHO_FONTE_HUD)

    pista = Pista()
    carro = Carro()
    lista_trafego = carregar_trafego()

    tempo_decorrido = 0.0
    voltas = 0
    volta_anterior = 0
    flash_colisao = 0.0

    rodando = True
    while rodando:
        dt = relogio.tick(cfg.FPS) / 1000.0

        for evento in pygame.event.get():
            if evento.type == pygame.QUIT:
                rodando = False
            elif evento.type == pygame.KEYDOWN and evento.key == pygame.K_ESCAPE:
                rodando = False

        teclas = pygame.key.get_pressed()
        segmento_atual = pista.segmento_atual(carro.posicao_z)
        carro.atualizar(teclas, dt, segmento_atual.curva)

        if verificar_colisoes(carro, lista_trafego):
            flash_colisao = cfg.DURACAO_FLASH_COLISAO
        flash_colisao = max(0.0, flash_colisao - dt)

        volta_atual = int(carro.posicao_z // pista.comprimento_total)
        if volta_atual > volta_anterior:
            voltas += 1
            volta_anterior = volta_atual

        tempo_decorrido += dt

        pista.desenhar(tela, carro)
        desenhar_trafego(tela, pista, carro, lista_trafego)
        carro.desenhar(tela)
        desenhar_hud(tela, fonte, carro, tempo_decorrido, voltas, flash_colisao)

        pygame.display.flip()

    pygame.quit()


if __name__ == "__main__":
    main()
