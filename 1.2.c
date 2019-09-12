/*
Written by: Dallas Cruz
The user inputs a series of numbers and the program will give
euler's phi of them.

*/
#include <stdio.h>

/*
To program this, I can calculate the GCD and write a function for euclidean algorithm
then use another function that takes the gcd and determines if they are one
conditional loop ie while (x!=0) for gcd. Mod the number until it reaches 0.
gcd requinum 1 nums, p-1 and loop through those numbers. Count numbers that have a GCD of 1
ie
            15
[1,2,3,4,5,6,7,8,9,10,11,12,13,14]
 1 1 3 1 5 3 1 1 3 5   1  3  1  1
 15 = 8

*/

int gcd (int q, int p)
{
    int rem = q % p; //intially mods the first two numbers
    int num = 0;

    while ( rem != 0 )//euclidean algorithem. basically a swapping method but adds in a mod in it
        {
            num = rem;      //takes the first mod
            rem = p % rem;  //mods the prev with the next numuber p
            p = rem;        //p becomes the new remainder and repeats until the final number is 0
        }

    return num;
}

int phi (int q, int p)//gets the value of the relative prime numbers
{
    int count = 0;

    for (p = 1; p < q; p++)
    {
    if(gcd(q,p) == 1)//checks to see if the GCD is 1
        {
            count++;//raises count and displays it as the phi
        }
    }

    return count;

}

int main(int argc, char *argv[])
{
	int p,i;
    for(i= 1; i <argc;i++)
    {
        int q = atoi (argv[i]);

        printf("Phi of %d is %d\n",q, phi(q,p));
    }
    return 0;
}
