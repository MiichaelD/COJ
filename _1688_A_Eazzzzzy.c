#include <stdio.h>

#define TRIANGLE 		1
#define PARALLELOGRAM 	2
#define RECTANGLE 		3
#define EXIT 			-1

int main(){

	int H, W, fig, h, i, j, k, first=1;
	
	
	for(;;){		
		if( first ){
			first = 0;
		}
		else {
			printf("\n");
		}
		
		scanf("%d",&fig);
		
		switch( fig ){
		case TRIANGLE:
			scanf("%d",&H);
			h = H;
			for(i = 0; i < H; i++){
				h--;
				//spaces
				for(j = 0 ; j < h ; j++)
					printf(" ");
				//sterisks
				k = i * 2 + 1;
				for(j = 0 ; j < k ; j++)
					printf("*");
				printf("\n");
			}
			break;
			
		case PARALLELOGRAM:
			scanf("%d %d",&W, &H);
			h = H;
			for(i = 0; i < H; i++){
				h--;
				//spaces
				for(j = 0 ; j < h ; j++)
					printf(" ");
				//sterisks
				for(j = 0 ; j < W ; j++)
					printf("*");
				printf("\n");
			}
			break;
			
		case RECTANGLE:
			scanf("%d %d",&W, &H);
			for(i = 0; i < H; i++){
				//sterisks
				for(j = 0 ; j < W ; j++)
					printf("*");
				printf("\n");
			}
			break;
			
		case EXIT:
			return 0;		
		}
		
	}
}



/*
sample input:
1
5
2
5 3
3
4 6
-1





*/
