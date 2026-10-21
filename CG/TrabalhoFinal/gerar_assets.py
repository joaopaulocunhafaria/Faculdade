"""Gera os sprites do carro do jogador e do tráfego (assets/carro.png e
assets/carro_trafego.png), vistos de trás, usando Pillow.

A pista não é mais uma imagem — é renderizada a cada frame pelo motor de
segmentos em pista.py — então este script não gera mais nenhum arquivo de pista.

Rodar uma única vez antes de jogar:
    ./venv/bin/python TrabalhoFinal/gerar_assets.py
"""

import os

from PIL import Image, ImageDraw

import configuracoes as cfg


def _desenhar_carro_visto_de_tras(largura, altura, cor_chassi, cor_janela, cor_lanterna):
    imagem = Image.new("RGBA", (largura, altura), (0, 0, 0, 0))
    desenho = ImageDraw.Draw(imagem)

    desenho.rounded_rectangle(
        [2, 6, largura - 3, altura - 3],
        radius=10,
        fill=cor_chassi,
        outline=(0, 0, 0, 255),
        width=2,
    )

    margem_x = largura // 6
    desenho.rounded_rectangle(
        [margem_x, 10, largura - margem_x, altura // 2],
        radius=6,
        fill=cor_janela,
    )

    largura_lanterna = largura // 6
    altura_lanterna = altura // 8
    desenho.rectangle(
        [8, altura - altura_lanterna - 8, 8 + largura_lanterna, altura - 8],
        fill=cor_lanterna,
    )
    desenho.rectangle(
        [largura - 8 - largura_lanterna, altura - altura_lanterna - 8, largura - 8, altura - 8],
        fill=cor_lanterna,
    )

    return imagem


def gerar_sprite_carro_jogador():
    imagem = _desenhar_carro_visto_de_tras(
        cfg.CARRO_SPRITE_LARGURA, cfg.CARRO_SPRITE_ALTURA,
        cfg.COR_CARRO_CHASSI, cfg.COR_CARRO_JANELA_TRASEIRA, cfg.COR_CARRO_LANTERNA,
    )
    imagem.save(cfg.CAMINHO_SPRITE_CARRO)
    print(f"Sprite do carro do jogador salvo em: {cfg.CAMINHO_SPRITE_CARRO}")


def gerar_sprite_carro_trafego():
    imagem = _desenhar_carro_visto_de_tras(
        cfg.CARRO_TRAFEGO_LARGURA, cfg.CARRO_TRAFEGO_ALTURA,
        cfg.COR_TRAFEGO_CHASSI, cfg.COR_TRAFEGO_JANELA, cfg.COR_CARRO_LANTERNA,
    )
    imagem.save(cfg.CAMINHO_SPRITE_CARRO_TRAFEGO)
    print(f"Sprite do carro de tráfego salvo em: {cfg.CAMINHO_SPRITE_CARRO_TRAFEGO}")


def main():
    os.makedirs(cfg.DIRETORIO_ASSETS, exist_ok=True)
    gerar_sprite_carro_jogador()
    gerar_sprite_carro_trafego()


if __name__ == "__main__":
    main()
