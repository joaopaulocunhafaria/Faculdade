import colorsys
import os

from PIL import Image

DIRETORIO_SCRIPT = os.path.dirname(os.path.abspath(__file__))
DIRETORIO_IMAGENS = os.path.join(DIRETORIO_SCRIPT, "imgs")

EXTENSOES_VALIDAS = (".png", ".jpg", ".jpeg", ".bmp")


def aplicar_chroma_key(imagem, h_min_graus=90, h_max_graus=150, s_minima_pct=20, v_minima_pct=15):
    """
    Remove o fundo verde de uma imagem, tornando-o transparente (Alpha = 0).

    A detecção é feita no espaço HSV, não no RGB: um pixel é considerado
    fundo quando seu Matiz (Hue) cai dentro da janela de tolerância ao
    redor do verde puro (120°), independente de quão claro ou escuro
    (Saturação/Brilho) ele esteja — cobrindo tanto um "verde limão" claro
    quanto um "verde musgo" escurecido por sombra.

    Pixels quase brancos/cinzas (Saturação baixa) ou quase pretos
    (Brilho baixo) são ignorados mesmo com o Matiz na faixa, pois neles
    o Matiz deixa de ser um indicador confiável de cor.

    :param h_min_graus: início da janela de tolerância do Matiz, em graus.
    :param h_max_graus: fim da janela de tolerância do Matiz, em graus.
    :param s_minima_pct: Saturação mínima (%) para o pixel contar como verde.
    :param v_minima_pct: Brilho mínimo (%) para o pixel contar como verde.
    """
    imagem_rgba = imagem.convert("RGBA")
    pixels = imagem_rgba.load()
    largura, altura = imagem_rgba.size

    h_min_norm = h_min_graus / 360.0
    h_max_norm = h_max_graus / 360.0
    s_minima_norm = s_minima_pct / 100.0
    v_minima_norm = v_minima_pct / 100.0

    for x in range(largura):
        for y in range(altura):
            r, g, b, a = pixels[x, y]
            h, s, v = colorsys.rgb_to_hsv(r / 255.0, g / 255.0, b / 255.0)

            matiz_eh_verde = h_min_norm <= h <= h_max_norm
            cor_eh_relevante = s >= s_minima_norm and v >= v_minima_norm

            if matiz_eh_verde and cor_eh_relevante:
                pixels[x, y] = (r, g, b, 0)

    return imagem_rgba


def processar_imagens_do_diretorio():
    """Aplica o chroma key em toda imagem encontrada em Aula7/imgs."""
    if not os.path.isdir(DIRETORIO_IMAGENS):
        print(f"[Chroma Key] Diretório não encontrado: {DIRETORIO_IMAGENS}")
        print("Crie a pasta 'imgs' e coloque uma imagem com fundo verde nela.")
        return

    arquivos = sorted(
        nome
        for nome in os.listdir(DIRETORIO_IMAGENS)
        if nome.lower().endswith(EXTENSOES_VALIDAS) and "_chroma_key" not in nome
    )

    if not arquivos:
        print(f"[Chroma Key] Nenhuma imagem encontrada em: {DIRETORIO_IMAGENS}")
        return

    for nome_arquivo in arquivos:
        caminho_entrada = os.path.join(DIRETORIO_IMAGENS, nome_arquivo)
        imagem = Image.open(caminho_entrada)

        imagem_recortada = aplicar_chroma_key(imagem)

        nome_base, _ = os.path.splitext(nome_arquivo)
        caminho_saida = os.path.join(DIRETORIO_IMAGENS, f"{nome_base}_chroma_key.png")
        imagem_recortada.save(caminho_saida)
        print(f"[Chroma Key] {nome_arquivo} -> {os.path.basename(caminho_saida)}")


if __name__ == "__main__":
    processar_imagens_do_diretorio()
