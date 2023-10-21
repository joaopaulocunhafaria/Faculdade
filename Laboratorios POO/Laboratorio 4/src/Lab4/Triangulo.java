package Lab4;

public class Triangulo {

	private float ladoA;
	private float ladoB;
	private float ladoC;

	public Triangulo(float A, float B, float C) {
		super();
		this.ladoA = A;
		this.ladoB = B;
		this.ladoC = C;
	}

	static int cont;

	public void tipoDeTriangulo() {

		if (ladoA + ladoB > ladoC && ladoA + ladoC > ladoB && ladoB + ladoC > ladoA) {

			cont++;

			if (ladoA == ladoB && ladoA == ladoC) {
				System.out.println("Triangulo equilatero");
			}
			if (ladoA != ladoB && ladoA != ladoC && ladoB != ladoC) {
				System.out.println("Triângulo Escaleno");
			}
			if ((ladoA == ladoB && ladoA != ladoC) || (ladoA == ladoC && ladoA != ladoB)
					|| (ladoC == ladoB && ladoA != ladoC)) {
				System.out.println("Triângulo Isósceles");
			}

		}

		else {
			System.out.println("Os lados fornecidos nao geram um triângulo");
		}
	}
}