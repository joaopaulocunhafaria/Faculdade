package Entites;

import java.util.HashMap;

public class AviaoDecolagem extends Aviao {

    private boolean decolar;
    private boolean emergencia;
    

    //se for um aviao com menos de 5 minutos de combustivel ele chamara este construtor
    //que ira setar o atributo emergencia como true
    public AviaoDecolagem(Integer numeroAviao, Integer tempoEspera, boolean emergencia) {
        super(numeroAviao, tempoEspera);
        this.emergencia = true;
        this.decolar =  true;
    }

    //se for um aviao com mais de 5 minutos de combustivel ele chamara este construtor
    //que ira setar o atributo emergencia como false
    public AviaoDecolagem(Integer numeroAviao, Integer tempoEspera) {
        super(numeroAviao, tempoEspera);
        this.emergencia = false;
        this.decolar =  true;
    }


    @Override
    public String toString() {
        return "AviaoDecolagem [decolar=" + decolar + ", emergencia=" + emergencia + "]";
    }


}
