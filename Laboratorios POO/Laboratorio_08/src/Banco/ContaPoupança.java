package Banco;

import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

public class ContaPoupança extends ContaCorrenteComum {

    private String aniversario;

    public ContaPoupança(int numeroDaConta, String nomeDoTitular, float saldo, String aniversario) {
        super(numeroDaConta, nomeDoTitular, saldo);
        this.aniversario = aniversario;
    }

    @Override
    public String toString() {
        return "ContaPoupança [aniversario=" + aniversario + ", Saldo do joao ´paulo =" + getSaldo() + "]";
    }

    @Override

    public void Extrato() {
        System.out
                .println("Extrato[\n Numero Da Conta =" + getNumeroDaConta() + "\nNome Do Titular=" + getNomeDoTitular()
                        + "\nSaldo =" + getSaldo() + "\nAniversario da conta:" + aniversario + "Lista De transaçoes:\n");
        imprimirTransaçoes();
    }
}
