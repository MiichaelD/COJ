/*

	Programador: 	Michael Duarte
	Fecha: 			20/Noviembre/2012
	Problema:		http://coj.uci.cu/virtual/vproblem.xhtml?abb=1352
*/

import java.util.Scanner;

class Main{

	static Scanner in=null;
	
	public static void  main(String args[]){
		SolOptima();	
	}
	
	public static void  Sol1(){
		in=new Scanner(System.in);
		int i,j,k,cases,aux;
		int arr[];
		boolean found;
		while( (cases=in.nextInt()) != 0 ){
			arr=new int[cases+1];
			aux=0;
			
			for(i=1;i<=cases;i++){
				arr[i]=in.nextInt();
			}
			
			found=true;
			int mid=cases/2+1;
			for(i=1;i<=mid;i++){
				if(arr[i]!=i){
					aux=arr[i];
					for(j=i,k=0;j<=aux;j++,k++){
						if(arr[aux-k] != j){
							found=false;
							System.out.println("0 0");
							break;
						}
					}
					if(found){
						System.out.println(i!=aux? (i+" "+aux) : ("0 0"));
						found=false;						
					}
					break;
				}
			}
			if(found){
				System.out.println("0 0");
			}
		}
	}
	
	public static void  SolOptima(){
		in=new Scanner(System.in);
		int i,j,k,cases,l,r;
		boolean found;
		while( (cases=in.nextInt()) != 0 ){
			l=r=0;
			found=true;
			for(i=1;i<=cases;i++){
				k=in.nextInt();
				if(k!=i){
					for(j=k-1;j>=i;j--){
						if(j != in.nextInt()){
							found=false;
							break;
						}
					}
					if(found){
						l=i;
						r=k;
					}
					i=k;
				}
			}
			System.out.println(l!=r? (l+" "+r) : ("0 0"));
		}
	}
	
}
/*input:
8
1 6 5 4 3 2 7 8
4
2 3 4 1
4
1 2 3 4
0

*/