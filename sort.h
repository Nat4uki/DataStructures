//
// Created by 19614 on 2021/4/29.
//

#ifndef DATASTRUCTURES_SORT_H
#define DATASTRUCTURES_SORT_H

#endif //DATASTRUCTURES_SORT_H

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/*
 * do
 *  swapped = false
 *  for i = 1 to indexOfLastUnsortedElement-1
 *      if leftElement > rightElement
 *          swap(leftElement, rightElement)
 *          swapped = true
 * while swapped*/
void bubbleSort(int *a,int arraySize){
    for (int i=0;i<arraySize-1;i++){
        for (int j=0;j<arraySize-1-i;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
            }
        }
    }
    return;
}
/*
 * repeat (numOfElements -1) times
 *  set the first unsorted element as the minimum
 *  for each of the the unsorted elements
 *      if element < currentMinimum
 *          set element as new minimum
 *  swap minimum with first unsorted position
 * */
void selectionSort(int *a,int arraySize){
    int currentMinIndex;
    for (int i =0;i<arraySize-1;i++){
        currentMinIndex = i;
        for (int j=i;j<arraySize;j++){
            if(a[j]<a[currentMinIndex]){
                currentMinIndex = j;
            }
        }
        swap(&a[i],&a[currentMinIndex]);
    }
    return;
}

void insertionSort(int *a,int arraySize){
    int currentInt;
    for (int i=1;i<arraySize;i++){
        currentInt = a[i];
        for (int j = i;j>0;j--){
            if (currentInt<a[j-1]){
                a[j] = a[j-1];
                if(j==1){
                    a[0] = currentInt;
                }
            }else{
                a[j] = currentInt;
                break;
            }
        }
    }
    return;
}

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