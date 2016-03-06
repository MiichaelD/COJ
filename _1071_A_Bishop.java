import java.util.Formatter;
import java.math.BigInteger;
import java.util.Scanner;

public class Main{
	public static void main (String arg[]){
		Scanner in =new Scanner(System.in);
		BigInteger num=null, TWO = new BigInteger("2");
		
		while (in.hasNext()){
			num= new BigInteger(in.next());
			System.out.println((num.equals(BigInteger.ONE)?"1":(num.subtract(BigInteger.ONE).multiply(TWO).toString())));
						
		}
			
	}
}