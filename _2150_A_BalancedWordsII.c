#include <stdio.h>
#include <string.h>
#define MAXLETTERS 101

main(){
	
	char str[MAXLETTERS];
	char c;
	int len1, len2, i, count, cases;
	
	scanf("%d",&cases);
	
	while( cases-- ){
		memset(str,'\0',MAXLETTERS);
		scanf("%s",str);
		//fgets(str,MAXLETTERS,stdin);
		
		len2 = strlen(str);
		len1 = len2/2;
		
		{
			count = 0;
			for(i = 0 ; i < len1 ; i ++ ) {
				//checking forward
				if( str[i] < 'a' )//its uppercase
					count++;
				//checking backwards
				if( str[--len2] < 'a' )//its uppercase
					count--;
			}
			if( count )
				printf("NO\n");
			else
				printf("SI\n");
		}
	}	
}
/*input:
4
aBcD
aBBCDE
aAaBcCc
aAabcCc


*/