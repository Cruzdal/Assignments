/*
The user inputs 3 numbers, a power and a range.
The program will then output the armstrong numbers
for the power that was entered and within the range

*/

#include <stdio.h>
#include <math.h>



int main (int argc, char *argv[])//takes arguments from command line
{
   int k, q, p, tot;

   printf("Question: %s",argv[0]);
   printf("\nInput a power, minimum range and a max range\n");
   scanf("%d%d%d",&k, &q, &p);

   tot = armstrong(k,q,p);

   printf("%d\n", tot);
}


int armstrong(int k, int q, int p)//calculates the armstrong number
{
    int sum = k + q +p;
    int l;
    for (l=q; l<=p; l++)
    {
    sum += pow(l,k);
    }
    return sum;
}
