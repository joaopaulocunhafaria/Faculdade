
package javaTeste;

import java.util.ArrayList;

public class main {

    public static void main(String[] args) {

        ArrayList<Integer> lista = new ArrayList<>();
       
        lista.add(9);
        
        System.out.println(lista);
        ArrayList <Integer> lista3 = listaPar(lista);
        System.out.println(lista3);
    }



    public static ArrayList listaPar(ArrayList<Integer> lista) {

        ArrayList<Integer> lista2 = new ArrayList<>();
        for (Integer numero : lista) {
            if (numero % 2 == 0) {
                lista2.add(numero);
            }

        }
        return lista2;
    }


    
}
