import java.util.*;
import java.math.*;

class Main{
	public static void main(String args[]){
		int input;
		Scanner in =new Scanner(System.in);
		int[] arr =new int[502];
		
		arr[1]=1;
		for(int i = 2; i < 502; i++){
			arr[i] = i * i + (arr[i-1]); 
		}
				
		while( (input = in.nextInt()) != 0 ){
			System.out.println(arr[input]);
				
		}
	}
}

/**
1
2
3
4
5
6
7
8
9
10
50
100
500
0



*/
