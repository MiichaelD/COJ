/*

	Program:	Army Buddies
	Contest:	ACM Latin America Contest 2011 - http://coj.uci.cu/24h/problem.xhtml?abb=1581

test 2:
S=10 B=4   ===> * 1 2 3 4 5 6 7 8 9 10 *
2 5        ===> * 1(2 3 4 5)6 7 8 9 10 *
                * 1<       >6 7 8 9 10 *
6 9        ===> * 1        (6 7 8 9)10 *
                * 1<               >10 *
1 1        ===> *(1)                10 *
                *<                 >10 *
10 10      ===> *                  (10)*
                *<                    >*

10 4
2 5
6 9
1 1
10 10
				
 */
 
 import java.util.Scanner;
 import java.util.Arrays;
 class Main{
	public static Scanner in;
	public static void main(String ar[]){
		in=new Scanner(System.in);
		int s,b,x,y,left[],right[];
		
		while((s=in.nextInt()) != 0){
			b=in.nextInt();
			left=new int[s+2];
			right=new int[s+1];
			for(int i=1;i<=s;i++){
				left[i]=i-1;
				right[i]=i+1;
			}
			
			
				System.out.println("L\t"+Arrays.toString(left));
				System.out.println("\tR\t"+Arrays.toString(right));
			
			for(int i=0;i<b;i++){
				x=in.nextInt();
				y=in.nextInt();
				
				System.out.print((left[x]==0? "* ":left[x]+" "));
				System.out.println((right[y]==(s+1)? "*":right[y]));
				
				left[right[y]]=left[x];
				right[left[x]]=right[y];
				
				
			}
			System.out.println('-');
		}
		
	}
 
 }