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
#define BUFFER_SIZE 5
int count = 0;
buffer_item buffer = (*buffer_item) malloc (sizeof (buffer_item) *BUFFER_SIZE);

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

int insert_item (buffer_item *item)
{
    // insert an object into buffer
    *item = buffer [count++];

     //return 0 if successful, otherwise
     return 0;
     //return -1 indicating an error condition
}

int remove_item (buffer_item *item)
{
    // remove an object from buffer placing it in item
    *item = buffer [count--];

     //return 0 if successful, otherwise
     return 0;
     //return -1 indicating an error condition

}

int main(int argc, char *argv[]) {
    int sleepDur;
    int mkProd;
    int mkCon;
// 1. Get command line arguments argv[1],argv[2],argv[3]
    if (argc != 3)     //if there isnt 3 arguments
    	{
      		perror("This program needs 3 arguments. \n");
      		exit(1);
    	}
    sleepDur = atoi (argv1);
    mkProd   = atoi (argv2);
    mkCon    = atoi (argv3);




// 2. Initialize buffer
    initialize();
// 3. Create producer thread(s)
    pthread_t producer [mkProd];
// 4. Create consumer thread(s)
    pthread_t consumer [mkCon];
// 5. Sleep
    sleep(sleepDur);
// 6. Exit


    return 0;
}
