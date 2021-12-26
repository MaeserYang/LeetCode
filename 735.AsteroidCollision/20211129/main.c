#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXNUM 20 //10001
#define DEBUG 1

int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize)
{
    return rArr;
} 

int main()
{
    int arr[]={5,-3,10,-5};
    int returnSize = 0;
    int *returnArr  = NULL;

    returnArr = asteroidCollision(arr, sizeof(arr)/sizeof(int), &returnSize);
    for(int i = 0; i < returnSize; i++)
        printf("%d ", returnArr[i]);
    printf("\n");

    return 0;
}
