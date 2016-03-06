import java.util.Scanner;
import java.util.Arrays;
class Main{
	public static void main(String ar[]){
		Scanner in=new Scanner(System.in);
		long[] list;
		
		int courses = in.nextInt(), i;
		long k = in.nextLong(), count = 0;
		list =new long[courses];
		for(i =0; i <courses; i++){
			list[i]=in.nextLong();
			count += list[i];
		}
		
		if (count < k)
			System.out.println("IMPOSSIBLE");
		else if( count == k )
			System.out.println(courses);
		else{
			Arrays.sort(list);
			i = courses;
			while( k > 0){
				k -= list[--i];
				//System.out.println ("\t k : "+k);
			}
			System.out.println(courses-i);
		}
	}
 
 }