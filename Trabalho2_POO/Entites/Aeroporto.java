package Entites;

import  Entites.GerenciadorDePista;
import  Entites.Pista;

public class Aeroporto {
    


  public Pista pista1 = new Pista("pista1", null, null   );
  public Pista pista2 = new Pista("pista2", null, null   );
  public Pista pista3 = new Pista("pista3", null, null   ); 


    GerenciadorDePista gerrenciadorDePista = new GerenciadorDePista(pista1,
                                                                    pista2,
                                                                    pista3);
                                                                


    public Aeroporto() {
    }





}
