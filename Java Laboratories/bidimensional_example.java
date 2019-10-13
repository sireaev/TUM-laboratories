import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Bidimensionalarray {
	public int n = 2;
	public int m = 2;
	int nm[][] = new int[n][m];
	public void initializare() throws IOException {
		/* declararea si citirea variabilelor de memorie in care se vor retine
		numarul de linii, respectiv numarul de coloane ale tabloului
		bidimensional */
		System.out.print("Introduceti numarul de linii n=");
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(stdin.readLine());
		System.out.print("Introduceti numarul de coloane m=");
		m = Integer.parseInt(stdin.readLine());

		/* declararea variabilei de tip tablou
		bidimensional A[][] */

		// citirea elementelor in tabloul dat
		int i, j;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				System.out.print("nm[" + i + "][" + j + "]=");
				nm[i][j] = Integer.parseInt(stdin.readLine());
			}
		}
	}

	public void show() {
		// afisarea elementelor tabloului
		System.out.println("Matricea citita este: ");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				System.out.print(" " + nm[i][j]);
		}
		System.out.println();
	}
}