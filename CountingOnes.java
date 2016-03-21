import java.util.*;

class CountingOnes{
	static Scanner in;
	public static void main (String args[]){
		in = new Scanner(System.in);
		long n,m;
		while(in.hasNext()){
			n = Long.parseLong(in.next());
			m = Long.parseLong(in.next());
			//System.out.println("n= "+n+", m = "+m);
			//System.out.println(Long.toBinaryString(n) + " "+Long.bitCount(n) );
			//System.out.println(Long.toBinaryString(m) + " "+Long.bitCount(m) );
			if (n == m){
				System.out.p rintln(Long.bitCount(n));
			}
			else
			{
				n 	= countOnes(n-1);
				m	= countOnes(m);
				long res = m - n;
				System.out.println(res);
			}
		}
	}

	public static long countOnes(long num){
		long resp, base = 1 ;
		double p;
		int iteraciones = 1;
		int bits = (int)(Math.log(num)/Math.log(2));
		num++;
		resp = num/2;
		//System.out.println("\tpasada "+iteraciones+": "+resp);
		
		while(bits-- > 0){
			iteraciones++;
			base *=  2;
			p = ((double) num) / base;
			resp += ((long) p)/2*base;
			//System.out.println("num "+ num+", base: "+base +", p "+((long)p)+", p/2 "+((long)p)/2+ " * base "+((long) p)/2*base);
			//System.out.println("\tpasada "+iteraciones+": "+resp);
			if( Math.ceil(p) % 2 == 0 ) {
				//System.out.println("\t\tMath ceil: "+Math.ceil(p) + "\tresiduo: "+num%base);
				resp += num%base;
				//System.out.println("\tpasada "+iteraciones+".5: "+resp);
			}
		}
		return resp;
	}
}