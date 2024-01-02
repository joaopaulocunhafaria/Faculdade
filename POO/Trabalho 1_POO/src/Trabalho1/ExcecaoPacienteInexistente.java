package Trabalho1;

public class ExcecaoPacienteInexistente extends Exception {
    public ExcecaoPacienteInexistente() {
        super("Impossível remover paciente. CPF não existe");
    }
}
