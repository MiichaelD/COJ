#include <stdio.h>
#include <string.h>
#define MAXLETTERS 1100

int main(){
	
	char str[MAXLETTERS];
	char c;
	int len,i, res;
	
	
	while( 1 ){
		memset(str,'\0',MAXLETTERS);
		//scanf("%s",str);
		fgets(str,MAXLETTERS,stdin);
		
		if( str[0] == '*')
			break;
		
		len = strlen(str)-1;
		if( str[0] >= 'a')
			c = str[0]-32;
		else
			c = str[0]+32;
		res = 1;
		for(i=0;i<len;i++){
			if( str[i] == ' ' && (str[i+1]!=str[0] && str[i+1]!=c) ){
				printf("N\n");
				res = 0;
				break; 
			}
		}
		if(res)
			printf("Y\n");
	}	
}
/*input:
Flowers Flourish from France
Sam Simmonds speaks softly
Peter pIckEd pePPers
truly tautograms triumph
this is NOT a tautogram
*


*/