
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Locale;

import Banco.BancoGerente;
import Banco.ContaCorrenteComum;
import Banco.ContaCorrentePremium;
import Banco.ContaInvestimento;
import Banco.ContaPoupança;

public class Main {

    public static void main(String[] args) {

        BancoGerente banco = new BancoGerente();

        Locale.setDefault(Locale.US);
        try (BufferedReader leitor = new BufferedReader(new FileReader("Teste.txt"))) {

            String linha;

            while ((linha = leitor.readLine()) != null) {
                System.out.println(linha);

                switch (linha) {

                    case "Criar Conta": {

                        linha = leitor.readLine();
                        switch (linha) {
                            case "Conta Corrente Comum": {

                                int numeroConta = Integer.parseInt(leitor.readLine());
                                String nome = leitor.readLine();
                                float saldo = Float.parseFloat(leitor.readLine());

                                ContaCorrenteComum c = new ContaCorrenteComum(numeroConta, nome, saldo);
                                banco.getContaComum().add(c);
                                System.out.println(c);
                                break;
                            }
                            case "Conta Corrente Premium": {
                                int numeroConta = Integer.parseInt(leitor.readLine());
                                String nome = leitor.readLine();
                                float saldo = Float.parseFloat(leitor.readLine());
                                float limiteCredito = Float.parseFloat(leitor.readLine());

                                ContaCorrentePremium contaPremium = new ContaCorrentePremium(numeroConta, nome, saldo,
                                        limiteCredito);

                                banco.getContaPremium().add(contaPremium);
                                break;
                            }
                            case "Conta Investimento": {

                                int numeroConta = Integer.parseInt(leitor.readLine());
                                String nome = leitor.readLine();
                                float saldo = Float.parseFloat(leitor.readLine());
                                String taxaDeRendimento = leitor.readLine();

                                ContaInvestimento contaInvestimento = new ContaInvestimento(numeroConta, nome, saldo,
                                        taxaDeRendimento);

                                banco.getContaInvestimento().add(contaInvestimento);

                                break;
                            }
                            case "Conta Poupança": {

                                int numeroConta = Integer.parseInt(leitor.readLine());
                                String nome = leitor.readLine();
                                float saldo = Float.parseFloat(leitor.readLine());
                                String aniversario = leitor.readLine();

                                ContaPoupança contaPoupança = new ContaPoupança(numeroConta, nome, saldo, aniversario);
                                banco.getContaPoupança().add(contaPoupança);
                                System.out.println(contaPoupança);
                                break;
                            }
                            default:
                                break;
                        }

                        break;
                    }
                    case "Deposito": {

                        linha = leitor.readLine();

                        switch (linha) {
                            case "Conta Corrente Comum": {
                                int numeroConta = Integer.parseInt(leitor.readLine());
                                float valor = Float.parseFloat(leitor.readLine());

                                banco.depositoComum(numeroConta, valor);

                                break;

                            }
                            case "Conta Corrente Premium": {

                                int numeroConta = Integer.parseInt(leitor.readLine());
                                float valor = Float.parseFloat(leitor.readLine());

                                banco.depositoPremium(numeroConta, valor);
                                System.out.println("Deposito conta premium feito");

                                break;
                            }
                            case "Conta Poupança": {

                                int numeroConta = Integer.parseInt(leitor.readLine());
                                float valor = Float.parseFloat(leitor.readLine());

                                banco.depositoPoupança(numeroConta, valor);
                                System.out.println("Deposito conta Poupança feito");

                                break;
                            }
                            case "Conta Investimento": {

                                int numeroConta = Integer.parseInt(leitor.readLine());
                                float valor = Float.parseFloat(leitor.readLine());

                                banco.depositoInvestimento(numeroConta, valor);

                                break;
                            }
                            default:
                                throw new IllegalArgumentException("Opçao invalida ");
                        }
                        break;

                    }

                    case "Saque": {

                        linha = leitor.readLine();
                        switch (linha) {
                            case "Conta Corrente Comum": {
                                int numeroConta = Integer.parseInt(leitor.readLine());
                                float valor = Float.parseFloat(leitor.readLine());

                                banco.saqueComum(numeroConta, valor);

                                break;

                            }
                            case "Conta Corrente Premium": {

                                int numeroConta = Integer.parseInt(leitor.readLine());
                                float valor = Float.parseFloat(leitor.readLine());

                                banco.saquePremium(numeroConta, valor);

                                break;
                            }
                            case "Conta Poupança": {

                                int numeroConta = Integer.parseInt(leitor.readLine());
                                float valor = Float.parseFloat(leitor.readLine());

                                banco.saquePoupança(numeroConta, valor);

                                break;
                            }
                            case "Conta Investimento": {

                                int numeroConta = Integer.parseInt(leitor.readLine());
                                float valor = Float.parseFloat(leitor.readLine());

                                banco.saqueInvestimento(numeroConta, valor);

                                break;
                            }
                            default:
                                System.out.println("Opçao invalida" + linha);
                        }
                        break;

                    }
                    case "Extrato": {

                        System.out.println("\n\n");
                        linha = leitor.readLine();

                        switch (linha) {
                            case "Conta Corrente Comum": {
                                int numeroConta = Integer.parseInt(leitor.readLine());

                                banco.extratoComum(numeroConta);

                                break;

                            }
                            case "Conta Corrente Premium": {

                                int numeroConta = Integer.parseInt(leitor.readLine());

                                banco.extratoPremium(numeroConta);

                                break;
                            }
                            case "Conta Poupança": {

                                int numeroConta = Integer.parseInt(leitor.readLine());

                                banco.extratoPoupança(numeroConta);

                                break;
                            }
                            case "Conta Investimento": {

                                int numeroConta = Integer.parseInt(leitor.readLine());

                                banco.extratoInvestimento(numeroConta);

                                break;
                            }
                            default:
                                throw new IllegalArgumentException("Opçao invalida ");
                        }
                        break;

                    }
                    case "Sair":
                        System.out.println("Saindo...");
                        return;

                    default:
                        System.out.println("Opçao invalida no switch principal");
                }

            }

            leitor.close();

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

}
