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