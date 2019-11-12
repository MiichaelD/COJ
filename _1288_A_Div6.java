import java.util.*;
import java.math.*;

class Main {

	public static void main(String[] args){
		Scanner in =new Scanner(System.in);
		String input;
		int cases = in.nextInt();
		while (cases-- != 0){
      input = in.next();
      int sum = 0;
      for (char c : input.toCharArray()) {
        sum += c - '0';
      }
      boolean divBy3 = (sum % 3) == 0;
      char lastChar = input.charAt(input.length() - 1);
      boolean divBy2 = ((lastChar - '0') % 2) == 0;
			System.out.println(divBy2 && divBy3 ? "YES" : "NO");
		}
    in.close();
	}
}