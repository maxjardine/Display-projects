/** Harmonious Numbers.
 * This code is C89 and when being compiled with gcc requires the flag -lm.
 * Necessary context:
 * I wrote this code for a lecturer who had a fictitious "Aunt Maude", a 
 * peculiar character who had strange ideas about complex mathetmatical 
 * patterns. In this case she has developed a modified case of "Amicable 
 * numbers" (pairs of numbers such tthat the sum of the proper divisors of each
 * number is equal to the other). Maude's modification is that the number 1 
 * should not be considered a proper factor, and so the list should be revised, 
 * and her revision shall be called "harmonious numbers".
 *
 * A small program that prints out all of "Aunt Maude's" specified harmonious
 * numbers (that don't include 1 in their products' sums) below 2 million.
 @Author Max Jardine
*/

#include<stdlib.h>
#include<stdio.h>

/* This method finds all the factors of a number then returns their sum. It
   does this by iterating through all numbers up to the square root of input
   number checking whether any of these numbers are a factor of the input
   number. If they are, the factor is then added to the output along with it's
   corresponding factor.
   @argument double n The number whose factors are being found.
   @return double out The sum of said numbers factors
 */
int facTotal(int n){
    int out = 0;
    int i;
    for(i = 2; n > i*i; i++){
        if(n % i == 0){
            out += i + n/i;
        }
    }
    return out;
}

/* This method is a simple check for whether the input number has a harmonious
   number pairing. It also ensures that each pair is only printed once.
   @argument double n The number being checked for a harmonious partner.
*/
void harmCheck(int n){
    int i = facTotal(n);
    if(i < n){
        return;
    } else if(facTotal(i) == n){
        fprintf(stdout, "%d %d\n", n, i);
    }
}

/* In the main method the program iterates through numbers up to two million
   as specified by the assignment, checking for all harmonious pairs along the
   way
*/
int main(void){
    int n;
    for(n=1; n < 2000000; n++){
        harmCheck(n);
    }
    return EXIT_SUCCESS;
}
