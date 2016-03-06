package concursoACM2012;
import java.util.Scanner;
class Cellphone {
	
	public static void main(String[] args) {
		Cellphone cell=new Cellphone();
		Scanner in=new Scanner(System.in);
		while(in.hasNextInt()){
			int words=in.nextInt();
			String wordsA[]=new String[words];
			cell.t=new Trie();
			for(int i=0;i<words;i++){//se agregan a TRIE y Arreglo
				wordsA[i]=in.next();
				cell.addWord(cell.t, wordsA[i]);
			}
			double sumatoria=0;
			for(int i=0;i<words;i++){
				sumatoria+=cell.algor(cell.t,wordsA[i]);
			}
			String word=""+cell.round(sumatoria/words,2);
			System.out.println((word.length() == 3 ? word+"0" : word));
			
		}

	}
	
	Trie t;
	
/* input:
4
hello
hell
heaven
goodbye
3
hi
he
h
7
structure
structures
ride
riders
stress
solstice
ridiculous
<EOF>

*/

	int algor(Trie t,String word){
		int consecutivas=-1, tecleadas=1,res=0;
		int pre=countPrefixes(t,word.substring(0,1));
		Trie aux=t;
		while( ++consecutivas < word.length() && (res=(aux=goToTrie(aux,word.charAt(consecutivas))).prefixes) == pre);
		pre=res;
		while(consecutivas < word.length()){
			tecleadas++;
			while(++consecutivas < word.length() && (res=(aux=goToTrie(aux,word.charAt(consecutivas))).prefixes) == pre);{
				
			}
			pre=res;
		}
		//System.out.println(tecleadas);
		return tecleadas;
	}
	
	double round(double cifra,int digitos){
		digitos=(int)Math.pow(10,digitos);
		cifra*=digitos;
		return Math.round(cifra)/(double)digitos;
	}
	
	void addWord(Trie t ,String word){
		Trie aux=t;
		aux.prefixes++;
		if (word!=null){
			int i;
			for (i=0;i<word.length();i++){
				//aux.prefixes++;		
				char k=word.charAt(i);
				int index=k-'a';
				if(aux.edges[index]==null){
					aux.edges[index]=new  Trie();
					aux.edges[index].Char=k;
				}
				aux=aux.edges[index];
				aux.prefixes++;
			}
		}
		aux.words++;
	}
	
	Trie goToTrie(Trie root,String st){
		Trie aux=root;
		if(st!=null){
			int i;
			for (i=0;i<st.length();i++){
				int index=st.charAt(i)-'a';
				if(aux.edges[index]==null){
					return null;
				}
				aux=aux.edges[index];
			}
		}
		return aux;
	}
	
	Trie goToTrie(Trie tr,char ch){
		Trie aux=tr;
		if(aux!=null){
			aux=aux.edges[ch-'a'];			
		}
		return aux;
	}
	
	int countPrefixes(Trie t,String pre){
		Trie aux=t;
		if(pre!=null){
			int i;
			for (i=0;i<pre.length();i++){
				int index=pre.charAt(i)-'a';
				if(aux.edges[index]==null){
					return 0;
				}
				aux=aux.edges[index];
			}
		}
		return aux.prefixes;

			
	}
	
	int countWords(Trie t,String word){
		Trie aux=t;
		if(word!=null){
			int i;
			for (i=0;i<word.length();i++){
				int index=word.charAt(i)-'a';
				if(aux.edges[index]==null){
					return 0;
				}
				aux=aux.edges[index];
			}
		}
		return aux.words;
	}

}

class Trie{
	int words,prefixes;
	char Char;
	Trie edges[];
	
	public Trie(){
		words=0;
		prefixes=0;
		edges=new Trie[26];
	}
}