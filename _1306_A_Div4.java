import java.util.*;
import java.math.*;

class Main {

	public static void main(String[] args){
		Scanner in =new Scanner(System.in);
		int cases;
		BigInteger num,n2=new BigInteger("4");
		
		cases = in.nextInt();
		while ( cases-- != 0){
			num=in.nextBigInteger();
			System.out.println( (num.mod(n2).equals(BigInteger.ZERO)?"YES":"NO"));
			
		}
		
	}
	
}