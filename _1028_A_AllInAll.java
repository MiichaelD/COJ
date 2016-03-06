import java.util.Scanner;
class Main{
	public static void  main(String args[]){
		Scanner input=new Scanner(System.in);
		String subs,seq;
		int i,j,subLen,seqLen;
		while(input.hasNext()){
			j=0;
			subs=input.next();
			seq=input.next();
			subLen=subs.length();
			seqLen=seq.length();
			for(i=0;i<seqLen;i++){
				if(seq.charAt(i) == subs.charAt(j)){
					if(++j == subLen)
						break;
				}
			}
			System.out.println((j==subLen)?"Yes":"No");
		}		
	}
}