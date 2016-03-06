/*
	example of QUICKSORT

*/

#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b){
  return (-1)*( *(int*)a - *(int*)b );//sort descending
}

int main () {
    int N, count, i;
    unsigned long long K, sum;
    unsigned long meals[1000];
    sum=0;
    count=0;
    scanf("%d %llu", &N, &K);
   
    for(i=0; i<N; i++)scanf("%lu", &meals[i]);
    qsort (meals, N, sizeof(unsigned long), compare);
    i=0;
    //if we want the minimum number of meal to make K then start taking the most tasty meals first
    while(sum<K && i<N){
                 count++;
                 sum+=meals[i++];             
    }
    
    //for(i=0; i<N; i++)printf("%d\n", meals[i]);
    if(sum < K)printf("IMPOSSIBLE\n");
    else printf("%d\n", count);
    //system("pause");
    return 0;
}
