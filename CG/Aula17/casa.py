import os
import glfw
from OpenGL.GL import *
import OpenGL.GL.shaders
import numpy as np
from PIL import Image 

# HADERS com suporte a textura
VERTEX_SHADER = """
#version 330 core
layout (location = 0) in vec3 aPos;     // Porta 0: Geometria (X, Y, Z)
layout (location = 1) in vec2 aTexCord; // Porta 1: Mapeamento (U, V)

out vec2 TexCord; // Passa o UV para o Fragment Shader
uniform mat4 MVP; // Matriz Mestre

void main() {
    gl_Position = MVP * vec4(aPos, 1.0);
    TexCord = aTexCord;
}
"""

FRAGMENT_SHADER = """
#version 330 core
in vec2 TexCord;
out vec4 FragColor;

// Slot de memória da GPU onde a imagem estará vinculada
uniform sampler2D textura_bloco;

void main() {
    // Lê a cor exata do pixel da textura naquela coordenada UV
    FragColor = texture(textura_bloco, TexCord);
}
"""

# Ler a imagem do HD
def carregar_textura_do_disco(caminho_arquivo):
    print(f"Carregando: {caminho_arquivo}...")
    
    try:
        # abre o arquivo e o joga na memória RAM da CPU
        imagem = Image.open(caminho_arquivo)
        
        # ATENÇÃO AQUI: O OpenGL considera a coordenada (0,0) da imagem 
        # no canto INFERIOR esquerdo. As imagens de computador padrão usam (0,0) no
        # canto SUPERIOR esquerdo. 
        # Precisamos inverter a imagem verticalmente!
        imagem = imagem.transpose(Image.FLIP_TOP_BOTTOM)
        
        # Converte para RGBA para garantir que teremos 4 canais (Red, Green, Blue, Alpha)
        imagem_dados = imagem.convert("RGBA").tobytes()
        largura, altura = imagem.size
        print(f" deu certim: {largura}x{altura}")
        
    except FileNotFoundError:
        print(" ixi, deu ruim. Gerando textura de 'Erro' (Rosa/Preto)...")
        largura, altura = 2, 2
        imagem_dados = np.array([
            255, 0, 255, 255,   0, 0, 0, 255, # Linha inferior (Rosa, Preto)
            0, 0, 0, 255,       255, 0, 255, 255  # Linha superior (Preto, Rosa)
        ], dtype=np.uint8).tobytes()

    # RAM -> VRAM: 1 ID de Textura para a GPU
    textura_id = glGenTextures(1)
    
    # liga a textura 
    glBindTexture(GL_TEXTURE_2D, textura_id)

    # comfigura para alto realismo (Filtro Bilinear/Trilinear)
    # O filtro MIN atua quando a imagem está longe. 
    # O filtro MAG atua quando a câmera chega muito perto.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)
    
    # Configuração de Repetição 
    # Se o UV passar de 1.0, a imagem se repete como papel de parede
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT)

    # envia os bytes da RAM (CPU) para a VRAM (Placa de Vídeo)
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, largura, altura, 
                 0, GL_RGBA, GL_UNSIGNED_BYTE, imagem_dados)
    
    # geração de Mipmaps 
    # isso que evita o "serrilhado piscante" quando a textura está muito longe ou inclinada.
    glGenerateMipmap(GL_TEXTURE_2D)
    
    #fecha a textura 
    glBindTexture(GL_TEXTURE_2D, 0)

    return textura_id
    # fim do método carregar_textura_do_disco 


