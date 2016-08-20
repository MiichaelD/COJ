#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>

 long long int countOnes(long long int num){
	long long int resp;
	float p;
	int base = 1, iteraciones = 1;
	int bits = (int)log2 (num);
	num++;
	resp = num/2;
	//System.out.println("\tpasada "+iteraciones+": "+resp);
	
	while(bits-- > 0){
		iteraciones++;
		base *=  2;
		p = ((float) num) / base;
		resp += (((long long int) p)/2)*base;
		//System.out.println("\tpasada "+iteraciones+": "+resp);
		//System.out.println("\t\tp = "+ p+ "\tp ->int = "+(((long) p)/2));
		if( ((int)ceil(p)) % 2 == 0 ) {
			//System.out.println("\t\tMath ceil: "+Math.ceil(p) + "\tresiduo: "+num%base);
			resp += num%base;
			//System.out.println("\tpasada "+iteraciones+".5: "+resp);
		}
	}
	return resp;
}
	
int main (){
	long long int n, m;
	scanf("%lld %lld",&n, &m);
	if (n == m){
	}
	else{
		n 	= countOnes(n-1);
		m	= countOnes(m);
		printf("n= %lld, m = %lld\n",n,m);
		long long int res = m - n;
		printf("%lld\n",res);
	}
}