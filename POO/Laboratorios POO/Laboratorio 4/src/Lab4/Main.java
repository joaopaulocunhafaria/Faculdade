package Lab4;

import java.util.Scanner;
import Lab4.Triangulo;
import Lab4.Lampada;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int opcao;

		while (true) {

			System.out.println("1-Triângulo\n2-Lampada");
			opcao = sc.nextInt();

			switch (opcao) {

			case 1:

				System.out.println("Digite o lado A,B,C do triângulo:");
				float a = sc.nextFloat();
				float b = sc.nextFloat();
				float c = sc.nextFloat();

				Triangulo t1 = new Triangulo(a, b, c);

				t1.tipoDeTriangulo();

				break;

			case 2:

				sc.nextLine();
				System.out.println("Digite o modelo da lampada:");

				String modelo = sc.nextLine();

				System.out.println("Digite a tensao da lampada:");
				float tensao = sc.nextFloat();

				Lampada l1 = new Lampada(modelo, tensao);
				modelo = l1.getModelo();
				tensao = l1.getTensao();
				
				int opçao = 0;

				do {

					int estado;
					System.out.println("1-Acender\n2-Apagar\n3-Estado da lampada\n4-Sair");
					opçao = sc.nextInt();

					if (opçao == 2) {
						estado = 0;
						estado = l1.getEstado();
						l1.apagar();
					}
					if (opçao == 1) {
						estado = 1;
						estado = l1.getEstado();
						l1.acender();
					}
					if (opçao == 3) {
						l1.estado();
					}

				} while ((opçao == 1 || opçao == 2 || opçao == 3));

				break;

			case 3:

				System.out.println("\nA classe Triangulo foi intanciada " + Triangulo.cont + " vezes");
				System.out.println("A classe Lampada foi instanciada " + Lampada.cont + " vezes\n Saindo...");

				return;

			default:
				System.out.println("Opçao não reconhecida!");
				break;

			}

		}

	}

}
