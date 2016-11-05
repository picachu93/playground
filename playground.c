/*------------------Includes and global definitions---------------------*/
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int grid[700][700];
int EXIT_STATUS = 0;
/*-----------------Main Code-------------------------------------------*/

int main (int argc, char** argv) {

  FILE *fp = fopen(argv[1],"r");
  int N;
  int K;
  if( fp == NULL) {

    perror("Error while opening the file.\n");
    exit(EXIT_FAILURE);

  } else {

    fscanf(fp, "%d", &N);
    fscanf(fp, "%d", &K);

  }

  for(int i=0;i<N;i++) {

    for(int j=0;j<N;j++) {

      fscanf(fp, "%d", &grid[i][j]);

    }

  }

/**
  *It counts for each grid-column the number of trees up to the cureent 
  *grid-row
  */
  int pSum[N][N];
  int tSum;
  for(int j = 0; j < N; j++) {
    
    tSum = 0;
    for (int i = 0; i < N; i++) {
      
      tSum = tSum + grid[i][j];
      pSum[i][j] = tSum;

    } 

  }

/*---------------Second  Debugging---------------------*/
  for(int i=0;i<N;i++) {

    for(int j=0;j<N;j++) {

      printf("%d",pSum[i][j]);

    }

    printf("\n");

  }

/*---------------------------------*/
  fclose(fp);
  return EXIT_STATUS;

  }
