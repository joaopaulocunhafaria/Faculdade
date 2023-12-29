package Applicaton;

import Entites.Aviao;
import Entites.GerenciadorDePista;
import Entites.Pista;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;
import java.nio.Buffer;
import java.io.BufferedReader;
import java.io.FileReader;

import Applicaton.aplicationUsingFiles;

public class main {
    public static void main(String[] args) {
        aplicationUsingFiles aplicationUsingFiles = new aplicationUsingFiles("InPut.txt");
        Scanner scanner = new Scanner(System.in);
        int opcao;
        GerenciadorDePista gerenciadorDePista = new GerenciadorDePista(new Pista("Pista 1"),
                new Pista("Pista 2"),
                new Pista("Pista 3"));

        while (true) {
            System.out.println("Iniciar com arquivo ou randomicamente?");
            System.out.println("1 - Randomicamente");
            System.out.println("2 - Arquivo");
            opcao = scanner.nextInt();
            scanner.nextLine();

            switch (opcao) {

                case 1: {
                    List<Aviao> avioes = new ArrayList();
                    int tempo = 0;
                    String resposta;
                    int numAvioes = 0;
                    do {
                        avioes.clear();
                        System.out.println("Deseja passar o tempo?");
                        System.out.println("Se sim, pressione ENTER");
                        resposta = scanner.nextLine();
                        tempo++;
                        numAvioes = gerenciadorDePista.randomizaNumAvioes();
                        for (int i = 0; i < numAvioes; i++) {

                            Aviao aviao = GerenciadorDePista.addAviaoAleatorio();//aqui é criado um avião

                            avioes.add(aviao);//lista de todos os avioes criados
                        }
                        linha();
                        gerenciadorDePista.addAviaoNaPista(avioes);
                        gerenciadorDePista.gerenciarPista();
                        linha();


                    } while (resposta.isEmpty());
                    break;
                }

                case 2: {
                    List<Aviao> avioes = aplicationUsingFiles.openFile();

                    int tempo = 0;
                    String resposta;
                    int numAvioes = 0;
                    do {
                        avioes.clear();
                        System.out.println("Deseja passar o tempo?");
                        System.out.println("Se sim, pressione ENTER");
                        resposta = scanner.nextLine();
                        tempo++;
                      
                        avioes = aplicationUsingFiles.openFile();
                        linha();
                        gerenciadorDePista.addAviaoNaPista(avioes);
                        gerenciadorDePista.gerenciarPista();
                        linha();
                    } while (resposta.isEmpty());
                }
            }
        }
    }


    static public void linha() {
        System.out.println("-----------------------------------------------------");
    }
}