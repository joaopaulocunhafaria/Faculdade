package Entites;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import Applicaton.main;

import javax.swing.plaf.synth.SynthOptionPaneUI;

public class GerenciadorDePista {

        private ArrayList<Pista> pistas = new ArrayList<>();

        private ArrayList<AviaoAterrissagem> hangar = new ArrayList<>();

        private ArrayList<AviaoDecolagem> voando = new ArrayList<>();

        public int quantidadeAterrissagensEmergenciais = 0;
        public boolean climaEmergencial;
        public boolean estadoCritico;

        public boolean emergencialPousando;

        static int interacoes = 0;
        private float tempoMedioAterrissagem;

        public GerenciadorDePista(Pista pista1, Pista pista2, Pista pista3) {
                pistas.add(pista1);
                pistas.add(pista2);
                pistas.add(pista3);
        }

        public boolean isClimaEmergencial() {
                return climaEmergencial;
        }

        public void setTempoMedioAterrissagem(float tempoMedioAterrissagem) {
                this.tempoMedioAterrissagem = tempoMedioAterrissagem;
        }

        public void setclimaEmergencialTrue() {
                this.climaEmergencial = true;
        }

        public void setclimaEmergencialFalse() {
                this.climaEmergencial = false;
        }

        public void conferirCondiçoesClimaticas() {
                Random random = new Random();
                Integer aleatorio = random.nextInt(10);
                if (aleatorio == 9) {
                        setclimaEmergencialTrue();
                        setEmergencialPorClima();
                } else {
                        setclimaEmergencialFalse();
                }
        }

        public Integer menorFilaAterrissagem() {

                // editar para comparar apenas entre a fila 1 e 2
                Integer menorFila = menorNumero(pistas.get(0).getQuantidadedeAviaoAterrissagemFila1(),
                                pistas.get(0).getQuantidadedeAviaoAterrissagemFila2(),
                                pistas.get(1).getQuantidadedeAviaoAterrissagemFila1(),
                                pistas.get(1).getQuantidadedeAviaoAterrissagemFila2());

                return menorFila;
        }

        public static Aviao addAviaoAleatorio() { // CRIA AVIOES ALEATORIOS

                String[] strings = { "LATAM", "GOL", "AZUL", "American Airlines" };
                Random random = new Random();

                int passageiros = random.nextInt(200 - 100 + 1) + 100;
                int combustivel = random.nextInt(15) + 1;
                String companhiaAerea = strings[random.nextInt(4)];

                boolean decolaOUpousa;
                // falso = decola, true = aterrissa

                int numeroAviao = random.nextInt(1000 - 300 + 1) + 300;

                if (numeroAviao % 2 == 0) {
                        decolaOUpousa = true;
                } else {
                        decolaOUpousa = false;

                }

                if (decolaOUpousa == true) {

                        AviaoAterrissagem aviao = new AviaoAterrissagem(numeroAviao, companhiaAerea, passageiros,
                                        combustivel);

                        return aviao;
                } else {
                        AviaoDecolagem aviao = new AviaoDecolagem(numeroAviao, passageiros, companhiaAerea);
                        return aviao;
                }

        }

        public void addAviaoNaPista(List<Aviao> aviao) {
                int aviaoAterrissou = 0;
                int aviaoDecolou = 0;
                for (int i = 0; i < aviao.size(); i++) {

                        if (aviao.get(i) instanceof AviaoAterrissagem) {

                                addAviaoAterrissagem((AviaoAterrissagem) aviao.get(i));
                                aviaoAterrissou++;
                        }

                        if (aviao.get(i) instanceof AviaoDecolagem) {

                                addAviaoDecolagem((AviaoDecolagem) aviao.get(i));
                                aviaoDecolou++;
                        }
                }

        }

        public int menorFilaDeDecolagem() {
                int menorFila = menorNumero(pistas.get(0).getQuantidadedeAviaoDecolagem(),
                                pistas.get(1).getQuantidadedeAviaoDecolagem(),
                                pistas.get(2).getQuantidadedeAviaoDecolagem());

                return menorFila;
        }

