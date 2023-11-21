package Trabalho1;

import java.util.ArrayList;

public class Consultorio {

	public Consultorio(int telefone, String endereco, String nome) {
		super();
		this.telefone = telefone;
		this.endereco = endereco;
		this.nome = nome;
	}

	ArrayList<Medico> listaMedicos = new ArrayList<Medico>();
	ArrayList<Paciente> listaPaciente = new ArrayList<Paciente>();

	ArrayList<Consulta> listaConsulta = new ArrayList<Consulta>();

	static int contPaciente;
	private int telefone;
	public String endereco;
	public String nome;

	public void cadastrarPaciente(Paciente p) {

		listaPaciente.add(p);
		System.out.println("Paciente cadastrado com sucesso!");

	}

	public void removerPaciente(String cpf) throws ExcecaoPacienteInexistente {

		Paciente p = null;
		for (int i = 0; i < listaPaciente.size(); i++) {

			if (listaPaciente.get(i).getCpf() == cpf) {

				listaPaciente.remove(i);

				p = listaPaciente.get(i);

				System.out.println("Paciente a ser removido ...");
				p.Imprimir();

				System.out.println("Paciente removido com sucesso!");
				return;
			}

		}

		if (p == null) {
			throw new ExcecaoPacienteInexistente();
		}

	}

	public void cadastrarMedico(Medico m) {

		listaMedicos.add(m);
		System.out.println("Medico cadastrado com sucesso!");

	}

	public void removerMedico(int crm) throws ExcecaoMedicoInexistente {

		Medico m = null;

		for (int i = 0; i < listaMedicos.size(); i++) {
			if (listaMedicos.get(i).getCrm() == crm) {

				m = listaMedicos.get(i);

				System.out.println("Medico a ser removido...");
				m.Imprimir();
				listaMedicos.remove(i);
				System.out.println("Medico removido com sucesso!");
				return;
			}

		}

		if (m == null) {
			throw new ExcecaoMedicoInexistente();
		}
	}

	public void cadastrarConsulta(Consulta C) {

		listaConsulta.add(C);
		System.out.println("Consulta agendada com sucesso!");

	}

	public void removerConsulta(String cpfPaciente, String data) throws ExcecaoConsultaInexistente {

		Consulta c = null;
		for (int i = 0; i < listaConsulta.size(); i++) {

			if (listaConsulta.get(i).getCpfPaciente() == cpfPaciente
					&& listaConsulta.get(i).getData() == data) {
			}

			c = listaConsulta.get(i);
			System.out.println("Consulta a ser removida...");
			c.Imprimir();
			listaConsulta.remove(i);
			System.out.println("Consulta removida com sucesso!");

		}
		if (c == null) {
			throw new ExcecaoConsultaInexistente(cpfPaciente, data);
		}
	}
	//

	public void imprimirListaPacientes() {

		if (listaPaciente.isEmpty()) {
			System.out.println("Não há pacientes cadastrados!");
		} else {
			for (int i = 0; i < listaPaciente.size(); i++) {

				listaPaciente.get(i).Imprimir();

			}

		}

	}

	public void imprimirListaMedicos() {

		if (listaMedicos.isEmpty()) {

			System.out.println("Não há medicos cadastrados!");
		} else {

			for (int i = 0; i < listaMedicos.size(); i++) {

				listaMedicos.get(i).Imprimir();

			}

		}

	}

	public void imprimirListaCosultas() {

		if (listaConsulta.isEmpty()) {

			System.out.println("Não há consultas cadastrados!");
		} else {

			for (int i = 0; i < listaConsulta.size(); i++) {

				listaConsulta.get(i).Imprimir();

			}

		}

	}

	public void procurarMedico(int crm) {

		if (listaMedicos.isEmpty()) {
			System.out.println("Não há medicos cadastrados!");
		} else {
			for (int i = 0; i < listaMedicos.size(); i++) {

				if (listaMedicos.get(i).getCrm() == crm) {

					System.out.println(listaMedicos.get(i).toString());
					return;
				}

			}
			System.out.println("Nao hà nenhum medico cadastrado com este CRM!");
			return;
		}

	}

	public void procuraPaciente(String cpf) {
		if (listaPaciente.isEmpty()) {

			System.out.println("Nao ha pacientes cadastrados!");
		} else {
			for (int i = 0; i < listaPaciente.size(); i++) {
				if (listaPaciente.get(i).getCpf() == cpf) {
					System.out.println(listaPaciente.get(i).toString());
					return;
				}
			}
			System.out.println("Nao ha pacientes com este cpf!");
			return;
		}
	}

	public void imprimirConsulta(int crmMedico, String cpfPaciente) {

		if (listaConsulta.isEmpty()) {
			System.out.println("Nao ha consultas cadastradas\n");
		} else {

			for (int i = 0; i < listaConsulta.size(); i++) {

				if (listaConsulta.get(i).cpfPaciente == cpfPaciente
						&& listaConsulta.get(i).getCrmMedico() == crmMedico) {

					listaConsulta.get(i).Imprimir();

					return;
				}

			}
			System.out.println("Nao ha consultas com este medico e este paciente\n");

		}

	}

	public void apagarDados() {
		if (!listaConsulta.isEmpty()) {
			for (int i = 0; i < listaConsulta.size(); i++) {
				listaConsulta.remove(i);
			}
		}

		if (!listaMedicos.isEmpty()) {
			for (int i = 0; i < listaMedicos.size(); i++) {
				listaMedicos.remove(i);
			}
		}

		if (!listaPaciente.isEmpty()) {
			for (int i = 0; i < listaPaciente.size(); i++) {
				listaPaciente.remove(i);
			}
		}
	}
}
