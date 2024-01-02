package Banco;

import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

public class ContaInvestimento extends ContaCorrenteComum {




    private String taxaDeRetornoAnual;




    public ContaInvestimento(int numeroDaConta, String nomeDoTitular, float saldo, String taxaDeRetornoAnual) {
        super(numeroDaConta, nomeDoTitular, saldo);
        this.taxaDeRetornoAnual = taxaDeRetornoAnual;
    }


    @Override

    public void Extrato() {
        System.out.println("Extrato[\n Numero Da Conta = " + getNumeroDaConta() + "\nNome Do Titular= " + getNomeDoTitular()
                + "\nSaldo = " + getSaldo()+"\nTaxa de retorno anual: "+taxaDeRetornoAnual + "\nLista De transaçoes:\n");
        imprimirTransaçoes();
    }
}

