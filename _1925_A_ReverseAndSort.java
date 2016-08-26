import java.util.*;

class Main{


	private static long reverse(long num){
		long res = 0, aux;
		double index = Math.floor(Math.log10(num))+1;
		while (num > 0){
			aux = num % 10;
			num /= 10;
			aux *= Math.pow(10, --index);
			res += aux;
		}
		return res;
	}

	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		long numbers[] = new long[n];

		for (int i = 0 ; i < n; ++i){
			numbers[i] = in.nextLong();
			numbers[i] = reverse(numbers[i]);
		}

		Arrays.sort(numbers);
		for (long num : numbers){
			System.out.println(num);
		}
	}
}