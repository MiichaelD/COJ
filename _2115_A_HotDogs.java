import java.util.Scanner;

class Main{

	public static void main(String[] arg){
		Scanner input=new Scanner(System.in);
		while(input.hasNext()){
			System.out.println(division(input.nextInt(),input.nextInt()));
		}		
	}
	
	public static String division(int i,int j){
		String res=Double.toString(round(((double)i)/j));
		if(res.charAt(res.length()-2)=='.')
			return (res+"0");
		return res;
		
	}
	
	public static double round(double a){
		return Math.round(a*100)/(double)100;
	}
}