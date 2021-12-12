#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void * _a, const void * _b) {
    int a = *(int *)_a;
    int b = *(int *)_b;
    return a < b ? 1 : -1;
}

int findindex(int score, int *sorted, int scoreSize) {
    for(int i = 0; i < scoreSize; i++) {
        if(score == sorted[i])
            return i;
    }
    return 0;
}

char* first = "Gold Medal";
char* second = "Silver Medal";
char* third = "Bronze Medal";

char ** findRelativeRanks(int* score, int scoreSize, int* returnSize){
    //排序sorted
    int * sorted = malloc(sizeof(int) * scoreSize);
    memcpy(sorted, score, sizeof(int) * scoreSize);
    qsort(sorted, scoreSize, sizeof(int), cmp);

    //利用sorted对score做排序，结果保存在map中
    int * map = malloc(sizeof(int) * scoreSize);
    for(int i = 0; i < scoreSize; i++) {
        int index = findindex(score[i], sorted, scoreSize);
        map[i] = index + 1;
    }

    //把map翻译成字符串数组输出
    char ** ret = malloc(sizeof(char*) * scoreSize);
    for(int i = 0; i < scoreSize; i++) {
        if(map[i] == 1) {
            ret[i] = first;
        }
        else if(map[i] == 2) {
            ret[i] = second;
        }
        else if(map[i] == 3) {
            ret[i] = third;
        }
        else {
            ret[i] = malloc(sizeof(char) * 6);
            sprintf(ret[i], "%d", map[i]);
        }
    }
    *returnSize = scoreSize;
    return ret;
}

int main() {
    int score[] = {10,3,8,9,4};
    int returnSize = 0;
    char ** ret = NULL;
    ret = findRelativeRanks(score, sizeof(score) / sizeof(int), &returnSize);

    printf("[");
    for(int i = 0; i < returnSize; i++) {
        if(i != 0) {
            printf(", ");
        }
        printf("%s", ret[i]);
    }
    printf("]\r\n");
}