        public void addAviaoDecolagem(AviaoDecolagem aviao) {
                int menorFila = menorFilaDeDecolagem();
                switch (menorFila) {
                        case 1:
                                System.out.println("\u001B[32mAviao decolagem adicionado na pista 1\u001B[0m\n");
                                System.out.println(aviao);
                                pistas.get(0).addAviaoDecolagem(aviao);
                                break;
                        case 2:
                                System.out.println("\u001B[32mAviao decolagem adicionado na pista 2\u001B[0m\n");
                                System.out.println(aviao);
                                pistas.get(1).addAviaoDecolagem(aviao);
                                break;
                        case 3:
                                System.out.println("\u001B[32mAviao decolagem adicionado na pista 3\u001B[0m\n");
                                System.out.println(aviao);
                                pistas.get(2).addAviaoDecolagem(aviao);
                                break;
                        default:
                                break;
                }
        }

        public void addAviaoAterrissagem(AviaoAterrissagem aviao) {

                int menorFila = menorFilaAterrissagem();

                switch (menorFila) {
                        case 1:
                                // Fila 1 - Pista 1
                                pistas.get(0).addAviaoAterrissagemFila1(aviao);
                                System.out.println("\n\u001B[32mAdicionado na Fila 1 - Pista 1\u001B[0m");
                                System.out.println("\u001B[32m" + aviao + "\u001B[0m");
                                return;

                        case 2: // Fila 2 - Pista 1
                                pistas.get(0).addAviaoAterrissagemFila2(aviao);
                                System.out.println("\n\u001B[32mAdicionado na Fila 2 - Pista 1\u001B[0m");
                                System.out.println("\u001B[32m" + aviao + "\u001B[0m");
                                return;

                        case 3:
                                // Fila 1 - Pista 2
                                pistas.get(1).addAviaoAterrissagemFila1(aviao);
                                System.out.println("\n\u001B[32mAdicionado na Fila 1 - Pista 2\u001B[0m");
                                System.out.println("\u001B[32m" + aviao + "\u001B[0m");
                                return;

                        case 4:
                                // Fila 2 - Pista 2
                                System.out.println("\n\u001B[32mAdicionado na Fila 2 - Pista 2\u001B[0m");
                                System.out.println("\u001B[32m" + aviao + "\u001B[0m");
                                return;

                        default:
                                break;
                }
        }

        // QUESTÃO 4 (a) - Imprimindo o tamanho de cada fila do sistema.
        public void imprimirAvioesCadaFila() {
                System.out.println("Numero de Avioes em Cada Fila");
                System.out.println("Fila 1 - Pista de Aterrissagem 1: ");
                System.out.println(pistas.get(0).getQuantidadedeAviaoAterrissagemFila1());
                System.out.println("Fila 2 - Pista de Aterrissagem 1: ");
                System.out.println(pistas.get(0).getQuantidadedeAviaoAterrissagemFila2());
                System.out.println("Fila 1 - Pista de Aterrissagem 2: ");
                System.out.println(pistas.get(1).getQuantidadedeAviaoAterrissagemFila1());
                System.out.println("Fila 2 - Pista de Aterrissagem 2: ");
                System.out.println(pistas.get(1).getQuantidadedeAviaoAterrissagemFila2());
                System.out.println("Fila - Pista de Decolagem: ");
                System.out.println(pistas.get(2).getQuantidadedeAviaoDecolagem());
        }

        public static int menorNumero(int a, int b, int c, int d) {
                int aux = Math.min(Math.min(a, b), Math.min(c, d));

                if (aux == a) {
                        return 1;
                } else if (aux == b) {
                        return 2;
                } else if (aux == c) {
                        return 3;
                } else {
                        return 4;

                }

        }

        public int menorNumero(int a, int b, int c) {
                int aux = Math.min(Math.min(a, b), c);

                if (aux == a) {
                        return 1;
                } else if (aux == b) {
                        return 2;
                } else {
                        return 3;
                }

        }

