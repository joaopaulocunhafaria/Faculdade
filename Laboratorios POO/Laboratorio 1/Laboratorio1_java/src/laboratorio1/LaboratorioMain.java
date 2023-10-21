package laboratorio1;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;

public class LaboratorioMain {
	public static void main(String[] args) {

		FileInputStream inFile = null;

		try {
			inFile = new FileInputStream(new File("entrada.txt"));

		} catch (IOException e) {
			System.err.println("Erro de E/S: " + e.getMessage());
		}

		int ch, aux = 0;
		char caracter;

		try {
			FileWriter outFile = new FileWriter(new File("saida.txt"));

			System.out.println("Lendo do arquivo de entrada!");

			while ((ch = inFile.read()) != -1) {

				caracter = (char) ch;
				System.out.print((char) ch);
				if (caracter == '_' && aux == 0) {
					outFile.write("<i>");

					aux = 1;
				} else if (caracter == '_' && aux == 1) {
					outFile.write("</i>");

					aux = 0;
				} else if (caracter == '*' && aux == 0) {
					outFile.write("<b>");

					aux = 1;
				} else if (caracter == '*' && aux == 1) {

					outFile.write("</b>");

					aux = 0;
				} else if (caracter != '_' && caracter != '*') {
					outFile.write(ch);

				}

			}
			outFile.close();

		} catch (IOException e) {
			System.err.println("Erro de E/S: " + e.getMessage());
		}

		try {
			inFile.close();

		} catch (IOException e) {
			System.err.println("Erro de E/S: " + e.getMessage());
		}

		FileInputStream outFile = null;

		try {
			outFile = new FileInputStream(new File("saida.txt"));

		} catch (IOException e) {
			System.err.println("Erro de E/S: " + e.getMessage());
		}

		try {
			System.out.println("Lendo do arquivo de saida!");

			while ((ch = outFile.read()) != -1) {
				System.out.print((char) ch);
			}

		} catch (IOException e) {
			System.err.println("Erro de E/S: " + e.getMessage());
		}

		
	}

}
