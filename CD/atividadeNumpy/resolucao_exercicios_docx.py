import numpy as np

# Ex. 1
ExA = np.array([[12, 9, 4, 1],
                [11, 5, 8, 1],
                [1, 2, 3, 1]])
ExB = np.array([[1, 5],
                [1, 7],
                [1, 9],
                [1, 1]])
print("ExA:")
print(ExA)
print("ExB:")
print(ExB)

# Ex. 2
ExC = ExA.dot(ExB)
print("\nExC:")
print(ExC)


# Ex. 3
def estatisticas(matriz):
    # ddof=1 -> desvio padrão amostral
    media_linha = matriz.mean(axis=1)
    desvio_linha = matriz.std(axis=1, ddof=1)
    media_coluna = matriz.mean(axis=0)
    desvio_coluna = matriz.std(axis=0, ddof=1)
    return media_linha, desvio_linha, media_coluna, desvio_coluna


for nome, matriz in (("ExA", ExA), ("ExC", ExC)):
    media_l, desvio_l, media_c, desvio_c = estatisticas(matriz)
    print(f"\n{nome}")
    print("Media Linha:\n", media_l)
    print("Desvio padrão Linha:\n", desvio_l)
    print("Media Coluna:\n", media_c)
    print("Desvio padrão Coluna:\n", desvio_c)

# Ex. 4
ExD = ExA[:, -2:]
print()
print(ExD.mean())
print(ExD)

# Ex. 5
ExE = ExA[1:3, 1:3]
print()
print(ExE)

# Ex. 6
ExF = np.zeros((5, 2))
print()
print(ExF)

# Ex. 7
ExG = np.ones((4, 3))
print()
print(ExG)
