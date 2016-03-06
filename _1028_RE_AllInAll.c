#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	int main(){
		char subs[32768],seq[32768];
		int i,j,subLen,seqLen;
		while(scanf("%s %s",subs,seq) != EOF){
			j=0;
			subLen=strlen(subs);
			seqLen=strlen(seq);
			for(i=0;i<seqLen;i++){
				if(seq[i] == subs[j]){
					if(++j == subLen)
						break;
				}
			}
			if(j==subLen)printf("Yes\n");
			else printf("No\n");
			//memset(subs,'\0',subLen);
			//memset(seq,'\0',seqLen);
		}		
	}
