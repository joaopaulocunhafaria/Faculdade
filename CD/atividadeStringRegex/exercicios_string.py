# Exercícios de String


# 1. Substituir a última ocorrência de uma palavra
def substituir_ultima(frase, antiga, nova):
    pos = frase.rfind(antiga)
    if pos == -1:
        return frase
    return frase[:pos] + nova + frase[pos + len(antiga):]


# 2. Cadeia complementar de DNA
def complementar_dna(cadeia):
    pares = {"A": "T", "T": "A", "C": "G", "G": "C"}
    return "".join(pares[base] for base in cadeia.upper())


# 3. Contar palavras (ignorando espaços extras no início/fim/meio)
def contar_palavras(frase):
    return len(frase.split())


# 4. Substituir espaços por "#"
def ler_frase():
    return input("Frase: ")


def substituir_espacos(frase):
    return frase.replace(" ", "#")


# 5. Palíndromas mútuas
def palindromas_mutuas(s1, s2):
    return s1.lower() == s2.lower()[::-1]


# 6. Nome de trás para frente em maiúsculas
def nome_invertido(nome):
    return nome.upper()[::-1]


# 7. Nome em escada
def nome_escada(nome):
    nome = nome.upper()
    return "\n".join(nome[:i] for i in range(1, len(nome) + 1))


# 8. Data com mês por extenso
MESES = ["janeiro", "fevereiro", "março", "abril", "maio", "junho", "julho",
         "agosto", "setembro", "outubro", "novembro", "dezembro"]


def data_extenso(data):
    dia, mes, ano = data.split("/")
    return f"Você nasceu em {int(dia)} de {MESES[int(mes) - 1]} de {ano}"


if __name__ == "__main__":
    print("--- Exercício 1 ---")
    frase = input("Frase: ")
    antiga = input("Palavra antiga: ")
    nova = input("Palavra nova: ")
    print(substituir_ultima(frase, antiga, nova))

    print("\n--- Exercício 2 ---")
    print(complementar_dna(input("Cadeia de DNA: ")))

    print("\n--- Exercício 3 ---")
    print("Número de palavras:", contar_palavras(input("Frase: ")))

    print("\n--- Exercício 4 ---")
    print(substituir_espacos(ler_frase()))

    print("\n--- Exercício 5 ---")
    s1 = input("Primeira string: ")
    s2 = input("Segunda string: ")
    if palindromas_mutuas(s1, s2):
        print(f"'{s1}' e '{s2}' são palíndromas mútuas")
    else:
        print(f"'{s1}' e '{s2}' não são palíndromas mútuas")

    print("\n--- Exercício 6 ---")
    print(nome_invertido(input("Nome: ")))

    print("\n--- Exercício 7 ---")
    print(nome_escada(input("Nome: ")))

    print("\n--- Exercício 8 ---")
    print(data_extenso(input("Data (dd/mm/aaaa): ")))
