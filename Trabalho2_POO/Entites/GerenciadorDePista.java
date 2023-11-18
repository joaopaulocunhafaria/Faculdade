package Entites;

public class GerenciadorDePista {

        Pista pista1;
        Pista pista2;
        Pista pista3;

        public GerenciadorDePista(Pista pista1, Pista pista2, Pista pista3) {
                this.pista1 = pista1;
                this.pista2 = pista2;
                this.pista3 = pista3;
        }

        public Integer menorFilaAterrissagem() {

                Integer menorFila = 0;
                for (int i = 0; i < 3; i++) {

                        if (pista1.getFilaAterrissagem().size() < pista2.getFilaAterrissagem().size()
                                        && pista1.getFilaAterrissagem().size() < pista3.getFilaAterrissagem().size()) {
                                menorFila = 1;
                        } else if (pista2.getFilaAterrissagem().size() < pista1.getFilaAterrissagem().size()
                                        && pista2.getFilaAterrissagem().size() < pista3.getFilaAterrissagem().size()) {
                                menorFila = 2;
                        } else if (pista3.getFilaAterrissagem().size() < pista1.getFilaAterrissagem().size()
                                        && pista3.getFilaAterrissagem().size() < pista2.getFilaAterrissagem().size()) {
                                menorFila = 3;
                        } else if (pista1.getFilaAterrissagem().size() == pista2.getFilaAterrissagem().size()
                                        && pista1.getFilaAterrissagem().size() < pista3.getFilaAterrissagem().size()) {
                                menorFila = 1;
                        } else if (pista1.getFilaAterrissagem().size() == pista3.getFilaAterrissagem().size()
                                        && pista1.getFilaAterrissagem().size() < pista2.getFilaAterrissagem().size()) {
                                menorFila = 1;
                        } else if (pista2.getFilaAterrissagem().size() == pista3.getFilaAterrissagem().size()
                                        && pista2.getFilaAterrissagem().size() < pista1.getFilaAterrissagem().size()) {
                                menorFila = 2;
                        } else if (pista1.getFilaAterrissagem().size() == pista2.getFilaAterrissagem().size()
                                        && pista1.getFilaAterrissagem().size() == pista3.getFilaAterrissagem().size()) {
                                menorFila = 1;
                        }

                }
                return menorFila;
        }

        public void addAviaoAterrissagem(Aviao aviao) {

                int menorFila = menorFilaAterrissagem();

                if (menorFila == 1) {
                        pista1.addAviaoAterrissagem(aviao);
                }

        }

}
