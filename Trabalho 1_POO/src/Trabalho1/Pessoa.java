package Trabalho1;

import Trabalho1.ExcecaoSexoInvalido;
import Trabalho1.Metodos;

public class Pessoa {

	public Pessoa(String nome, String endereço, String cpf, char sexo, int telefone, int identidade)
			throws ExcecaoSexoInvalido {

		this.nome = nome;
		this.endereço = endereço;
		this.cpf = cpf;
		
			setSexo(sexo);
		
		this.telefone = telefone;
		this.identidade = identidade;
	}

	public Pessoa() {
	}
	
	private String nome;
	private String endereço;
	private String cpf;
	private char sexo;
	private int telefone;
	private int identidade;
	public Metodos metodos = new Metodos();
	
	public void Imprimir() {
		System.out.println("Nome: " + nome);
		System.out.println("Endereço: " + endereço);
		System.out.println("Cpf: " + cpf);
		System.out.println("Sexo(M-Masculino, F-Feminino): " + sexo);
		System.out.println("Telefone: " + telefone);
		System.out.println("Identidade: " + identidade + "\n\n");

	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getEndereço() {
		return endereço;
	}

	public void setEndereço(String endereço) {
		this.endereço = endereço;
	}

	public String getCpf() {
		return cpf;
	}

	public void setCpf(String cpf) {
		this.cpf = cpf;
	}

	public char getSexo() {
		return sexo;
	}

	public void setSexo(char sexo) throws ExcecaoSexoInvalido {
		if (sexo != 'M' && sexo != 'F') {
            
			throw new ExcecaoSexoInvalido();
			
		}
		this.sexo = sexo;
	}

	public void setTelefone(int telefone) {
		this.telefone = telefone;
	}

	public int getTelefone() {
		return telefone;
	}
	public int getIdentidade() {
		return identidade;
	}

	public void setIdentidade(int identidade) {
		this.identidade = identidade;
	}

}
