
#include <cstdio>
#include <vector>
using namespace std;

int tens[]  = {1,10,100,1000,10000,100000,1000000,10000000,100000000, 1000000000};
int nines[] = {0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 2000000000};

int howManyNines(int x){			//cuenta cuantos digitos '9' SEGUIDOS tiene el numero
	for(int i=1; i<9 ;i++)			//sin contar el 1er digito (en caso de tener 2 o mas digitos)
		if(x%tens[i] != nines[i])
			return x > nines[i-1] ? (i-1) : (i-2);
	
	return 7;
}

vector<int> countDig(int a){
	vector<int> dig(10, 0);//creamos un nuevo vector de 10 posiciones
	while(a > 0){
		int n = howManyNines(a);//checamos con cuantos '9's termina 
		for(int i=a/tens[n]; i ;i/=10)
			dig[ i%10 ] += tens[n];
		if(n){
			int m=n-1;
			for(int i=0; i<10 ;i++)
				dig[ i ] += tens[m] * n;
		}
		a -= tens[n];
	}
	return dig;
}

int main() {
	int a, b;
	while(scanf("%d%d", &a, &b), a){
		vector<int> digA = countDig(a-1);
		vector<int> digB = countDig(b);
		
		if(a-1){
			for(int i=0; i<9;i++){
				digB[i] -= digA[i];
				printf("%d ", digB[i]);
			}
			printf("%d", digB[9]-=digA[9]);
		}
		else{
			for(int i=0; i<9;i++)
				printf("%d ", digB[i]);
			printf("%d", digB[9]);
		}
		printf("\n");
	}
}