
#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <string.h>

#define M 1001

int arr[M];

int main(){
	char str[20];
	int s1=0,s2=0;
	memset(str,'\0',sizeof(str));
	
	scanf("%s",str);
	
	if ( !strcmp("rectangle",str) ){
		scanf(" %d %d",&s1,&s2);
		printf("%d",s1*s2);
	}
	else{
		scanf(" %d",&s1);
		printf("%d",s1*s1);
	}
	
}
/*input:
rectangle 5 6

*/