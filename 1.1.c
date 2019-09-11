/*
The user inputs 3 numbers, a power and a range.
The program will then output the armstrong numbers
for the power that was entered and within the range
*/

#include <stdio.h>
#include <math.h>



int main (int argc, char *argv[])//takes arguments from command line
{
   int k, q, p;

   scanf("%d%d%d",&k,&q,&p);//power, min, max range
   armstrong(k,q,p);
}


void armstrong(int k, int q, int p)//calculates the armstrong number.
{
    int a;

    for (a = q; a <= p; a++)
    {
        int sum, num, rem, count;
        sum = 0;
        num = a;

        while(num != 0)
        {
        rem  = num % 10;    //gets the remainder
        sum += pow(rem,k);  //powers the remainder by k
        num /= 10;          //shifts the number
        }

        if(sum == a)//if the summed power is an armstrong
        {
        printf("%d\n", sum);
        }
    }
}
