package Applicaton;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import Entites.AviaoAterrissagem;
import Entites.AviaoDecolagem;
import Entites.GerenciadorDePista;
import Entites.Aeroporto;
import Entites.Aviao;
import java.util.List;

public class aplicationUsingFiles {

    public Aeroporto aeroporto = new Aeroporto();
    private String filePath;

    public aplicationUsingFiles(String filePath) {
        this.filePath = filePath;

    }

    public ArrayList<Aviao> openFile() {
ArrayList<Aviao> avioes = new ArrayList<>();
        try (BufferedReader rd = new BufferedReader(
                new FileReader("/home/joao/Desktop/Trabalho2_POO/Applicaton/InPut.txt"))) {

            String line = rd.readLine();

            Integer numAvioes = aeroporto.getGerrenciadorDePista().randomizaNumAvioes();

            for (int i = 0; i < numAvioes; i++) {

                String[] words = line.split(" ");
                if (words[0].equals("aterrissar")) {
                    int numeroAviao = Integer.parseInt(words[3]);
                    int passageiros = Integer.parseInt(words[2]);
                    int combustivel = Integer.parseInt(words[4]);
                    String companhiaAerea = words[1];
                    AviaoAterrissagem aviao = new AviaoAterrissagem(numeroAviao, companhiaAerea, passageiros,
                            combustivel);
                    avioes.add(aviao);
                }

                if (words[0].equals("decolar")) {

                    int numeroAviao = Integer.parseInt(words[3]);
                    int passageiros = Integer.parseInt(words[2]);
                    String companhiaAerea = words[1];
                    AviaoDecolagem aviao = new AviaoDecolagem(numeroAviao, passageiros, companhiaAerea);
                    avioes.add(aviao);
                }
                line = rd.readLine();

            }

        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        } catch (NumberFormatException e) {
            System.out.println("Error: " + e.getMessage());
        }
        return avioes;
    }

}
