package Taxi;

public class Corrida {

	private String modeloCarro;
	private String motorCarro;
	private String nomeMotorista;
	private double kmInicial;
	private double kmFinal;
	private double kmRodado;
	private double valor;



	public String getModeloCarro() {
		return modeloCarro;
	}

	public void setModeloCarro(String modeloCarro) {
		this.modeloCarro = modeloCarro;
	}

	public String getMotorCarro() {
		return motorCarro;
	}

	public void setMotorCarro(String motorCarro) {
		this.motorCarro = motorCarro;
	}

	public String getNomeMotorista() {
		return nomeMotorista;
	}

	public void setNomeMotorista(String nomeMotorista) {
		this.nomeMotorista = nomeMotorista;
	}

	public double getKmInicial() {
		return kmInicial;
	}

	public void setKmInicial(double kmInicial) {
		this.kmInicial = kmInicial;
	}

	public double getKmFinal() {
		return kmFinal;
	}

	public void setKmFinal(double kmFinal) {
		this.kmFinal = kmFinal;
	}

	public double getKmRodado() {
		return kmRodado;
	}

	public void setKmRodado(double kmRodado) {
		this.kmRodado = kmRodado;
	}

	public double getValor() {
		return valor;
	}

	public void setValor(double valor) {
		this.valor = valor;
	}

	public double calcularQuilometragemPercorrida() {

		double quilometragemDaCorrida= (this.kmFinal - this.kmInicial);
		
		return quilometragemDaCorrida;

	}

	public double valorFinal() {

		double valorDaCorrida =kmRodado * 3.75;
		
		return valorDaCorrida;

	}


	public String toString() {
		return
	"\nModelo do Carro:" 
	+ modeloCarro 
	+ "\nMotor do Carro:"
	+ motorCarro 
	+ "\nNome do Motorista:"
	+ nomeMotorista
	+ "\nQuilometro Inicial:"
	+ kmInicial 
	+ "\nQuilometro Final:"
	+ kmFinal 
	+ "\nQuilometros Rodados:"
	+ kmRodado
	+ "\nValor da corrida: R$"
	+ valor;

	}


}
