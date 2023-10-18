package Trabalho1;

public class Consulta {

	public Consulta(String data, String hora, String cpfPaciente, int crmMedico) {
		super();
		this.data = data;
		this.hora = hora;
		this.cpfPaciente = cpfPaciente;
		this.crmMedico = crmMedico;
	}

	public String data;
	public String hora;
	public String cpfPaciente;
	public int crmMedico;

	public void Imprimir() {
		
		
		System.out.println("Data: "+data);

		System.out.println("Hora: "+ hora);
		System.out.println("Cpf do paciente: "+cpfPaciente);
		System.out.println("Crm do medico: "+ crmMedico);
		
		
	}

	public String getData() {
		return data;
	}

	public void setData(String data) {
		this.data = data;
	}

	public String getHora() {
		return hora;
	}

	public void setHora(String hora) {
		this.hora = hora;
	}

	public String getCpfPaciente() {
		return cpfPaciente;
	}

	public void setCpfPaciente(String cpfPaciente) {
		this.cpfPaciente = cpfPaciente;
	}

	public int getCrmMedico() {
		return crmMedico;
	}

	public void setCrmMedico(int crmMedico) {
		this.crmMedico = crmMedico;
	}
	
	
	
	
	
	
}
