#include <stdlib.h>
#include <stdio.h>
/*
   A program to solve the specific seven eleven problem.
   Language = C89, Author = Max Jardine
   A method that takes the value, and then finds the possible combination of
   factors/combinants that would add to this value(divided by 100 to fit the
   scenario) and then prints them out. 
   @param int targ The target integer.
*/
void calc(int targ){
    int a, b, c, d, mult;
    /*This is a run of iterating loops designed to find the ascending
      combination of four values that fit the bounds of the scenario. They are
      checked as integers.
    */
    for(a = 0; a <= targ/4; a++){
        for(b = a; b <= targ/3; b++){
            for(c = b; c <= targ/2; c++){
                d = targ - (a + b + c);
                if (d >= c){
                    mult = a * b * c * d;
                    /*This if clause checks the result of the multiplication,
                      and then converts the combination monetary format for 
                      printing. 
                    */
                    if(mult == targ*1000000){
                        printf("$%d.%02d $%d.%02d $%d.%02d $%d.%02d\n", a/100,
                               a%100, b/100, b%100, c/100, c%100, d/100, d%100);
                    }
                }
            }
        }
    }
    return;
}
/*The main method serves as a wrapper function for the calc function.*/
int main(void){
    int target = 711;
    calc(target);
    return EXIT_SUCCESS;
}
