/**

Link:					https://www.hackerrank.com/contests/101apr14/challenges/gem-stones

Description:
							John has discovered various rocks. Each rock is composed of various elements, and each element is represented by a lowercase latin letter from 'a' to 'z'. An element can be present multiple times in a rock. An element is called a 'gem-element' if it occurs at least once in each of the rocks.

							Given the list of N rocks with their compositions, display the number of gem-elements that exist in those rocks.

							Input Format
							The first line consists of N, the number of rocks.
							Each of the next N lines contain rocks' composition. Each composition consists of lowercase letters of English alphabet.

							Output Format
							Print the number of gem-elements that are common in these rocks. If there are none, print 0.

							Constraints
							1 = N = 100
							Each composition consists of only small latin letters ('a'-'z').
							1 = Length of each composition = 100

							Sample Input

							3
							abcdde
							baccd
							eeabg

							Sample Output

							2

							Explanation
							Only "a", "b" are the two kind of gem-elements, since these are the only characters that occur in each of the rocks' composition.
							
							
	Programmer:		Michael Duarte
	
	Date:				October/2014
*/
import java.util.Scanner;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;

public class Rocks{


	public static void main(String args[]){
		Scanner in= new Scanner(System.in);
		int words = in.nextInt();
		
		final Integer ONE = new Integer(1);
		
		HashMap<Character,Integer> repeated = new HashMap<Character,Integer>();
		HashSet<Character> lettersInWords = new HashSet<Character>();
		
		//iterate each word
		for(int i =0;i<words;i++){
			lettersInWords.clear();
			
			//get the word and store it
			String word = in.next();
			int len = word.length();
			
			//iterate each letter
			for(int j = 0; j<len; j++){
				Character c = word.charAt(j);
			
				if(lettersInWords.contains(c)) // if already counted, skip it
					continue;
					
				lettersInWords.add(c); // added to know that we already count it in this word
				
				 //increment the number of times this letter has appered in all the words
				Integer contained = repeated.get(c);
				//repeated.put(c,  contained == null ? ONE : new Integer(contained.intValue() + 1) );
				repeated.put(c,  contained == null ? 1 : contained + 1 );
			}
		}
		
		
		int gemElements = 0;//we will store the number of gem-elements
		
		//Iterate thru the hashMap values to find the ones repeated
		Iterator<Integer> values = repeated.values().iterator();
		while(values.hasNext()){
			if (values.next().intValue() == words)
				gemElements++;			
		}
		
		System.out.println(gemElements);
	
	}



}