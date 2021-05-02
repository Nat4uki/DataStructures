//
// Created by Natsuki on 2021/4/28.
//

#ifndef DATASTRUCTURES_ARRAY_H
#define DATASTRUCTURES_ARRAY_H
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#endif //DATASTRUCTURES_ARRAY_H
/**
 * @brief 打印数组指正内容
 * @param a
 * @param arraySize
 */
void printArray(int *a, int arraySize) {
//    printf("The arraySize of array = %d\n", arraySize);
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}


/**
 * @brief 创建数组指针并分配地址，使用随机数填充
 * @param arraySize 数组大小
 * @param limit 随机数的最小值
 * @param range 随机数变动的范围
 * @return 数组指针
 */
int* mallocArray(int arraySize, int limit, int range) {
    srand(time(0));
    int *a = (int *) malloc(sizeof(int) * arraySize);
    for (int i = 0; i < arraySize; i++) {
        a[i] = rand() % (range - limit + 1) + limit;
    }
    return a;

}
/**
 * @brief 释放指定的数组指针
 * @param array
 * @return int 0
 */
int freeArray(int * array){
    free(array);
    return 0;
}

