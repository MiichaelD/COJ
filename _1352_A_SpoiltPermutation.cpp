#include <cstdio>
int main(void){
    int k = -1, l = -1, r = - 1, z = -1;
	
    int n;
	scanf("%d", &n);
	while (n != 0){
		bool valid = true;
		k = -1, l = -1, r = - 1, z = -1;
		for(int i = 1; i <= n; ++i){
			scanf("%d", &k);
			if(k != i){
				valid &= (k > i && l == -1);
				l = i;
				int j;
				for(j = 1; i + j <= k; ++j){
					scanf("%d", &z);
					if(k - z != j) valid = false;
				}
				if(valid) r = k;
				i += --j;
			}
		}
		if(valid && l != r) printf("%d %d\n", l, r);
		else printf("0 0\n");
		scanf("%d", &n);
	}
	return 0;
}