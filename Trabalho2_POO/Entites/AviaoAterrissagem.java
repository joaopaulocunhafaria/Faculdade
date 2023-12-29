
package Entites;

import java.util.ArrayList;
import java.lang.reflect.Array;
import java.util.Comparator;
import java.util.List;

public class AviaoAterrissagem extends Aviao implements Comparable<AviaoAterrissagem> {

    private boolean aterrissar;
    private boolean emergencia;
    private boolean passageiroEmergencial;
    public int combustivel;
    public int combustivelInicial;
    public int tempoVoando;
    public ArrayList<AviaoAterrissagem> avioesAterrissagem = new ArrayList<>();//jpara salvar os avios e tempo de voo

    public AviaoAterrissagem(Integer numeroAviao, String companhiaAerea, int passageiros,
            int combustivel) {

        super(numeroAviao, passageiros, companhiaAerea);
        this.emergencia = false;
        this.aterrissar = true;
        this.combustivel = combustivel;
        this.combustivelInicial = combustivel;
        setPassageiroEmergencial();
    }

    public int getCombustivel() {
        return combustivel;
    }

    public boolean isAterrissar() {
        return aterrissar;
    }

    public void setAterrissar(boolean aterrissar) {
        this.aterrissar = aterrissar;
    }

    public boolean isEmergencia() {
        return emergencia;
    }

    public void setEmergencia(boolean emergencia) {
        this.emergencia = emergencia;
    }

    public boolean isPassageiroEmergencial() {
        return passageiroEmergencial;
    }

    public int getTempoVoando() {
        return tempoVoando;
    }

    public void setPassageiroEmergencial() {
        Integer aleatorio = random.nextInt(10);
        if (aleatorio == 10) {
            this.passageiroEmergencial = true;
        } else {
            this.passageiroEmergencial = false;
        }
    }

    public int getTempoEspera() {
        return tempoVoando;
    }

    public void Calculotempomedio(List<AviaoAterrissagem> listaavioes)
    {
        for(int i = 0; i < listaavioes.size(); i++)
        {
            AviaoAterrissagem aviao =  listaavioes.get(i);
            System.out.println("aviao");
            System.out.println(aviao.tempoVoando);
            
        }
    }

    public void setCombustivel(){
        this.combustivel--;
        this.tempoVoando++;
    }

    @Override
    public int compareTo(AviaoAterrissagem a) {
        return Integer.compare(this.combustivel, a.combustivel);
    }

    @Override
    public String toString() {
        return "AviaoAterrissagem: NumeroAviao=" + getNumeroAviao()
                + ", companhiaAerea=" + getCompanhiaAerea();
    }

}
