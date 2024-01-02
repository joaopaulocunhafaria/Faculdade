package Trabalho1;

public class Paciente extends Pessoa {



	public String relato;
	public String medicacaoConsumidaRegularmente;
	



	public Paciente(String nome, String endereço, String cpf, char sexo, int telefone, int identidade, String relato,
			String medicacaoConsumidaRegularmente) throws ExcecaoSexoInvalido {
		super(nome, endereço, cpf, sexo, telefone, identidade);
		this.relato = relato;
		this.medicacaoConsumidaRegularmente = medicacaoConsumidaRegularmente;
	}


	public Paciente() {
		super();
	}
	
	
	public void Imprimir() {
		System.out.println("Relato: "+relato);
	    System.out.println("Medicação presscrita: "+medicacaoConsumidaRegularmente);
	
	}



	public String getRelato() {
		return relato;
	}



	public void setRelato(String relato) {
		this.relato = relato;
	}



	public String getMedicacaoConsumidaRegularmente() {
		return medicacaoConsumidaRegularmente;
	}



	public void setMedicacaoConsumidaRegularmente(String medicacaoConsumidaRegularmente) {
		this.medicacaoConsumidaRegularmente = medicacaoConsumidaRegularmente;
	}
	
	
	
	
}
