package COJ;
import java.util.Scanner;

public class _2346__GlassOfWiskey {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in =new Scanner(System.in);
		
		double R1,R2,H,h;
		
		while(in.hasNext()){
			R1=in.nextInt();
			R2=in.nextInt();
			H=in.nextInt();
			h=in.nextInt();
			
			if(R1==0 && R2 == 0 && H==0 && h==0)
				return;
			
			//the glass is full
			if(H == h)
				System.out.println("0.0000");
			
			//get The vol of the missing whisky to fill the glass
			if( R1 < R2)
				System.out.println(String.format("%.4f",getVol(R1, R2, H, h)));
			else
				System.out.println(String.format("%.4f",getVol(R1, H-h)));
		}
	}
	
	/**
	 * Use this function to get the volume of missing whisky
	 * if glass's figure is a cylindric
	 * @param R1 radius
	 * @param h  height of missing whisky
	 * @return
	 */
	public static double getVol(double R1, double h){
		return Math.PI*R1*R1*h;
	}
	
	
	/**
	 * Use this function to get the volume of missing whisky
	 * if figure is a frustum ( circular cone sliced between 2 parallel planes)
	 * @param R1 minor radius
	 * @param R2 major radius
	 * @param H glass height
	 * @param h whiskey height
	 * @return
	 */
	public static double getVol(double R1, double R2, double H, double h){
		double sAngle	= getSmallAngle(((int) (R2-R1)), ((int) H )),
			   R3		= R1 + (Math.tan(sAngle)*h);
		
		//System.out.println("\tgetVol: bAngle = "+Math.toDegrees(bAngle)+", sAngle="+Math.toDegrees(sAngle)+", R3="+R3);
		return getFrustumVol(R2,R3,H-h);
	}
	
	/**
	 * Mathematical formula to get a frustum
	 * (circular cone between 2 parallel planes) volume 
	 * @param R1 minor radius
	 * @param R2 major radius
	 * @param h  height between both radius
	 * @return
	 */
	public static double getFrustumVol(double R1, double R2, double h){
		return Math.PI * h * (R1*R1 + R2*R2 + R1*R2) / 3;
	}
	
	
	/**
	 * funcion que devuelve el angulo en radianes
	 * base = cateto adyacente, h = cateto opuesto
	 * @param base base del triangulo
	 * @param h    altura del triangulo
	 * @return angulo
	 */
	public static double getSmallAngle(int co, int ca){
		/*    /|
		 *   / |
		 *  /  |ady
		 * /___|
		 *  opu
		 */
		//System.out.println("\tgetBigAngle: c.o = "+h+", c.a="+base);
		return Math.atan2(co, ca); //tang = cat op / hipotenusa
	}

	
	
}

/*
2 6 7 3
100 200 150 100
0 0 0 0

*/
