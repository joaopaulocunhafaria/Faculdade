"""Motor de renderização pseudo-3D da pista: segmentos projetados em perspectiva,
técnica clássica de clones de OutRun (câmera atrás e acima do carro).
"""

import math
from dataclasses import dataclass

import pygame

import configuracoes as cfg


@dataclass
class Segmento:
    indice: int
    z: float
    curva: float
    altura: float
    cor_grama: tuple
    cor_asfalto: tuple
    cor_acostamento: tuple
    tem_faixa_central: bool


@dataclass
class PontoProjetado:
    tela_x: float
    tela_y: float
    tela_w: float
    escala: float


def projetar(x_mundo, y_mundo, z_relativo, camera_x, camera_y, profundidade_camera,
             largura_tela, altura_tela, largura_pista):
    """Projeta um ponto do mundo para a tela via divisão por profundidade.

    z_relativo é a distância do ponto até a câmera (já descontada a posição da câmera),
    e deve ser positivo — pontos muito próximos de zero não devem ser passados aqui.
    """
    escala = profundidade_camera / z_relativo
    tela_x = largura_tela / 2 + escala * (x_mundo - camera_x) * largura_tela / 2
    tela_y = altura_tela / 2 - escala * (y_mundo - camera_y) * altura_tela / 2
    tela_w = escala * largura_pista * largura_tela / 2
    return PontoProjetado(tela_x, tela_y, tela_w, escala)


def _facilitar_entrada(inicio, fim, fracao):
    return inicio + (fim - inicio) * (fracao ** 2)


def _facilitar_entrada_saida(inicio, fim, fracao):
    return inicio + (fim - inicio) * ((1 - math.cos(fracao * math.pi)) / 2)


