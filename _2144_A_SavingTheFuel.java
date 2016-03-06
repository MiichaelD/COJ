import java.util.Arrays;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;
// http://coj.uci.cu/24h/problem.xhtml?abb=2144

class Main{
	
	void algoritmo() throws IOException {
		int K,N,D,dif,Pi[];
		K=nextInt();
		for(;K>0;K--){
			N=nextInt();
			D=nextInt();
			Pi=new int[N];
			int sum=0;
			if(next().charAt(0) == 'i'){//Irregular Highway
				captureWeights(Pi,N);
				for(int i=0;i<D;i++)
					sum+=Pi[i];
			}
			else{
				captureWeights(Pi,N);
				dif=N-D;
				N--;
				for(;N>=dif;N--)
					sum+=Pi[N];
			}
			out.println(sum);
		}
		
	}
	
	void captureWeights(int[] P, int N)throws IOException{
		for(int i=0;i<N;i++){
			P[i]=nextInt();
		}
		Arrays.sort(P);
	}
	
	/////////////////Interfacing with input///////////////////////////
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
