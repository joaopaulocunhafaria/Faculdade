package Banco;

import java.time.LocalDateTime;

public class ContaCorrentePremium extends ContaCorrenteComum {

    private float limiteCredito;

    public ContaCorrentePremium(int numeroDaConta, String nomeDoTitular, float saldo, float limiteCredito) {
        super(numeroDaConta, nomeDoTitular, saldo);
        this.limiteCredito = limiteCredito;
    }

    public void imprimirTransaçoes() {
        if (!getListaTransaçoes().isEmpty()) {
            for (int i = 0; i < getListaTransaçoes().size(); i++) {

                System.out.println(getListaTransaçoes().get(i) + "\nLimite de credito:" + limiteCredito + "\n\n");

            }
        } else {
            System.out.println("Nao ha transaçoes");
        }

    }


    @Override
    public void saque(float valorSaque) {

        if ((this.limiteCredito + this.getSaldo()) == valorSaque) {
            setSaldo(getSaldo() - valorSaque);

            Transaçoes t = new Transaçoes(dtf.format(LocalDateTime.now()), (-1 * valorSaque), "Saque");

            getListaTransaçoes().add(t);


        } else {
            System.out.println("Valor de saque ultrapasa o limite de credito ");
        }
    }


    @Override
    public void Extrato() {
        System.out
                .println("\nExtrato[\n Numero Da Conta =" + getNumeroDaConta() + "\nNome Do Titular=" + getNomeDoTitular()
                        + "\nSaldo =" + getSaldo() + "\nLimite de credito:" + limiteCredito + "\nLista De transaçoes:\n");
        imprimirTransaçoes();
    }


}
