import java.util.Scanner;
//floor(log10(abs(the_integer))) + 1; - conocer cuantos digitos tiene un numero
class Main{

	public static void main(String[] arg){
		Scanner input=new Scanner(System.in);
		Scanner scan;
		String st=null;
		int n,i,counter,last,len;
		while(input.hasNextLine()){
			n=Integer.parseInt(input.nextLine())*2;
			st=input.nextLine();
			counter=0;
			if(st.charAt(0)=='1' || st.charAt(2)=='1'){
				len=st.length();
				st=st.substring(0,n-1);
				st+=" "+st.charAt(0);
			}
			for(i=0;i<n;i+=2)
				try{
					if(st.charAt(i)=='0')
						if(st.charAt(i+=2)=='0'){
							counter++;
						}
				}catch(Exception e){}			
			System.out.println(Integer.toString(counter));
		}		
	}
}