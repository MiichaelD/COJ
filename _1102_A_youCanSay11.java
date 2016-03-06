import java.util.Scanner;
class Main{
	public static void main(String arg[]){
			Scanner input=new Scanner(System.in);
			long in;
			String str=null;
			while(true){
				try{
				str=input.next();
				if(str.length() >19)
					in=Long.parseLong(str.substring(str.length()-19,str.length()));
				else if ((in=Long.parseLong(str)) == 0)
					return;
				System.out.println(str+" is "+((in%11==0)?"":"not ") +"a multiple of 11.");
				}catch(Exception e){System.out.println("Fucking error");}
			}
	}
}/*

Rule A number passes the test for 11 if the difference of the sums of alternating digits is divisible by 11.(This abstract and confusing sounding rule is much clearer with a few examples)
Use the divisibility calculator below to determine if any number is divisible by eleven. Type in any number that you want, and the calculator will explain whether or not it's divisible by 11 based on this rule.

See what the rule for divisibility by 11 has to say about:

    Examples of numbers that satisfy this rule
    946 (9+6) - 4 = 11 which is, of course, evenly divided by 11 so 946 passes this divisibility test
    10,813 (1+8+3) - (0+1) = 12-1 =11. Yes, this satisfies the rule for 11!
    25, 784 = (2+ 7 + 4) - (5+8) = 13 - 13 =0 . Yes, this does indeed work. In case you found this last bit confusing, remember that any number evenly divides 0. Think about it, how many 11's are there in 0? None, right. Well that means that 11 divides zero, zero times!
    119,777,658 (1+ 9 + 7 + 6 + 8) - (1+ 7 + 7 +5) = 31 - 20 = 11

    Examples of numbers that are do not pass this divisibility test
    947 (9+7) - 4 = 12 which is not divisible by 11
    10,823 (1+8+3) - (0+2) = 12- 2 =10. No, no good. This one fails!
    35, 784 = (3 + 7 + 4) - (5+8) = 14 - 13 = 1.  No, does not satisfy the rule for 11!
    12,347, 496, 132 = (1+3+7+9+3) - (2 + 4 +4 + 6 + 3)= 23- 19 = 4

	
	
	correct answer:
#include <stdio.h>
main(){
	int a,i;char A[1000];
	while(1){gets(A);
	if(A[0]=='0'&& A[1]=='\0')return 0;
	a=0;i=0;
	while(A[i]){
		if(i%2==0) a+=A[i]-48;
		else a-=A[i++]+48;
	}
	if(a%11==0)
		printf("%s is a multiple of 11.\n",A);
	else 
		printf("%s is not a multiple of 11.\n",A);}}
*/