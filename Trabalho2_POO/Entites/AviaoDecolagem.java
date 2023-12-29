package Entites;

import java.util.HashMap;

public class AviaoDecolagem extends Aviao {

    private boolean decolar;
    int tempoEspera;

    //se for um aviao com menos de 5 minutos de combustivel ele chamara este construtor
    //que ira setar o atributo emergencia como true
    public AviaoDecolagem(int numeroAviao, int passageiros, String companhiaAerea) {
        //Integer numeroAviao, int passageiros, String companhiaAerea) {

        super(numeroAviao, passageiros, companhiaAerea);
        this.tempoEspera = 0;
        this.decolar =  true;
    }

    
    public int getTempoEspera() {
        return tempoEspera;
    }

    public void setTempoEspera(int tempoEspera) {
        this.tempoEspera = tempoEspera;
    }

    @Override
    public String toString() {
        return "AviaoDecolagem Numero: " + getNumeroAviao() + " Companhia Aerea: " + getCompanhiaAerea() ;
    }


}