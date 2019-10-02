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
    pid_t cId;

    if (argc != 3)     //if there isnt 3 arguments
    	{
      		perror("Filecopy needs 3 arguments. \n");
      		exit(1);
    	}

        int original = open(argv[1],O_RDWR, 0666);                                          // opens file to read and write, 0666 are the perms used which is read and write
        int copied = open(argv[2], O_CREAT | O_RDWR, 0666);                                // opens file create, read and write into target file, 0666 are the perms used which is read and write
        ssize_t cFile, length;

        pipe(pipeId);

        if (fork() ==0)
        {

            close(pipeId[1]);                                                            // end the writing of the pipe
            cFile = read(pipeId[0], cBuffer, sizeof(cBuffer));                          // reads the contents of pipe and puts it into buffer
            close(pipeId[0]);                                                          // end the reading of the pipe

            write(copied, cBuffer, cFile);                                           // writes the contents of pipe and puts it into child buffer
        }

        else if (cId == -1)
        {

            perror("There was a problem");
            exit(1);
        }

        else
        {
            close(pipeId[0]);                                                    // end the reading of the pipe

            length = read(original, buffer, sizeof(buffer));                   // get number bytes to read

            write(pipeId[1], buffer, length);                                // writes the contents of pipe into child
            close(pipeId[1]);                                               // end the writing of the pipe
        }
    return 0;
}

