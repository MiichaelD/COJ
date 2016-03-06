#include <stdio.h>

	int main(){
		int rows, cols, c, r, found, foundInCol,pos, aux;
		char arr[52][52];
		int output[10];
		
		
		for (c=0;c<10;c++){
			output[c]=0;
		}
		
		
		scanf("%d %d",&rows,&cols);
		
		//printf("Capturing:\n");
		for(r=0;r<rows;r++){
			for(c=0;c<=cols;c++){
				scanf("%c",&arr[r][c]);
			}
		}
		/*
		printf("showing:\n");
		for(r=0;r<rows;r++){
			for(c=0;c<=cols;c++){
				printf("%c",arr[r][c]);
			}
			printf("\n");
		}
		*/
		
		found = 0;
		pos=0;
		//printf("Searching:\n");
		for(c=cols-1;c>=0;c--){
			foundInCol=0;
			//printf("\t@col: %d\n",c);
			for(r=0;r<rows;r++){
				switch(arr[r][c]){
				case 'S':
				case 'F':
				case '.': 
					break;
				default:
					aux = arr[r][c]-'0';
						//1st time found
					if( output[aux]  == 0){
						if( foundInCol == 0 )
							pos++;
						
						output[aux]=pos;
						
						//printf("\t\tfound %d,[%d][%d] at pos:%d\n",aux,r,c,pos);
						
						foundInCol = 1;
						found++;
					}
					break;
				 
				}
			}
			//printf("founds this far: %d\n",found);
			if(found == 9)
				break;				

		}		
		for(found =1; found<10;found ++)
			printf("%d\n",output[found]);
		
	}
/*

10 15
S..........222F
S.....111.....F
S...333.......F
S...555.......F
S.......444...F
S.............F
S......777....F
S..888........F
S........999..F
S...666.......F



*/