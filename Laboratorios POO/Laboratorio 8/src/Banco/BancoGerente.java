package Banco;

import java.util.ArrayList;
import java.util.Iterator;

public class BancoGerente {

    private ArrayList<ContaCorrenteComum> contaComum = new ArrayList<>();
    private ArrayList<ContaCorrentePremium> contaPremium = new ArrayList<>();
    private ArrayList<ContaPoupança> contaPoupança = new ArrayList<>();
    private ArrayList<ContaInvestimento> contaInvestimento = new ArrayList<>();

    public ArrayList<ContaCorrenteComum> getContaComum() {
        return contaComum;
    }

    public ArrayList<ContaCorrentePremium> getContaPremium() {
        return contaPremium;
    }

    public ArrayList<ContaPoupança> getContaPoupança() {
        return contaPoupança;
    }

    public ArrayList<ContaInvestimento> getContaInvestimento() {
        return contaInvestimento;
    }

    public void depositoComum(int numeroConta, float deposito) {

        if (!contaComum.isEmpty()) {
            for (int i = 0; i < contaComum.size(); i++) {
                if (contaComum.get(i).getNumeroDaConta() == numeroConta) {
                    contaComum.get(i).deposito(deposito);
                }
            }
        }

    }

    public void depositoPremium(int numeroConta, float deposito) {

        if (!contaPremium.isEmpty()) {
            for (int i = 0; i < contaPremium.size(); i++) {
                if (contaPremium.get(i).getNumeroDaConta() == numeroConta) {
                    contaPremium.get(i).deposito(deposito);
                }
            }
        }

    }

    public void depositoPoupança(int numeroConta, float deposito) {

        if (!contaPoupança.isEmpty()) {
            for (int i = 0; i < contaPoupança.size(); i++) {
                if (contaPoupança.get(i).getNumeroDaConta() == numeroConta) {
                    contaPoupança.get(i).deposito(deposito);
                }
            }
        }

    }

    public void depositoInvestimento(int numeroConta, float deposito) {

        if (!contaInvestimento.isEmpty()) {
            for (int i = 0; i < contaInvestimento.size(); i++) {
                if (contaInvestimento.get(i).getNumeroDaConta() == numeroConta) {
                    contaInvestimento.get(i).deposito(deposito);
                }
            }
        }

    }

    public void saqueComum(int numeroConta, float saque) {
        if (!contaComum.isEmpty()) {
            for (int i = 0; i < contaComum.size(); i++) {
                if (contaComum.get(i).getNumeroDaConta() == numeroConta) {
                    contaComum.get(i).saque(saque);
                }
            }
        }

    }

    public void saquePremium(int numeroConta, float saque) {
        if (!contaPremium.isEmpty()) {
            for (int i = 0; i < contaPremium.size(); i++) {
                if (contaPremium.get(i).getNumeroDaConta() == numeroConta) {
                    contaPremium.get(i).saque(saque);
                }
            }
        }

    }

    public void saquePoupança(int numeroConta, float saque) {
        if (!contaPoupança.isEmpty()) {
            for (int i = 0; i < contaPoupança.size(); i++) {
                if (contaPoupança.get(i).getNumeroDaConta() == numeroConta) {
                    contaPoupança.get(i).saque(saque);
                }
            }
        }

    }

    public void saqueInvestimento(int numeroConta, float saque) {
        if (!contaInvestimento.isEmpty()) {
            for (int i = 0; i < contaInvestimento.size(); i++) {
                if (contaInvestimento.get(i).getNumeroDaConta() == numeroConta) {
                    contaInvestimento.get(i).saque(saque);
                }
            }
        }

    }

    public void extratoComum(int numeroConta) {
        if (!contaComum.isEmpty()) {
            for (int i = 0; i < contaComum.size(); i++) {
                if (contaComum.get(i).getNumeroDaConta() == numeroConta) {
                    contaComum.get(i).Extrato();

                }
            }
        }

    }


    public void extratoInvestimento(int numeroConta) {
        if (!contaInvestimento.isEmpty()) {
            for (int i = 0; i < contaInvestimento.size(); i++) {
                if (contaInvestimento.get(i).getNumeroDaConta() == numeroConta) {
                    contaInvestimento.get(i).Extrato();

                }
            }
        }

    }
    public void extratoPoupança(int numeroConta) {
        if (!contaPoupança.isEmpty()) {
            for (int i = 0; i < contaPoupança.size(); i++) {
                if (contaPoupança.get(i).getNumeroDaConta() == numeroConta) {
                    contaPoupança.get(i).Extrato();

                }
            }
        }

    }
    public void extratoPremium(int numeroConta) {
        if (!contaPremium.isEmpty()) {
            for (int i = 0; i < contaPremium.size(); i++) {
                if (contaPremium.get(i).getNumeroDaConta() == numeroConta) {
                    contaPremium.get(i).Extrato();

                }
            }
        }

    }





}
