#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a, const void* b)
{
    if(*(int*)a > *(int*)b)
        return 1;
    else
        return -1;
}

int printfArray(int* nums, int numsSize)
{
    int i = 0;
    while(i < numsSize) {
        printf("%d,", nums[i]);
        i++;
    }
    printf("\n");
    return 0;
}

int maxFrequency(int* nums, int numsSize, int k){
    qsort(nums, numsSize, sizeof(int), cmp);
    return 0;
}

int main(){
    int test[] = {3,9,6};
    printfArray(test, 3);
    maxFrequency(test, 3, 5);
    printfArray(test, 3);
    return 0;
}
