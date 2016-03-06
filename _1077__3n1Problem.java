package COJ;
import java.util.Scanner;
public class _1077__3n1Problem {

	static Scanner in;
	
	public static void main(String[] args) {
		
		in=new Scanner(System.in);
		
		while(in.hasNextInt()){
			int i=in.nextInt(),j=in.nextInt();
			int max=0;
			for(int m=i;m<=j;m++){
				max=Math.max(max,algor(m));
			}
			System.out.println(i+" "+j+" "+max);
		}	
		
	}
	
	public static  int algor(int i){
		int n=1;
		while(i!=1){
			n++;
			if(i%2==0)
				i/=2;
			else
				i=i*3+1;
		}
		return n;
	}

}
