package Entites;

import java.util.Random;

public class Aviao {

    public Random random = new Random();

    private int  numeroAviao;

    private int passageiros;

    private String companhiaAerea;

    public Aviao(int numeroAviao, int passageiros, String companhiaAerea) {

        this.numeroAviao = numeroAviao;
        this.passageiros = passageiros;
        this.companhiaAerea = companhiaAerea;
       
    }


    public Integer getNumeroAviao() {
        return numeroAviao;
    }
 
    public int getPassageiros() {
        return passageiros;
    }
    
    
    public void setNumeroAviao(Integer numeroAviao) {
        this.numeroAviao = numeroAviao;
    }


    @Override
    public String toString() {
        return "Aviao [numeroAviao=" + numeroAviao + ", passageiros=" + passageiros
                +", companhiaAerea=" + companhiaAerea + "]";
    }

    public String getCompanhiaAerea() {
        return companhiaAerea;
    }
}