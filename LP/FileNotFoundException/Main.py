class LeitorArquivo:
    def __init__(self, caminho_arquivo):
        self.caminho_arquivo = caminho_arquivo

    def ler_arquivo(self):
        try:
            with open(self.caminho_arquivo, 'r') as arquivo:
                print("Conteúdo do arquivo:")
                for linha in arquivo:
                    print(linha, end="")  
        except FileNotFoundError:
            print("Erro: O arquivo '{}' não foi encontrado.".format(self.caminho_arquivo))

def main():
    leitor = LeitorArquivo("arquivo.txt")
    leitor.ler_arquivo()

if __name__ == '__main__':
    main()
