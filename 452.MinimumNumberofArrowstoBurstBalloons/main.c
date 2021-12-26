#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int pr(int** points, int pointsSize, int* pointsColSize)
{
    for(int i = 0; i < pointsSize; i++) {
        for(int j = 0; j < pointsColSize[i]; j++) {
            printf("%d ", points[i][j]);
        }
        printf("\r\n");
    }
    return 0;
}

int cmp(const void * _a, const void * _b)
{
    int *a = *(int **)_a;
    int *b = *(int **)_b;
/*
    printf("_a %lx\n", _a);
    printf("a %lx\n", a);
    printf("_b %lx\n", _b);
    printf("b %lx\n", b);
*/
    return a[1] > b[1] ? 1 : -1;
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    pr(points, pointsSize, pointsColSize);
    qsort(points, pointsSize, sizeof(int*), cmp);
    printf("==>after\n");
    pr(points, pointsSize, pointsColSize);

    int pos_balloon = points[0][1];
    int swords = 1;
    for(int i = 0; i < pointsSize; i++) {
        if(points[i][0] > pos_balloon) {
            swords++;
            pos_balloon = points[i][1];
        }
    }

    return swords;
}

int main()
{
    int points0[]={10,16};
    int points1[]={2,8};
    int points2[]={1,6};
    int points3[]={7,12};
    int* p[] = {points0, points1, points2, points3};
    int pointsColSize[] = {sizeof(points0)/sizeof(int),
                            sizeof(points1)/sizeof(int),
                            sizeof(points2)/sizeof(int),
                            sizeof(points3)/sizeof(int)
                            };
/*
    printf("sizeof(pointsColSize) %d\n", sizeof(pointsColSize));
    printf("pointsColSize[0] %d\n", pointsColSize[0]);
    printf("sizeof(int) %d\n", sizeof(int));
    printf("sizeof(int*) %d\n", sizeof(int*));
    printf("sizeof(p) %d\n", sizeof(p));
    printf("sizeof(p)/sizeof(int*) %d\n", sizeof(p)/sizeof(int*));
    printf("points0 %lx\n", points0);
    printf("points1 %lx\n", points1);
    printf("points2 %lx\n", points2);
    printf("points3 %lx\n", points3);
    printf("&p[0] %lx\n", &p[0]);
    printf("&p[1] %lx\n", &p[1]);
    printf("&p[2] %lx\n", &p[2]);
    printf("&p[3] %lx\n", &p[3]);
*/
    int ret = 0;
    //printf("sizeof(p) %d\n", sizeof(p));
    ret = findMinArrowShots(p, sizeof(pointsColSize)/sizeof(int), pointsColSize);
    printf("[%d]\r\n", ret);

    return 0;
}
