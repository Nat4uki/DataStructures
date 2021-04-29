//
// Created by Natsuki on 2021/4/27.
//
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"array.h"
#include"sort.h"


int partition(int a[], int i, int j) {
    int p = a[i]; // P是枢纽
    int m = i; // S1和S2一开始是空的
    for (int k = i + 1; k <= j; k++) { // 探索其他区域
        if (a[k] < p) { // case 2
            m++;
            swap(&a[k], &a[m]);
        } //主义：在情况1的时候我们设么都不做：a[k] >= p
    }
    swap(&a[i], &a[m]); //  最后一步，用a[m]交换枢纽
    return m; // 返回枢纽的指数，用于快速排序
}

void quickSort(int *a, int low, int high) {
    if (low < high) {
        int m = partition(a, low, high); // O(N)
        // a[low..high] ~> a[low..m–1], pivot, a[m+1..high]
        quickSort(a, low, m - 1); // 递归地将左子阵列排序
        // a[m] = pivot 在分区后就被排序好了
        quickSort(a, m + 1, high); // 然后将右子阵列排序
    }
}


int main() {
    int arraySize = 6;
    int *array = mallocArray(arraySize, 1, 100);
    printArray(array, arraySize);
    quickSort(array,0,arraySize-1);
    printArray(array, arraySize);
    freeArray(array);
    return 0;
}
