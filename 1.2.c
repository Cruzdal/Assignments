/*
The user inputs a series of numbers and the program will give
euler's phi of them.

*/
#include <stdio.h>
#include <math.h>
/*
To program this, I can calculate the GCD and write a function for euclidean algorithm
then use another function that takes the gcd and determines if they are one
conditional loop ie while (x!=0) for gcd. Mod the number until it reaches 0.
gcd requires 1 nums, p-1 and loop through those numbers. Count numbers that have a GCD of 1
ie
            15
[1,2,3,4,5,6,7,8,9,10,11,12,13,14]
 1 1 3 1 5 3 1 1 3 5   1  3  1  1
 15 = 8

*/

void gcd (int p)
{
    int q, rem,result = 0, length=0, count=0;
   // rem = p % q;
    for(q = 1; q < p; q++)
    {
            length++;
            do{
            result = rem;
            rem = q % rem;
            q = rem;
            } while(rem !=0);

            if(rem == 1)
            {
                count++;
            }

    printf("%2d %d %d \n", length,rem,count);
    }


}


int main (int argc, char *argv[])//takes arguments from command line
{
   //int e = atoi (argv[1]);
   int p,q;
   scanf("%d", &p);
   gcd(p);
}














