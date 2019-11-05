
/*
Product consumer problem using pthread or POSIX threads
This program will altername between sleeping for a random
amount of time and insert a random number into a buffer.
Once awake, will attempt to remove an item from the buffer
*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include "buffer.h"

buffer_item buffer[BUFFER_SIZE];
int count = 0;

sem_t full, empty;
pthread_mutex_t mutex;

void *producer (void *param)
{
   buffer_item item;

   while (1)
   {
   	   //Produce an item
       sleep(rand()%5);
       item = rand() ;
       
       sem_wait(&empty);
	   pthread_mutex_lock(&mutex);
    
       if (insert_item(item)){
       		printf("Number could not be inserted into buffer");
       		
       }
       else{
    		printf("Producer produced %d\n" ,item);
       }
       
       pthread_mutex_unlock(&mutex);
       sem_post(&full);
   }
}
 void *consumer (void *param)
 {
    buffer_item item;

    while (1)
    {		
		sleep(rand()%5);
    	sem_wait(&full);
		pthread_mutex_lock(&mutex);
      
        if (remove_item(&item)){
        	printf("Consumer could not remove number");
        
        }
        else{
            printf("Consumer consumed %d\n" ,item);
        
        }
        
	    pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
 }
int insert_item (buffer_item item)
{
	
    //Insert an object into buffer
    if(count < BUFFER_SIZE){
	
		//Insert item into buffer
		buffer [count] = item;
		count++;
		
		//Return 0 if successful
		return 0;
     }
	 
	//Return -1 indicating an error condition
	return -1;
}

int remove_item (buffer_item *item)
{
	
    // remove an object from buffer placing it in item
    if (count >0){
	
		//remove item from buffer
    	*item = buffer [count-1];
		count--;
		
		//return 0 if successful
		return 0;
    }
	
	//return -1 indicating an error condition
	return -1;

}

int main(int argc, char *argv[]) {
    int sleepDur, mkProd, mkCon;
   	int x;

	// 1. Get command line arguments argv[1],argv[2],argv[3]
    if (argc != 4){    //if there isnt 3 arguments

      	printf("Usage: myprog arg1 arg2 arg3\narg1: Sleep Duration \narg2: Number of Producer Threads \narg3: Number of Consumer Threads\n");
      	exit(0);
    }
    
	sleepDur = atoi (argv[1]);
	mkProd = atoi (argv[2]);
	mkCon = atoi (argv[3]);

	//Declare threads
	pthread_t tidProd, tidCons, tid;

	//Declare default attribute
	pthread_attr_t attr;

	//Initialize semaphores
	sem_init(&full,0,0);
	sem_init(&empty,0,5);
	pthread_mutex_init(&mutex,NULL);
	
	//Initialize default attribute
	pthread_attr_init(&attr);

 	//int pthread_create(thread id, attribute, void*(*start_routine)(void*), arg)
	
 	for(x=0; x < mkProd; x++){
 		
 		pthread_create(&tid,&attr,producer,NULL);
 		
	}
	for(x=0; x < mkCon; x++){
		
 		pthread_create(&tid,&attr,consumer,NULL);
 		
	}
	
   	// Sleep
	sleep(sleepDur);

	// 6. Exit
	exit(0);


    return 0;
}

