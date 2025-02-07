package FileNotFoundException;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

class LeitorArquivo {
    private String caminhoArquivo;

    public LeitorArquivo(String caminhoArquivo) {
        this.caminhoArquivo = caminhoArquivo;
    }

    public void lerArquivo() {
        try {
            File arquivo = new File(caminhoArquivo);
            Scanner scanner = new Scanner(arquivo);

            System.out.println("Conteúdo do arquivo:");
            while (scanner.hasNextLine()) {
                System.out.println(scanner.nextLine());
            }

            scanner.close();
        } catch (FileNotFoundException e) {
            System.err.println("Erro: O arquivo '" + caminhoArquivo + "' não foi encontrado.");
        }
    }
}

public class Main {
    public static void main(String[] args) {
        LeitorArquivo leitor = new LeitorArquivo("arquivo.txt");
        leitor.lerArquivo();
    }
}
