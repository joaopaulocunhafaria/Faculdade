import os
import numpy as np
from PIL import Image, ImageDraw, ImageFilter

# Gera as 4 texturas da casa (tijolo, telhado, madeira, vidro) com Pillow,
# para o casa.py não depender de imagens baixadas da internet.
# As imagens são salvas em Aula17/texturas/, ao lado deste script.

TAMANHO = 256
PASTA = os.path.join(os.path.dirname(os.path.abspath(__file__)), "texturas")

rng = np.random.default_rng(42)  # semente fixa: sempre gera as mesmas imagens


def adicionar_ruido(imagem, intensidade):
    # Soma um ruído aleatório em cada pixel para a textura não ficar "chapada"
    pixels = np.asarray(imagem, dtype=np.int16)
    ruido = rng.integers(-intensidade, intensidade + 1, pixels.shape[:2])
    pixels = pixels + ruido[:, :, None]
    return Image.fromarray(np.clip(pixels, 0, 255).astype(np.uint8))


def gerar_tijolos():
    imagem = Image.new("RGB", (TAMANHO, TAMANHO), (170, 165, 155))  # cor do rejunte
    desenho = ImageDraw.Draw(imagem)

    altura_tijolo, largura_tijolo, rejunte = 32, 64, 4
    for linha in range(TAMANHO // altura_tijolo):
        y = linha * altura_tijolo
        # linhas ímpares deslocadas meio tijolo (assentamento "amarração")
        deslocamento = (largura_tijolo // 2) if linha % 2 else 0
        for coluna in range(-1, TAMANHO // largura_tijolo + 1):
            x = coluna * largura_tijolo + deslocamento
            r = int(rng.integers(140, 190))
            cor = (r, int(r * 0.42), int(r * 0.30))
            desenho.rectangle([x + rejunte, y + rejunte,
                               x + largura_tijolo - 1, y + altura_tijolo - 1], fill=cor)

    return adicionar_ruido(imagem, 18)


def gerar_telhado():
    imagem = Image.new("RGB", (TAMANHO, TAMANHO))
    pixels = np.zeros((TAMANHO, TAMANHO, 3), dtype=np.float32)

    # Cada fileira de telhas é um degradê: clara em cima e escura embaixo,
    # e cada telha é uma "onda" no eixo X (telha colonial)
    altura_fileira, largura_telha = 32, 32
    ys = np.arange(TAMANHO)[:, None]
    xs = np.arange(TAMANHO)[None, :]
    luz_fileira = 1.0 - 0.55 * ((ys % altura_fileira) / altura_fileira)
    deslocamento = (ys // altura_fileira % 2) * (largura_telha // 2)
    luz_onda = 0.75 + 0.25 * np.cos(2 * np.pi * (xs + deslocamento) / largura_telha)
    luz = luz_fileira * luz_onda

    pixels[:, :, 0] = 235 * luz
    pixels[:, :, 1] = 95 * luz
    pixels[:, :, 2] = 45 * luz
    imagem = Image.fromarray(np.clip(pixels, 0, 255).astype(np.uint8))
    return adicionar_ruido(imagem, 8)


def gerar_madeira():
    pixels = np.zeros((TAMANHO, TAMANHO, 3), dtype=np.float32)

    # Tábuas verticais com veios ondulados (seno no eixo X que varia com Y)
    largura_tabua = 64
    ys = np.arange(TAMANHO)[:, None]
    xs = np.arange(TAMANHO)[None, :]
    veio = np.sin((xs + 6 * np.sin(ys / 23.0)) * 0.6) * 0.5 + 0.5
    luz = 0.75 + 0.25 * veio
    # frestas escuras entre as tábuas
    luz = np.where(xs % largura_tabua < 3, 0.35, luz)
    # barras horizontais (travessas) da porta
    travessa = ((ys > 40) & (ys < 56)) | ((ys > 200) & (ys < 216))
    luz = np.where(travessa, luz * 0.8, luz)

    pixels[:, :, 0] = 150 * luz
    pixels[:, :, 1] = 100 * luz
    pixels[:, :, 2] = 55 * luz
    imagem = Image.fromarray(np.clip(pixels, 0, 255).astype(np.uint8))
    return adicionar_ruido(imagem, 6)


def gerar_vidro():
    imagem = Image.new("RGB", (TAMANHO, TAMANHO), (150, 200, 230))
    desenho = ImageDraw.Draw(imagem)

    # Reflexos diagonais claros no vidro
    for inicio in (40, 70, 150):
        desenho.polygon([(inicio, 0), (inicio + 25, 0),
                         (inicio + 25 - TAMANHO, TAMANHO), (inicio - TAMANHO, TAMANHO)],
                        fill=(205, 232, 248))
    imagem = imagem.filter(ImageFilter.GaussianBlur(4))

    # Moldura e cruz de madeira branca (4 vidraças)
    desenho = ImageDraw.Draw(imagem)
    moldura = 18
    branco = (240, 240, 235)
    desenho.rectangle([0, 0, TAMANHO - 1, TAMANHO - 1], outline=branco, width=moldura)
    meio = TAMANHO // 2
    desenho.rectangle([meio - moldura // 2, 0, meio + moldura // 2, TAMANHO], fill=branco)
    desenho.rectangle([0, meio - moldura // 2, TAMANHO, meio + moldura // 2], fill=branco)
    return imagem


def main():
    os.makedirs(PASTA, exist_ok=True)
    texturas = {
        "tijolos.png": gerar_tijolos(),
        "telhado.png": gerar_telhado(),
        "madeira.png": gerar_madeira(),
        "vidro.png": gerar_vidro(),
    }
    for nome, imagem in texturas.items():
        caminho = os.path.join(PASTA, nome)
        imagem.save(caminho)
        print(f"Salvo: {caminho}")


if __name__ == "__main__":
    main()
