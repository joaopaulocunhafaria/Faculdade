package Taxi;

import java.util.Scanner; 
import Taxi.Corrida;

public class Main {

	public static void main(String[] args) {

		String modeloCarro;
		String motorCarro;
		String nomeMotorista;
		double kmInicial;
		double kmFinal;
		double kmDaCorrida;

		Corrida c1 = new Corrida();

		Scanner sc = new Scanner(System.in);

		System.out.print("Nome do motorista:");
		nomeMotorista = sc.nextLine();
		c1.setNomeMotorista(nomeMotorista);

		System.out.print("Modelo do carro:");
		modeloCarro = sc.nextLine();
		c1.setModeloCarro(modeloCarro);

		System.out.print("Motor do carro:");
		motorCarro = sc.nextLine();
		c1.setMotorCarro(motorCarro);

		System.out.print("Quilometragem inicial:");
		kmInicial = sc.nextInt();
		c1.setKmInicial(kmInicial);

		System.out.print("Quilometragem final");
		kmFinal = sc.nextInt();
		c1.setKmFinal(kmFinal);

		kmDaCorrida = c1.calcularQuilometragemPercorrida();
		c1.setKmRodado(kmDaCorrida);

		double valorDaCorrida = c1.valorFinal();
		c1.setValor(valorDaCorrida);

		System.out.println(c1);

		sc.close();

	}

}
