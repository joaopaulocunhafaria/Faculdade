import glfw
from OpenGL.GL import *
import OpenGL.GL.shaders
import numpy as np

# SHADERS (A GPU pintando o prisma)
VERTEX_SHADER = """
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 vertexColor;
uniform mat4 MVP;

void main() {
    gl_Position = MVP * vec4(aPos, 1.0);
    vertexColor = aColor; // Repassa a cor para o fragmento
}
"""

FRAGMENT_SHADER = """
#version 330 core
in vec3 vertexColor;
out vec4 FragColor;

void main() {
    FragColor = vec4(vertexColor, 1.0); // Pinta a tela
}
"""

def matriz_perspectiva(fov, aspecto, perto, longe):
    f = 1.0 / np.tan(np.radians(fov) / 2.0)
    m = np.zeros((4, 4), dtype=np.float32)
    m[0, 0] = f / aspecto
    m[1, 1] = f
    m[2, 2] = (longe + perto) / (perto - longe)
    m[2, 3] = (2.0 * longe * perto) / (perto - longe)
    m[3, 2] = -1.0
    return m
    # fim matriz_perspectiva

def matriz_translacao(x, y, z):
    return np.array([
        [1,0,0,x],
        [0,1,0,y],
        [0,0,1,z],
        [0,0,0,1]]
    , dtype=np.float32)
    # fim matriz_translacao

def matriz_rotacao_x(graus):
    c, s = np.cos(np.radians(graus)), np.sin(np.radians(graus))
    return np.array([
        [1,0,0,0],
        [0,c,-s,0],
        [0,s,c,0],
        [0,0,0,1]],
    dtype=np.float32)
    # fim matriz_rotacao_x

def matriz_rotacao_y(graus):
    c, s = np.cos(np.radians(graus)), np.sin(np.radians(graus))
    return np.array([
        [c,0,s,0],
        [0,1,0,0],
        [-s,0,c,0],
        [0,0,0,1]],
    dtype=np.float32)
    # fim matriz_rotacao_y

