package Trabalho1;

public class Medico extends Pessoa {

	private int crm;
	private String especialidade;

	
	
	

	@Override
	public String toString() {
		return "Medico [\nNome: "+getNome()+" \ncrm=" + getCrm() + ", \nespecialidade=" + getEspecialidade() + ", \ncpf=" + getCpf() + ", \nsexo=" + getSexo()
				+ ", \ntelefone=" + getTelefone() + ", \nidentidade=" + getIdentidade() + "\n]\n\n";
	}





	public Medico(String nome, String endereço, String cpf, char sexo, int telefone, int identidade, int crm,
			String especialidade) {
		super(nome, endereço, cpf, sexo, telefone, identidade);
		this.crm = crm;
		this.especialidade = especialidade;
	}





	public int getCrm() {
		return crm;
	}

	public void setCrm(int crm) {
		this.crm = crm;
	}

	public String getEspecialidade() {
		return especialidade;
	}

	public void setEspecialidade(String especialidade) {
		this.especialidade = especialidade;
	}

}
