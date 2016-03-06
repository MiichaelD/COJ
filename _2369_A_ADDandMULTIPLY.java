import java.util.*;
import java.math.*;

class Main {

	public static void main(String[] args){
		Scanner in =new Scanner(System.in);
		int cases, i;
		long arr[]=new long[3], max, min, res;		
				
		cases = in.nextInt();
		while ( cases-- != 0){
			i=3;
			while( i-- != 0 ){
				arr[i]=in.nextInt();			
			}
			Arrays.sort(arr);
			max = Long.MIN_VALUE;
			min = Long.MAX_VALUE;
			
			// * (+) 
			res = arr[2] * (arr[1] + arr[0]);
			
			min = Math.min(min,res);
			max = Math.max(max,res);
			
			
			res = arr[1] * (arr[2] + arr[0]);
			
			min = Math.min(min,res);
			max = Math.max(max,res);
			
			
			res = arr[0] * (arr[1] + arr[2]);
			
			min = Math.min(min,res);
			max = Math.max(max,res);
			
			// + (*)
			res = arr[2] + (arr[1] * arr[0]);
			
			min = Math.min(min,res);
			max = Math.max(max,res);
			
			
			res = arr[1] + (arr[2] * arr[0]);
			
			min = Math.min(min,res);
			max = Math.max(max,res);
			
			
			res = arr[0] + (arr[1] * arr[2]);
			
			min = Math.min(min,res);
			max = Math.max(max,res);
			
			
			
			System.out.println(min+" "+max);
			
		}
		
	}
	
}


/*
2
10 3 2
-3 2 -5



*/