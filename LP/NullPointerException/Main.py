class Usuario:
    def __init__(self, nome):
        self.nome = nome

    def get_nome(self):
        return self.nome

def exibir_nome_usuario(usuario):
    try:
        
        # Diferente do java, o python não possui NullPointerException
        print("Nome do usuário:", usuario.get_nome().upper())
    except AttributeError:
        print("Erro: O nome do usuário está nulo!")

def main():
    usuario1 = Usuario("Carlos")
    usuario2 = Usuario(None)  # Nome não definido (None)
    
    exibir_nome_usuario(usuario1)
    exibir_nome_usuario(usuario2)

if __name__ == "__main__":
    main()
