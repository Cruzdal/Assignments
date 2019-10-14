/*
Written by: Dallas cruz
This program uses multithread to calculate various stat values for a list of numbers.
First thread will find the average
Second thread will find the maxmimum
The last thread will find the minimum
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int count = 0;
int avg;
int max;
int min;

void *average(void *arg) //Function that determines the average numbers given
{
    int *avgNum = (int*) arg, sum = 0,i;

    for (i=0; i < count; i++)
    {
        sum = sum + avgNum[i];
    }
    avg = (sum/count);
    pthread_exit(0);
}

void *maximum(void *arg)  //Function that determines the maximum numbers given
{
    int *maxNum = (int*) arg, i;
    max = maxNum[0];

    for (i=0; i < count; i++)
    {
        if(maxNum[i] > max)
        {
            max = maxNum[i];
        }
    }
    pthread_exit(0);
}

void *minimum(void *arg)  //Function that determines the minimum numbers given
{
    int *minNum = (int*) arg, i;
    min = minNum[0];

    for (i=0; i < count; i++)
    {
        if(minNum[i] < min)
        {
            min = minNum[i];
        }
    }
    pthread_exit(0);
}

int main(int argc, char *argv[])
{
    int i,numbers =0;

    for(i=1; i < argc; i++)
    {
        numbers = atoi (argv[i]);
    }

    pthread_t aT;   //Average Thread
    pthread_t maT;  //Maximum Thread
    pthread_t miT;  //Minimum Thread

    pthread_create(&aT,NULL,average,(void*)numbers);
    pthread_create(&maT,NULL,maximum,(void*)numbers);
    pthread_create(&miT,NULL,minimum,(void*)numbers);

    pthread_join(aT,NULL);
    pthread_join(maT,NULL);
    pthread_join(miT,NULL);

    printf("Average value is %d \n", average);
    printf("Minimum value is %d \n", minimum);
    printf("Maximum value is %d \n", maximum);

}