# Envia vértices + índices para a GPU (mesmos passos do cubo da aula)
# Como agora temos 4 objetos (corpo, telhado, porta, janelas),
# colocamos esses passos numa função para não repetir o bloco 4 vezes.
def criar_vao(vertices, indices):
    # MEMÓRIA DA GPU
    VAO = glGenVertexArrays(1)
    VBO = glGenBuffers(1)
    EBO = glGenBuffers(1)

    glBindVertexArray(VAO)
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO)
    glBufferData(GL_ARRAY_BUFFER, vertices.nbytes, vertices, GL_STATIC_DRAW)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO)
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.nbytes, indices, GL_STATIC_DRAW)

    # passo da memória: 5 floats por vértice (X, Y, Z, U, V)
    passo = 5 * vertices.itemsize
    
    # Atributo 0: geometria (3 floats). Offset = 0.
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, passo, ctypes.c_void_p(0))
    glEnableVertexAttribArray(0)
    
    # Atributo 1: Textura UV (2 floats). Offset = Pule os 3 primeiros floats (3 * bytes do float).
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, passo, ctypes.c_void_p(3 * vertices.itemsize))
    glEnableVertexAttribArray(1)
    
    glBindVertexArray(0) # Fecha o VAO

    return VAO
    # fim do método criar_vao


def matriz_perspectiva(fov, aspecto, perto, longe):
    f = 1.0 / np.tan(np.radians(fov) / 2.0)
    m = np.zeros((4, 4), dtype=np.float32)
    m[0,0] = f / aspecto; m[1,1] = f; m[2,2] = (longe + perto) / (perto - longe)
    m[2,3] = (2.0 * longe * perto) / (perto - longe); m[3,2] = -1.0
    return m

def matriz_translacao(x, y, z): 
    return np.array(
        [[1,0,0,x], 
         [0,1,0,y], 
         [0,0,1,z], 
         [0,0,0,1]
         ], dtype=np.float32)

def matriz_rotacao_x(g): 
    c,s = np.cos(np.radians(g)), np.sin(np.radians(g)); 
    return np.array([
        [1,0,0,0], 
        [0,c,-s,0], 
        [0,s,c,0], 
        [0,0,0,1]
        ], dtype=np.float32)

def matriz_rotacao_y(g): 
    c,s = np.cos(np.radians(g)), np.sin(np.radians(g)); 
    return np.array([
        [c,0,s,0], 
        [0,1,0,0], 
        [-s,0,c,0], 
        [0,0,0,1]
        ], dtype=np.float32)


