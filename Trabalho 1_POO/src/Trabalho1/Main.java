package Trabalho1;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Consultorio consultorio = new Consultorio(99020290, "Rua do engenho- Numero 342", "Consultorio Saude em Dia");
		Metodos metodos = new Metodos();

		while (true) {

			System.out.println("1 para cadastrar um médico.");
			System.out.println("2 cadastrar um paciente.");
			System.out.println("3 cadastrar uma consulta");
			System.out.println("4 imprimir dados do médico.");
			System.out.println("5 imprimir consultas.");
			System.out.println("6 imprimir dados do paciente");
			System.out.println("7 imprimir data, hora, paciente e médico de uma consulta em específico");
			System.out.println("8 remover médico");
			System.out.println("9 remover paciente");
			System.out.println("10 remover consulta");
			System.out.println("11 sair");
			String opçao = metodos.sc.nextLine();

			switch (opçao) {
			case "1": {

				String nome = metodos.PedirNome();
				String endereco = metodos.PedirEndereço();
				String cpf = metodos.PedirCpf();
				String especialidade = metodos.PedirEspecialidade();
				char sexo = metodos.PedirSexo();
				int telefone = metodos.PedirTelefone();
				int identidade = metodos.PedirIdentidade();
				int crm = metodos.PedirCrm();

				Medico medico = new Medico(nome, endereco, cpf, sexo, telefone, identidade, crm, especialidade);

				consultorio.cadastrarMedico(medico);

				break;
			}

			case "2":

			{
				String nome = metodos.PedirNome();
				String endereco = metodos.PedirEndereço();
				String cpf = metodos.PedirCpf();
				char sexo = metodos.PedirSexo();
				int telefone = metodos.PedirTelefone();
				int identidade = metodos.PedirIdentidade();
				String relato = metodos.PedirRelato();
				String medicacao = metodos.PedirMedicacaoConsumidaRegularmente();

				Paciente paciente = new Paciente(nome, endereco, cpf, sexo, telefone, identidade, relato, medicacao);

				consultorio.cadastrarPaciente(paciente);

				break;
			}

			case "3": {
				String data = metodos.PedirData();
				String hora = metodos.PedirHora();
				String cpf = metodos.PedirCpf();
				int crmMedico = metodos.PedirCrm();

				Consulta consulta = new Consulta(data, hora, cpf, crmMedico);

				consultorio.cadastrarConsulta(consulta);
				break;
			}

			case "4": {
				int crmConsulta = metodos.PedirCrm();

				consultorio.procurarMedico(crmConsulta);
				break;
			}

			case "5": {
				consultorio.imprimirListaCosultas();

				break;
			}

			case "6": {
				String cpf = metodos.PedirCpf();
				consultorio.procuraPaciente(cpf);

				break;
			}

			case "7": {
				String cpf = metodos.PedirCpfPaciente();
				int crm = metodos.PedirCrmMedico();

				consultorio.imprimirConsulta(crm, cpf);

				break;
			}

			case "8": {

				{
					int crm = metodos.PedirCrm();
					consultorio.removerMedico(crm);
				}

				break;
			}

			case "9": {
				String cpf = metodos.PedirCpf();
				consultorio.removerPaciente(cpf);
				break;
			}

			case "10": {
				String cpf = metodos.PedirCpfPaciente();
				int crm = metodos.PedirCrmMedico();

				consultorio.removerConsulta(cpf, crm);

				break;
			}
			case "11": {

				consultorio.apagarDados();
				metodos.closeScanner();
				System.out.println("Saindo...");
				return;
			}

			default:
				System.out.println("Opçao invalida!");
			}

		}

	}

}
