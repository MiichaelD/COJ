import java.util.Scanner;
class Main{
	
	public static boolean validate(String guess, String word){
		int len=guess.length(),		ind;
		if(len < 4 || guess.indexOf(word.charAt(4)) < 0)
			return false;
		
		for(int i=0;i<len;i++){
			if((ind = word.indexOf(guess.charAt(i))) < 0)
				return false;
			//System.out.print(word+" -> ");
			word=word.substring(0,ind)+'.'+word.substring(ind+1,9);
			//System.out.println(word);
				
		}
		return true;
	}

	public static void main(String args[]){
		Scanner input=new Scanner(System.in);
		String word,guess;
		long guesses;
		while(input.hasNext()){
			word=input.next();
			guesses=input.nextLong();
			while(guesses-- > 0){
				System.out.println((guess=input.next())+" is "+
				(Main.validate(guess,word)?"valid":"invalid"));
				
			}
		}
	}
}