def main():
    if not glfw.init(): return
    glfw.window_hint(glfw.CONTEXT_VERSION_MAJOR, 3)
    glfw.window_hint(glfw.CONTEXT_VERSION_MINOR, 3)
    glfw.window_hint(glfw.OPENGL_PROFILE, glfw.OPENGL_CORE_PROFILE)

    janela = glfw.create_window(800, 600, "Casa: Filtro Linear + Mipmaps", None, None)
    if not janela:
        glfw.terminate()
        return

    glfw.make_context_current(janela)
    glfw.swap_interval(1) # VSync: trava na taxa de atualização do monitor
    glEnable(GL_DEPTH_TEST) # Z-Buffer ativado (esconde a face de trás)

    shader = OpenGL.GL.shaders.compileProgram(
        OpenGL.GL.shaders.compileShader(VERTEX_SHADER, GL_VERTEX_SHADER),
        OpenGL.GL.shaders.compileShader(FRAGMENT_SHADER, GL_FRAGMENT_SHADER),
        validate=False  # Evita erro "No vertex array object bound" na validação
    )

    # =========================================================
    # 1) CORPO DA CASA: o mesmo cubo da aula
    # 24 Vértices (4 por face) 
    # Formato: [ X, Y, Z,   U, V ]
    # =========================================================
    vertices_corpo = np.array([
        # Face Frontal (Z = 0.5)
        -0.5, -0.5,  0.5,   0.0, 0.0, # Canto Inferior Esquerdo
         0.5, -0.5,  0.5,   1.0, 0.0, # Canto Inferior Direito
         0.5,  0.5,  0.5,   1.0, 1.0, # Canto Superior Direito
        -0.5,  0.5,  0.5,   0.0, 1.0, # Canto Superior Esquerdo

        # Face Traseira (Z = -0.5)
        -0.5, -0.5, -0.5,   1.0, 0.0,
         0.5, -0.5, -0.5,   0.0, 0.0,
         0.5,  0.5, -0.5,   0.0, 1.0,
        -0.5,  0.5, -0.5,   1.0, 1.0,

        # Face Esquerda (X = -0.5)
        -0.5, -0.5, -0.5,   0.0, 0.0,
        -0.5, -0.5,  0.5,   1.0, 0.0,
        -0.5,  0.5,  0.5,   1.0, 1.0,
        -0.5,  0.5, -0.5,   0.0, 1.0,

        # Face Direita (X = 0.5)
         0.5, -0.5, -0.5,   1.0, 0.0,
         0.5, -0.5,  0.5,   0.0, 0.0,
         0.5,  0.5,  0.5,   0.0, 1.0,
         0.5,  0.5, -0.5,   1.0, 1.0,

        # Face Superior (Y = 0.5)
        -0.5,  0.5, -0.5,   0.0, 1.0,
         0.5,  0.5, -0.5,   1.0, 1.0,
         0.5,  0.5,  0.5,   1.0, 0.0,
        -0.5,  0.5,  0.5,   0.0, 0.0,

        # Face Inferior (Y = -0.5)
        -0.5, -0.5, -0.5,   0.0, 0.0,
         0.5, -0.5, -0.5,   1.0, 0.0,
         0.5, -0.5,  0.5,   1.0, 1.0,
        -0.5, -0.5,  0.5,   0.0, 1.0,
    ], dtype=np.float32)

    # conectando os vértices em triângulos
    indices_corpo = np.array([
        0, 1, 2,  2, 3, 0,       # Frontal
        4, 5, 6,  6, 7, 4,       # Traseira
        8, 9, 10, 10, 11, 8,     # Esquerda
        12, 13, 14, 14, 15, 12,  # Direita
        16, 17, 18, 18, 19, 16,  # Superior
        20, 21, 22, 22, 23, 20   # Inferior
    ], dtype=np.uint32)

    # =========================================================
    # 2) TELHADO: pirâmide de base quadrada em cima do cubo
    # Base em Y = 0.5 (topo do cubo), um pouco maior (0.6) para
    # o telhado "sobrar" nas bordas. Ponta (ápice) em Y = 1.1.
    # Cada face triangular tem seus próprios 3 vértices (igual ao
    # cubo, que tem 4 por face) para cada uma ter seu próprio UV.
    # UV do triângulo: base (0,0)-(1,0) e ponta no meio (0.5, 1).
    # =========================================================
    vertices_telhado = np.array([
        # Face Frontal (Z = 0.6)
        -0.6,  0.5,  0.6,   0.0, 0.0, # Base esquerda
         0.6,  0.5,  0.6,   1.0, 0.0, # Base direita
         0.0,  1.1,  0.0,   0.5, 1.0, # Ponta

        # Face Traseira (Z = -0.6)
         0.6,  0.5, -0.6,   0.0, 0.0,
        -0.6,  0.5, -0.6,   1.0, 0.0,
         0.0,  1.1,  0.0,   0.5, 1.0,

        # Face Esquerda (X = -0.6)
        -0.6,  0.5, -0.6,   0.0, 0.0,
        -0.6,  0.5,  0.6,   1.0, 0.0,
         0.0,  1.1,  0.0,   0.5, 1.0,

        # Face Direita (X = 0.6)
         0.6,  0.5,  0.6,   0.0, 0.0,
         0.6,  0.5, -0.6,   1.0, 0.0,
         0.0,  1.1,  0.0,   0.5, 1.0,

        # Base (Y = 0.5) - fecha a parte de baixo do telhado
        -0.6,  0.5, -0.6,   0.0, 0.0,
         0.6,  0.5, -0.6,   1.0, 0.0,
         0.6,  0.5,  0.6,   1.0, 1.0,
        -0.6,  0.5,  0.6,   0.0, 1.0,
    ], dtype=np.float32)

    indices_telhado = np.array([
        0, 1, 2,                 # Frontal
        3, 4, 5,                 # Traseira
        6, 7, 8,                 # Esquerda
        9, 10, 11,               # Direita
        12, 13, 14, 14, 15, 12   # Base (2 triângulos)
    ], dtype=np.uint32)

    # =========================================================
    # 3) PORTA: retângulo na face frontal
    # A face frontal do cubo está em Z = 0.5. Colocamos a porta em
    # Z = 0.505, só um pouquinho à frente. Se ficasse exatamente em
    # 0.5, o Z-Buffer não saberia quem desenhar e as duas texturas
    # ficariam "brigando" (piscando) - isso se chama Z-fighting.
    # =========================================================
    vertices_porta = np.array([
        -0.12, -0.5,  0.505,   0.0, 0.0, # Canto Inferior Esquerdo
         0.12, -0.5,  0.505,   1.0, 0.0, # Canto Inferior Direito
         0.12,  0.1,  0.505,   1.0, 1.0, # Canto Superior Direito
        -0.12,  0.1,  0.505,   0.0, 1.0, # Canto Superior Esquerdo
    ], dtype=np.float32)

    indices_porta = np.array([
        0, 1, 2,  2, 3, 0
    ], dtype=np.uint32)

    # =========================================================
    # 4) JANELAS: quadrados de 0.2 x 0.2
    # Duas na frente (ao lado da porta) e uma em cada lateral.
    # Mesma ideia da porta: 0.005 para fora da parede.
    # =========================================================
    vertices_janelas = np.array([
        # Janela Frontal Esquerda (Z = 0.505)
        -0.4,  0.0,  0.505,   0.0, 0.0,
        -0.2,  0.0,  0.505,   1.0, 0.0,
        -0.2,  0.2,  0.505,   1.0, 1.0,
        -0.4,  0.2,  0.505,   0.0, 1.0,

        # Janela Frontal Direita (Z = 0.505)
         0.2,  0.0,  0.505,   0.0, 0.0,
         0.4,  0.0,  0.505,   1.0, 0.0,
         0.4,  0.2,  0.505,   1.0, 1.0,
         0.2,  0.2,  0.505,   0.0, 1.0,

        # Janela Lateral Esquerda (X = -0.505)
        -0.505,  0.0, -0.1,   0.0, 0.0,
        -0.505,  0.0,  0.1,   1.0, 0.0,
        -0.505,  0.2,  0.1,   1.0, 1.0,
        -0.505,  0.2, -0.1,   0.0, 1.0,

        # Janela Lateral Direita (X = 0.505)
         0.505,  0.0,  0.1,   0.0, 0.0,
         0.505,  0.0, -0.1,   1.0, 0.0,
         0.505,  0.2, -0.1,   1.0, 1.0,
         0.505,  0.2,  0.1,   0.0, 1.0,
    ], dtype=np.float32)

    indices_janelas = np.array([
        0, 1, 2,  2, 3, 0,       # Frontal Esquerda
        4, 5, 6,  6, 7, 4,       # Frontal Direita
        8, 9, 10, 10, 11, 8,     # Lateral Esquerda
        12, 13, 14, 14, 15, 12   # Lateral Direita
    ], dtype=np.uint32)

    # MEMÓRIA DA GPU: um VAO para cada parte da casa
    VAO_corpo   = criar_vao(vertices_corpo, indices_corpo)
    VAO_telhado = criar_vao(vertices_telhado, indices_telhado)
    VAO_porta   = criar_vao(vertices_porta, indices_porta)
    VAO_janelas = criar_vao(vertices_janelas, indices_janelas)

    matriz_proj = matriz_perspectiva(45.0, 800/600, 0.1, 100.0)
    # Câmera um pouco mais longe (-4.0) e casa descida (-0.3)
    # para caber o telhado inteiro na tela
    matriz_view = matriz_translacao(0, -0.3, -4.0) 
    
    # Lendo os arquivos do disco! Uma textura para cada parte.
    # As imagens ficam em Aula17/texturas/ (geradas pelo gerar_texturas.py).
    # O caminho é montado a partir da pasta deste script, então funciona
    # de qualquer diretório em que o terminal estiver.
    # Se algum arquivo não existir, aparece a textura de Erro (Rosa/Preto).
    pasta_texturas = os.path.join(os.path.dirname(os.path.abspath(__file__)), "texturas")
    textura_corpo   = carregar_textura_do_disco(os.path.join(pasta_texturas, "tijolos.png"))
    textura_telhado = carregar_textura_do_disco(os.path.join(pasta_texturas, "telhado.png"))
    textura_porta   = carregar_textura_do_disco(os.path.join(pasta_texturas, "madeira.png"))
    textura_janela  = carregar_textura_do_disco(os.path.join(pasta_texturas, "vidro.png"))

    loc_mvp = glGetUniformLocation(shader, "MVP")
    loc_tex = glGetUniformLocation(shader, "textura_bloco")

    rot_x, rot_y = 25.0, -30.0
    velocidade = 2.0

    print("Tudo pronto...")

    # loop de renderização
    while not glfw.window_should_close(janela):
        glfw.poll_events()

        # entrada do teclado 
        if glfw.get_key(janela, glfw.KEY_RIGHT) == glfw.PRESS: rot_y += velocidade
        if glfw.get_key(janela, glfw.KEY_LEFT) == glfw.PRESS:  rot_y -= velocidade
        if glfw.get_key(janela, glfw.KEY_DOWN) == glfw.PRESS:  rot_x += velocidade
        if glfw.get_key(janela, glfw.KEY_UP) == glfw.PRESS:    rot_x -= velocidade

        # cor de fundo
        glClearColor(0.5, 0.8, 1.0, 1.0) 
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)

        glUseProgram(shader)

        # atualiza a Matriz MVP (a mesma para todas as partes,
        # assim a casa inteira gira junta)
        matriz_model = matriz_rotacao_x(rot_x) @ matriz_rotacao_y(rot_y)
        MVP = matriz_proj @ matriz_view @ matriz_model
        glUniformMatrix4fv(loc_mvp, 1, GL_FALSE, np.ascontiguousarray(MVP.T, dtype=np.float32))

        # Todas as texturas usam o Slot 0; só trocamos qual está ligada
        glActiveTexture(GL_TEXTURE0)
        # Avisa o Fragment Shader para ler do Slot 0
        glUniform1i(loc_tex, 0) 

        # CORPO: 36 vértices indexados (12 triângulos)
        glBindTexture(GL_TEXTURE_2D, textura_corpo)
        glBindVertexArray(VAO_corpo)
        glDrawElements(GL_TRIANGLES, len(indices_corpo), GL_UNSIGNED_INT, None)

        # TELHADO: 18 vértices indexados (6 triângulos)
        glBindTexture(GL_TEXTURE_2D, textura_telhado)
        glBindVertexArray(VAO_telhado)
        glDrawElements(GL_TRIANGLES, len(indices_telhado), GL_UNSIGNED_INT, None)

        # PORTA: 6 vértices indexados (2 triângulos)
        glBindTexture(GL_TEXTURE_2D, textura_porta)
        glBindVertexArray(VAO_porta)
        glDrawElements(GL_TRIANGLES, len(indices_porta), GL_UNSIGNED_INT, None)

        # JANELAS: 24 vértices indexados (8 triângulos)
        glBindTexture(GL_TEXTURE_2D, textura_janela)
        glBindVertexArray(VAO_janelas)
        glDrawElements(GL_TRIANGLES, len(indices_janelas), GL_UNSIGNED_INT, None)

        glfw.swap_buffers(janela)
        # fim do while 

    glfw.terminate()
    # fim do main

if __name__ == "__main__":
    main()