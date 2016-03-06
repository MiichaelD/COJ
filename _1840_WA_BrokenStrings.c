//floor(log10(abs(the_integer))) + 1; - conocer cuantos digitos tiene un numero
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

3
PASSWORDSECURE
BLUEWORKING
SECUREWORD

*/

	int main(){
		int words;
		char letter;
		short broken[6];
		char word[101];
		memset(word,'\0',101);
		scanf("%d",&words);
		scanf("%c",&letter);
		while(words--){
			memset(broken,0,sizeof(broken));
			while(scanf("%c",&letter),letter!='\n'){
				switch(letter){
				case 'B': broken[0]=1; break;
				case 'R': broken[1]=1; break;
				case 'O': broken[2]=1; break;
				case 'K': broken[3]=1; break;
				case 'E': broken[4]=1; break;
				case 'N': broken[5]=1; break;
				}
				if (broken[0] && broken[1] && broken[2] && broken[3] && broken[4] && broken[5]){
					while(scanf("%c",&letter),letter!='\n');
					break;
				}
			}
			if (broken[0] && broken[1] && broken[2] && broken[3] && broken[4] && broken[5])
				printf("No Secure\n");
			else 
				printf("Secure\n");
		}
		return	EXIT_SUCCESS;
	}
