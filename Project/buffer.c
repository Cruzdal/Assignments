
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
#include <semaphore.h>
#include "buffer.h"

//typedef int buffer_item;
//#define BUFFER_SIZE 5
//buffer_item buffer = (*buffer_item) malloc (sizeof (buffer_item) *BUFFER_SIZE);
buffer_item buffer[BUFFER_SIZE];
int count = 0;
sem_t full, empty;
pthread_mutex_t mutex;
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

void *producer (void *param)
{
   buffer_item item;

   while (true)
   {
   	   //Produce an item
       sleep(rand());
       item = rand();
       
       sem_wait(&empty);
       pthread_mutex_lock(&mutex);
       //sem_wait(&mutex);
       
       //insert item in buffer
      // insert_item(item);
       
       if (insert_item(item))
       {
           fprintf("Number could not be inserted into buffer");
       }
       else
       {
           printf("Producer produced %d\n" ,item);
       }
       //sem_post(&mutex);
        pthread_mutex_unlock(&mutex);
       sem_post(&full);
   }
}

 void *consumer (void *param)
 {
     buffer_item item;

     while (true)
     {		
     
         sleep(rand());
         sem_wait(&full);
		 pthread_mutex_lock(&mutex);
         
         //sem_wait(&mutex);
         
         //remove item from buffer
         remove_item(&item);
         
         if (remove_item(&item))
         {
             fprintf("Consumer could not remove number");
         }
         else
         {
             printf("consumer consumed %d\n" ,item);
         }
		//sem_post(&mutex);
		 pthread_mutex_unlock(&mutex);
        sem_post(&empty);
     }
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
    sleepDur = atoi (argv[0]);
    mkProd   = atoi (argv[1]);
    mkCon    = atoi (argv[2]);

	//Declare threads
	pthread_t tidProd, tidCons;
	//Declare default attribute
	pthread_t attr_t attr;
	
	//Initialize semaphores
	sem_init(&full,0,0);
	sem_init(&empty,0,5);
	sem_init(&mutex,0,1);
	
	//Initialize default attribute
	pthread_attr_init(&attr);
 	//int pthread_create(thread id, attribute, void*(*start_routine)(void*), arg)
 	for(int x=0; x < mkProd; x++){
 		pthread_create(&tidProd,&attr,producer,null);
	 }
	 for(int x=0; x < mkCon; x++){
 		pthread_create(&tidCons,&attr,consumer,null);
	 }
	

   	// Sleep
	pthread_join(tidProd,sleepDur);//wait for thread to exit
	pthread_join(tidCons,sleepDur);
	
	
	// 2. Initialize buffer
   //initialize();
 	// pthread_attr_init(&attr);
	// 3. Create producer thread(s)
  //pthread_t producer [mkProd];
 
	// 4. Create consumer thread(s)
   // pthread_t consumer [mkCon];
  
	// 5. Sleep
   // sleep(sleepDur);
	// 6. Exit
	exit(0);


    return 0;
}

