/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : playg.c

* Purpose : Educational

* Creation Date : 13-11-2016

* Last Modified : Sun 13 Nov 2016 03:46:12 PM EET

* Created By :  Stamatios Anoustis

_._._._._._._._._._._._._._._._._._._._._.*/

/*------------------Includes and global definitions---------------------*/
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int grid[701][701];
int B[701];
char str[701];
int EXIT_STATUS = 0;
/*-----------------Main Code-------------------------------------------*/

int main (int argc, char** argv) {

  FILE *fp = fopen(argv[1],"r");
  int N;
  int K;
  char chr;
  if( fp == NULL) {

    perror("Error while opening the file.\n");
    exit(EXIT_FAILURE);

  } else {

    fscanf(fp, "%d", &N);
    fscanf(fp, "%d", &K);

  }

  for(int i=0;i<N;i++) {

    fscanf(fp, "%s", str);

    for(int j=0;j<N;j++) {

      chr = str[j];
      grid[i][j] = (int)(chr - '0');

    }

  }

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

/**
  * (i)For each pair of rows let be p,q it is counted the sub-
  * Bays with currSum k.AscurrSumed that  p < q.
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
  for ( int p = 1; p <= N; p++ ) {

    for ( int q = 1; q <= N; q++ ) {
      
      if ( p > q ) { 
 
        continue;

      }

      start = 0;
      end = 0;
      for ( int j = 0; j < N; j++) {
   
        B[j] = pSum[q][j] - pSum[ p - 1 ][j];

      }

      currSum = B[0];
      while ( end < N) {
        
        if ( currSum == K) {

          int d_end = 0;
          int d_start = 0;
	  if ( end + 1 < N) {

            while ( B[end + 1] == 0) {

              end++;
              d_end++;
	      if ( end + 1 >= N ) {

                break;
	      
	      }

	    }

	  }

	  if ( start < N) {

            while ( B[start] == 0) {               
	      
              start++;
              d_start++;
              if (start >= N) {

		break;
		  
              }

            }

	  }

	  result += ( (d_end + 1) * (d_start + 1) );
        
	}       
      
        if ( currSum <= K) {

          end++;
          if ( end < N) {

            currSum += B[end];

          }

        } else {

          if ( start < N) {

            currSum -= B[start];

          }

          start++;

        }

      }
     
    }

  }
  
  printf("%d \n", result);
  fclose( fp);
  return EXIT_STATUS;

}
