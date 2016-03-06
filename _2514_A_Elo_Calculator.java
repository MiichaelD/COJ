import java.util.Scanner;

/**
 * Elo Calculator
 */
class Main1 {
	
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		String competition =in.next();
		int players = in.nextInt();
		double media = 0;
		
		String name;
		int K;
		double R, W, We, Ra;
		
		System.out.println("Tournament: "+competition+"\nNumber of players: "+players+"\nNew ratings:");
		for(int i = 0; i < players ; i++){
			name = in.next();
			R = Double.parseDouble(in.next());
			W = Double.parseDouble(in.next());
			We = Double.parseDouble(in.next());
			K = in.nextInt();
			media += R;
			Ra = R+ K*(W-We);
			System.out.printf("%s %.0f\n", name, Ra);
		}
		System.out.printf("Media Elo: %.0f\n", media/players);
		
	}
}


