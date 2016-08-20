/*
 test:
 
3
PASSWORDSECURE
BLUEWORKING
SECUREWORD


 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int words;
    char letter;
    short broken[6];
    scanf("%d",&words);
    scanf("%c",&letter);
    while(words--){
        memset(broken,0,sizeof(broken));
        while(scanf("%c",&letter),letter!='\n'){
            switch(letter){
                case 'B': broken[0]++; break;
                case 'R': broken[1]++; break;
                case 'O': broken[2]++; break;
                case 'K': broken[3]++; break;
                case 'E': broken[4]++; break;
                case 'N': broken[5]++; break;
                default: break;
            }
        }
        if (broken[0] == (broken[0] & broken[1] & broken[2] & broken[3] & broken[4] & broken[5]))
            printf("No Secure\n");
        else 
            printf("Secure\n");
    }
    return	EXIT_SUCCESS;
}
