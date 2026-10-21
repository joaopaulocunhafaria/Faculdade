# aula 3 - 12 de agosto de 2026

from PIL import Image

def renderizar_circulo(fator_qualidade):
    """
        O parâmetro fator_qualidade vai funcionar como um multiplicador da resolução da imagem

        A resolução padrão será: tela de 300x300 e raio 50

        Se fator = 0.1 -> Tela vira 30x30, Raio vira 5 (Muito pixelado)
        Se fator = 1.0 -> Tela 
    
    """

def main():
    print("Iniciando Rasterização do círculo...")

     # Define a resolução da Tela 300x300
    largura_tela, altura_tela = 300 * 2 , 300 * 2
    img = Image.new("RGB", (largura_tela, altura_tela), color="white")

    # propriedade matemáticas do círculo
    centro_x = 150 * 2
    centro_y = 150 * 2
    raio = 50
   
    raio_quadrado = raio ** 2

    # aqui to definindo apenas o quadrado onde o círculo pode existir
    x_min = centro_x - raio
    x_max = centro_x + raio
    y_min = centro_y - raio
    y_max = centro_y + raio

    # Simulação do proesso de Rasterização
    for x in range(x_min, x_max + 1):
        for y in range(y_min, y_max + 1):
            # calcula a distância
            distancia_quadrada = (x - centro_x) ** 2 + (y - centro_y) ** 2

            # Se a distância do pixel (x,y) até o centro for menor ou igual ao raio
            if distancia_quadrada <= raio_quadrado:
                # o pixel pertence ao círculo! Pinta de vermelho.
                img.putpixel((x, y), (255, 0, 0))

    # Salva a imagem na pasta de execução do script
    img.save("circulo_rasterizado.png")
    print("Círculo salvo como 'circulo_rasterizado.png'")


if __name__ == "__main__":
    main()