/*
The user inputs 3 numbers, a power and a range.
The program will then output the armstrong numbers
for the power that was entered and within the range

*/

#include <stdio.h>
#include <math.h>



int main (int argc, char *argv[])//takes arguments from command line
{
   int k, q, p, total;

   printf("Question: %s",argv[0]);
   printf("\nInput a power, minimum range and a max range\n");
   scanf("%d%d%d",&k, &q, &p);

   total = armstrong(k,q,p);

   printf("%d\n", total);
}


int armstrong(int k, int q, int p)//calculates the armstrong number. the int l is the letter L and not a one.
{
    int sum,l,num;

    for (l=q; l<=p; l++)
    {
        num = l/10;
        l = l%10;
        sum += pow(l,k);
    }
    if(sum == l)
        {
        return sum;
        }

    else
        {
        //do nothing
        }
}
