"""Carro do jogador: avança ao longo da pista (posicao_z) e se desloca lateralmente
(offset_x) — sem ângulo de mundo, já que a técnica pseudo-3D não tem essa noção:
é a pista que se curva sob um carro que sempre olha para frente.
"""

import pygame

import configuracoes as cfg


class Carro:
    def __init__(self, posicao_z=0.0, offset_x=0.0):
        self.posicao_z = posicao_z
        self.offset_x = offset_x
        self.velocidade = 0.0
        self.inclinacao = 0.0  # graus, puramente cosmético

        self.sprite = pygame.image.load(cfg.CAMINHO_SPRITE_CARRO).convert_alpha()

    def atualizar(self, teclas, dt, curvatura_segmento_atual):
        acelerando = any(teclas[tecla] for tecla in cfg.TECLAS_ACELERAR)
        freando = any(teclas[tecla] for tecla in cfg.TECLAS_FRENAR)
        virando_esquerda = any(teclas[tecla] for tecla in cfg.TECLAS_VIRAR_ESQUERDA)
        virando_direita = any(teclas[tecla] for tecla in cfg.TECLAS_VIRAR_DIREITA)

        self._atualizar_velocidade(acelerando, freando, dt)
        self.posicao_z += self.velocidade * dt

        offset_anterior = self.offset_x
        self._atualizar_direcao(virando_esquerda, virando_direita, curvatura_segmento_atual, dt)
        self.inclinacao = max(-cfg.INCLINACAO_MAXIMA, min(cfg.INCLINACAO_MAXIMA,
                               (self.offset_x - offset_anterior) * cfg.FATOR_INCLINACAO))

    def _atualizar_velocidade(self, acelerando, freando, dt):
        if acelerando:
            self.velocidade += cfg.ACELERACAO * dt
        elif freando:
            self.velocidade -= cfg.FRENAGEM * dt
        else:
            if self.velocidade > 0:
                self.velocidade = max(0.0, self.velocidade - cfg.ATRITO * dt)
            elif self.velocidade < 0:
                self.velocidade = min(0.0, self.velocidade + cfg.ATRITO * dt)

        self.velocidade = max(-cfg.VELOCIDADE_MAXIMA_RE, min(cfg.VELOCIDADE_MAXIMA, self.velocidade))

    def _atualizar_direcao(self, virando_esquerda, virando_direita, curvatura_segmento_atual, dt):
        fator_velocidade = abs(self.velocidade) / cfg.VELOCIDADE_MAXIMA
        dx = dt * cfg.VELOCIDADE_LATERAL * fator_velocidade

        if virando_esquerda:
            self.offset_x -= dx
        if virando_direita:
            self.offset_x += dx

        # Puxão de curva: quanto mais rápido, mais a curva da pista empurra o carro para fora.
        self.offset_x -= dx * fator_velocidade * curvatura_segmento_atual * cfg.FATOR_CENTRIFUGO

        self.offset_x = max(-cfg.LIMITE_OFFSET_CLAMP, min(cfg.LIMITE_OFFSET_CLAMP, self.offset_x))

    def esta_na_pista(self):
        return abs(self.offset_x) <= cfg.LIMITE_OFFSET_ACOSTAMENTO

    def desenhar(self, tela):
        sprite = self.sprite
        if abs(self.inclinacao) > 0.5:
            sprite = pygame.transform.rotozoom(sprite, -self.inclinacao, 1.0)

        deslocamento_x = self.offset_x * cfg.FATOR_DESLOCAMENTO_TELA_CARRO
        centro = (cfg.LARGURA_TELA / 2 + deslocamento_x, cfg.ALTURA_TELA - cfg.MARGEM_INFERIOR_CARRO)
        retangulo = sprite.get_rect(center=centro)
        tela.blit(sprite, retangulo)
