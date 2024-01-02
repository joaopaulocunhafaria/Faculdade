package Entites;

import java.util.PriorityQueue;

import  Entites.GerenciadorDePista;
import  Entites.Pista;

public class Aeroporto {
    


  public Pista pista1 = new Pista("pista1");
  public Pista pista2 = new Pista("pista2");
  public Pista pista3 = new Pista("pista3"); 


    private GerenciadorDePista gerrenciadorDePista = new GerenciadorDePista(pista1,
                                                                    pista2,
                                                                    pista3);
                                                                


    public Aeroporto() {
    }



    public GerenciadorDePista getGerrenciadorDePista() {
      return gerrenciadorDePista;
    }



    public void setGerrenciadorDePista(GerenciadorDePista gerrenciadorDePista) {
      this.gerrenciadorDePista = gerrenciadorDePista;
    }


     


}
