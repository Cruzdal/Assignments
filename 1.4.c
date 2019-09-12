/*
* Name: Jash Patel
* Assignement 1: question 1.4c
* Summary: This program is designed to remove all the occurances of a character from second string  in the string
*/
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

void rmstr(char str[],char str2[]){

  
  int count =0,count2=0; 
 
    int incrementStr2= str2[count];

	char *ptr=str; //points to the value of 0th elementx	
    char *ptr2=str2;
  
       for( ptr=str;*ptr!='\0';ptr++){
 			//for (int i = 0; i < strlen(str2); i++) {
        	if(*ptr!=*str2){          // check if pointer is not pointing to the occurances of the character
        	
			 printf("%c", *ptr);       // Print non occuraces characters in a string
			 
		}
	
	}
  }



int main(){
	char userInput1 [1000];
	char userInput2 [1000];
	printf("Please enter the first String: \n");
	scanf("%[^\n]%*c",userInput1); // takes the user input input until newline
	printf("Please enter the second String:\n");
	scanf("%[^\n]%*c",userInput2);
     
     rmstr(userInput1 , userInput2);

	
	
}
