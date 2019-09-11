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

   printf("Question: %s",argv[0]);//prints the file name

   scanf("%d%d%d",&k, &q, &p);//power, min, max range

   total = armstrong(k,q,p);

   printf("%d\n", total);//prints the armstrong numbers
}


int armstrong(int k, int q, int p)//calculates the armstrong number. the int l is the letter L and not a one.
{
    int sum,l,num;

    for (l=q; l<=p; l++)
    {
        num = l/10;//shifts the number
        l = l%10;//gets the remainder
        sum += pow(l,k);//powers the remainder by k

    }

    if(sum == l)//if the summed power is an armstrong
        {
        return sum;
        }

    else
        {
        //do nothing
        }
}
/* displays numbers with the length of the power
if (sum == k){
    return sum;
}
*/
