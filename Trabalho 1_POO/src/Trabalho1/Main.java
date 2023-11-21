package Trabalho1;

import java.util.Scanner;
import Trabalho1.ExcecaoSexoInvalido;

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
            Integer op = Integer.parseInt(opçao); 
           

			switch (op) {
				case 1: {

					Medico medico = new Medico();
					String nome;
					medico.setNome(nome = metodos.PedirNome());
					String endereco = metodos.PedirEndereço();
					medico.setEndereço(endereco);
					String cpf = metodos.PedirCpf();
					medico.setCpf(cpf);
					String especialidade = metodos.PedirEspecialidade();
					medico.setEspecialidade(especialidade);
                   boolean sexoValido = false;
					
					do {
					char sexo = metodos.PedirSexo();
					try {
						medico.setSexo(sexo);
						sexoValido = true;
					} catch (ExcecaoSexoInvalido e) {
						System.out.println(e.getMessage());
					}
						
					} while (!sexoValido);

					int telefone = metodos.PedirTelefone();
					medico.setTelefone(telefone);
					int identidade = metodos.PedirIdentidade();
					medico.setIdentidade(identidade);
					int crm = metodos.PedirCrmMedico();
					medico.setCrm(crm);

					consultorio.cadastrarMedico(medico);
					break;
				}

			
					case 2: {
						Paciente paciente = new Paciente();
						String nome;
						paciente.setNome(nome = metodos.PedirNome());
						String endereco = metodos.PedirEndereço();
						paciente.setEndereço(endereco);
						String cpf = metodos.PedirCpf();
						paciente.setCpf(cpf);
						boolean sexoValido = false;
						
						do {
							char sexo = metodos.PedirSexo();
							try {
								paciente.setSexo(sexo);
								sexoValido = true;
							} catch (ExcecaoSexoInvalido e) {
								System.out.println(e.getMessage());
							}
						} while (!sexoValido);
						
						int telefone = metodos.PedirTelefone();
						paciente.setTelefone(telefone);
						int identidade = metodos.PedirIdentidade();
						paciente.setIdentidade(identidade);
						String relato = metodos.PedirRelato();
						paciente.setRelato(relato);
						String medicacao = metodos.PedirMedicacaoConsumidaRegularmente();
						paciente.setMedicacaoConsumidaRegularmente(medicacao);
						
						consultorio.cadastrarPaciente(paciente);
						
						break;
					}
				case 3: {
					String data = metodos.PedirData();
					String hora = metodos.PedirHora();
					String cpf = metodos.PedirCpf();
					int crmMedico = metodos.PedirCrm();

					Consulta consulta = new Consulta(data, hora, cpf, crmMedico);

					consultorio.cadastrarConsulta(consulta);
					break;
				}

				case 4: {
					int crmConsulta = metodos.PedirCrm();

					consultorio.procurarMedico(crmConsulta);
					break;
				}

				case 5: {
					consultorio.imprimirListaCosultas();

					break;
				}

				case 6: {
					String cpf = metodos.PedirCpf();
					consultorio.procuraPaciente(cpf);

					break;
				}

				case 7: {
					String cpf = metodos.PedirCpfPaciente();
					int crm = metodos.PedirCrmMedico();

					consultorio.imprimirConsulta(crm, cpf);

					break;
				}

				case 8: {

					{
						int crm = metodos.PedirCrmMedico();

						try {
							consultorio.removerMedico(crm);

						} catch (ExcecaoMedicoInexistente e) {
							System.err.println(e.getMessage());
						}
					}

					break;
				}

				case 9: {
					String cpf = metodos.PedirCpf();
					try {
						consultorio.removerPaciente(cpf);

					} catch (ExcecaoPacienteInexistente e) {
						System.err.println(e.getMessage());
					}

					break;
				}

				case 10: {
					String cpf = metodos.PedirCpfPaciente();
					String data = metodos.PedirData();

					try {

						consultorio.removerConsulta(cpf, data);

					} catch (ExcecaoConsultaInexistente e) {
						System.err.println(e.getMessage());
					}
					break;
				}
				case 11: {

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
