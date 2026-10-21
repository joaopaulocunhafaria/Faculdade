"""Tráfego simples: carros parados/lentos posicionados manualmente ao longo da pista,
para desviar. Sem IA de perseguição/corrida — apenas obstáculos com posição fixa."""

import pygame

import configuracoes as cfg
from pista import projetar


class CarroTrafego:
    def __init__(self, indice_segmento, offset_x, sprite):
        self.indice_segmento = indice_segmento
        self.offset_x = offset_x
        self.sprite = sprite
        self.atingido = False


def carregar_trafego():
    sprite = pygame.image.load(cfg.CAMINHO_SPRITE_CARRO_TRAFEGO).convert_alpha()
    return [CarroTrafego(indice, offset, sprite) for indice, offset in cfg.POSICOES_TRAFEGO]


def desenhar_trafego(tela, pista, carro, lista_trafego):
    n = len(pista.segmentos)
    indice_base = int(carro.posicao_z // cfg.COMPRIMENTO_SEGMENTO) % n
    fracao = (carro.posicao_z % cfg.COMPRIMENTO_SEGMENTO) / cfg.COMPRIMENTO_SEGMENTO
    camera_y = cfg.ALTURA_CAMERA + pista.altura_interpolada(indice_base, fracao)
    camera_x = carro.offset_x * (cfg.LARGURA_PISTA / 2)
    deslocamentos_x = pista.deslocamentos_laterais(indice_base, fracao)

    for veiculo in lista_trafego:
        n_rel = (veiculo.indice_segmento - indice_base) % n
        if n_rel >= cfg.DISTANCIA_DESENHO:
            continue

        segmento = pista.segmentos[veiculo.indice_segmento % n]
        z_relativo = (n_rel - fracao) * cfg.COMPRIMENTO_SEGMENTO
        if z_relativo <= 1.0:
            continue

        x_mundo = deslocamentos_x[n_rel] + veiculo.offset_x * (cfg.LARGURA_PISTA / 2)
        ponto = projetar(x_mundo, segmento.altura, z_relativo, camera_x, camera_y,
                          cfg.PROFUNDIDADE_CAMERA, cfg.LARGURA_TELA, cfg.ALTURA_TELA, cfg.LARGURA_PISTA)

        largura_bruta = ponto.escala * cfg.LARGURA_MUNDO_CARRO_TRAFEGO * cfg.LARGURA_TELA / 2
        largura = max(1, min(int(largura_bruta), cfg.LARGURA_TELA * 3))
        altura = max(1, int(largura * (cfg.CARRO_TRAFEGO_ALTURA / cfg.CARRO_TRAFEGO_LARGURA)))

        sprite_escalado = pygame.transform.smoothscale(veiculo.sprite, (largura, altura))
        retangulo = sprite_escalado.get_rect(midbottom=(ponto.tela_x, ponto.tela_y))
        tela.blit(sprite_escalado, retangulo)


def verificar_colisoes(carro, lista_trafego):
    houve_colisao = False
    for veiculo in lista_trafego:
        distancia_z = abs(carro.posicao_z - veiculo.indice_segmento * cfg.COMPRIMENTO_SEGMENTO)
        distancia_lateral = abs(carro.offset_x - veiculo.offset_x)

        if distancia_z < cfg.LIMIAR_Z_COLISAO and distancia_lateral < cfg.LIMIAR_LATERAL_COLISAO:
            if not veiculo.atingido:
                carro.velocidade *= cfg.FATOR_PENALIDADE_COLISAO
                veiculo.atingido = True
                houve_colisao = True
        elif distancia_z > cfg.LIMIAR_Z_COLISAO * 4:
            veiculo.atingido = False

    return houve_colisao
