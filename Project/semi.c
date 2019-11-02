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


int main(int argc, char *argv[]) {


    if (argc != 3)     //if there isnt 3 arguments
    	{
      		perror("Filecopy needs 3 arguments. \n");
      		exit(1);
    	}

    return 0;
}