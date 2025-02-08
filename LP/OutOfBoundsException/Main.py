class ListaNumeros:
    def __init__(self, numeros):
        self.numeros = numeros

    def get_numero(self, indice):
        try:
            print("Número na posição {}: {}".format(indice, self.numeros[indice]))
        except IndexError:
            print("Erro: Índice {} está fora dos limites do array!".format(indice))


def main():
    numeros = [10, 20, 30, 40, 50]
    lista = ListaNumeros(numeros)
    

    lista.get_numero(2)
    
    # Índice inválido (gera exceção)
    lista.get_numero(10)


if __name__ == "__main__":
    main()
