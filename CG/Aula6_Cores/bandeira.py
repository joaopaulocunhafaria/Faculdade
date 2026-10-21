from PIL import Image, ImageDraw

def criar_fundo_rgb(largura, altura, cor_rgb):
    """
    Cria uma imagem RGB com uma cor sólida
    """
    # Imagem.new aloca a matriz na memória.
    fundo = Image.new("RGB", (largura, altura), cor_rgb)

    # Retorna a imagem
    return fundo

def criar_losango_rgb(largura, altura, cor_rgb, bandeira):
    """
    Cria um losango RGB
    """
    
    # Ativando modo de sobreescrever pixels
    losango = ImageDraw.Draw(bandeira)

    # Coordenadas do losango
    pontoA = (largura / 2, altura * 0.05)
    pontoB = (largura * 0.95, altura / 2)
    pontoC = (largura / 2, altura * 0.95)
    pontoD = (altura * 0.05, altura / 2)

    # Lista de coordenadas para desenhar o losango
    coordenadas = [(pontoA), (pontoB), (pontoC), (pontoD)]

    # Criar o losango
    losango.polygon(coordenadas, fill=cor_rgb)

    # Retornar 
    return bandeira


def criar_esfera_rgb(largura, altura, cor_rgb, bandeira):
    """
    Cria uma esfera RGB
    """

    # Ativando modo de sobreescrever pixels
    esfera = ImageDraw.Draw(bandeira)

    # Coordenadas da esfera (dois ponto, superior esquerdo e inferior direit)
    centro_x = largura / 2
    centro_y = altura / 2

    # Raio da esfera
    raio = largura * 0.20

    # Coordenadas do quadrado que envolve a esfera
    pontoA = (centro_x - raio, centro_y - raio)
    pontoB = (centro_x + raio, centro_y + raio)

    # Lista de coordenadas para desenhar a esfera
    coordenadas = [(pontoA), (pontoB)]

    # Criar a esfera
    esfera.ellipse(coordenadas, fill=cor_rgb)

    # Retornar 
    return bandeira


if __name__ == "__main__":
    # dimensões da imagem 
    LARGURA = 2400
    ALTURA = 1600

    # Testando a cor Verde: (0, 148, 64) RGB
    cor_verde_rgb = (0, 148, 64)
    print(f"Cor Verde em RGB: {cor_verde_rgb}")

    # Criar o fundo da bandeira
    bandeira = criar_fundo_rgb(LARGURA, ALTURA, cor_verde_rgb)

    # Testando a cor Amarela: (255, 255, 0) RGB
    cor_amarela_rgb = (255, 255, 0)
    print(f"Cor Amarela em RGB: {cor_amarela_rgb}")

    # Criar o losango
    bandeira = criar_losango_rgb(LARGURA, ALTURA, cor_amarela_rgb, bandeira)

    # Testando a cor Azul: (0, 0, 255) RGB
    cor_azul_rgb = (0, 0, 255)
    print(f"Cor Azul em RGB: {cor_azul_rgb}")

    # Criar a esfera
    bandeira = criar_esfera_rgb(LARGURA, ALTURA, cor_azul_rgb, bandeira)

    # Salvar a imagem
    bandeira.save("bandeira.png")

    