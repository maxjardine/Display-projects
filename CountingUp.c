/** Counting Up, written in C89.
 * Author: Max Jardine
 * In order to calculate the binomial coefficient of two numbers in the nCk
 * (n choose k) format, the code recursively builds half of Pascal's triangle
 * and then uses the input values from the user as an index value. 
 * The recursive method uses two arrays of long longs, and builds a new layers 
 * of Pascal's triangle (hence the hideous portmanteau; pascurse) for each 
 * function call.
 @arguments long long *updated The array of long longs to be updated.
 @arguments long long *prev The array of long longs being used for the update.
 @arguments int n The length of the arrays and the n of the 'n Choose k'
 * formula.
 @arguments int c The recursion count, so the method knows when to stop.
 @return updated The array of long longs equivalent to the nth level of
 * Blaise Pascal's wonderful triangle.
 */
#include<stdlib.h>
#include<stdio.h>

long long* pascurse(long long *updated, long long *prev, int n, int c){
    if(c > n){
        return updated;
    }
    int i;
    for(i = 1; i < n; i++){
        updated[i] = (long long)(prev[i-1] + prev[i]);
    }
    return pascurse(prev, updated, n, c+1);
}

/* The main method handles the presentation the data and also ensures that the
   command line arguments are befitting of the scenario.
   @arguments char *argv[] An array of character arrays from the command line,
   which get parsed into integers.
   @arguments int argc The maximum number of arguments.
*/
int main(int argc, char *argv[]){
    int n, k, x;
    n = atoi(argv[1]);
    k = atoi(argv[2]);
    if(argc != 3 || k > n || k < 0){
        fprintf(stderr, "Incorrect input parameters.\nFormat: [n][k]\n");
        return EXIT_FAILURE;
    }
    /*This ensures the k value will index inside the correct 'half' of Pascal's
      triangle.*/
    if(k > n/2){
        k = n - k;
    }
    /*This aims to save space by reducing the n value.*/
    n = (n+1/2);
    /*Initialising arrays.*/
    long long pascal[n];
    long long pasCopy[n];
    pascal[0] = 1;
    pasCopy[0] = 1;
    for(x = 1; x < n; x++){
        pascal[x] = 0;
        pasCopy[x] = 0;
    }
    printf("%lli\n", pascurse(pasCopy, pascal, n, 0)[k]);
    return EXIT_SUCCESS;
    
}
