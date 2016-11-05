#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main (int argc, char** argv) {
	FILE *fp = fopen(argv[1],"r");
	int N,K,i,j;
	int grid[15][15];
	if( fp == NULL)	
	{
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		fscanf(fp, "%d", &N);
		fscanf(fp, "%d", &K);
	}


	for( i=0;i<N;i++){
		for( j=0;j<N;j++){
			fscanf(fp, "%d", &grid[i][j]);
		}
	}
		printf("N = %d\n", N);
		printf("K = %d\n", K);
	for( i=0;i<N;i++){
		for( j=0;j<N;j++){

			printf("%d",grid[i][j]);
		}
		printf("\n");
	}
	
	fclose(fp);
	return(0);
}
