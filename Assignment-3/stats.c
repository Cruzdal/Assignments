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

void *average(void *arg)
{
    int *avgNum = (int*) arg, sum = 0,i;

    for (i=0; i < count; i++)
    {
        sum = sum + avgNum[i];
    }
    avg = (sum/count);
    pthread_exit(0);
}

void *maximum(void *arg)
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

void *minimum(void *arg)
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

}
