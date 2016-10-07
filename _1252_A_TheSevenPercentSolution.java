//http://coj.uci.cu/24h/problem.xhtml?pid=1252

import java.util.*;

class Main{

	final static int MAX_LEN = 81;
	final static int MAX_SIZE = 255;


	static char getLastChar(char c){
		switch (c){
			case ' ': return '0';
			case '!': return '1';
			case '$': return '4';
			case '%': return '5';
			case '(': return '8';
			case ')': return '9';
			case '*': return 'a';
			default:
				break;
		}
		return c;
	}

	static boolean isSpecial(char c){
		switch (c){
			case ' ': 
			case '!': 
			case '$': 
			case '%': 
			case '(': 
			case ')': 
			case '*':
				return true;
			
			default:
				break;
			
		}
		return false;
	}

	static String urifyGood(String string){
		int i = 0, size = 0, specials = 0;
		for (; i < string.length() ; ++i){
			if (isSpecial(string.charAt(i))){
				++specials;
			}
		}

		if (specials == 0) return string; // nothing to do here.

		size = i + (specials * 2);
		char newStr[] = new char[size];
		
		for (--i, --size; i >= 0; --i, --size){
		// for (--i, --size; specials && i < size && i >= 0; --i, --size){
			char c = string.charAt(i);
			newStr[size] = getLastChar(c);
			if (isSpecial(c)){
				newStr[--size] = '2';
				newStr[--size] = '%';
				--specials;
			}
		}
		return new String(newStr);
	}

	static String urify(String str){
		str = str.replace("%","%25")
				.replace(" ","%20")
				.replace("!","%21")
				.replace("$","%24")
				.replace("(","%28")
				.replace(")","%29")
				.replace("*","%2a");
		return str;
	}


	public static void main(String args[]){
		String str;
		Scanner in = new Scanner(System.in);
		while (in.hasNextLine()){
			str = in.nextLine();
			if (str.charAt(0) == '#')
				break;
			str = urifyGood(str);
			System.out.println(str);
		}
	}
}

