#include <stdlib.h>
#include <stdio.h>
/*
   Generalised Seven Eleven problem program.
   Language = C89, Author = Max Jardine

  This first method is to print the money in the appropriate format.
*/
void prmoney(int value){
    printf("$%d.%02d", value/100, value%100);
}

/*
  A method that does all the heavy lifting. It takes the target value within
  the range of 100 - 999, and then finds the possible combination of factors
  and combinants that would add to this value(divided by 100 to fit the
  scenario) and then prints them out. This method also ensures that only
  unique solutions are printed, by keeping count of how many solutions appear
  for each target.
  @param int targ The target integer.
  @return int Returns a 1 it there is a unique solution, returns 0 if there is
  no solution or multiple solutions.
*/
int calc(int targ){
    int a, b, c, d, e, f, g, h, us=0;
    /*This is a run of iterating loops designed to find the ascending
      combination of four values that fit the bounds of the scenario.
    */
    for(a = 0; a <= targ/4; a++){
        for(b = a; b <= targ/3; b++){
            for(c = b; c <= targ/2; c++){
                d = targ - (a + b + c);
                if (d >= c){
                    /*This if clause checks the result of the multiplication,
                      and then increments the us count (unique
                      solution count).
                    */
                    if(a*b*c*d == targ*1000000){
                        us++;
                        e=a;
                        f=b;
                        g=c;
                        h=d;
                    }
                }
            }
        }
    }
    /*This if statement checks that there is only one solution, and then sends
      it to be printed. It also returns a 1, which increments the unique
      solution count to be printed and the end of the program.
    */
    if(us == 1){
        prmoney(targ);
        printf(" = ");
        prmoney(e);
        printf(" + ");
        prmoney(f);
        printf(" + ");
        prmoney(g);
        printf(" + ");
        prmoney(h);
        printf("\n");
        return us;
    }
    else{
        return 0;
    }
}

/*The main method keeps track of the number of unique solutions based on the
  return values from the calc method. It contains a for-loop which iterates
  100 through to 1000, and then prints out the final line displaying the number
  of unique solutions.
*/
int main(void){
    int uniq = 0, target;
    for (target = 100; target < 1000; target++){
        uniq += calc(target);
    }
    printf("%d solutions\n", uniq);
    return EXIT_SUCCESS;
}
