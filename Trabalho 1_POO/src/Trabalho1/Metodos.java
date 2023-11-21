package Trabalho1;

//concertar o metodo pedirCpf
//concertar o metodo pedirNome
import java.util.Scanner;

public class Metodos {

	Scanner sc = new Scanner(System.in);

	public String PedirNome() {

		System.out.println("Nome: ");
		String nome = sc.nextLine();
		return nome;
	}

	public String PedirCpf() {

		System.out.println("Cpf: ");
		String cpf = sc.nextLine();

		return cpf;

	}

	public String PedirEndereço() {

		System.out.println("Endereço: ");
		String endereço = sc.nextLine();
		return endereço;
	}

	public char PedirSexo() {
		System.out.println("Sexo (M/F): ");
		char sexo = sc.next().charAt(0);
		return sexo;
	}

	public int PedirTelefone() {
		System.out.println("Telefone: ");
		int telefone = sc.nextInt();
		return telefone;
	}

	public int PedirIdentidade() {
		System.out.println("Identidade: ");
		int identidade = sc.nextInt();
		sc.nextLine();
		return identidade;
	}

	public String PedirData() {
		System.out.println("Data (DD/MM/AAAA): ");
		String data = sc.nextLine();
		return data;
	}

	public String PedirHora() {
		System.out.println("Hora (HH:MM): ");
		String hora = sc.nextLine();
		return hora;
	}

	public String PedirCpfPaciente() {
		System.out.println("CPF do Paciente: ");
		String cpfPaciente = sc.nextLine();
		return cpfPaciente;
	}

	public int PedirCrmMedico() {
		System.out.println("CRM do Médico: ");

		String crmMedico = sc.nextLine();
		char crmMedicoChar = crmMedico.charAt(0);
		crmMedico = Character.toString(crmMedicoChar);
		int crm = Integer.parseInt(crmMedico);

		return crm;
	}

	public String PedirRelato() {
		System.out.println("Relato: ");
		String relato = sc.nextLine();
		return relato;
	}

	public String PedirMedicacaoConsumidaRegularmente() {
		System.out.println("Medicação Consumida Regularmente: ");
		String medicacao = sc.nextLine();
		return medicacao;
	}

	public int PedirCrm() {
		System.out.println("CRM: ");
		int crm = sc.nextInt();
		return crm;
	}

	public String PedirEspecialidade() {
		System.out.println("Especialidade: ");
		String especialidade = sc.nextLine();
		return especialidade;
	}

	public void closeScanner() {
	
	sc.close();
	
	}

}
