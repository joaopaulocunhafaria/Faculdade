class ValorNegativoException(Exception):
    def __init__(self, mensagem):
        super().__init__(mensagem)
 
class ProcessadorValor:
    def processar_valor(self, valor):
        if valor < 0:
            raise ValorNegativoException(f"Valor negativo não permitido: {valor}")
        else:
            print(f"Valor processado: {valor}")
 
def main():
    processador = ProcessadorValor()
    valores = [10, -5, 20]

    for valor in valores:
        try:
            processador.processar_valor(valor)
        except ValorNegativoException as e:
            print(f"Exceção capturada: {e}")

if __name__ == "__main__":
    main()
