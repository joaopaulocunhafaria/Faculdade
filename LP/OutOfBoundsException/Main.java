package OutOfBoundsException;

class ListaNumeros {
    private int[] numeros;

    public ListaNumeros(int[] numeros) {
        this.numeros = numeros;
    }

    public void getNumero(int indice) {
        try {
            System.out.println("Número na posição " + indice + ": " + numeros[indice]);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.err.println("Erro: Índice " + indice + " está fora dos limites do array!");
        }
    }
}

public class Main {
    public static void main(String[] args) {
        int[] numeros = {10, 20, 30, 40, 50};
        ListaNumeros lista = new ListaNumeros(numeros);

        lista.getNumero(2);  // Índice válido (exibe 30)
        lista.getNumero(10); // Índice inválido (gera exceção)
    }
}
