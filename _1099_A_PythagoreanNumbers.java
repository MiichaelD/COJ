
import java.util.*;

class Main {

	public static void main(String[] args){
		Scanner in =new Scanner(System.in);
		int[] arr =new int[3];
		
		while (true){
			arr[0] = in.nextInt();
			if (!in.hasNext())
				break;
			arr[1] = in.nextInt();
			arr[2] = in.nextInt();
			
			Arrays.sort(arr);
			
			System.out.println((Math.sqrt(arr[0]*arr[0]+arr[1]*arr[1]) == arr[2])?"right":"wrong");
			
		}
		
	}
	
}