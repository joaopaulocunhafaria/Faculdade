
package Entites;

import java.util.HashMap;

public class AviaoAterrissagem extends Aviao {

    private boolean aterrissar;
    private boolean emergencia;

    // se for um aviao com mais de 5 minutos de combustivel ele chamara este
    // construtor
    // que ira setar o atributo emergencia como false
    public AviaoAterrissagem(Integer numeroAviao, Integer tempoEspera) {
        super(numeroAviao, tempoEspera);
        this.emergencia = false;
        this.aterrissar = true;
    }

    // se for um aviao com menos de 5 minutos de combustivel ele chamara este
    // construtor
    // que ira setar o atributo emergencia como true
    public AviaoAterrissagem(Integer numeroAviao, Integer tempoEspera, boolean emergencia) {
        super(numeroAviao, tempoEspera);
        this.emergencia = true;
        this.aterrissar = true;
    }

}