package Entites;

import java.util.HashMap;

public class Aviao {

private Integer  numeroAviao;
private Integer tempoEspera;

public Aviao(Integer numeroAviao, Integer tempoEspera) {
    this.numeroAviao = numeroAviao;
    this.tempoEspera = tempoEspera;
}
public Integer getNumeroAviao() {
    return numeroAviao;
}
public void setNumeroAviao(Integer numeroAviao) {
    this.numeroAviao = numeroAviao;
}
public Integer getTempoEspera() {
    return tempoEspera;
}
public void setTempoEspera(Integer tempoEspera) {
    this.tempoEspera = tempoEspera;
}

   



}