package COJ;
import java.util.Scanner;
class _1002_RE_newHouse {
	//RunTimeError - 17/Noviembre/12
//http://coj.uci.cu/24h/problem.xhtml?abb=1002
	static Scanner in;
	static int T,N;
	static char mat[][];
	
	public static void main(String[] args) {
		in=new Scanner(System.in);
		T=in.nextInt();
		for(int casos=0;casos<T;casos++){
			N=in.nextInt();
			mat=new char[N][N];
			for(int f=0;f<N;f++){
				String line=in.next();
				for(int c=0;c<N;c++){
					mat[f][c]=line.charAt(c);
				}	
			}
			System.out.println(maxD());
			
			
		}

	}
	
	static int maxD(){
		boolean found=false;
		for(int dimen=N;dimen>0;dimen--){// maximo de recorridos con diferentes dimenciones!!!
				for(int rf=0;rf<N-dimen+1  && !found;rf++)
					for(int rc=0;rc<N-dimen+1 && !found;rc++)
						for(int f=rf;f<dimen+rf;f++){
							found=true;
							for(int c=rc;c<dimen+rc;c++){
								if( mat[f][c] != '.' ){
									found=false;
									rc=c;
									break;
								}
							}
							if(!found){
								break;
							}
					}
					if(found)return dimen;
			
		}
		return 0;
	}

}
/*input:
3
10
..........
.#####....
..#..###..
...##.....
...#..#...
...#...###
....######
..........
##########
#########.
4
..xx
x..x
x..x
xx..
5
##..#
....#
.#..#
####.
.#..#




*/