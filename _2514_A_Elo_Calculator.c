#include <stdio.h>
/**
 * Elo Calculator
 */
main(){
       char competition[100], name[100];
       int players, K, i;
       float media = 0, R, W, We, Ra;
       scanf("%s %d",	competition, &players );
		
		printf("Tournament: %s\nNumber of players: %d\nNew ratings:\n",competition, players);
		for(i = 0; i < players ; i++){
            memset(name,0,sizeof(name));
            scanf("%s %f %f %f %d",name, &R, &W, &We, &K);
			media += R;
			Ra=R + K*(W-We);
			printf("%s %.0f\n", name, Ra);
		}
		media /=players;
        printf("Media Elo: %.0f\n", media);             
}
/*
Capablanca 5
Delgado 2700 3.6 0.3 20
Quesada 2639 2.6 2.7 20
Gonzalez 2520 1.6 3.6 30
Bruzon 2698 1.4 4.8 10
Arencibia 2526 2.9 1.9 10

*/