        public Integer quantidadedeAviao(Pista p) {

                return p.quantidadeGeralDeAvioes;

        }

        public static int randomizaNumAvioes() {
                Random random = new Random();
                int numeroAleatorio = random.nextInt(3) + 1;
                return numeroAleatorio;
        }

        public void conferirAvioesEmergenciais() {

                for (Pista pista : pistas) {
                        for (int i = 0; i < pista.getQuantidadedeAviaoAterrissagemFila1(); i++) {
                                if (pista.getFilaAterrissagem1().get(i).getCombustivel() < 5) {
                                        pista.getFilaAterrissagem1().get(i).setEmergencia(true);
                                }

                        }
                        for (int i = 0; i < pista.getQuantidadedeAviaoAterrissagemFila2(); i++) {
                                if (pista.getFilaAterrissagem2().get(i).getCombustivel() < 5) {
                                        pista.getFilaAterrissagem2().get(i).setEmergencia(true);

                                }
                        }

                }
        }

        // public int retornaTamanhoFilaAterrisagemTotal(){
        // int tamanhoTotal = 0;
        // for (Pista pista : pistas) {
        // tamanhoTotal += pista.getFilaAterrissagem1().size();
        // tamanhoTotal += pista.getFilaAterrissagem2().size();
        // }
        // return tamanhoTotal;

        // }

        public void setEmergencialPorClima() {
                // Quando o clima estiver emergencial esta funçao ira
                // setar como emergencial todos os avioes com passageiros emergenciais

                for (int i = 0; i < pistas.size() - 1; i++) {
                        for (int j = 0; j < pistas.get(j).getQuantidadedeAviaoAterrissagemFila1(); j++) {
                                if (pistas.get(j).getFilaAterrissagem1().get(j).isPassageiroEmergencial() == true) {
                                        pistas.get(j).getFilaAterrissagem1().get(j).setEmergencia(true);
                                }
                        }
                        for (int k = 0; k < pistas.get(k).getQuantidadedeAviaoAterrissagemFila2(); k++) {
                                if (pistas.get(k).getFilaAterrissagem2().get(k).isPassageiroEmergencial() == true) {
                                        pistas.get(k).getFilaAterrissagem2().get(k).setEmergencia(true);
                                }
                        }

                }
        }

        public void adicionarAviaoEmergencial() {
        }

        public ArrayList avioesEmergenciais() {

                ArrayList<Aviao> avioesEmergenciais = new ArrayList<>();

                for (int i = 0; i < pistas.size() - 1; i++) {
                        for (int j = 0; j < pistas.get(i).getQuantidadedeAviaoAterrissagemFila1(); j++) {
                                if (pistas.get(i).getFilaAterrissagem1().get(j).isEmergencia()) {

                                        avioesEmergenciais.add(pistas.get(i).getFilaAterrissagem1().get(j));
                                        pistas.get(i).getFilaAterrissagem1()
                                                        .remove(pistas.get(i).getFilaAterrissagem1().get(j));
                                }
                        }

                        for (int k = 0; k < pistas.get(i).getQuantidadedeAviaoAterrissagemFila2(); k++) {
                                if (pistas.get(i).getFilaAterrissagem2().get(k).isEmergencia() == true) {
                                        avioesEmergenciais.add(pistas.get(i).getFilaAterrissagem2().get(k));
                                        pistas.get(i).getFilaAterrissagem2()
                                                        .remove(pistas.get(i).getFilaAterrissagem2().get(k));
                                }
                        }

                }
                return avioesEmergenciais;
        }

        public void decrescerCombustivel() {

                for (Pista pista : pistas) {
                        if (!pista.getFilaAterrissagem1().isEmpty()) {
                                for (AviaoAterrissagem aviao : pista.getFilaAterrissagem1()) {
                                        aviao.setCombustivel();

                                }
                        }
                        if (!pista.getFilaAterrissagem2().isEmpty()) {
                                for (AviaoAterrissagem aviao : pista.getFilaAterrissagem2()) {
                                        aviao.setCombustivel();

                                }
                        }
                }

        }

