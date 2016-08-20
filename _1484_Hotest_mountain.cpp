#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>


int main (){
	unsigned int n, x, i=0;
	float m = -1000, tmp;
	scanf("%d",&n);
	while(i++ < n ){
	  scanf("%f",&tmp);
	  if(tmp >= m ){
	    m = tmp;
	    x = i;
	  }
	}
	printf("%d\n",x);
}
