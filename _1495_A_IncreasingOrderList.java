
 import java.util.Scanner;
 import java.util.Arrays;
 class Main{
	public static Scanner in;
	public static void main(String ar[]){
		in=new Scanner(System.in);
		
		int k= in.nextInt();
		int arr[] = new int[k];
		
		for(int i =0; i<k;i++)
			arr[i]=in.nextInt();
		
		Arrays.sort(arr);
		
		for(int i =0; i<k;i++)
			System.out.println(arr[i]);
	}
 
 }