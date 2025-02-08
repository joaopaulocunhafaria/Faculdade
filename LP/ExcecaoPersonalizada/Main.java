class ProcessadorValor {
    public void processarValor(int valor) throws ValorNegativoException {
        if (valor < 0) {
            throw new ValorNegativoException("Valor negativo não permitido: " + valor);
        } else {
            System.out.println("Valor processado: " + valor);
        }
    }
}

// Definição da exceção personalizada que estende Exception
class ValorNegativoException extends Exception {
    public ValorNegativoException(String mensagem) {
        super(mensagem);
    }
}


public class Main {
    public static void main(String[] args) {
        ProcessadorValor processador = new ProcessadorValor();
        int[] valores = {10, -5, 20};
        
        for (int valor : valores) {
            try {
                processador.processarValor(valor);
            } catch (ValorNegativoException e) {
                System.err.println("Exceção capturada: " + e.getMessage());
            }
        }
    }
}