        public void aumentarTempoDeEspera() {
                for (Pista pista : pistas) {

                        if (pista.getQuantidadedeAviaoDecolagem() > 0) {
                                pista.getFilaDecolagem().get(0)
                                                .setTempoEspera(pista.getFilaDecolagem().get(0).getTempoEspera() + 1);
                        }
                }
        }

        public boolean estadoCritico() {
                for (Pista pista : pistas) {
                        if (pista.getFilaAterrissagemEmergencial().size() > 3) {
                                return true;
                        }
                }

                return false;

        }

        public void organizaAvioesEmergenciais() {
                ArrayList<AviaoAterrissagem> avioesEmergenciais = avioesEmergenciais();
                for (AviaoAterrissagem aviao : avioesEmergenciais) {
                        pistas.get(2).getFilaAterrissagemEmergencial().add(aviao);
                }
        }

        public void aterrissaEmergencialEstadoCritico() {

                quantidadeAterrissagensEmergenciais = quantidadeAterrissagensEmergenciais + 3;
                hangar.add(pistas.get(2).getFilaAterrissagemEmergencial().peek());
                pistas.get(2).getFilaAterrissagemEmergencial().remove();
                hangar.add(pistas.get(2).getFilaAterrissagemEmergencial().peek());
                pistas.get(2).getFilaAterrissagemEmergencial().remove();
                hangar.add(pistas.get(2).getFilaAterrissagemEmergencial().peek());
                pistas.get(2).getFilaAterrissagemEmergencial().remove();

        }

        public void MelhorAcaoDecolaOuAterrissa() {
                int somaAterrisagem;

                for (int i = 0; i < (pistas.size() - 1); i++) {
                        somaAterrisagem = pistas.get(i).getFilaAterrissagem1().size()
                                        + pistas.get(i).getFilaAterrissagem2().size();

                        if (somaAterrisagem - pistas.get(i).getFilaDecolagem().size() > 5) {
                                // Aterrisa
                                Aterrisa(i);
                        }
                        if (pistas.get(i).getFilaDecolagem().size() - somaAterrisagem > 5) {
                                // decola
                                Decola(i);
                        } else {
                                Aterrisa(i);
                        }

                        somaAterrisagem = 0;
                }
                if (!pistas.get(2).getFilaAterrissagemEmergencial().isEmpty()) {
                        Aterrisa(2);
                        return;
                } else if (!pistas.get(2).getFilaDecolagem().isEmpty()) {
                        Decola(2);
                        return;
                } else {
                        System.out.println("Nao ha avioes para decolar na pista 3!\n");
                }
        }

        public void Aterrisa(int i) {

                int maiorFila = Integer.compare(pistas.get(i).getFilaAterrissagem1().size(),
                                pistas.get(i).getFilaAterrissagem2().size());
                if (maiorFila > 0) {
                        // fila 1
                        if (!pistas.get(i).getFilaAterrissagem1().isEmpty()) {

                                System.out.println("\n\u001B[31mAviao aterrissou na pista " + (i + 1) + "\u001B[0m");
                                System.out.println(pistas.get(i).getFilaAterrissagem1().get(0));
                                hangar.add(pistas.get(i).getFilaAterrissagem1().get(0));
                                pistas.get(i).getFilaAterrissagem1().remove(0);
                        }

                } else {
                        // fila 2
                        if (!pistas.get(i).getFilaAterrissagem2().isEmpty()) {
                                System.out.println("\nAviao aterrissou na pista " + (i + 1));
                                System.out.println(pistas.get(i).getFilaAterrissagem2().get(0));
                                hangar.add(pistas.get(i).getFilaAterrissagem2().get(0));
                                pistas.get(i).getFilaAterrissagem2().remove(0);
                        }
                }
        }

