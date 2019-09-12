/*
* Name: Jash Patel
* Assignement 1: question 1.3c
* Summary: This program is designed to remove all the occurances of a character from the string
*/
#include <stdio.h>
#include <stdlib.h>


void rmchr(char str[],char c){
	int count =0;
	char *ptr=str; //points to the value of 0th element

    printf("\nResult String is:\n"); 

     for( ptr=str;*ptr!='\0';ptr++){     // Iterate through each character from the string

        	if(*ptr!=c){          // check if pointer is not pointing to the occurances of the character
			 printf("%c", *ptr);  // Print non-occuraces characters in a string
		}
    }

}

int main(){
	//Declare variables
	char userInput [1000];
	char character;
	
	//User input
	printf("Please enter a String: \n");
	scanf("%[^\n]%*c",userInput); // takes the input until newline
	printf("Please enter a Character:\n");
	scanf("%c",&character);
	
	//Call rmchr() function
	rmchr(userInput , character );

	
	
}
