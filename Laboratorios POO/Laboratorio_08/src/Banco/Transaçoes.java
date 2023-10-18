package Banco;

import java.time.format.DateTimeFormatter;
import java.util.Date;

public class Transaçoes {

    private String data;
    private float valor;
    private String descriçao;
    public Transaçoes(String data, float valor, String descriçao) {
        super();
        this.data = data;
        this.valor = valor;
        this.descriçao = descriçao;
    }
    public String getData() {
        return data;
    }
    public void setData(String data) {
        this.data = data;
    }
    public float getValor() {
        return valor;
    }
    public void setValor(float valor) {
        this.valor = valor;
    }
    public String getDescriçao() {
        return descriçao;
    }
    public void setDescriçao(String descriçao) {
        this.descriçao = descriçao;
    }
    @Override
    public String toString() {
        return "Transaçoes [data=" + data
                + ", \nvalor=" + valor
                + ", \ndescriçao=" + descriçao
                ;
    }




}
