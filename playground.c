/*------------------Includes and global definitions---------------------*/
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int grid[700][700];
int B[700];
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
/*---------------First  Debugging---------------------*/
  for( int i=0; i<N; i++) {

    for( int j=0; j<N; j++) {

      printf("%d", grid[i][j]);

    }

    printf( "\n");

  }
  printf("\n");
/*---------------------------------*/

/**
  * pSum is the prefix currSums of the original matrix
  */
  int pSum[ N+1 ][N];
  int tSum;
  for(int j = 0; j < N; j++) {
    
    tSum = 0;
    for (int i = 0; i <= N; i++) {
      
      if ( i == 0) {
        
        pSum[i][j] = 0;
   
      } else {

        tSum = tSum + grid[i-1][j];
        pSum[i][j] = tSum;
      }

    } 

  }

/*---------------Second  Debugging---------------------*/
  for( int i=0; i<=N; i++) {

    for( int j=0; j<N; j++) {

      printf("%d", pSum[i][j]);

    }

    printf( "\n");

  }
/*---------------------------------*/
/**
  * (i)For each pair of rows let be p,q it is counted the sub-
  * arrays with currSum k.AscurrSumed that  p < q.
  * (ii)It is  established a two point algorithm which uses 
  * two pointers the start and the end starting in column
  * zero.
  * (iii)Find the currSum of implicit values
  * pSum(q,j) - pSum(p,j) between the rows p,q.
  * While currSum of values is less than k the start is advanced 
  * and while currSum of values is more than k end is advanced.
  * If currSum is k then increase the result(number of k-currSum sub-
  * submatrices) and advance end and start until currSum is changed.
  * Add to result the product of pointer advances.
  * 
  */
  int start;
  int end;
  int currSum;
  int result = 0;
  printf("\n");
  for ( int p = 1; p <= N; p++ ) {

    for ( int q = 1; q <= N; q++ ) {
      
      if ( p > q ) { 
 
        continue;

      }

      start = 0;
      end = 0;
      /*-------------------Third Debugging------------------*/
      for ( int j = 0; j < N; j++) {
   
        B[j] = pSum[q][j] - pSum[ p - 1 ][j];
        printf("%d", B[j]);

      }
     /*----------------------------------------------------*/ 
      printf("\n");
      currSum = B[0];
      while ( end <= N ) {
       
        if ( currSum == K ) {
         
         if ( end == N) {
 
            currSum = currSum - B[start];
            start++;
	    if (currSum == K) {

               result++;
               printf("The result from %d to %d is %d \n", start, end, result);

            } 

            continue;  
       
          } else {

          result++;
          printf("The result from %d to %d is %d \n", start, end, result);
         
          }

        }
  
      if ( end == N ) {

        break;

      }
 
      if ( currSum <= K ) {

          end++;
          if ( end < N) {

            currSum = currSum + B[end];

          }

        } else {

          currSum = currSum - B[start];
          start++;

        }
 
      }

    }

  }
  
  printf("The result is %d \n", result);
  fclose( fp);
  return EXIT_STATUS;

  }
