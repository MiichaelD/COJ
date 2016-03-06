import java.util.Scanner;
import java.util.Arrays;
class Main{
	public static void main(String ar[]){
		Scanner in=new Scanner(System.in);
		
		int res;
		String  s1=in.next(),s2=in.next();
		
		res = Integer.parseInt(s1.replace('6','5')) + Integer.parseInt(s2.replace('6','5'));
		System.out.print(res+" ");
		
		res = Integer.parseInt(s1.replace('5','6')) + Integer.parseInt(s2.replace('5','6'));
		System.out.println(res);
	}
 
 }