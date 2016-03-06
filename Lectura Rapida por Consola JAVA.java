import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

class Main {

//floor(log10(abs(the_integer))) + 1; - conocer cuantos digitos tiene un numero

	void algoritmo() throws IOException {
		int n; 
		while (( n = nextInt()) != 42) {
			out.println(n);
		}
	}

	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	private void eat(String str) {
		st = new StringTokenizer(str);
	}

	String next() throws IOException {
		while (!st.hasMoreTokens()) {//nos acabamos los tokens de la ultima linea leida
			String line = in.readLine();//leemos nueva linea
			if (line == null) {//linea es null
				return null;
			}
			eat(line);//separamos linea en tokens;
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	// @Override
	Main() throws IOException {
		Locale.setDefault(Locale.US);// Locale
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		eat("");//inicializamos string tokenizer
		algoritmo();//algoritmo a desarrollar
		in.close();
		out.close();
	}
}