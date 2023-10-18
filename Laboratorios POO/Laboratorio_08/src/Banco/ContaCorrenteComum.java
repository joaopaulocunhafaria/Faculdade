package Banco;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

public class ContaCorrenteComum {

    DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");

    private int numeroDaConta;
    private String nomeDoTitular;
    private float saldo;

    private ArrayList<Transaçoes> listaTransaçoes = new ArrayList<>();

    public float getSaldo() {
        return saldo;
    }

    public void setSaldo(float saldo) {
        this.saldo = saldo;
    }

    public int getNumeroDaConta() {
        return numeroDaConta;
    }

    public void setNumeroDaConta(int numeroDaConta) {
        this.numeroDaConta = numeroDaConta;
    }

    public String getNomeDoTitular() {
        return nomeDoTitular;
    }

    public void setNomeDoTitular(String nomeDoTitular) {
        this.nomeDoTitular = nomeDoTitular;
    }

    public void deposito(float deposito) {
        this.saldo = this.saldo + deposito;

        Transaçoes t = new Transaçoes(dtf.format(LocalDateTime.now()), deposito, "Deposito");
        listaTransaçoes.add(t);

        System.out.println("Deposito realizado!\nTransçao:" + t);

    }

    public void saque(float saque) {
        if (this.saldo - saque >= 0) {
            this.saldo = this.saldo - saque;
            Transaçoes t = new Transaçoes(dtf.format(LocalDateTime.now()), (-1 * saque), "saque");

            System.out.println("Saque realizado!\nTransaçao:" + t);
        } else {
            System.out.println("Saldo insuficiente");
            return;
        }

    }

    public ArrayList<Transaçoes> getListaTransaçoes() {
        return listaTransaçoes;
    }

    public void setListaTransaçoes(ArrayList<Transaçoes> listaTransaçoes) {
        this.listaTransaçoes = listaTransaçoes;
    }

    public ContaCorrenteComum(int numeroDaConta, String nomeDoTitular, float saldo) {
        super();
        this.numeroDaConta = numeroDaConta;
        this.nomeDoTitular = nomeDoTitular;
        this.saldo = saldo;
    }

    public void Extrato() {
        System.out.println("Extrato[\n Numero Da Conta =" + numeroDaConta + "\nNome Do Titular=" + nomeDoTitular
                + "\nSaldo =" + saldo + "Lista De transaçoes:\n");
        imprimirTransaçoes();
    }

    public void imprimirTransaçoes() {
        if (!listaTransaçoes.isEmpty()) {
            for (int i = 0; i < listaTransaçoes.size(); i++) {

                System.out.println(listaTransaçoes.get(i));

            }
        } else {
            System.out.println("Nao ha transaçoes");
        }

    }

    @Override
    public String toString() {
        return "ContaCorrenteComum [numeroDaConta=" + numeroDaConta + ", nomeDoTitular=" + nomeDoTitular + ", saldo="
                + saldo + "]";
    }

}