def _cor_do_segmento(indice):
    par = (indice // cfg.SEGMENTOS_POR_FAIXA_COR) % 2 == 0
    cor_grama = cfg.COR_GRAMA if par else cfg.COR_GRAMA_ESCURA
    cor_asfalto = cfg.COR_ASFALTO if par else cfg.COR_ASFALTO_ESCURO
    cor_acostamento = cfg.COR_ACOSTAMENTO_CLARO if par else cfg.COR_ACOSTAMENTO_ESCURO
    tem_faixa_central = (indice // cfg.PERIODO_FAIXA_CENTRAL) % 2 == 0
    return cor_grama, cor_asfalto, cor_acostamento, tem_faixa_central


def _adicionar_segmento(segmentos, curva, altura):
    indice = len(segmentos)
    cor_grama, cor_asfalto, cor_acostamento, tem_faixa_central = _cor_do_segmento(indice)
    segmentos.append(Segmento(
        indice=indice,
        z=indice * cfg.COMPRIMENTO_SEGMENTO,
        curva=curva,
        altura=altura,
        cor_grama=cor_grama,
        cor_asfalto=cor_asfalto,
        cor_acostamento=cor_acostamento,
        tem_faixa_central=tem_faixa_central,
    ))


def _adicionar_trecho(segmentos, entrada, sustentacao, saida, curva, delta_altura):
    altura_inicial = segmentos[-1].altura if segmentos else 0.0
    altura_final = altura_inicial + delta_altura

    for n in range(entrada):
        _adicionar_segmento(
            segmentos,
            _facilitar_entrada(0.0, curva, n / entrada),
            _facilitar_entrada_saida(altura_inicial, altura_final, n / entrada),
        )
    for _ in range(sustentacao):
        _adicionar_segmento(segmentos, curva, altura_final)
    for n in range(saida):
        _adicionar_segmento(
            segmentos,
            _facilitar_entrada_saida(curva, 0.0, n / saida),
            altura_final,
        )


def construir_segmentos(trechos):
    segmentos = []
    for entrada, sustentacao, saida, curva, delta_altura in trechos:
        _adicionar_trecho(segmentos, entrada, sustentacao, saida, curva, delta_altura)
    return segmentos


class Pista:
    def __init__(self):
        self.segmentos = construir_segmentos(cfg.TRECHOS_PISTA)
        self.comprimento_total = len(self.segmentos) * cfg.COMPRIMENTO_SEGMENTO

    def segmento_atual(self, posicao_z):
        indice = int(posicao_z // cfg.COMPRIMENTO_SEGMENTO) % len(self.segmentos)
        return self.segmentos[indice]

    def altura_interpolada(self, indice, fracao):
        """Altura no ponto exato dentro do segmento `indice`, interpolando entre a
        borda próxima (altura do segmento anterior) e a borda distante (altura deste
        segmento) — usada para a câmera acompanhar a subida/descida com suavidade."""
        n = len(self.segmentos)
        altura_anterior = self.segmentos[(indice - 1) % n].altura
        altura_atual = self.segmentos[indice].altura
        return altura_anterior + (altura_atual - altura_anterior) * fracao

    def deslocamentos_laterais(self, indice_base, fracao):
        """Acúmulo de curvatura (x) por segmento visível a partir de indice_base.

        Usado tanto para desenhar a pista quanto para alinhar o tráfego com as curvas,
        já que os dois precisam do mesmo deslocamento lateral acumulado por segmento.
        """
        n = len(self.segmentos)
        segmento_base = self.segmentos[indice_base]
        x = 0.0
        dx = -(segmento_base.curva * fracao)
        valores = []
        for _ in range(cfg.DISTANCIA_DESENHO):
            segmento = self.segmentos[(indice_base + len(valores)) % n]
            valores.append(x)
            x += dx
            dx += segmento.curva
        return valores

    def desenhar(self, tela, carro):
        tela.fill(cfg.COR_CEU)

        n = len(self.segmentos)
        indice_base = int(carro.posicao_z // cfg.COMPRIMENTO_SEGMENTO) % n
        fracao = (carro.posicao_z % cfg.COMPRIMENTO_SEGMENTO) / cfg.COMPRIMENTO_SEGMENTO
        segmento_base = self.segmentos[indice_base]

        camera_y = cfg.ALTURA_CAMERA + self.altura_interpolada(indice_base, fracao)
        camera_x = carro.offset_x * (cfg.LARGURA_PISTA / 2)

        x = 0.0
        dx = -(segmento_base.curva * fracao)
        maxy = cfg.ALTURA_TELA

        for n_rel in range(cfg.DISTANCIA_DESENHO):
            indice = (indice_base + n_rel) % n
            segmento = self.segmentos[indice]
            altura_proxima = self.segmentos[(indice - 1) % n].altura  # borda de trás do segmento anterior
            z_perto = (n_rel - fracao) * cfg.COMPRIMENTO_SEGMENTO
            z_longe = z_perto + cfg.COMPRIMENTO_SEGMENTO

            p1 = p2 = None
            if z_perto > 1.0:
                p1 = projetar(x, altura_proxima, z_perto, camera_x, camera_y,
                               cfg.PROFUNDIDADE_CAMERA, cfg.LARGURA_TELA, cfg.ALTURA_TELA, cfg.LARGURA_PISTA)
                p2 = projetar(x + dx, segmento.altura, z_longe, camera_x, camera_y,
                               cfg.PROFUNDIDADE_CAMERA, cfg.LARGURA_TELA, cfg.ALTURA_TELA, cfg.LARGURA_PISTA)

            x += dx
            dx += segmento.curva

            if p1 is None or p2.tela_y >= p1.tela_y or p2.tela_y >= maxy:
                continue

            _renderizar_segmento(tela, p1, p2, segmento)
            maxy = p1.tela_y


def _renderizar_segmento(tela, p1, p2, segmento):
    largura_tela = cfg.LARGURA_TELA

    pygame.draw.polygon(tela, segmento.cor_grama, [
        (0, p2.tela_y), (largura_tela, p2.tela_y),
        (largura_tela, p1.tela_y), (0, p1.tela_y),
    ])

    largura_acostamento1 = p1.tela_w * cfg.FATOR_ACOSTAMENTO
    largura_acostamento2 = p2.tela_w * cfg.FATOR_ACOSTAMENTO
    pygame.draw.polygon(tela, segmento.cor_acostamento, [
        (p1.tela_x - largura_acostamento1, p1.tela_y), (p1.tela_x + largura_acostamento1, p1.tela_y),
        (p2.tela_x + largura_acostamento2, p2.tela_y), (p2.tela_x - largura_acostamento2, p2.tela_y),
    ])

    pygame.draw.polygon(tela, segmento.cor_asfalto, [
        (p1.tela_x - p1.tela_w, p1.tela_y), (p1.tela_x + p1.tela_w, p1.tela_y),
        (p2.tela_x + p2.tela_w, p2.tela_y), (p2.tela_x - p2.tela_w, p2.tela_y),
    ])

    if segmento.tem_faixa_central:
        largura_faixa1 = p1.tela_w * cfg.FATOR_FAIXA_CENTRAL
        largura_faixa2 = p2.tela_w * cfg.FATOR_FAIXA_CENTRAL
        pygame.draw.polygon(tela, cfg.COR_FAIXA_CENTRAL, [
            (p1.tela_x - largura_faixa1, p1.tela_y), (p1.tela_x + largura_faixa1, p1.tela_y),
            (p2.tela_x + largura_faixa2, p2.tela_y), (p2.tela_x - largura_faixa2, p2.tela_y),
        ])
