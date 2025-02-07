package NullPointerException;

class Usuario {
    private String nome;

    public Usuario(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }
}

public class Main {
    public static void main(String[] args) {
        Usuario usuario1 = new Usuario("Carlos");
        Usuario usuario2 = new Usuario(null); // Nome não definido (null)

        exibirNomeUsuario(usuario1);
        exibirNomeUsuario(usuario2); // Isso causaria NullPointerException sem tratamento
    }

    public static void exibirNomeUsuario(Usuario usuario) {
        try {
            System.out.println("Nome do usuário: " + usuario.getNome().toUpperCase());
        } catch (NullPointerException e) {
            System.err.println("Erro: O nome do usuário está nulo!");
        }
    }
}
