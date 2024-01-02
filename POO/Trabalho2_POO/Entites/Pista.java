package Entites;

import java.util.ArrayList;
import java.util.PriorityQueue;

public class Pista {

    public Integer quantidadeGeralDeAvioes;

    private ArrayList<AviaoAterrissagem> filaAterrissagem1 = new ArrayList<AviaoAterrissagem>();

    private ArrayList<AviaoAterrissagem> filaAterrissagem2 = new ArrayList<AviaoAterrissagem>();

    private PriorityQueue<AviaoAterrissagem> filaAterrissagemEmergencial = new PriorityQueue<>();

    private ArrayList<AviaoDecolagem> filaDecolagem = new ArrayList<AviaoDecolagem>();

    private String nome;

    public Integer getQuantidadeGeralDeAvioes() {
        return filaAterrissagem2.size() + filaAterrissagem1.size();
    }

    public Integer getQuantidadedeAviaoAterrissagemFila1() {
        return filaAterrissagem1.size();
    }

    public Integer getQuantidadedeAviaoAterrissagemFila2() {
        return filaAterrissagem2.size();
    }

    public Integer getQuantidadedeAviaoDecolagem() {
        return filaDecolagem.size();
    }

    public ArrayList<AviaoAterrissagem> getFilaAterrissagem1() {
        return filaAterrissagem1;
    }

    public ArrayList<AviaoAterrissagem> getFilaAterrissagem2() {
        return filaAterrissagem2;
    }

    public PriorityQueue<AviaoAterrissagem> getFilaAterrissagemEmergencial() {
        return filaAterrissagemEmergencial;
    }

    public ArrayList<AviaoDecolagem> getFilaDecolagem() {
        return filaDecolagem;
    }

    public Pista() {
    }

    public Pista(String nome) {
        this.filaAterrissagem1 = new ArrayList<AviaoAterrissagem>();
        this.filaAterrissagem2 = new ArrayList<AviaoAterrissagem>();
        this.filaDecolagem = new ArrayList<AviaoDecolagem>();
        this.nome = nome;
        this.filaAterrissagemEmergencial = new PriorityQueue<>();
    }

    public void addAviaoAterrissagemFila1(AviaoAterrissagem aviao) {
        this.filaAterrissagem1.add(aviao);

    }

    public void addAviaoAterrissagemFila2(AviaoAterrissagem aviao) {
        this.filaAterrissagem2.add(aviao);

    }

    public void addAviaoDecolagem(AviaoDecolagem aviao) {
        this.filaDecolagem.add(aviao);
    }

}
