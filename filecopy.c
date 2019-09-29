/*
Written by: Dallas Cruz
This program takes a text file and copies the content in it into another test file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  //used for ssize_t which is used to count bytes
#include <unistd.h> //used for read, write, close
#include <fcntl.h> // used for open functions

int main (int argc, char *argv[])
{

    char buffer[200];
    char cBuffer[200];

    int pipeId[2];

    if (argc != 3)     //if there isnt 3 arguments
    	{

      		perror("Filecopy needs 3 arguments. \n");
      		exit(1);
    	}

        char* original = argv[1];
        char* copied = argv[2];

        close(pipeId[1]);                                                            // end the writing of the pipe

        ssize_t cFile = read(pipeId[0], cBuffer, sizeof(cBuffer));                  // reads the contents of pipe and puts it into buffer

        close(pipeId[0]);                                                          // end the reading of the pipe

    return 0;

}
