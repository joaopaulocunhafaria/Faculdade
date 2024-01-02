package Trabalho1;

public class ExcecaoConsultaInexistente extends Exception{
    
    public ExcecaoConsultaInexistente(String cpf, String data) {
        super("“Impossível remover Consulta. Paciente " +cpf +"não tem consulta agendada para a data "+data);
    }

}
