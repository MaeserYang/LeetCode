#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXNUM 20 //10001
#define DEBUG 1

#if DEBUG
int prArr(int* asteroids, int asteroidsSize)
{
    for(int i = 0; i < asteroidsSize; i++)
        printf("%d ", asteroids[i]);
    printf("\n");
}
#endif

int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize)
{
    #if DEBUG
        printf("size %d \n", asteroidsSize);
        prArr(asteroids, asteroidsSize);
        printf("1====\n");
    #endif

    int *left = NULL;
    int *right =  NULL;
    int *tmp =  NULL;
    int *rArr = NULL;
    int rArrIndex = 0;

    rArr = malloc(sizeof(int)*MAXNUM);
    memset(rArr, 0, MAXNUM);
    #if DEBUG
        printf("memset ");
        prArr(rArr, MAXNUM);
    #endif
    left = &asteroids[0]; right = &asteroids[1];
    for(;;) {
        if((left - asteroids) > asteroidsSize &&  (right - asteroids) > (asteroidsSize - 1)) {
            *returnSize = rArrIndex;
            return rArr;
        }

        if(*left > 0 && *right < 0) {
            if(abs(*left) > abs(*right)) {
                rArr[rArrIndex] = *left;
                right = right + 1;
                rArrIndex = rArrIndex + 1;
            } else if(abs(*left) == abs(*right)){
                left = left + 2;
                right = right + 2;
            } else {
                rArr[rArrIndex] = *right;
                left = right;
                right = right + 1;
                rArrIndex = rArrIndex + 1;
            }
        } else {
                rArr[rArrIndex] = *left;
                rArr[rArrIndex+1] = *right;
                left = left + 2;
                right = right + 2;
                rArrIndex = rArrIndex + 2;
        }
    }
    #if DEBUG
        printf("5====\n");
        prArr(rArr, rArrIndex);
    #endif
    *returnSize = rArrIndex;
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