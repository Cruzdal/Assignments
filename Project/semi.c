/*
Product consumer problem using pthread or POSIX threads
This program will altername between sleeping for a random
amount of time and insert a random number into a buffer.
Once awake, will attempt to remove an item from the buffer
*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

typedef int buffer item;
#define BUFFER SIZE 5

void *producer (void *param)
{
   buffer item item;

   while (true)
   {
       sleep(rand());

       item = rand();

       if (insert_item(intem))
       {
           fprintf("Number could not be inserted into buffer");
       }
       else
       {
           printf("Producer produced %d\n" ,item);
       }
   }

 void *consumer (void *param)
 {
     buffer item item;

     while (true)
     {
         sleep(rand());

         if (remove_item(&item))
         {
             fprintf("Consumer could not remove number");
         }
         else
         {
             printf("consumer consumed %d\n" ,item);
         }

     }
 }








}

int main(int argc, char *argv[]) {


    if (argc != 3)     //if there isnt 3 arguments
    	{
      		perror("This program needs 3 arguments. \n");
      		exit(1);
    	}

    return 0;
}
