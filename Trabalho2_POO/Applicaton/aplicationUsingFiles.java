package Applicaton;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import Entites.AviaoAterrissagem;
import Entites.AviaoDecolagem;

public class aplicationUsingFiles {

    public void openFile() {

        try (BufferedReader rd = new BufferedReader(new FileReader("/home/joao/Desktop/faculdade/Faculdade/Trabalho2_POO/Applicaton/Teste.txt"))) {

            String line = rd.readLine();

            while (line != null) {

                String[] words = line.split(" ");
                if (words[2].equals("aterrisar")) {
                     
                if (Integer.parseInt(words[8])>5) {
                    AviaoAterrissagem aviao = new AviaoAterrissagem(Integer.parseInt(words[4]),
                                                                    Integer.parseInt(words[8]));
                    
                }
                if (Integer.parseInt(words[8])<5) {
                    AviaoAterrissagem aviao = new AviaoAterrissagem(Integer.parseInt(words[4]),
                                                                    Integer.parseInt(words[8]),
                                                                    true);
                    
                }

                //aqui deve atribuir o aviao a uma pista de aterrissagem de forma que fiquem todas bem
                
                }




                if (words[2].equals("decolar")) {

                    //se o tempo de espera for menor que 5 minutos ele chama o construtor que seta o atributo emergencia como true
                   if (Integer.parseInt(words[8]) < 5) {
                    AviaoDecolagem aviao = new AviaoDecolagem(Integer.parseInt(words[4]),
                                                              Integer.parseInt(words[8]),
                                                              true);    
                   }

                     //se o tempo de espera for maior que 5 minutos ele chama o construtor que seta o atributo emergencia como false
                   if (Integer.parseInt(words[8]) > 5) {
                    AviaoDecolagem aviao = new AviaoDecolagem(Integer.parseInt(words[4]),
                                                              Integer.parseInt(words[8]));    
                    
                   }
                    
                    
                    
                    
                    //aqui deve atribuir o aviao a uma pista de decolagem de forma que fiquem todas bem 
                    //distribuidas 
                }

                System.out.println(words[2]+" "+words[4]+" "+words[8]);
                line = rd.readLine();
            }

        } catch (IOException e ) {
            System.out.println("Error: " + e.getMessage());
        }catch (NumberFormatException e) {
            System.out.println("Error: " + e.getMessage());
        }

    }

}
