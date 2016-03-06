import java.util.Scanner;
import java.text.DecimalFormat;
class Main{
	
	public static void main(String ar[]){
		Scanner input=new Scanner(System.in);
		DecimalFormat nformat=new DecimalFormat("###.######");
		nformat.setMinimumFractionDigits(6);
		nformat.setMaximumFractionDigits(6);
		double in; 
		while(input.hasNext()){
			in=input.nextDouble();
			System.out.println(nformat.format(in/2));
		}
	}
}