def main():

    if not glfw.init(): return
    glfw.window_hint(glfw.CONTEXT_VERSION_MAJOR, 3)
    glfw.window_hint(glfw.CONTEXT_VERSION_MINOR, 3)
    glfw.window_hint(glfw.OPENGL_PROFILE, glfw.OPENGL_CORE_PROFILE)

    janela = glfw.create_window(800, 600, "Prisma - Use as SETAS do Teclado", None, None)
    if not janela:
        glfw.terminate()
        return

    glfw.make_context_current(janela)
    # VSync: Trava a execução em 60 FPS
    glfw.swap_interval(1)
    # O Z-Buffer que esconde as faces de trás
    glEnable(GL_DEPTH_TEST)

    shader = OpenGL.GL.shaders.compileProgram(
        OpenGL.GL.shaders.compileShader(VERTEX_SHADER, GL_VERTEX_SHADER),
        OpenGL.GL.shaders.compileShader(FRAGMENT_SHADER, GL_FRAGMENT_SHADER),
        validate=False  # Evita erro "No vertex array object bound" na validação
    )

    # Prisma de base triangular:
    #   Triângulo da frente em z = 0.5 e triângulo de trás em z = -0.5
    #   Cada triângulo tem os cantos (-0.5, -0.5), (0.5, -0.5) e (0, 0.5)
    # 18 Vértices (3 para cada uma das 2 bases + 4 para cada uma das 3 faces laterais)
    # Formato: X, Y, Z,    R, G, B
    vertices = np.array([
        # Base Frontal - triângulo (Verde Claro)
        -0.5, -0.5,  0.5,   0.3, 0.9, 0.4,
         0.5, -0.5,  0.5,   0.3, 0.9, 0.4,
         0.0,  0.5,  0.5,   0.3, 0.9, 0.4,

        # Base Traseira - triângulo (Verde Escuro)
        -0.5, -0.5, -0.5,   0.0, 0.35, 0.1,
         0.5, -0.5, -0.5,   0.0, 0.35, 0.1,
         0.0,  0.5, -0.5,   0.0, 0.35, 0.1,

        # Face Inferior - retângulo (Verde Quase Preto - Sombra)
        -0.5, -0.5, -0.5,   0.0, 0.15, 0.05,
         0.5, -0.5, -0.5,   0.0, 0.15, 0.05,
         0.5, -0.5,  0.5,   0.0, 0.15, 0.05,
        -0.5, -0.5,  0.5,   0.0, 0.15, 0.05,

        # Face Esquerda Inclinada - retângulo (Verde Médio Escuro)
        -0.5, -0.5, -0.5,   0.1, 0.55, 0.2,
        -0.5, -0.5,  0.5,   0.1, 0.55, 0.2,
         0.0,  0.5,  0.5,   0.1, 0.55, 0.2,
         0.0,  0.5, -0.5,   0.1, 0.55, 0.2,

        # Face Direita Inclinada - retângulo (Verde Médio Claro)
         0.5, -0.5, -0.5,   0.2, 0.75, 0.3,
         0.5, -0.5,  0.5,   0.2, 0.75, 0.3,
         0.0,  0.5,  0.5,   0.2, 0.75, 0.3,
         0.0,  0.5, -0.5,   0.2, 0.75, 0.3,
    ], dtype=np.float32)

    # conectar os 18 vértices para formar 8 triângulos
    indices = np.array([
        0, 1, 2,                   # Base Frontal (triângulo)
        3, 4, 5,                   # Base Traseira (triângulo)
        6, 7, 8,     8, 9, 6,      # Inferior (retângulo = 2 triângulos)
        10, 11, 12,  12, 13, 10,   # Esquerda (retângulo = 2 triângulos)
        14, 15, 16,  16, 17, 14    # Direita (retângulo = 2 triângulos)
    ], dtype=np.uint32)

    # Memória da Placa de Vídeo
    VAO = glGenVertexArrays(1)
    VBO = glGenBuffers(1)
    EBO = glGenBuffers(1)

    glBindVertexArray(VAO)

    glBindBuffer(GL_ARRAY_BUFFER, VBO)
    glBufferData(GL_ARRAY_BUFFER, vertices.nbytes, vertices, GL_STATIC_DRAW)

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO)
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.nbytes, indices, GL_STATIC_DRAW)

    passo = 6 * vertices.itemsize
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, passo, ctypes.c_void_p(0))
    glEnableVertexAttribArray(0)
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, passo, ctypes.c_void_p(3 * vertices.itemsize))
    glEnableVertexAttribArray(1)

    glBindVertexArray(0)

    # matrizes Base
    projecao = matriz_perspectiva(45.0, 800.0/600.0, 0.1, 100.0)
    view = matriz_translacao(0, 0, -3.5) # Câmera recuada
    loc_mvp = glGetUniformLocation(shader, "MVP")

    # Variáveis de Estado da Rotação
    rot_x = 25.0
    rot_y = 45.0
    velocidade = 2.0 # Velocidade do giro

    print("Use as setas do teclado para rotacionar o prisma.")

    # GAME LOOP (Laço Principal)
    while not glfw.window_should_close(janela):
        glfw.poll_events()

        # "A tecla está pressionada AGORA?"
        if glfw.get_key(janela, glfw.KEY_RIGHT) == glfw.PRESS:
            rot_y += velocidade
        if glfw.get_key(janela, glfw.KEY_LEFT) == glfw.PRESS:
            rot_y -= velocidade
        if glfw.get_key(janela, glfw.KEY_DOWN) == glfw.PRESS:
            rot_x += velocidade
        if glfw.get_key(janela, glfw.KEY_UP) == glfw.PRESS:
            rot_x -= velocidade

        # Limpeza do frame anterior
        glClearColor(0.8, 0.9, 1.0, 1.0) # Fundo azul bem claro
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        glUseProgram(shader)

        # Atualização Matemática
        model = matriz_rotacao_x(rot_x) @ matriz_rotacao_y(rot_y)
        MVP = projecao @ view @ model

        glUniformMatrix4fv(loc_mvp, 1, GL_FALSE,
                           np.ascontiguousarray(MVP.T, dtype=np.float32))

        # Desenho
        glBindVertexArray(VAO)
        glDrawElements(GL_TRIANGLES, len(indices), GL_UNSIGNED_INT, None)

        glfw.swap_buffers(janela)

    glfw.terminate()

if __name__ == "__main__":
    main()
