package Entites;

import java.util.ArrayList;

public class Pista {

    private ArrayList<Aviao> filaAterrissagem = new ArrayList<Aviao>();

    private ArrayList<Aviao> filaDecolagem = new ArrayList<Aviao>();

    private String nome;

    public ArrayList<Aviao> getFilaAterrissagem() {
        return filaAterrissagem;
    }

    public void setFilaAterrissagem(ArrayList<Aviao> filaAterrissagem) {
        this.filaAterrissagem = filaAterrissagem;
    }

    public ArrayList<Aviao> getFilaDecolagem() {
        return filaDecolagem;
    }

    public void setFilaDecolagem(ArrayList<Aviao> filaDecolagem) {
        this.filaDecolagem = filaDecolagem;
    }

    public Pista() {
    }

    public Pista(String nome, ArrayList<Aviao> filaAterrissagem, ArrayList<Aviao> filaDecolagem) {
        this.filaAterrissagem = filaAterrissagem;
        this.filaDecolagem = filaDecolagem;
        this.nome = nome;
    }

    public void addAviaoAterrissagem(Aviao aviao) {
        this.filaAterrissagem.add(aviao);
    }

    public void addAviaoDecolagem(Aviao aviao) {
        this.filaDecolagem.add(aviao);
    }

    public void removeAviaoAterrissagem(Aviao aviao) {
        this.filaAterrissagem.remove(aviao);
    }

    public void removeAviaoDecolagem(Aviao aviao) {
        this.filaDecolagem.remove(aviao);
    }

    public void printFilaAterrissagem() {
        for (Aviao aviao : filaAterrissagem) {
            System.out.println(aviao.getNumeroAviao());
        }
    }

}
