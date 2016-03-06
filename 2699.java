import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int i = 0, input;
		double acum =0;
		for(;i<30;++i){
			input = in.nextInt();
			acum += input;
		}
		double average = acum / 30.0;
		acum += average;
		System.out.printf("%.3f\n",acum);
	}
}
