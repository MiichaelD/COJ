import java.util.Arrays;
import java.util.Scanner;
class kingsPoker {

	/* @problem: Problem K - King's Poker
	 * @contest: ACM ICPC Latin America Regional 2011
	 * 5799
	 */
	static int[] v=new int[3];
	static Scanner in;
	public static void main(String[] args) {
/*
1 1 1
1 1 12
1 1 13
1 13 1
10 13 10
1 2 2
13 13 13
13 12 13
12 12 12
3 1 4
1 5 9
0 0 0

*/		in=new Scanner(System.in);
		while((v[0]=in.nextInt())!=0){
			v[1]=in.nextInt();
			v[2]=in.nextInt();
			Arrays.sort(v);
			if(v[0] == v[1] && v[0] == v[2]){//tercia
			      if(v[0] == 13) System.out.println("*");
			      else System.out.println((v[0]+1)+" "+(v[0]+1)+" "+(v[0]+1));
			}
			else 
				if(v[0] == v[1]){//par chico
					if(v[2] == 13) System.out.println("1 "+(v[0]+1)+" "+(v[0]+1));
					else System.out.println(v[0]+" "+v[0]+" "+(v[2]+1));
				}else 
					if(v[1] == v[2]){//par grande
						if(v[0] == v[1]-1){
							if(v[1] == 13) System.out.println("1 1 1");
							else System.out.println(v[2]+" "+v[2]+" "+(v[0]+2));
						}else 
							System.out.println((v[0]+1)+" "+v[2]+" "+v[2]);
					}
					else 
						System.out.println("1 1 2");
		  }
		System.exit(0);
	}
}
