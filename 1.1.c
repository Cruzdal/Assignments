/*
The user inputs 3 numbers, a power and a range.
The program will then output the armstrong numbers
for the power that was entered and within the range
*/

#include <stdio.h>
#include <math.h>

void armstrong(int k, int q, int p)//calculates the armstrong number.
{
    int a;

    for (a = q; a <= p; a++)
    {
        int sum, num, rem, count; //sum to add powers, num as a num, rem is the remainder used to get the decimal to power

        sum = 0;
        count = 0;
        float var = 0;
        num = a;

        while(num != 0)
        {
            rem  = num % 10;    //gets the remainder
            var = pow(rem,k);   //powers the remainder by k
            sum += (int)var;    //type casts var into an int
            num /= 10;          //shifts the number
            count++;            //used to count the amount of digits
        }

        if(sum == a && count == k)//if the summed power is an armstrong AND if the length is the same as the power
        {
            printf("%d", sum); // prints out the armstrong numbers

        }
    }
}


int main (int argc, char *argv[])//takes arguments from command line
{
    int k = atoi (argv[1]),
        p = atoi (argv[2]),
        q = atoi (argv[3]);

    armstrong(k,p,q);
}