        public void Decola(int i) {
                System.out.println("\u001B[31mAviao decolou na pista " + (i + 1) + "\u001B[0m");
                System.out.println("\u001B[31m" + pistas.get(i).getFilaDecolagem().get(0) + "\u001B[0m");
                voando.add(pistas.get(i).getFilaDecolagem().get(0));
                pistas.get(i).getFilaDecolagem().remove(0);
        }

        public void DecolarAterrissar() {
                if (estadoCritico()) {
                        System.out.println("\u001B[31mO aeroporto está em estado crítico\u001B[0m");
                        aterrissaEmergencialEstadoCritico();
                        return;
                }
                MelhorAcaoDecolaOuAterrissa();
        }

        public void imprimirTempoMedioDecolagem() {

                float tempoMedioDecolagem = 0;
                float quantidadeGeralAvioes = 0;

                for (Pista pista : pistas) {
                        for (int i = 0; i < pista.getFilaDecolagem().size(); i++) {
                                tempoMedioDecolagem += pista.getFilaDecolagem().get(i).getTempoEspera();
                        }
                }
                for (Pista pista : pistas) {
                        quantidadeGeralAvioes += pista.getQuantidadedeAviaoDecolagem();
                }
                tempoMedioDecolagem = tempoMedioDecolagem / quantidadeGeralAvioes;

                System.out.println("Tempo Medio de Decolagem Atual: " + tempoMedioDecolagem);
        }

        public void imprimirTempoMedioAterrissagem() {

                float tempoMedioEspera = 0;
                for (AviaoAterrissagem aviao : hangar) {
                        tempoMedioEspera += aviao.getTempoEspera();
                }
                tempoMedioEspera = tempoMedioEspera / hangar.size();
                setTempoMedioAterrissagem(tempoMedioEspera);
                System.out.println("Tempo Medio de Aterrissagem Atual: " + tempoMedioEspera);
        }

        public void imprimirTempoGlobal() {

                int tempoMedioDecolagemGlobal = 0;
                float print = 0;
                for (int i = 0; i < voando.size(); i++) {
                        tempoMedioDecolagemGlobal += voando.get(i).getTempoEspera();
                }
                if (!voando.isEmpty()) {

                        print = tempoMedioDecolagemGlobal / voando.size();
                        tempoMedioDecolagemGlobal = tempoMedioDecolagemGlobal / voando.size();

                }
                System.out.println("Tempo Medio de Decolagem Global: " + print);

                float tempoMedioGlobal = tempoMedioDecolagemGlobal + tempoMedioAterrissagem / 2;

                System.out.println("Tempo Medio Global: " + tempoMedioGlobal);
        }

        public void imprimirQuantidadeDeAterrissagensEmergenciais() {
                System.out.println("Quantidade de aterrissagem Emergencial: " + quantidadeAterrissagensEmergenciais);
        }

        public void imprimirInformacoes() {
                interacoes++;

                if (interacoes % 5 == 0) {
                        System.out.println("Informacoes:");
                        imprimirTempoMedioDecolagem();
                        imprimirTempoMedioAterrissagem();
                        imprimirTempoGlobal();
                        imprimirQuantidadeDeAterrissagensEmergenciais();
                }

        }

        public void gerenciarPista() {
                emergencialPousando = false;

                decrescerCombustivel();
                aumentarTempoDeEspera();
                conferirAvioesEmergenciais();
                conferirCondiçoesClimaticas();
                organizaAvioesEmergenciais();
                DecolarAterrissar();
                imprimirInformacoes();

        }

}
/*
 * +MenorFilaDeAterrissagem(): int -ok
 * +MenorFilaDeDecolagem():int -ok
 * +QuantidadeDeAviao(Pista p): int -ok
 * +AdicionarAviaoAterrissagem(): void -ok
 * +AdicionarAviaoDecolagem():void -ok
 * +AdicionarAviaoEmergencial():void -ainda nao
 * +ConferirAviaoEmergencial():Aviao - ok
 * *+ConferirCondiçoesclimaEmergencialticas():boolean -falta implementar um
 * reorganizarPorClima() -
 * metodo
 * dentro da funçao
 * 
 */
