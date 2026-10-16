# Exercícios de Regex
import re

# 1.1. CPF com ou sem pontuação
CPF_1_1 = re.compile(r"^\d{3}\.?\d{3}\.?\d{3}-?\d{2}$")

# 1.2. CPF com pontos ou espaços entre os grupos e hífen ou barra antes dos dígitos de controle
CPF_1_2 = re.compile(r"^\d{3}[. ]?\d{3}[. ]?\d{3}[-/]?\d{2}$")

# 2.1. Palavras que terminam com a letra "o"
PALAVRA_TERMINA_O = re.compile(r"\b\w*o\b", re.IGNORECASE)

# 2.2. Palavras que começam e terminam com vogal
VOGAIS = "aeiouáéíóúâêôãõàü"
PALAVRA_VOGAIS = re.compile(rf"\b[{VOGAIS}](?:\w*[{VOGAIS}])?\b", re.IGNORECASE)

# 3.1. Hora e minutos (00:00 até 23:59)
HORA = re.compile(r"^([01]\d|2[0-3]):[0-5]\d$")

# 3.2. Octeto de IPv4 (0 até 255)
OCTETO = r"(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)"
OCTETO_IPV4 = re.compile(rf"^{OCTETO}$")

# 3.3. Endereço IPv4 completo
IPV4 = re.compile(rf"^{OCTETO}(?:\.{OCTETO}){{3}}$")

# 4. Número inteiro ou real
NUMERO = re.compile(r"^[+-]?\d+(?:\.\d+)?$")

# 5. Telefone fixo ou celular
# DDD com 2 dígitos (com 0 opcional), com ou sem parênteses,
# seguido de 4 (fixo) ou 5 (celular) dígitos, separador opcional e mais 4 dígitos
TELEFONE = re.compile(r"^(?:\(0?(\d{2})\)|0?(\d{2}))\s?(\d{4,5})[-\s]?(\d{4})$")


def eh_numero(s):
    return NUMERO.match(s) is not None


def eh_telefone(s):
    return TELEFONE.match(s) is not None


# 6. Formata o telefone como (XX) XXXX-XXXX ou (XX) XXXXX-XXXX
def formatar_telefone(s):
    m = TELEFONE.match(s)
    if m is None:
        return None
    ddd = m.group(1) or m.group(2)
    return f"({ddd}) {m.group(3)}-{m.group(4)}"


def testar(titulo, regex, exemplos):
    print(f"\n--- {titulo} ---")
    for e in exemplos:
        print(f"{e!r:22} -> {'válido' if regex.match(e) else 'inválido'}")


if __name__ == "__main__":
    testar("1.1 CPF", CPF_1_1, ["772.843.809-34", "77284380934", "772 843 809/34"])
    testar("1.2 CPF", CPF_1_2, ["772.843.809-34", "77284380934", "772 843 809/34",
                                "772.843.809/34", "772-843-809-34"])

    texto = ("Escreva uma regex capaz de encontrar no texto deste parágrafo todas "
             "as palavras que teriminam com a letra “o”.")
    print("\n--- 2.1 Palavras terminadas em 'o' ---")
    print(PALAVRA_TERMINA_O.findall(texto))

    texto = "A abelha voava sobre o ipê e a uva, enquanto Otávio e Ana olhavam a árvore."
    print("\n--- 2.2 Palavras que começam e terminam com vogal ---")
    print(PALAVRA_VOGAIS.findall(texto))

    testar("3.1 Hora", HORA, ["00:00", "09:45", "23:59", "24:00", "12:60", "7:30"])
    testar("3.2 Octeto IPv4", OCTETO_IPV4, ["0", "9", "156", "255", "256", "01", "300"])
    testar("3.3 IPv4", IPV4, ["192.169.1.1", "255.0.0.0", "256.0.0.1", "1.2.3", "10.0.0.300"])
    testar("4 Número", NUMERO, ["10", "+5", "-3", "-10.3", "0.80", "2.8033", "1.", ".5", "abc", "1.2.3"])

    telefones = ["(19) 3123-4567", "193123-4567", "(019)3123-4567", "(19)31234567",
                 "1931234567", "(019) 91234 5678", "(019)91234 5678", "019912345678",
                 "19 91234 5678", "1991234 5678", "123", "(19 3123-4567"]
    testar("5 Telefone", TELEFONE, telefones)

    print("\n--- 6 Formatar telefone ---")
    for t in telefones:
        print(f"{t!r:22} -> {formatar_telefone(t)}")
