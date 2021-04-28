//
// Created by Natsuki on 2021/4/28.
//

#ifndef DATASTRUCTURES_ARRAY_H
#define DATASTRUCTURES_ARRAY_H
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#endif //DATASTRUCTURES_ARRAY_H

void printArray(int *a, int arraySize) {
    printf("The arraySize of array = %d\n", arraySize);
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int* mallocArray(int arraySize, int limit, int range) {
    srand(time(0));
    int *a = (int *) malloc(sizeof(int) * arraySize);
    for (int i = 0; i < arraySize; i++) {
        a[i] = rand() % (range - limit + 1) + limit;
    }
    return a;
}
int freeArray(int * array){
    free(array);
    return 0;
}

